// SPDX-License-Identifier: MIT
pragma solidity 0.8.20;

import {Base_TestV1} from "./Base_TestV1.t.sol";
import {HuffDeployer} from "foundry-huff/HuffDeployer.sol";
import {HorseStore} from "../../src/horseStoreV1/HorseStoreV1.sol";
contract HorseStoreHuff is Base_TestV1 {
    string public constant HOURSE_STORE_CODE = "horseStoreV1/HorseStoreV1";

    function setUp() public override {
        horseStore = HorseStore(
            HuffDeployer.config().deploy(HOURSE_STORE_CODE)
        );
    }
}
