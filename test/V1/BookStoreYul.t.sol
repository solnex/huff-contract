//SPDX-License-Identifier: MIT
pragma solidity 0.8.20;
import {BookStoreYul} from "../../src/bookStoreV1/BookStoreYul.sol";
import {Base_Test, BookStore} from "./Base_Test.t.sol";
contract BookStoreYulTest is Base_Test{
    function setUp() public override{
         bookStore = BookStore(address(new BookStoreYul()));
    }

}