//SPDX-License-Identifier: MIT
pragma solidity 0.8.20;
import {Base_Test,BookStore} from "./Base_Test.t.sol";
import {HuffDeployer} from "foundry-huff/HuffDeployer.sol";
contract BookStoreHuff is Base_Test{
    string public constant BOOK_STORE_HUFF_LOCATION="bookStoreV1/BookStore";
    function setUp() public override {
    
        bookStore = BookStore(HuffDeployer.config().deploy(BOOK_STORE_HUFF_LOCATION));
    }
}