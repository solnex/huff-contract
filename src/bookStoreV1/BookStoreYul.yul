object "BookStoreYul"{
    code{
        //contract deploy
        datacopy(0, dataoffset("runtime"), datasize("runtime"))
        return(0, datasize("runtime"))
    
    }

    object "runtime"{
        code{
            
            switch selector()
            //cast sig "updateBooksNumber(uint256)"
            case 0x227ffe59{
              sstore(0, decodeAsUint(0))
            }  
            //cast sig "getNumberOfBook()"\
            case 0x356f4ea4{
               returnUint(sload(0))
            }
            default{
                revert(0,0)
            }

            function selector() -> s {
                s := div(calldataload(0), exp(2, 224))
            }

            function decodeAsUint(offset) -> v {
                let pos := add(4,mul(offset, 32))
                if lt(calldatasize(), add(pos, 32)) {
                    revert(0, 0)
                }
                v := calldataload(pos)
            }

            function returnUint(v){
                mstore(0,v)
                return(0,32)
            }
        }
    }
}