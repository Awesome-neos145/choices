#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ch_def.h"
#include <gccore.h>

#include <wiiuse/wpad.h>

int choices[20];

void startgame(void) {
    makechoices();
    gameRound(0);
}

void makechoices(void) {
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        choices[i] = (rand() % 3) + 1; // generates a random number 1-3
    }
}

void gameRound(int round) {
    printf("Press A, 1, or 2: \n");

    while (1) {  // begin loop
        VIDEO_WaitVSync();
        
        // get the player's choice
        WPAD_ScanPads();
        u32 btpress = WPAD_ButtonsDown(0);

        if (btpress == 0) {
            continue;
        }

        // process the player's choice
        if (btpress & WPAD_BUTTON_A) {
            int choice = 1;
            
            if (choice == choices[round]) {
                printf("Correct!\n");
                if (round == 19) {
                    printf("You Win!\n");
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                printf("Wrong!\n");
                round = 0;  // restart from round 0
            }
            printf("Press A, 1, or 2: \n");
        } else if (btpress & WPAD_BUTTON_1) {
            int choice = 2;
            
            if (choice == choices[round]) {
                printf("Correct!\n");
                if (round == 19) {
                    printf("You Win!\n");
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                printf("Wrong!\n");
                round = 0;  // restart from round 0
            }
            printf("Press A, 1, or 2: \n");
        } else if (btpress & WPAD_BUTTON_2) {
            int choice = 3;
            
            if (choice == choices[round]) {
                printf("Correct!\n");
                if (round == 19) {
                    printf("You Win!\n");
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                printf("Wrong!\n");
                round = 0;  // restart from round 0
            }
            printf("Press A, 1, or 2: \n");
        } else if (btpress & WPAD_BUTTON_HOME) {
            printf("Exiting...\n");
            exit(0);
        } else if (btpress != 0) {
            printf("Not an option.\n");
            // stay on current round
            printf("Press A, 1, or 2: \n");
        }
    }
}

