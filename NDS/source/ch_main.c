// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// includes for nintendo ds
#include <nds.h>

// my own includes
#include "ch_def.h"

int main() {
    // first we need to init the program for ds

    PrintConsole topScreen;

    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);

    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);

    consoleInit(&topScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);

    consoleSelect(&topScreen);

    iprintf("Choices Init...\n");

    iprintf("\x1b[2J");
    iprintf("Choices for Nintendo DS\n\n");
    iprintf("A stupid little excuse for a\nbeginner C game by awes145\n\n");
    iprintf("Button A: play\n");
    iprintf("Button B: help\n");
    iprintf("START: quit\n");
    #ifdef DEBUG
    iprintf("Button X: run the rng\n");
    #endif
    while (1) {
        swiWaitForVBlank();
        scanKeys();
        u32 btpress = keysDown();
        if (btpress & KEY_A) {
            // start the game
            iprintf("\x1b[2J");
            startgame();
        } else if (btpress & KEY_B) {
            iprintf("\x1b[2J");
            iprintf("Choices is a game about picking the correct choices.\n\n");
            iprintf("If you make the wrong choice, \nyou will be sent back to the\nbeginning.\n\n");
            iprintf("You will be presented with 3\nchoices, 20 times.\n\n");
            iprintf("Each choice is completely\nrandomized each time the game\nstarts.\n\n");
            iprintf("Version %s\n", VERSION);
            iprintf("-----------------------------\n");
            iprintf("Button A: play\n");
            iprintf("Button B: help\n");
            iprintf("START: quit\n");
            #ifdef DEBUG
            iprintf("Button X: run the rng\n");
            #endif
        } 
        #ifdef DEBUG
        else if (btpress & KEY_X) {
            // just gen the numbers
            iprintf("\x1b[2J");
            srand(time(NULL));
            for (int i = 0; i < 20; i++) {
                iprintf("%d ", (rand() % 3) + 1);
            }
            iprintf("\n");
            exit(0);
        } 
        #endif
        else if (btpress & KEY_START) {
            iprintf("Exiting...\n");
            exit(0);
        } 
        #ifdef FUNNY
        else if (btpress & KEY_SELECT) {
            // experience eardrum implosion moron
            iprintf("you know what's funny???");
            abort();
        }
        #endif
    }
}