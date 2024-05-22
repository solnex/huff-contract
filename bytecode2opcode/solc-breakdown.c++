//0x6080604052348015600e575f80fd5b5060a58061001b5f395ff3fe
//6080604052348015600e575f80fd5b50600436106030575f3560e01c8063227ffe59146034578063356f4ea4146045575b5f80fd5b6043603f3660046059565b5f55565b005b5f5460405190815260200160405180910390f35b5f602082840312156068575f80fd5b503591905056fea26469706673582212208c7e16efd489e2659c6593119b6cdb29c8ad067da5f51546e571781f2d1df45b64736f6c63430008140033


//1.contract creation code
//2.runtime bytecode
//3.metadata

//1. contract creation code
//free memory pointer
PUSH1 0x80              //[0x80]
PUSH1 0x40              //[0x40, 0x80]
MSTORE                  //[]    memory[0x40] = 0x80

//if call value is zero, jump to 0x0e
//otherwise, revert
CALLVALUE               //[msg.value]
DUP1                    //[msg.value, msg.value]
ISZERO                  //[msg.value == 0 ?, msg.value]
PUSH1 0x0e              //[0x0e, msg.value == 0 ?, msg.value]
JUMPI                   //[msg.value]
PUSH0                   //[0x00, msg.value]
DUP1                    //[0x00, 0x00, msg.value]
REVERT                  //[]

//0x0e 
JUMPDEST                //[msg.value]
POP                     //[]
PUSH1 0xa5              //[0xa5]
DUP1                    //[0xa5, 0xa5]
PUSH2 0x001b            //[0x001b, 0xa5, 0xa5]
PUSH0                   //[0x00, 0x001b, 0xa5, 0xa5]
CODECOPY                //[0xa5]
PUSH0                   //[0x00, 0xa5]
RETURN                  //[]
INVALID

//2. runtime bytecode
//free memory pointer
PUSH1 0x80              //[0x80]
PUSH1 0x40              //[0x40, 0x80]
MSTORE                  //[]       memory[0x40] = 0x80
CALLVALUE               //[msg.value]
DUP1                    //[msg.value, msg.value]
ISZERO                  //[msg.value == 0 ?, msg.value]
PUSH1 0x0e              //[0x0e, msg.value == 0 ?, msg.value]
JUMPI                   //[msg.value]
PUSH0                   //[0x00, msg.value]
DUP1                    //[0x00, 0x00, msg.value]
REVERT                  //[]

//0x0e
JUMPDEST                
POP                     //[]
PUSH1 0x04              //[0x04]
CALLDATASIZE            //[calldata_size, 0x04]
LT                      //[calldata_size < 0x04 ?, calldata_size]
PUSH1 0x30              //[0x30, calldata_size < 0x04 ?, calldata_size]
//if calldata_size < 0x04, jump to 0x30,revert
JUMPI                   //[calldata_size]
PUSH0                   //[0x00,calldatasize]
CALLDATALOAD            //[calldata[0], calldatasize]
PUSH1 0xe0              //[0xe0, calldata[0], calldatasize]
SHR                     //[function_signature, calldatasize]
DUP1                    //[function_signature, function_signature, calldatasize]
PUSH4 0x227ffe59        //[0x227ffe59, function_signature, function_signature, calldatasize]
EQ                      //[function_signature == 0x227ffe59 ?,function_signature, calldatasize]
PUSH1 0x34              //[0x34, function_signature == 0x227ffe59 ?,function_signature, calldatasize]
//if function_signature == 0x227ffe59, jump to 0x34
JUMPI                   //[function_signature, calldatasize]
DUP1                    //[function_signature, function_signature, calldatasize]
PUSH4 0x356f4ea4        //[0x356f4ea4, function_signature, function_signature, calldatasize]
EQ                      //[function_signature == 0x356f4ea4 ?,function_signature, calldatasize]
PUSH1 0x45              //[0x45, function_signature == 0x356f4ea4 ?,function_signature, calldatasize]
JUMPI                   //[function_signature, calldatasize]

//0x30
//if calldata_size < 0x04, revert
JUMPDEST
PUSH0                   //[0x00]
DUP1                    //[0x00, 0x00]
REVERT                  //[]

