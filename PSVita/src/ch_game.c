#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>

#include "ch_def.h"
#include "debugScreen.h"

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
    printf("Press Cross, Circle, or Square:\n");
    SceCtrlData ctrl_peek, ctrl_press;
    sceKernelDelayThread(500);
    while (1) {  // begin loop
        ctrl_press = ctrl_peek;
        sceCtrlPeekBufferPositive(0, &ctrl_peek, 1);
        ctrl_press.buttons = ctrl_peek.buttons & ~ctrl_press.buttons;

        if (ctrl_press.buttons == 0) {
            continue;
        }

        // process the player's choice
        if (ctrl_press.buttons & SCE_CTRL_CROSS) {
            int choice = 1;
            
            if (choice == choices[round]) {
                printf("\e[H\e[2J");
                printf("Correct!\n\n");
                if (round == 19) {
                    printf("You Win!\n\n");
                    sceKernelDelayThread(2000);
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                printf("\e[H\e[2J");
                printf("Wrong!\n\n");
                round = 0;  // restart from round 0
            }
            printf("Round %d\n", round + 1);
            printf("Press Cross, Circle, or Square:\n");
        } else if (ctrl_press.buttons & SCE_CTRL_CIRCLE) {
            int choice = 2;

            if (choice == choices[round]) {
                printf("\e[H\e[2J");
                printf("Correct!\n\n");
                if (round == 19) {
                    printf("You Win!\n\n");
                    sceKernelDelayThread(2000);
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                printf("\e[H\e[2J");
                printf("Wrong!\n\n");
                round = 0;  // restart from round 0
            }
            printf("Round %d\n", round + 1);
            printf("Press Cross, Circle, or Square:\n");
        } else if (ctrl_press.buttons & SCE_CTRL_SQUARE) {
            int choice = 3;

            if (choice == choices[round]) {
                printf("\e[H\e[2J");
                printf("Correct!\n\n");
                if (round == 19) {
                    printf("You Win!\n\n");
                    sceKernelDelayThread(2000);
                    exit(0);
                }
                round++;  // move to the next round
            } else {
                printf("\e[H\e[2J");
                printf("Wrong!\n\n");
                round = 0;  // restart from round 0
            }
            printf("Round %d\n", round + 1);
            printf("Press Cross, Circle, or Square:\n");
        } else if (ctrl_press.buttons & SCE_CTRL_START) {
            printf("Exiting...\n");
            exit(0);
        } else if (ctrl_press.buttons != 0) {
            printf("\e[H\e[2J");
            printf("Not an option.\n");
            printf("Press Cross, Circle, or Square:\n");
        }
    }
}

