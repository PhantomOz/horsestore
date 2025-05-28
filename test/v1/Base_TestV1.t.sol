// SPDX-License-Identifier: MIT
pragma solidity 0.8.20;

import {Test, console2} from "forge-std/Test.sol";
import {HorseStore} from "../../src/horseStoreV1/HorseStoreV1.sol";
import {IHorseStoreV1} from "../../src/horseStoreV1/IHorseStoreV1.sol";
abstract contract Base_TestV1 is Test {
    IHorseStoreV1 public horseStore;

    function setUp() public virtual {
        horseStore = IHorseStoreV1(address(new HorseStore()));
    }

    function testReadValue() public {
        uint256 initialValue = horseStore.readNumberOfHorses();
        assertEq(initialValue, 0);
    }

    function testUpdateValue() public {
        horseStore.updateHorseNumber(10);
        uint256 updatedValue = horseStore.readNumberOfHorses();
        assertEq(updatedValue, 10);
    }
}
