pragma solidity ^0.8.0;

// SPDX-License-Identifier: MIT

contract lotteryDapp {

    // Struct Item
    struct Item {
        uint itemId;
        string name;
        address[] bids;
        uint bidCount; 
    }

    address public primaryOwner; // Διεύθυνση πρώτου ιδιοκτήτη
    address public secondaryOwner; // Διεύθυνση δεύτερου ιδιοκτήτη
    mapping(uint => Item) public items; // Mapping από item ID στο Item struct
    mapping(uint => address) public itemWinners;  // Mapping από item ID στη διεύθυνση του νικητή

    uint public bidPrice = 0.01 ether; // Τιμή για κάθε bid
    uint constant numItems = 3; // Αριθμός αντικειμένων 

    // Events
    event BidPurchased(address indexed buyer, uint itemId);
    event WinnerDeclared(uint itemId, address indexed winnerAddress);

    // Modifier για περιορισμό μόνο για τους Owners
    modifier onlyOwners() {
        require(msg.sender == primaryOwner || msg.sender == secondaryOwner, "Only an owner can perform this action.");
        _;
    }

    // Constructor
    constructor() {
        primaryOwner = msg.sender; // Πρώτος owner, ο δημιουργός του συμβολαίου
        secondaryOwner = 0x153dfef4355E823dCB0FCc76Efe942BefCa86477; // Δεύτερος owner έχει την παρούσα διεύθυνση
        // Αρχικοποίηση αντικειμένων
        items[0] = Item(0, "Car", new address[](0), 0);
        items[1] = Item(1, "Phone", new address[](0), 0);
        items[2] = Item(2, "Computer", new address[](0), 0);
    }

    // Συνάρτηση για bidding ανά αντίκειμενο
    function buyBids(uint itemId, uint numBids) public payable {
        require(itemId < numItems, "Invalid item ID.");
        require(msg.value == bidPrice * numBids, "Incorrect Ether value.");

        for (uint i = 0; i < numBids; i++) {
            items[itemId].bids.push(msg.sender);
            items[itemId].bidCount++; 
    }

    emit BidPurchased(msg.sender, itemId);
    }

    // Συνάρτηση για αποκάλυψη των νικητών
    function drawWinner(uint itemId) public onlyOwners {
        require(itemId < numItems, "Invalid item ID.");
        require(items[itemId].bids.length > 0, "No bids for this item.");

        // Γεννήτρια τυχαίου αριθμού με χρήση https://www.geeksforgeeks.org/random-number-generator-in-solidity-using-keccak256/
        uint randomIndex = uint(keccak256(abi.encodePacked(block.timestamp, block.difficulty, itemId))) % items[itemId].bids.length;
        address winnerAddress = items[itemId].bids[randomIndex];

        itemWinners[itemId] = winnerAddress; 

        emit WinnerDeclared(itemId, winnerAddress);

    }

    // Συνάρτηση που επιστρέφει τα αντικείμενα σε περίπτωση νίκης
    function amIWinner(uint itemId) public view returns (bool) {
        require(itemId < numItems, "Invalid item ID.");
        return itemWinners[itemId] == msg.sender;
    }

    // Συνάρτηση που μεταφέρει τα ETH του συμβολαίου στους owners
    function withdraw() public onlyOwners {
        payable(primaryOwner).transfer(address(this).balance / 2);
        payable(secondaryOwner).transfer(address(this).balance);
    }

    // Επιστροφή του αριθμού των bids για κάθε αντικείμενο
    function getBidCounts() public view returns (uint[] memory) {
        uint[] memory bidCounts = new uint[](numItems);
        for (uint i = 0; i < numItems; i++) {
             bidCounts[i] = items[i].bidCount;
        }   
        return bidCounts;
    }

    // Συνάρτηση για επιστροφή του id των αντικειμένων που έχει κερδίσει ο παίκτης
    function getWinningItems(address player) public view returns (uint[] memory) {
        uint[] memory playerWins = new uint[](numItems); 
        uint count = 0;

        for (uint i = 0; i < numItems; i++) {
            if (itemWinners[i] == player) { 
                playerWins[count] = i;
                count++;
            }
        }

        uint[] memory winningItems = new uint[](count);
        for (uint i = 0; i < count; i++) {
            winningItems[i] = playerWins[i];
        }

    return winningItems;
    }   

    // Συνάρτηση για επανέναρξη νέου κύκλου
    function startNewLotteryCycle() public onlyOwners {
        for (uint i = 0; i < numItems; i++) {
            delete items[i].bids; 
            items[i].bidCount = 0; 
        }
        
        for (uint i = 0; i < numItems; i++) {
            delete itemWinners[i];
        }
    }

    // Συνάρτηση για μεταφορά του συμβολαίου σε νέο ιδιοκτήτη
    function transferOwnership(address newOwner) public onlyOwners {
        require(newOwner != address(0), "New owner is the zero address.");
        primaryOwner = newOwner;
    }

    // Συνάρτηση για καταστροφή του συμβολαίου
    function destroyContract() public onlyOwners {
        selfdestruct(payable(primaryOwner));
    }

}
