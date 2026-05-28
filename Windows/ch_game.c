#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ch_def.h"

int choices[20];

void startgame(void) {
    makechoices();
    startgameRound(0);
}

void makechoices(void) {
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        choices[i] = (rand() % 3) + 1; // generates a random number 1-3
    }
}

void startgameRound(int round) {
    printf("Pick 1, 2, or 3: ");
    
    // get the player's choice
    char playerchoice[100];
    fgets(playerchoice, sizeof(playerchoice), stdin);
    playerchoice[strcspn(playerchoice, "\n")] = 0; // get rid of the dumbass newline
    
    // process the player's choice
    if (strcmp(playerchoice, "1") == 0 || strcmp(playerchoice, "2") == 0 || strcmp(playerchoice, "3") == 0) {
        int choice = atoi(playerchoice);
        
        if (choice == choices[round]) {
            printf("Correct!\n");
            if (round == 19) {
                printf("You Win!\n");
                exit(0);
            }
            startgameRound(round + 1); // move to the next round
            // check if player wins

        } else {
            printf("Wrong!\n");
            startgameRound(0); // restart from round 0
        }
    } else {
        printf("Not an option.\n");
        startgameRound(round); // stay on current round
    }
}

