// ByteCodes
/*
608060405234801561000f575f80fd5b506101438061001d5f395ff3fe6080604
05234801561000f575f80fd5b5060043610610034575f3560e01c8063cdfead2e14610038578
063e026c01714610054575b5f80fd5b610052600480360381019061004d91906100ba565b610
072565b005b61005c61007b565b60405161006991906100f4565b60405180910390f35b805f8
190555050565b5f8054905090565b5f80fd5b5f819050919050565b61009981610087565b811
46100a3575f80fd5b50565b5f813590506100b481610090565b92915050565b5f6020828
40312156100cf576100ce610083565b5b5f6100dc848285016100a6565b91505092915050565
b6100ee81610087565b82525050565b5f6020820190506101075f8301846100e5565b9291505
056fea2646970667358fe122012f50afefe691cc3b59e8d775a15c7d265a7e7efbeb04e32fe5
4fefe35f1fefe64736f6c63430008140033
*/

// Opcodes

// 1. Contract Creation Code. 
PUSH1 0x80   // [0x80]
PUSH1 0x40   // [0x40]
MSTORE       // []  0x40 -> 0x80

// What's this chunk do?
CALLVALUE    // [msg.value]
DUP1         // [msg.value, msg.value]
ISZERO       // [msg.value == 0, msg.value]
PUSH2 0x000f // [0x000f, msg.value == 0, msg.value]
JUMPI        // [msg.value]
PUSH0        // [0x00, msg.value]
DUP1         // [0x00, 0x00, msg.value]
REVERT       // [msg.value]

// Jump here if msg.value is zero
JUMPDEST   // [msg.value]
POP        // []
PUSH2 0x0143 // [0x0143]
DUP1       // [0x0143, 0x0143]
PUSH2 0x001d // [0x001d, 0x0143, 0x0143]
PUSH0      // [0x00, 0x001d, 0x0143, 0x0143]
CODECOPY   // [0x0143]             Memory:[runtime code]
PUSH0      // [0x00, 0x0143]
RETURN     // []
INVALID    // []

// 2. Runtime Code.
PUSH1 0x80   // [0x80]
PUSH1 0x40   // [0x40]
MSTORE       // []  0x40 -> 0x80
CALLVALUE    // [msg.value]
DUP1         // [msg.value, msg.value]
ISZERO       // [msg.value == 0, msg.value]
PUSH2 0x000f // [0x000f, msg.value == 0, msg.value]
JUMPI        // [msg.value]
PUSH0        // [0x00, msg.value]
DUP1         // [0x00, 0x00, msg.value]
REVERT       // [msg.value]

// Jump here if msg.value is zero
// This is checking if the calldata is big enough for a function selector.
JUMPDEST   // [msg.value]
POP        // []
PUSH1 0x04  // [0x04]
CALLDATASIZE // [callData.length, 0x04]
LT           // [callData.length < 0x04]
PUSH2 0x0034 // [0x0034, callData.length < 0x04]
JUMPI        // [callData.length]


PUSH0        // [0x00]
CALLDATALOAD // [bytes32 of callData]
PUSH1 0xe0   // [0xe0, bytes32 of callData]
SHR          // [bytes32 of callData[0:4]]
DUP1         // [bytes32 of callData[0:4], bytes32 of callData[0:4]]
PUSH4 0xcdfead2e // [0xcdfead2e, bytes32 of callData[0:4], bytes32 of callData[0:4]]
EQ           // [bytes32 of callData[0:4] == 0xcdfead2e, bytes32 of callData[0:4]]
PUSH2 0x0038 // [0x0038, bytes32 of callData[0:4] == 0xcdfead2e, bytes32 of callData[0:4]]
JUMPI        // [bytes32 of callData[0:4]]
DUP1         // [bytes32 of callData[0:4], bytes32 of callData[0:4]]
PUSH4 0xe026c017 // [0xe026c017, bytes32 of callData[0:4], bytes32 of callData[0:4]]
EQ           // [bytes32 of callData[0:4] == 0xe026c017, bytes32 of callData[0:4]]
PUSH2 0x0054 // [0x0054, bytes32 of callData[0:4] == 0xe026c017, bytes32 of callData[0:4]]
JUMPI        // [bytes32 of callData[0:4]]

