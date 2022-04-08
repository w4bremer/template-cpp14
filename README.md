# C++ 14 Blueprint

A pure C++ 14 blueprint with [CMake](https://cmake.org/) build system support. [Poco](https://pocoproject.org/) is used for network connections. The generated code can be enhanced with support for the [Conan](https://conan.io/) package manager.

## Features
The following list presents a set of features which can be individually enabled in the solution file for code generation.

* **api**<br/>
    Create the plain interface data structure files
* **core**<br/>
    Create a core set of files for json serialization and event handling support implemented
* **scaffold**<br/>
    Create a fully featured project with reference implementations, tests and this README. This is only for convenience. It is also possible to just build and link against e.g. the **api** and **core** libraries. And provide a implementation in a completely seperate folder.
* **monitor**<br/>
    Create support libraries for monitoring API traffic
* **olink**<br/>
    Create IPC implementation for [ObjectLink](https://objectlinkprotocol.net/)
* **apigear**<br/>
    Create necessary ApiGear support library for extended features like monitoring, olink IPC - needs to be generated for monitor or olink
* **examples**<br/>
    Create simple examples for "How to use" the generated code
* **conan**<br/>
    Create files for conan package manager