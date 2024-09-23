import React, { Component } from "react";
import Web3 from "web3";
import lottery from "./lotteryDapp";
import "./App.css";
import carImage from "./images/car.png";
import phoneImage from "./images/phone.png";
import computerImage from "./images/laptop.png";

class App extends Component {
  state = {
    currentAccount: null, // Τρέχον επιλεγμένος λογαριασμός
    contractOwner: null, // Ιδιοκτήτης του συμβολαίου
    items: ["Car", "Phone", "Computer"], // Διαθέσιμα αντικείμενα
    bidCounts: [], // Πίνακας για την παρακολούθηση των bids για κάθε αντικείμενο
    totalEther: 0, // Συνολικό Ether που έχει συλλέξει το συμβόλαιο
    isOwner: false, // Flag για τον έλεγχο αν ο τρέχων λογαριασμός είναι ο ιδιοκτήτης του συμβολαίου
    winnerDeclared: false, // Flag που δηλώνει αν έχουν κηρυχθεί νικητές
    lastWinner: null, // Διεύθυνση του τελευταίου νικητή
    newOwner: "", // Διεύθυνση για τη μεταφορά ιδιοκτησίας
    metaMaskInstalled: false, // Flag για τον έλεγχο αν το MetaMask είναι εγκατεστημένο
    userMessage: "", // Μήνυμα προς εμφάνιση στον χρήστη
  };

  componentDidMount() {
    this.initializeWeb3(); // Αρχικοποίηση web3 και έλεγχος αν το MetaMask είναι εγκατεστημένο
    this.loadBlockchainData(); // Φόρτωση αρχικών δεδομένων από το blockchain

    // Event listeners
    lottery.events.BidPurchased().on("data", this.onBidPurchased);
    lottery.events.WinnerDeclared().on("data", this.onWinnerDeclared);

    // Listener για αλλαγές στους λογαριασμούς
    window.ethereum?.on("accountsChanged", this.handleAccountsChanged);

    // Ανανέωση δεδομένων blockchain κάθε 3 δευτερόλεπτα
    this.interval = setInterval(this.loadBlockchainData, 3000);

    // Έλεγχος αν έχουν κηρυχθεί νικητές
    const winnerDeclared = localStorage.getItem("winnerDeclared") === "true";
    this.setState({ winnerDeclared });
  }

  componentWillUnmount() {
    // "Καθαρισμός" listeners και interval
    clearInterval(this.interval);
    window.ethereum?.removeListener(
      "accountsChanged",
      this.handleAccountsChanged
    );
  }

  // Αρχικοποίηση της έκδοσης web3 και ρύθμιση σύνδεσης με το MetaMask
  initializeWeb3 = async () => {
    if (window.ethereum) {
      window.web3 = new Web3(window.ethereum);
      try {
        await window.ethereum.enable();
        this.setState({
          metaMaskInstalled: true,
          userMessage: "Metamask connected",
        });
      } catch (error) {
        console.error("User denied account access", error);
        this.setState({
          userMessage:
            "MetaMask access denied. Please allow access to use this app.",
        });
      }
    } else if (window.web3) {
      window.web3 = new Web3(window.web3.currentProvider);
      this.setState({ metaMaskInstalled: true });
    } else {
      this.setState({
        userMessage:
          "You should consider installing MetaMask to interact with this app.",
      });
    }
  };

  // Φόρτωση δεδομένων από το blockchain
  loadBlockchainData = async () => {
    if (!this.state.metaMaskInstalled) return;

    const accounts = await window.web3.eth.getAccounts();
    if (accounts.length === 0) {
      this.setState({
        userMessage: "No accessible accounts. Please connect with MetaMask.",
      });
      return;
    }

    const account = accounts[0];
    this.setState({ currentAccount: account });

    const contractOwner = await lottery.methods.primaryOwner().call();
    this.setState({
      contractOwner,
      isOwner: contractOwner.toLowerCase() === account.toLowerCase(),
    });

    const totalEther = await window.web3.eth.getBalance(
      lottery.options.address
    );
    this.setState({
      totalEther: window.web3.utils.fromWei(totalEther, "ether"),
    });

    const bidCountsArray = await lottery.methods.getBidCounts().call();
    this.setState({
      bidCounts: bidCountsArray.map((count) => count.toString()),
    });
  };

