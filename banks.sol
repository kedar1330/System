
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank {

    uint256 public balance = 0;
    address public accOwner;

    // Constructor
    constructor() {
        accOwner = msg.sender;
    }

    // Deposit
    function Deposit() public payable {
        require(
            accOwner == msg.sender,
            "You are not an account owner"
        );

        require(
            msg.value > 0,
            "Deposit amount should be greater than zero"
        );

        balance += msg.value;
    }

    // Withdraw
    function Withdraw(uint256 amount) public payable  {
        require(
            accOwner == msg.sender,
            "You are not an account owner"
        );

        require(
            amount > 0,
            "Withdrawal amount should be greater than zero"
        );

        require(
            amount <= balance,
            "Insufficient balance"
        );

        balance -= amount;

        
    }

    // Show balance
    function show() public view returns (uint256) {
        require(
            accOwner == msg.sender,
            "You are not an account owner"
        );

        return balance;
    }
}
