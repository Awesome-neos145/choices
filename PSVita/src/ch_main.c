// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// includes for playstation vita
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>

#include "debugScreen.h"

// my own includes
#include "ch_def.h"

int main(int argc, char *argv[]) {
    // setup some vars

    // first we need to init the program for vita
    psvDebugScreenInit();

    // 2x font otherwise it looks ugly
    psvDebugScreenSetFont(psvDebugScreenScaleFont2x(psvDebugScreenGetFont()));

    SceCtrlData ctrl_peek, ctrl_press;

    printf("Choices Init...\n");

    printf("\e[H\e[2J");
    printf("Choices for PlayStation Vita\n\n");
    printf("A stupid little excuse for a beginner C game by\nawes145\n\n");
    printf("Triangle: play\n");
    printf("Circle: help\n");
    printf("START: quit\n");
    #ifdef DEBUG
    printf("Square: run the rng\n");
    #endif
    while (1) {
        ctrl_press = ctrl_peek;
        sceCtrlPeekBufferPositive(0, &ctrl_peek, 1);
        ctrl_press.buttons = ctrl_peek.buttons & ~ctrl_press.buttons;

        if (ctrl_press.buttons & SCE_CTRL_TRIANGLE) {
            // start the game
            printf("\e[H\e[2J");
            startgame();
        } else if (ctrl_press.buttons & SCE_CTRL_CIRCLE) {
            printf("\e[H\e[2J");
            printf("Choices is a game about picking the correct\nchoices.\n\n");
            printf("If you make the wrong choice, you will be sent\nback to the beginning.\n\n");
            printf("You will be presented with 3 choices, 20 times.\n\n");
            printf("Each choice is completely randomized each time\nthe game starts.\n\n");
            printf("Version %s\n", VERSION);
            printf("------------------------------------\n");
            printf("Triangle: play\n");
            printf("Circle: help\n");
            printf("START: quit\n");
            #ifdef DEBUG
            printf("Square: run the rng\n");
            #endif
        } 
        #ifdef DEBUG
        else if (ctrl_press.buttons & SCE_CTRL_SQUARE) {
            // just gen the numbers
            printf("\e[H\e[2J");
            srand(time(NULL));
            for (int i = 0; i < 20; i++) {
                printf("%d ", (rand() % 3) + 1);
            }
            printf("\n");
            exit(0);
        } 
        #endif
        else if (ctrl_press.buttons & SCE_CTRL_START) {
            printf("Exiting...\n");
            exit(0);
        } 
        #ifdef FUNNY
        else if (ctrl_press.buttons & SCE_CTRL_SELECT) {
            // experience eardrum implosion moron
            printf("you know what's funny???");
            abort();
        }
        #endif
    }
}