//0x34
//update book number
JUMPDEST
PUSH1 0x43              //[0x43]
PUSH1 0x3f              //[0x3f, 0x43]
CALLDATASIZE            //[calldatasize, 0x3f, 0x43]
PUSH1 0x04              //[0x04, calldatasize, 0x3f, 0x43]
PUSH1 0x59              //[0x59, 0x04, calldatasize, 0x3f, 0x43]
JUMP

//0x3f
JUMPDEST                //[value_book_number, 0x43]
PUSH0                   //[0x00, value_book_number, 0x43]
SSTORE                  //[0x43]   storage[0] = value_book_number
JUMP
//0x43
JUMPDEST
STOP

//0x45
//get book number function
JUMPDEST                //[function_signature, calldatasize]
PUSH0                   //[0x00, function_signature, calldatasize]
SLOAD                   //[value_book_number, function_signature, calldatasize]
PUSH1 0x40              //[0x40, value_book_number, function_signature, calldatasize]   memory[0x40] = 0x80
MLOAD                   //[0x80, value_book_number, function_signature, calldatasize]
SWAP1                   //[value_book_number, 0x80, function_signature, calldatasize]
DUP2                    //[0x80, value_book_number, 0x80, function_signature, calldatasize]
MSTORE                  //[0x80, function_signature, calldatasize]  memory[0x80] = value_book_number
PUSH1 0x20              //[0x20, 0x80, function_signature, calldatasize]
ADD                     //[0xa0, function_signature, calldatasize]
PUSH1 0x40              //[0x40, 0xa0, function_signature, calldatasize]
MLOAD                   //[0x80, 0xa0, function_signature, calldatasize]
DUP1                    //[0x80, 0x80, 0xa0, function_signature, calldatasize]
SWAP2                   //[0xa0, 0x80, 0x80, function_signature, calldatasize]
SUB                     //[0x20, 0x80, function_signature, calldatasize]
SWAP1                   //[0x80, 0x20, function_signature, calldatasize]
RETURN

//0x59
JUMPDEST                //[0x04, calldatasize, 0x3f, 0x43]
PUSH0                   //[0x00, 0x04, calldatasize, 0x3f, 0x43]
PUSH1 0x20              //[0x20, 0x00, 0x04, calldatasize, 0x3f, 0x43]
DUP3                    //[0x04, 0x20, 0x00, 0x04, calldatasize, 0x3f, 0x43]
DUP5                    //[calldatasize, 0x04, 0x20, 0x00, 0x04, calldatasize, 0x3f, 0x43]
SUB                     //[calldatasize - 0x04, 0x20, 0x00, 0x04, calldatasize, 0x3f, 0x43]
SLT                     //[calldatasize - 0x04 < 0x20 ?, 0x00, 0x04, calldatasize, 0x3f, 0x43]
ISZERO                  //[calldatasize - 0x04 < 0x20 ? == 0 ?,0x00, 0x04, calldatasize, 0x3f, 0x43]
PUSH1 0x68              //[0x68, calldatasize - 0x04 < 0x20 ? == 0 ?, 0x00, 0x04, calldatasize, 0x3f, 0x43]
JUMPI
//if calldatasize - 0x04 < 0x20, revert
PUSH0
DUP1
REVERT

//0x68
//if calldatasize - 0x04 >= 0x20, continue
JUMPDEST
POP                      //[0x04, calldatasize, 0x3f, 0x43]
CALLDATALOAD             //[value_book_number, calldatasize, 0x3f, 0x43]
SWAP2                    //[0x3f, calldatasize, value_book_number, 0x43]
SWAP1                    //[calldatasize, 0x3f, value_book_number, 0x43]
POP                      //[0x3f, value_book_number, 0x43]
//jump to 0x3f to sstore the value_book_number
JUMP
INVALID

//3. metadata
LOG2
PUSH5 0x6970667358
INVALID
SLT
KECCAK256
DUP13
PUSH31 0x16efd489e2659c6593119b6cdb29c8ad067da5f51546e571781f2d1df45b64
PUSH20 0x6f6c63430008140033
