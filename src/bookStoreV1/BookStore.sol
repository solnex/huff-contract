// SPDX-License-Identifier: GPL-3.0-only
pragma solidity 0.8.20;

contract BookStore {
    uint256 numberOfBooks;

    function updateBooksNumber(uint256 newNumberOfBook) external {
        numberOfBooks = newNumberOfBook;
    }

    function getNumberOfBook() external view returns (uint256) {
        return numberOfBooks;
    }
}
