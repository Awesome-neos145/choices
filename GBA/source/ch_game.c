#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ch_def.h"
#include <gba.h>

int choices[20];

extern unsigned int ticker;

void startgame(void) {
    makechoices();
    gameRound(0);
}

void makechoices(void) {
    srand(ticker); // seed the (Dr.) RNG with a frame ticker (gba does not have a real-time clock)
    // if i were to make actual cartridges, i'd use a battery to give it time and update my code to that
    // until then, frame ticker it is
    for (int i = 0; i < 20; i++) {
        choices[i] = (rand() % 3) + 1; // generates a random number 1-3
    }
}

void gameRound(int round) {
    // clear screen
    iprintf("\x1b[2J");
    iprintf("Round %d\n", round + 1);
    iprintf("Press Left, Up, or Right: \n");

    while (1) {  // begin loop
        VBlankIntrWait();
        
        // get the player's choice
        int btpress;
        scanKeys();
        btpress = keysDown();

        if (btpress == 0) {
            continue;
        }

        // process the player's choice
        if (btpress & KEY_LEFT) {
            int choice = 1;
            
            if (choice == choices[round]) {
                iprintf("\x1b[2J");
                iprintf("Correct!\n\n");
                if (round == 19) {
                    iprintf("You Win!\n\n");
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                iprintf("\x1b[2J");
                iprintf("Wrong!\n\n");
                round = 0;  // restart from round 0
            }
            iprintf("Round %d\n", round + 1);
            iprintf("Press Left, Up, or Right: \n");
        } else if (btpress & KEY_UP) {
            int choice = 2;
            
            if (choice == choices[round]) {
                iprintf("\x1b[2J");
                iprintf("Correct!\n\n");
                if (round == 19) {
                    iprintf("You Win!\n\n");
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                iprintf("\x1b[2J");
                iprintf("Wrong!\n\n");
                round = 0;  // restart from round 0
            }
            iprintf("Round %d\n", round + 1);
            iprintf("Press Left, Up, or Right: \n");
        } else if (btpress & KEY_RIGHT) {
            int choice = 3;
            
            if (choice == choices[round]) {
                iprintf("\x1b[2J");
                iprintf("Correct!\n\n");
                if (round == 19) {
                    iprintf("You Win!\n\n");
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                iprintf("\x1b[2J");
                iprintf("Wrong!\n\n");
                round = 0;  // restart from round 0
            }
            iprintf("Round %d\n", round + 1);
            iprintf("Press Left, Up, or Right: \n");
        }
    }
}

