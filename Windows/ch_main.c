// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// looks like it's time to backport the changes i made to the GBA version
// literally just QOL features...

// my own includes
#include "ch_def.h"

int main() {

    char starterchoice[100];
    printf("Choices\n");
    printf("A stupid little excuse for a beginner C game by awes145\n");
    #ifndef DEBUG
    printf("Type 'play', 'help', or 'quit': ");
    #else
    printf("Type 'play', 'help', 'rng', or 'quit': ");
    #endif
    while (1) {
        fgets(starterchoice, sizeof(starterchoice), stdin);
        starterchoice[strcspn(starterchoice, "\n")] = 0; // get rid of the dumbass newline
        if (strcmp(starterchoice, "play") == 0) {
            // start the game
            startgame();
        } else if (strcmp(starterchoice, "help") == 0) {
            printf("Choices is a game about picking the correct choices.\n\n");
            printf("If you make the wrong choice, you will be sent back to the beginning.\n\n");
            printf("You will be presented with 3 choices, 20 times.\n\n");
            printf("Each choice is completely randomized each time the game starts.\n\n");
            printf("Version %s\n", VERSION);
            printf("------------------------------------\n");
            #ifndef DEBUG
            printf("Type 'play', 'help', or 'quit': ");
            #else
            printf("Type 'play', 'help', 'rng', or 'quit': ");
            #endif
        } 
        #ifdef DEBUG
        else if (strcmp(starterchoice, "rng") == 0) {
            // just gen the numbers
            srand(time(NULL));
            for (int i = 0; i < 20; i++) {
                printf("%d ", (rand() % 3) + 1);
            }
            printf("\n");
            exit(0);
        } 
        #endif
        else if (strcmp(starterchoice, "quit") == 0) {
            exit(0);
        } else {
        #ifdef FUNNY
            printf("oh fuck you man");
            abort();
        #else
            printf("That wasn't valid.\n");
            #ifndef DEBUG
            printf("Type 'play', 'help', or 'quit': ");
            #else
            printf("Type 'play', 'help', 'rng', or 'quit': ");
            #endif
        #endif
        }
    }
}