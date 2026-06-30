// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// includes for nintendo 3ds
#include <3ds.h>

// my own includes
#include "ch_def.h"

int main() {
    // first we need to init the program for 3ds
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    printf("Choices Init...\n");

    printf("\x1b[2J");
    printf("Choices for Nintendo 3DS\n");
    printf("A stupid little excuse for a beginner C game by\nawes145\n");
    printf("Button A: play\n");
    printf("Button B: help\n");
    printf("START: quit\n");
    #ifdef DEBUG
    printf("Button X: run the rng\n");
    #endif
    while (1) {
        gspWaitForVBlank();
        gfxSwapBuffers();
        hidScanInput();

        u32 btpress = hidKeysDown();
        if (btpress & KEY_A) {
            // start the game
            printf("\x1b[2J");
            startgame();
        } else if (btpress & KEY_B) {
            printf("\x1b[2J");
            printf("Choices is a game about picking the correct\nchoices.\n\n");
            printf("If you make the wrong choice, you will be sent\nback to the beginning.\n\n");
            printf("You will be presented with 3 choices, 20 times.\n\n");
            printf("Each choice is completely randomized each time\nthe game starts.\n\n");
            printf("Version %s\n", VERSION);
            printf("------------------------------------\n");
            printf("Button A: play\n");
            printf("Button B: help\n");
            printf("START: quit\n");
            #ifdef DEBUG
            printf("Button X: run the rng\n");
            #endif
        } 
        #ifdef DEBUG
        else if (btpress & KEY_X) {
            // just gen the numbers
            printf("\x1b[2J");
            srand(time(NULL));
            for (int i = 0; i < 20; i++) {
                printf("%d ", (rand() % 3) + 1);
            }
            printf("\n");
            exit(0);
        } 
        #endif
        else if (btpress & KEY_START) {
            printf("Exiting...\n");
            exit(0);
        } 
        #ifdef FUNNY
        else if (btpress & KEY_SELECT) {
            // experience eardrum implosion moron
            printf("you know what's funny???");
            abort();
        }
        #endif
    }
}