  // Callback για bids
  onBidPurchased = (event) => {
    this.loadBlockchainData(); // Refresh data to reflect the ticket purchase
  };

  // Callback για την κήρυξη ενός νικητή
  onWinnerDeclared = (event) => {
    const lastWinner = event.returnValues.winnerAddress;
    this.setState({ lastWinner, winnerDeclared: true });
    this.loadBlockchainData();
    localStorage.setItem("winnerDeclared", "true");
  };

  // Callback για την αλλαγή του επιλεγμένου λογαριασμού του χρήστη στο MetaMask
  handleAccountsChanged = (accounts) => {
    if (accounts.length === 0) {
      this.setState({ userMessage: "Please connect to MetaMask." });
    } else {
      const newAccount = accounts[0];
      this.setState({ currentAccount: newAccount });
      this.loadBlockchainData();
    }
  };

  // Μέθοδος για την αγορά bids
  bid = async (itemId) => {
    if (this.state.winnerDeclared) {
      this.setState({
        userMessage: "Bidding is closed. Winners have been declared.",
      });
      return;
    }
    try {
      await lottery.methods.buyBids(itemId, 1).send({
        from: this.state.currentAccount,
        value: window.web3.utils.toWei("0.01", "ether"),
      });
    } catch (error) {
      this.handleError(error);
    }
  };

  // Μέθοδος για έλεγχο των νικητών
  checkWinner = async () => {
    const { currentAccount } = this.state;
    try {
      const winningItemIds = await lottery.methods
        .getWinningItems(currentAccount)
        .call();

      if (winningItemIds.length > 0) {
        const winningItemNames = winningItemIds
          .map((id) => this.state.items[id])
          .join(", ");
        this.setState({ userMessage: `You won: ${winningItemNames}` });
      } else {
        this.setState({ userMessage: "You did not win any items." });
      }
    } catch (error) {
      this.handleError(error);
    }
  };

  // Μέθοδος για την κήρυξη των νικητών
  declareWinner = async () => {
    try {
      for (let itemId = 0; itemId < this.state.items.length; itemId++) {
        await lottery.methods
          .drawWinner(itemId)
          .send({ from: this.state.currentAccount });
      }
      this.setState({
        userMessage: "Winners declared for all items.",
        winnerDeclared: true,
      });
      localStorage.setItem("winnerDeclared", "true");
    } catch (error) {
      this.handleError(error);
    }
  };

  // Μέθοδος για την ανάληψη των ETH του συμβολαίου
  withdraw = async () => {
    try {
      await lottery.methods
        .withdraw()
        .send({ from: this.state.currentAccount });
    } catch (error) {
      this.handleError(error);
    }
  };

  // Μέθοδος για την έναρξη νέου κύκλου της λαχειοφόρου αγοράς
  startNewLotteryCycle = async () => {
    try {
      await lottery.methods
        .startNewLotteryCycle()
        .send({ from: this.state.currentAccount });
      this.loadBlockchainData();
      this.setState({
        userMessage: "New lottery cycle started. All bid counts reset.",
        winnerDeclared: false,
      });
    } catch (error) {
      this.handleError(error);
    }
  };

  // Event handler για την αλλαγή ιδιοκτησίας
  handleNewOwnerChange = (event) => {
    this.setState({ newOwner: event.target.value });
  };

  // Μέθοδος για την μεταφορά της ιδιοκτησίας του συμβολαίου
  transferOwnership = async () => {
    try {
      await lottery.methods
        .transferOwnership(this.state.newOwner)
        .send({ from: this.state.currentAccount });
    } catch (error) {
      this.handleError(error);
    }
  };

  // Μέθοδος για την καταστροφή του συμβολαίου
  destroyContract = async () => {
    try {
      await lottery.methods
        .destroyContract()
        .send({ from: this.state.currentAccount });
    } catch (error) {
      this.handleError(error);
    }
  };

