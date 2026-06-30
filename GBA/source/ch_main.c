// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// gba includes
#include <gba.h>

// my own includes
#include "ch_def.h"

unsigned int ticker = 0;

int main() {

    // gba setup
    irqInit();
    irqEnable(IRQ_VBLANK);

    // start console
    consoleDemoInit();

    // clear screen
    iprintf("\x1b[2J");

    // start game
    iprintf("Choices for Game Boy Advance\n\n");
    iprintf("A stupid little excuse for a\nbeginner C game by awes145\n\n");
    iprintf("Button A: play\n");
    iprintf("Button B: help\n");
    #ifdef DEBUG
    iprintf("START: just run the RNG\n");
    #endif
    iprintf("----------------\n\n");
    while (1) {
        VBlankIntrWait();

        int btpress;

        scanKeys();
        btpress = keysDown();
        
        ticker++;
        
        if (btpress & KEY_A) {
            // start the game
            startgame();
        } else if (btpress & KEY_B) {
            iprintf("\x1b[2J");
            iprintf("Choices is a game about\npicking the correct choices.\n\n");
            iprintf("If you make the wrong choice, you will be sent back to the\nbeginning.\n\n");
            iprintf("You will be presented with 3\nchoices, 20 times.\n\n");
            iprintf("Each choice is completely\nrandomized each time the game starts.\n\n");
            iprintf("Version %s\n", VERSION);
            iprintf("----------------\n\n");
            iprintf("Button A: play\n");
            iprintf("Button B: help\n");
        } 
        #ifdef DEBUG
        else if (btpress & KEY_START) {
            iprintf("\x1b[2J");
            srand(ticker);
            for (int i = 0; i < 20; i++) {
                int rng = (rand() % 3) + 1;
                iprintf("%d ", rng);
            }
            iprintf("\n");
            iprintf("----------------\n\n");
            iprintf("Button A: play\n");
            iprintf("Button B: help\n");
            #ifdef DEBUG
            iprintf("START: run RNG\n");
            #endif
        }
        #endif
        #ifdef FUNNY
        else if (btpress & WPAD_BUTTON_MINUS) {
            // experience eardrum implosion moron
            iprintf("you know what's funny???");
            exit(0);
        }
        #endif
    }
}
