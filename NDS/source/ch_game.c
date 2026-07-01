#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nds.h>

#include "ch_def.h"

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
    printf("Round %d\n", round + 1);
    printf("Press Y, B, or A:\n");
    
    while (1) {  // begin loop
        swiWaitForVBlank();

        
        // get the player's choice
        scanKeys();
        int btpress;
        btpress = keysDown();
        
        if (btpress == 0) {
            continue;
        }

        // process the player's choice
        if (btpress & KEY_Y) {
            int choice = 1;
            
            if (choice == choices[round]) {
                printf("\x1b[2J");
                printf("Correct!\n\n");
                if (round == 19) {
                    printf("You Win!\n\n");
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                printf("\x1b[2J");
                printf("Wrong!\n\n");
                round = 0;  // restart from round 0
            }
            printf("Round %d\n", round + 1);
            printf("Press Y, B, or A:\n");
        } else if (btpress & KEY_B) {
            int choice = 2;

            if (choice == choices[round]) {
                printf("\x1b[2J");
                printf("Correct!\n\n");
                if (round == 19) {
                    printf("You Win!\n\n");
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                printf("\x1b[2J");
                printf("Wrong!\n\n");
                round = 0;  // restart from round 0
            }
            printf("Round %d\n", round + 1);
            printf("Press Y, B, or A:\n");
        } else if (btpress & KEY_A) {
            int choice = 3;

            if (choice == choices[round]) {
                printf("\x1b[2J");
                printf("Correct!\n\n");
                if (round == 19) {
                    printf("You Win!\n\n");
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                printf("\x1b[2J");
                printf("Wrong!\n\n");
                round = 0;  // restart from round 0
            }
            printf("Round %d\n", round + 1);
            printf("Press Y, B, or A:\n");
        } else if (btpress & KEY_START) {
            printf("Exiting...\n");
            exit(0);
        } else if (btpress != 0) {
            printf("\x1b[2J");
            printf("Not an option.\n");
            printf("Press Y, B, or A:\n");
        }
    }
}

