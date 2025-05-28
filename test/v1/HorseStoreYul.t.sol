// SPDX-License-Identifier: MIT
pragma solidity 0.8.20;

import {Base_TestV1, IHorseStoreV1} from "./Base_TestV1.t.sol";
import {HorseStoreYul} from "../../src/horseStoreV1/HorseStoreV1Yul.sol";

contract HorseStoreYulTest is Base_TestV1 {
    function setUp() public override {
        horseStore = IHorseStoreV1(address(new HorseStoreYul()));
    }
}
