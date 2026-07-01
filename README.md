# Choices
Choices is a game about picking the correct numbers.
This is one of my first C projects I've ever made myself. (AMP doesn't count, it's a source code modification)
# How to play?
The premise of the game is simple:
If you make the wrong choice, you will be sent back to the beginning.
You will be presented with 3 choices 20 times.
Each choice is completely randomized each time the game starts.
# Compiling for Linux
You need a GCC compilation environment to be installed. There shouldn't (?) be any other dependencies other than just that.
Just run `make` in the directory of your downloaded code and it should build a fresh executable for you.
# Compiling for Windows
You need MinGW to compile this one. Either 32 bit or 64 bit works fine. Just install that and it should compile just fine.
# Compiling for DOS
You need Borland C++ 3.1 and a copy of the DOS code. C89 has some differences so the code is a little different. Load up `CHOICES.PRJ` and go to `Compile > Build all`. If done correctly, it should link up and create a working 16-bit executable for you.
# Compiling for Wii/3DS/GBA/NDS
You will need to follow the setup process for devkitPro to get it working correctly. After everything necessary is installed, run `build.sh` in the Wii, 3DS, GBA, or NDS folders.

Because the Wii version of Choices supports MOD music, you can replace the MOD file in `/data` to have your own music play in the background.
# Compiling for iPhoneOS 2.0 - iOS 10.3.4
You must have made and compiled [cctools-port](https://github.com/tpoechtrager/cctools-port) and [apple-libdispatch](https://github.com/tpoechtrager/apple-libdispatch) to compile this game.

You will also need to compile 'modsi3', 'udivsi3', and 'divsi3' for the game to function properly. These can be found in [The LLVM Project](https://github.com/llvm/llvm-project).

Finally, you will need to obtain the iPhoneOS 5.1 SDK. If you need to compile for armv7s, you have to grab the iPhoneOS 7.1 SDK instead.

First, export your LD target:
`export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH`

To build:
`clang -target arm-apple-darwin11 -arch (arch) -isysroot /path/to/iPhoneOS(version).1.sdk/ -miphoneos-version-min=2.0 -c file.c -o file.o`

To link up:
`clang -target arm-apple-darwin11 -arch (arch) -isysroot ~/path/to/iPhoneOS(version).1.sdk file1.o file2.o -o choices`

...where "arch" should be either 'armv6', 'armv7', or 'armv7s', "version" should be either 5 or 7, and replace `file.c`/`file.o` with the files you need to make/link.

# License
This project is licensed under the GNU GPL v3.0 license.
# Are there any prebuilt binaries?
Head over to the releases tab to grab the binaries.
# Credits
tredI9100 created the icon for Choices. He also suggested the name for DOS Choices.
awes145
devkitPro
LLVM
tpoechtrager