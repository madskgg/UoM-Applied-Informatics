pragma solidity ^0.8.18;
// SPDX-License-Identifier: GPL-3.0

contract Lottery {

    // Struct Person
    struct Person {
        uint personId;
        address addr;
        uint remainingTokens;
    }

    // Struct Item
    struct Item {
        uint itemId;
        uint[] itemTokens;
    }
    
    // Δημιουργία μεταβλητής Stage 
    enum Stage {Init, Reg, Bid, Done} 
    Stage public stage; 

    mapping(address => Person) tokenDetails; // Διεύθυνση παίκτη
    Person [] public bidders; // Πίνακας παικτών
    Item [] public items; // Πίνακας αντικειμένων
    address[] public winners; // Πίνακας νικητών
    address public beneficiary; // Ο πρόεδρος του συλλόγου και ιδιοκτήτης του smart contract
    uint bidderCount = 0; // Πλήθος των εγγεγραμένων παικτών

    uint lotteriesCount = 1; // Αριθμός λαχειοφόρου

    event Winner(address winnerAddr, uint itemId, uint lotteriesCount); // event Winner

    // Constructor ο οποίος δέχεται σαν όρισμα των αριθμό των αντικειμένων
    constructor(uint itemsNumber) payable{
        // Αρχικοποίηση του προέδρου με τη διεύθυνση του κατόχου του έξυπνου συμβολαίου
        beneficiary = msg.sender;

        //Δημιουργία αντικειμένων με τη χρήση μια επανάλψης for 
        uint[] memory emptyArray;
        for (uint i = 0; i < itemsNumber; i++){
            items.push(Item({itemId:i, itemTokens:emptyArray})); // Η push προσθέτει ένα στοιχείο τύπου struct Item στον πίνακα items
            winners.push(address(0)); // Προσθέτει στον πίνακα winners (ίδιου μεγέθους με τον πίνακα items) την διεύθυνση address(0) που συμβολίζει το null address στο ethereum
        }
        stage = Stage.Init;
    }

    // Συνάρτηση για την εγγραφή ενός παίκτη
    function register() public payable isRegisteredPlayer {
        require(stage == Stage.Reg,"Not in reg stage");
        require(msg.sender != beneficiary,"You are the beneficiary");
        bidders.push(Person({personId:bidderCount, addr:msg.sender, remainingTokens:5})); // Η push προσθέτει ένα στοιχείο τύπου struct Person στον πίνακα items
        tokenDetails[msg.sender] = bidders[bidderCount];
        bidderCount++;
    }

    // Ποντάρει _count λαχεία στο αντικείμενο _itemId
    function bid (uint _itemId, uint _count) public payable isValid(_itemId) hasTokens(_count){ 
        require(stage == Stage.Bid,"Not in bid stage");
        for (uint i = 0; i < _count; i++) {
            items[_itemId].itemTokens.push(tokenDetails[msg.sender].personId);
            tokenDetails[msg.sender].remainingTokens--;
        }
    }

    // Συνάρτηση που φανερώνει τους νικητές (με χρήση του modifier onlyOwner)
    function revealWinners() public payable onlyOwner {
        require(stage == Stage.Done,"Not in done stage");
        uint temp = 0;
        uint lgth = items.length;
        for (uint i = 0; i<lgth; i++) {
            if(items[i].itemTokens.length > 0 && winners[i] == address(0)){
                temp = randomNumber() % bidders.length; // Καλούμε την συνάρτηση randomNumber που επιστρέφει έναν τυχαίο αριθμό τον οποίο αποθηκέυουμε προσωρινά στο temp
                winners[i] = (findAddress(items[i].itemTokens[temp])); // Αποθηκεύουμε στον πίνακα winners την διεύθυνση του παίκτη-νικητή με τη βοήθεια της συνάρτησης findAddress
                emit Winner(winners[i], i, lotteriesCount); // Κάνουμε emit το event Winner
            }
        }
    }

    // Συνάρτηση για να μεταφέρει ο ιδιοκτήτης του contact τα δοκιμαστικά ether
    // στο πορτοφόλι του
    function withdraw() public payable onlyOwner{
        address payable recipient = payable(beneficiary);
        recipient.transfer(address(this).balance);
    }

    // Συνάρτηση με την οποία ο ιδιοκτήτης του συμβολαίου μπορεί να κάνει 
    // επανέναρξη του συμβολαίου με καινούριο αριθμό αντικειμένων, έχοντας
    // διαγράψει όλα τα προηγούμενα. Γίνονται χρήση της δεσμευμένης λέξης delete
    // και ορισμένες αρχικοποιήσεις.
    function reset(uint numberOfItems) public payable onlyOwner{
        for(uint i=0; i<bidders.length; i++){
            delete tokenDetails[bidders[i].addr];
        }
        lotteriesCount++;
        delete bidders;
        delete items;
        delete winners;
        bidderCount = 0;
        stage = Stage.Init;
        uint[] memory emptyArray;
        for (uint i = 0; i < numberOfItems; i++){
            items.push(Item({itemId:i, itemTokens:emptyArray}));
            winners.push(address(0)); 
        }
    }

    // Συνάρτηση για την εύρεση της διέυθυνσης χρησιμοποιώντας το id ενός παίκτη 
    // με τη χρήση linear search
    function findAddress(uint id) internal view returns(address){
        for(uint i=0; i<bidders.length; i++){
            if(bidders[i].personId == id){
                return bidders[i].addr;
            }
        }
        return address(0);
    }

    // Modifier για να ελέγχει αν είναι ο ιδιοκτήτης του contract
    modifier onlyOwner {
        require(msg.sender == beneficiary, "You are NOT the owner");
        _;
    }

    // Modifier για τον έλεγχο του ποσού πληρωμής
    modifier hasMoney {
        require(msg.value >= 0.005 ether,"You do NOT have enough ethers!");
        _;
    }

    // Modifier για να ελέγχει απομένουν αρκετά tokens στον παίκτη
    modifier hasTokens(uint _count) {
        require(tokenDetails[msg.sender].remainingTokens >= _count, "You do NOT have enough tokens!");
        _;
    }

    // Modifier για τον έλεγχο του id ενός item
    modifier isValid(uint _itemId) {
        bool flag = false;
        for (uint id = 0; id < items.length; id++) { 
            if(items[id].itemId == _itemId){
                flag = true;
            }
        }
        require(flag == true, "No item with this id found");
        _;
    }

    // Modifier για να ελέγχει αν ένας παίκτης έχει ήδη εγγραφεί
    modifier isRegisteredPlayer {
        bool flag = false;
        for (uint i = 0; i < bidderCount; i++){
            if(bidders[i].addr == msg.sender ){
                flag = true;
            }
        } 
        require(flag == false, "You are already registered");
        _;
    }

    // Πολύ απλή γεννήτρια τυχαίων
    function randomNumber() private view returns (uint) {
        return uint(block.timestamp);
    }

    // Συνάρτηση με την οποία ο ιδιοκτήτης του συμβολαίου μετακινεί την
    // εκτέλεση στο επόμενο στάδιο
    function advanceState() public payable onlyOwner{
        if(stage == Stage.Init){
            stage = Stage.Reg;
        }else if(stage == Stage.Reg){
            stage = Stage.Bid;
        }else if(stage == Stage.Bid){
            stage = Stage.Done;
        }
    }
}