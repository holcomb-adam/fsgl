# fsgl

### Overview
Welcome to the fsgl! fsgl (From Scratch Graphics Library) is an open-source, lightweight, framework specialized for quick and dirty 2D and 3D graphical application and game programming. fsgl is written in C++ and leverages the standard library when applicable and practical. Currently, fsgl ___only supports Windows 64 bit and Linux environments___ and performs rendering via OpenGL3. There are plans to support other operating systems and graphics APIs.


## Consuming fsgl
### Features
As mentioned before, fsgl tries to utilize the C++ standard library whenever possible. With that being said, fsgl does have a few dependencies that are useful to know and understand before consuming the engine. Not every dependency is essential to know but here are a few key dependencies:
1. [spdlog](https://github.com/gabime/spdlog) - Used for logging information to the console (see: `FSGL_TRACE`, `FSGL_INFO`, `FSGL_WARN`, `FSGL_ERROR`, and `FSGL_CRITICAL`)

__The Standard Library__  
fsgl uses the stardard library and is one of the core philosophies of the framework. So why do we use the standard library? Simple, it's easier. If you are planning on utilizing fsgl, chances are you familiar with the standard library. It wouldn't make much sense to rewrite everything and make users learn a new library. 