// 0x0034 jump destination if the call data is less than function selector size
JUMPDEST
PUSH0
DUP1
REVERT


JUMPDEST
PUSH2 0x0052 // [0x0052, bytes32 of callData[0:4]]
PUSH1 0x04   // [0x04, 0x0052, bytes32 of callData[0:4]]
DUP1         // [0x04, 0x04, 0x0052, bytes32 of callData[0:4]]
CALLDATASIZE // [callData.length, 0x04, 0x0052, bytes32 of callData[0:4]]
SUB
DUP2
ADD
SWAP1
PUSH2 0x004d
SWAP2
SWAP1
PUSH2 0x00ba
JUMP

JUMPDEST
PUSH2 0x0072
JUMP

JUMPDEST
STOP

JUMPDEST
PUSH2 0x005c
PUSH2 0x007b
JUMP

JUMPDEST
PUSH1 0x40
MLOAD
PUSH2 0x0069
SWAP2
SWAP1
PUSH2 0x00f4
JUMP

JUMPDEST
PUSH1 0x40
MLOAD
DUP1
SWAP2
SUB
SWAP1
RETURN

JUMPDEST
DUP1
PUSH0
DUP2
SWAP1
SSTORE
POP
POP
JUMP

JUMPDEST
PUSH0
DUP1
SLOAD
SWAP1
POP
SWAP1
JUMP

JUMPDEST
PUSH0
DUP1
REVERT

JUMPDEST
PUSH0
DUP2
SWAP1
POP
SWAP2
SWAP1
POP
JUMP

JUMPDEST
PUSH2 0x0099
DUP2
PUSH2 0x0087
JUMP

JUMPDEST
DUP2
EQ
PUSH2 0x00a3

JUMPI
PUSH0
DUP1
REVERT

JUMPDEST
POP
JUMP

JUMPDEST
PUSH0
DUP2
CALLDATALOAD
SWAP1
POP
PUSH2 0x00b4
DUP2
PUSH2 0x0090
JUMP

JUMPDEST
SWAP3
SWAP2
POP
POP
JUMP

JUMPDEST
PUSH0
PUSH1 0x20
DUP3
DUP5
SUB
SLT
ISZERO
PUSH2 0x00cf
JUMPI
PUSH2 0x00ce
PUSH2 0x0083
JUMP

JUMPDEST
JUMPDEST
PUSH0
PUSH2 0x00dc
DUP5
DUP3
DUP6
ADD
PUSH2 0x00a6
JUMP
JUMPDEST
SWAP2
POP
POP
SWAP3
SWAP2
POP
POP
JUMP
JUMPDEST
PUSH2 0x00ee
DUP2
PUSH2 0x0087
JUMP
JUMPDEST
DUP3
MSTORE
POP
POP
JUMP
JUMPDEST
PUSH0
PUSH1 0x20
DUP3
ADD
SWAP1
POP
PUSH2 0x0107
PUSH0
DUP4
ADD
DUP5
PUSH2 0x00e5
JUMP
JUMPDEST
SWAP3
SWAP2
POP
POP
JUMP
INVALID
LOG2
PUSH5 0x6970667358
INVALID
SLT
KECCAK256
SLT
CREATE2
EXP
INVALID
INVALID
PUSH10 0x1cc3b59e8d775a15c7d2
PUSH6 0xa7e7efbeb04e
ORIGIN
INVALID
SLOAD
INVALID
INVALID
CALLDATALOAD
CALL
INVALID
INVALID
PUSH5 0x736f6c6343
STOP
ADDMOD
EQ
STOP
CALLER