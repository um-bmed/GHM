# GHM
An open-source gyroscopic controller: designed for limited mobility
## Contents

[Overview](#Overview)
- [Interface](#Interface)
- [Pre-Compiled Binaries](#Pre-compiled-binaries)


[Build cpp source](#Build-cpp)
- [windows](#Windows-cpp)
- [linux](#Linux-cpp)


## Overview

### Interface


### Pre-Compiled binaries
Project pre-compiled binaries can be found here: [releases](https://github.com/ChromaticPanic/HeadGamingMouse/releases)

## Build cpp
### Windows cpp
Building the cpp source requires the following:  
OS: Win 10 x64  
Build tools and dependencies:  
- [ARM build tools](#ARM-build-tools)  
- [cmake](#cmake)  
- [mingw](#mingw)  
- [Qt5](#Qt5) 

- [git and github desktop](#github-desktop) *optional*   
- [Command Prompt](####Command-Prompt)  
- [Arduino IDE Setup](#Arduino) *optional*
- [VScode Setup](#VScode) *optional*  
- [Clion Setup](#CLion) *optional*  
 

#### ARM build tools

Install GNU Arm Embedded Toolchain

The GNU Arm Embedded Toolchain contains the Arm GCC compiler that we need to compile C and C++ code for the RP2040. Head to the [GNU Arm Embedded Toolchain download page](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) and download the latest installer for Windows. e.g. gcc-arm-none-eabi-10-2020-q4-major-win32.exe.

Run the installer. Select your preferred folder. Continue with the installation process. When it is complete, select the option to Add path to environment variable. At this point, you should be able to call any of the Arm compiler tools in a new command prompt, such as arm-none-eabi-gcc.exe.

#### github desktop

#### cmake

CMake is a tool that helps you automate the build process of programs. It does not build/compile (like Make does), but rather, it can generate the directory structures and files needed for any build system (Make, Qt Creator, Ninja, etc.). The Raspberry Pi Pico SDK relies on CMake to help create these build files.  

Head to the [download page on CMake’s site](https://cmake.org/download/). Download the version 3.19.8 installer for Windows (cmake-3.19.8-win64-x64.msi).  

Run the installer and accept the user license. On Install Options, select Add CMake to the system PATH for all users.  

Continue the installation process, accepting all the defaults. Note that this will install CMake to C:\Program Files\CMake, which is fine, as it will be used as a system-wide tool (not just for VSARM projects).  

#### mingw

MinGW (short for Minimalist GNU for Windows) is a collection of open-source utilities, such as compilers and linkers, that allow us to build applications for Windows.  

When we build Pico projects, we need to compile the elf2uf2 and pioasm tools from source. These tools run on our computer (not the target RP2040 microcontroller), and we need a native compiler and linker. The original Getting Started guide has us install Build Tools for Visual Studio to get a Windows compiler (cl.exe), linker (link.exe), and make tool (nmake.exe). We’re going to use the open-source GNU suite (e.g. gcc, ld, make) for Windows instead.  

Head to the downloads page on the Mingw-w64 project site, and go to the Mingw-w64 Builds page for Windows: https://www.mingw-w64.org/downloads/#mingw-builds.  

On that page, click Sourceforge to download the installer for Mingw-w64.  

Run the .exe installer, accepting the defaults for Settings. When asked for an Installation folder, select your preferred folder. Let the installer finish. When it’s done, open a Windows Command Prompt and enter the following into the terminal:  

````
echo mingw32-make %* > C:\VSARM\mingw\mingw32\bin\make.bat
````

This creates a wrapper batch file that will call the mingw32-make tool whenever you type make into a Windows terminal. We will update the Windows Path to find all of the tools in mingw32\bin (along with this .bat file) in a later step.  


#### ArduinoCore mbed

Arduino Core and Mbed OS

Arduino is no stranger to Mbed OS. It’s a hugely important platform and operating system in the IoT space. This is due toits support for Cortex-M microcontrollers and its real-time operating system capabilities. So a lot of work was done when Mbed OS was adopted for the Nano 33 BLE and Nano 33 BLE Sense devices. Since all Mbed infrastructure and drivers were in place, we could easily support all new Arduino boards with minimal effort. Including new ones like the Portenta H7 and Nano RP2040 Connect.

This makes the Arduino Core plug-and-play, and an easy choice for getting your devices up and running quickly. We provide two cores; one for our Nano RP2040 Connect board, and one for other RP2040-based boards, including the Raspberry Pi Pico. As the core is based on Mbed OS you can choose between using Arduino or Mbed’s API.

If you’d like to support any other RP2040 board with its custom features you can do so. It requires very little effort by cloning and tweaking the Arduino Mbed Core.
Ready for the Nano RP2040 Connect

All Arduino APIs are standardized, which means they can be used on all boards. If you have a sketch for your Nano 33 BLE, you can now upload it to a Nano RP2040 Connect and run it without making any changes.

In effect this means you can create sketches for the new Arduino board, even if you don’t have your hands on it yet. It also makes project upgrades very easy. Nor does the Arduino Core require a custom bootloader for RP2040 devices, as it uses the ROM-based bootloader from Raspberry Pi.

https://github.com/arduino/ArduinoCore-mbed

````
git clone -b master https://github.com/arduino/ArduinoCore-mbed.git
````



#### Command Prompt
1. open cmd
2. navigate to the project folder
```
Drive:\PathTo\ProjectFolder> cmake CMakeLists.txt -G "MinGW Makefiles" -B build
Drive:\PathTo\ProjectFolder> cmake --build build
```
3. The program is now a compiled exe in the build folder

#### VScode

#### CLion




### Linux cpp
Dependencies
