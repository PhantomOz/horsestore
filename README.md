# HorseStore

A simple smart contract project that demonstrates basic state management in Solidity. The project includes both Solidity and Huff implementations of a horse store contract.

## Project Overview

The HorseStore contract is a basic state management contract that:
- Tracks the number of horses in the store
- Allows updating the horse count
- Provides a view function to read the current horse count

The project includes:
- Solidity implementation (`HorseStoreV1.sol`)
- Huff implementation (`HorseStoreV1.huff`)
- Test suite
- Deployment scripts

## Development

This project uses Foundry for development, testing, and deployment.

### Prerequisites

- [Foundry](https://book.getfoundry.sh/getting-started/installation)

### Build

```shell
$ forge build
$ solc --strict-assembly --optimize --optimize-runs 20000 ./yul/HorseStoreYul.yul --bin
```

### Test

```shell
$ forge test
```

### Format

```shell
$ forge fmt
```

### Gas Snapshots

```shell
$ forge snapshot
```

### Anvil (Local Development)

```shell
$ anvil
```

### Deploy

```shell
$ forge script script/Counter.s.sol:CounterScript --rpc-url <your_rpc_url> --private-key <your_private_key>
```

### Cast

```shell
$ cast <subcommand>
```

### Help

```shell
$ forge --help
$ anvil --help
$ cast --help
```

## Foundry Documentation

For more information about Foundry, visit the [official documentation](https://book.getfoundry.sh/).