  // Μέθοδος για την εμφάνιση σφαλμάτων
  handleError = (error) => {
    console.error(error);
    let message = "An error occurred. Please try again.";
    if (error.code === 4001) {
      // User denied transaction signature
      message = "Transaction canceled by user.";
    } else if (error.message.includes("revert")) {
      // Handle revert errors
      message =
        "Transaction failed: " + error.message.split("revert")[1].trim();
    }
    this.setState({ userMessage: message });
  };

  // Μέθοδος για την εμφάνιση των αντικειμένων
  renderItems = () => {
    const { items, bidCounts, isOwner, winnerDeclared } = this.state;
    const images = {
      Car: carImage,
      Phone: phoneImage,
      Computer: computerImage,
    };

    return (
      <div className="items-container">
        {items.map((item, index) => (
          <div key={index} className="item-card">
            <span className="item-title">{item}</span>
            <img src={images[item]} alt={item} className="item-img" />
            <div className="item-body">
              <button
                onClick={() => this.bid(index)}
                className={`item-button ${
                  isOwner || winnerDeclared ? "button-disabled" : ""
                }`} // Add winnerDeclared condition
                disabled={isOwner || winnerDeclared} // Disable the button if the owner has declared winners
              >
                Bid
              </button>
              <div className="item-count">{bidCounts[index]}</div>
            </div>
          </div>
        ))}
      </div>
    );
  };

  // Μέθοδος για την εμφάνιση των επιλογών του ιδιοκτήτη
  renderOwnerActions = () => {
    const { isOwner, winnerDeclared } = this.state;

    return (
      <>
        <div className="main-buttons">
          <button
            className={`account-action ${
              winnerDeclared ? "winner-declared" : "button-disabled"
            }`}
            onClick={this.checkWinner}
            disabled={!winnerDeclared} // Enable the button if winners have been declared
          >
            Am I Winner
          </button>
          <button
            className={`account-action ${!isOwner ? "button-disabled" : ""}`}
            onClick={this.withdraw}
            disabled={!isOwner}
          >
            Withdraw
          </button>
          <button
            className={`account-action ${
              !isOwner || winnerDeclared ? "button-disabled" : ""
            }`}
            onClick={this.declareWinner}
            disabled={!isOwner || winnerDeclared} // Button is disabled if not the owner or winners have been declared
          >
            Declare Winners
          </button>

          <button
            className={`account-action ${!isOwner ? "button-disabled" : ""}`}
            onClick={this.startNewLotteryCycle}
            disabled={!isOwner}
          >
            Start New Lottery
          </button>
        </div>
        <div className="main-buttons">
          <button
            className={`account-action ${!isOwner ? "button-disabled" : ""}`}
            onClick={this.transferOwnership}
            disabled={!isOwner}
          >
            Transfer Ownership
          </button>
          <input
            type="text"
            placeholder="New Owner Address"
            onChange={this.handleNewOwnerChange}
            value={this.state.newOwner}
            disabled={!isOwner}
            className={!isOwner ? "input-disabled" : ""}
          />
          <button
            className={`account-action destroy-button ${
              !isOwner ? "button-disabled" : ""
            }`}
            onClick={this.destroyContract}
            disabled={!isOwner}
          >
            Destroy Contract
          </button>
        </div>
      </>
    );
  };

  // Μέθοδος για την εμφάνιση του UI
  render() {
    const { currentAccount, contractOwner, userMessage } = this.state;

    return (
      <div className="app-container">
        <h1 className="header">Lottery - Ballot</h1>
        {this.renderItems()}
        {this.renderOwnerActions()}
        <div className="accounts-container">
          <div className="account">
            <p>Current account:</p>
            <input
              type="text"
              className="account-address"
              value={currentAccount}
              readOnly
            />
          </div>
          <div className="account">
            <p>Owner's account:</p>
            <input
              type="text"
              className="account-address"
              value={contractOwner}
              readOnly
            />
          </div>
        </div>
        <br />
        <hr />
        <br />
        <div className="user-message">Info: {userMessage}</div>
      </div>
    );
  }
}

export default App;
