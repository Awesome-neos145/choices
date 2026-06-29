// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// wii includes
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <aesndlib.h>
#include <gcmodplay.h>
#include <gctypes.h>

#include "music_mod.h"

// my own includes
#include "ch_def.h"

void startgame(void);
void crash_yo_shit(void);

static MODPlay play;

int main(int argc, char **argv) {

    // extra stuff required for the Wii will be placed here
    // start video
    VIDEO_Init();

    // is the console outputting NTSC or PAL?
    GXRModeObj *rmode = VIDEO_GetPreferredMode(NULL);

    // give memory to video
    void *xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

    // setup video
    VIDEO_Configure(rmode);
    VIDEO_SetNextFramebuffer(xfb);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();
    VIDEO_WaitVSync();
    if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();

    // now we begin setting up the console to fully boot the game

    console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);


    // controller setup
    WPAD_Init();

    // audio setup
    AESND_Init();
    MODPlay_Init(&play);
    MODPlay_SetMOD(&play, music_mod);
    MODPlay_SetVolume(&play, 63, 63);
    MODPlay_Start(&play);

    // start game
    printf("Choices\n");
    printf("A stupid little excuse for a beginner C game by awes145\n");
    printf("Button A: play\n");
    printf("Button 1: help\n");
    printf("HOME: quit\n");
    printf("----------------\n");
    printf("For best experience, hold the Wiimote horizontally.\n");
    while (1) {
        VIDEO_WaitVSync();
        WPAD_ScanPads();
        u32 btpress = WPAD_ButtonsDown(0);
        if (btpress & WPAD_BUTTON_A) {
            // start the game
            startgame();
        } else if (btpress & WPAD_BUTTON_1) {
            printf("Choices is a game about picking the correct choices.\n");
            printf("If you make the wrong choice, you will be sent back to the beginning.\n");
            printf("You will be presented with 3 choices, 20 times.\n");
            printf("Each choice is completely randomized each time the game starts.\n");
            printf("Button A: play\n");
            printf("Button 1: help\n");
            printf("HOME: quit\n");
        } else if (btpress & WPAD_BUTTON_HOME) {
            // quit the game
            exit(0);
        } 
        #ifdef FUNNY
        else if (btpress & WPAD_BUTTON_MINUS) {
            // experience eardrum implosion moron
            printf("you know what's funny???");
            crash_yo_shit();
        }
        #endif
    }
}

void crash_yo_shit(void) {
    asm volatile (
        "lis 3, 0\n"
        "mtmsr 3\n"
        "1:\n"
        "b 1b\n"
    );
}