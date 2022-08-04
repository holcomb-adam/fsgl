# RogueLikeEngine

![RLE](/resources/images/RLE-Anvil logo.png?raw=true)

### Overview
Welcome to the Rogue-Like Engine! Rogue-Like Engine, or "RLE" for short, is an open-source, lightweight, 2D and 3D graphics/game engine specialized for indie rogue-like games. RLE is written in C++ and leverages the standard library when applicable and practical. Currently, RLE ___only supports Windows 64 bit___ environments and performs rendering via OpenGL3, however, this is all only temporary.


## Consuming RLE
### Features
As mentioned before, RLE tries to utilize the C++ standard library whenever possible. With that being said, RLE does have a few dependencies that are useful to know and understand before consuming the engine. Not every dependency is essential to know but here are a few:
1. [spdlog](https://github.com/gabime/spdlog) - Used for logging information to the console (see: `RLE_TRACE`, `RLE_INFO`, `RLE_WARN`, `RLE_ERROR`, and `RLE_CRITICAL`)

__The Standard Library__  
RLE uses the stardard library and is the main selling point of the engine. Why do we use the standard library? Simple. It's easier. If you are planning on utilizing RLE, chances are you familiar with the standard library. It wouldn't make much sense to rewrite everything and make users learn a new library.



### Installing
In the releases section, you can find the offcial releases of RLE. Download the .zip and extract it to get started in using RLE. If you wish to clone the repository and build the project yourself, feel free (see: "Contributing to RLE" for cloning the repository).



## Contributing to RLE
### Getting Started
So, you want to contribute to RLE? Well, first things first, you need to clone the repository.
