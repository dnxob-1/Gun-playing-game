#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>


/*
couldn't find an alternative to make it so I can give back the coins/bullets in the same func to
the player in their respected ints. this was the only way I could assign a return value to the ints.
also, the coins logic is just broken and sometimes it gives coins beyond what is meant to, I didn't
bother fixing it.
*/
int runWaveBETA (int monsters, int coins, int player, int bullets) {
    if (player == 2 && monsters >= 27){
        coins = rand() % 100 + 70;
    }else if(player == 1 && monsters >= 15){
        coins = rand() % 60 + 40;
    }else{
        coins = rand() % 35 + 10;
    }

    if (bullets == 0){
        printf("You got 0 coins for losing");
    }else {
        printf("You also got %d coins.\n\n\n", coins);
    }
    return coins;
}
