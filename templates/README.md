# C++ 14 Blueprint

A pure C++ 14 blueprint with [CMake](https://cmake.org/) build system support. [Poco](https://pocoproject.org/) is used for network connections. The generated code can be enhanced with support for the [Conan](https://conan.io/) package manager.

## Features
The following list presents a set of features which can be individually enabled in the solution file for code generation.

* **api**<br/>
    Create the plain interface data structure files
* **stubs**<br/>
    Provides a basic example implementation, without business logic in operations.
* **scaffold**<br/>
    Adds a structure to project. Adds cmake files for the api and stubs, sets up tests with catch2.
* **monitor**<br/>
    Create support libraries for monitoring API traffic
* **olink**<br/>
    Create IPC [ObjectLink](https://objectlinkprotocol.net/) adapters for your interface classes.
* **examples**<br/>
    Create simple examples for "How to use" the generated code for stubs
* **example-olink**<br/>
    Creates simple example for "How to use" the generated code with olink
* **conan**<br/>
    Create files for conan package manager

* **core**<br/>
    Create a core set of files common for few features. Generated anytime one of features is enabled: stubs, monitor, olink.
* **apigear**<br/>
    Create necessary ApiGear support library for extended features like monitoring, olink IPC - needs to be generated for monitor or olink

## Folder structure
The following gives a simplified overview of the generated code structure with `all` features enabled.

In general, the files in the `modules/modulename1/generated/..` are completely auto generated and should not be modified manually.
If changes to these files are necessary those should be applied in the technology template.

The files in the `modules/modulename1/implementation/..` are meant to be a starting point for the implementation of real business logic for the interface. Those files will not be automatically overwritten by the generators **scaffold** feature unless `force: true` is specified in the solution file.

It is recommended to have at least manually modified files, like the `implementation` folder, under source code version control. This can also be helpful to spot differences in the auto generated code, e.g. after API changes or a new version of the template, generator.

```
outputfolder
|   README.md
|   CMakeLists.txt
│   test_conan.sh
│   test_conan.bat
│
└───apigear
│   │   ...
│
└───examples
│   │   ...
│   
└───modules
    └───modulename1_module
        └─── conanfile.py
        └─── test_package
		└─── modulename1
				|  CMakeLists.txt
				|   modulename.cmake.in
				└───generated
				|   └───api
				|   |    | ...
				|   |
				|   └───core
				|   |    | ...
				|   |
				|   └───monitor
				|   |    | ...
				|   |
				|   └───olink
				|        | ...
				└───implementation
```
## Build

The template supports two build methods. Depending on your environment you can choose between a [pure CMake](#CMake-pure) approach and additional one with [Conan support](#Conan-support).

### CMake pure

If you want to manage and install dependencies manually into the environment, the plain CMakeLists.txt approach will just work fine. 
[Documentation for CMake](https://cmake.org/)

#### Ubuntu 20.04 Setup

1. Install needed packages

    ```
    $ sudo apt install gcc-10 g++-10 git cmake libpoco-dev
    ```
2. Set gcc-10 with C++14 support as default compiler
   
    ```
    $ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 10 --slave /usr/bin/g++ g++ /usr/bin/g++-10
    $ sudo update-alternatives --config gcc
    ```

3. Ubuntu 20.04 does not provide a newer nlohmann::json version within the packages sources. Therefore it has to be manually downloaded and installed.

    ```
    $ git clone --branch v3.9.1 --depth 1 https://github.com/nlohmann/json.git
    $ cd json
    $ cmake -Bbuild -H. -DBUILD_TESTING=OFF
    $ sudo cmake --build build/ --target install
    ```

4. Ubuntu 20.04 does not provide Catch2 within the packages sources. Therefore it has to be manually downloaded and installed.

    ```
    $ git clone --branch v2.13.8 --depth 1 https://github.com/catchorg/Catch2.git
    $ cd Catch2
    $ cmake -Bbuild -H. -DBUILD_TESTING=OFF
    $ sudo cmake --build build/ --target install
    ```

5. Build the generated code

    ```
    $ cmake -Bbuild -H.
    $ sudo cmake --build build/ --target install
    ```


#### Minimum Poco build

In case you want to build a minimum poco version. You need to install the necessary dependencies like described [here](https://github.com/pocoproject/poco#prerequisites) and then do a minimal configuration.

```
$ mkdir cmake-build && cd cmake-build
$ cmake -DENABLE_ACTIVERECORD=OFF -DENABLE_ACTIVERECORD_COMPILER=OFF -DENABLE_APACHECONNECTOR=OFF -DENABLE_CPPPARSER=OFF -DENABLE_CRYPTO=ON -DENABLE_DATA=OFF -DENABLE_DATA_MYSQL=OFF -DENABLE_DATA_ODBC=OFF -DENABLE_DATA_POSTGRESQL=OFF -DENABLE_DATA_SQLITE=OFF -DENABLE_ENCODINGS=OFF -DENABLE_ENCODINGS_COMPILER=OFF -DENABLE_FOUNDATION=ON -DENABLE_JSON=OFF -DENABLE_JWT=OFF -DENABLE_MONGODB=OFF -DENABLE_NET=ON -DENABLE_NETSSL=ON -DENABLE_PAGECOMPILER=OFF -DENABLE_PAGECOMPILER_FILE2PAGE=OFF -DENABLE_PDF=OFF -DENABLE_POCODOC=OFF -DENABLE_REDIS=OFF -DENABLE_SEVENZIP=OFF -DENABLE_TESTS=OFF -DENABLE_UTIL=ON -DENABLE_XML=OFF -DENABLE_ZIP=OFF ..
$ make -j
```

### Conan support

For ease of use and package distribution we generate all files necessary files to use the Conan package manager.
[Documentation for Conan](https://conan.io/)
1. Set your conan profile to use C++11 and newer. The default configuration is usually at `.conan/profiles/default`. More details on the conan profile can be found [here](https://docs.conan.io/en/latest/reference/profiles.html).
   This can be set like:

    ```
    compiler.libcxx=libstdc++11
    ```
2. Execute the test script depending on the host platform. This will build all dependencies and module files, including examples.
   * Or on **Linux, Mac** execute the shell script `test_conan.sh`.

        ```
        $ bash test_conan.sh
        ```
    * On **Windows** execute the batch script `test_conan.bat`. 

        ```
        >test_conan.bat
        ```

## Run
Once the build was successful you can easily launch one of the examples applications.

### CMake
- Execute one of the examples

    ```
    $ ./build/examples/olinkserver/OLinkServer
    ```
### Conan

* On **Linux, Mac** follow these steps
  1. Source the conan [virtual environment](https://docs.conan.io/en/latest/mastering/virtualenv.html) with all built dependency libraries.

        ```
        $ source ./build/examples/olinkserver/activate.sh
        (conanenv)
        ```
  2. Execute one of the examples

        ```
        $ ./build/examples/olinkserver/OLinkServer.exe
        [info   ] RemoteRegistry.addObjectSource: modulename.Interfacename
        wss.listen() on 8000
        Enter command:
        ```
* On **Windows** follow these steps
  1. Source the conan [virtual environment](https://docs.conan.io/en/latest/mastering/virtualenv.html) with all built dependency libraries.

        ```
        >build\examples\olinkserver\activate.bat
        (conanenv)
        ```
  2. Execute one of the examples

        ```
        >build\examples\olinkserver\Debug\OLinkServer.exe
        [info   ] RemoteRegistry.addObjectSource: modulename.Interfacename
        wss.listen() on 8000
        Enter command:
        ```





