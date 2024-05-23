//SPDX-License-Identifier: MIT
pragma solidity 0.8.20;

contract BookStoreYul{
    uint256 bookCount;

    function updateBooksNumber(uint256 newNumber) external {
        assembly {
            sstore(bookCount.slot, newNumber)
        }
    }

    function getNumberOfBook() external view returns (uint256) {
        assembly{
            let x:= sload(bookCount.slot)
            mstore(0x00, x)
            return(0,0x20)
        }
    }
}