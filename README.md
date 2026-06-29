# Choices
Choices is a game about picking the correct numbers.
This is one of my first C++ projects I've ever made myself. (AMP doesn't count, it's a source code modification)
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
# Compiling for Wii
You will need to follow the setup process for devkitPro to get it working correctly. After everything necessary is installed, run `setup.sh` in the Wii folder. Then run the included `build.sh` file.
# License
This project is licensed under the GNU GPL v3.0 license.
# Are there any prebuilt binaries?
Head over to the releases tab to grab the binaries.
# Credits
tredI9100 created the icon for Choices. He also suggested the name for DOS Choices.
I coded this.