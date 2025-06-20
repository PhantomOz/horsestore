// SPDX-License-Identifier: MIT
pragma solidity 0.8.20;

import {Base_TestV1, IHorseStoreV1} from "./Base_TestV1.t.sol";
import {HuffDeployer} from "foundry-huff/HuffDeployer.sol";

contract HorseStoreHuff is Base_TestV1 {
    string public constant HOURSE_STORE_CODE = "horseStoreV1/HorseStoreV1";

    function setUp() public override {
        horseStore = IHorseStoreV1(
            HuffDeployer.config().deploy(HOURSE_STORE_CODE)
        );
    }
}
