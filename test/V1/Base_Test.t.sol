//SPDX-License-Identifier: MIT
pragma solidity 0.8.20;
import {BookStore} from  "../../src/bookStoreV1/BookStore.sol";
import {Test} from "forge-std/Test.sol";

abstract contract Base_Test is Test{
    BookStore public bookStore;
    function setUp() public virtual  {
        bookStore = new BookStore();
    }

    function testSetBookNumber() public {
        bookStore.updateBooksNumber(1);
        assertEq(bookStore.getNumberOfBook(), 1);
    }

    function testGetBookNumber() public view {
        assertEq(bookStore.getNumberOfBook(), 0);
    }
}