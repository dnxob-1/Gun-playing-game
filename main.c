#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#ifdef _WIN32
#include <conio.h>
#define CLEAR_SCREEN system("cls")
#else
#define CLEAR_SCREEN system("clear")
#endif
#include <unistd.h>

// Gun playing game

//this func is for bullet count to return the bullet count and display how many monsters were killed.
int waveBETA(int monsters, int bullets) {
    for (int i = 0; i < monsters; i++) {
        bullets -= 1;
    }

    if (bullets == 0) {
            printf("%d bullets left. You lose!\nYou have defeated %d monsters.\n", bullets, monsters);
    }else {
            printf("%d bullets left after facing %d monsters.\n", bullets, monsters);
    }
        return bullets;
}
//this func is for the reload feature. kinda self explanatory.
int acceptingTheTerms(int coins, char accept, int *bullets, int player, int exitSeconds){
    if(accept == 'Y' || accept == 'y'){
        coins = coins - 10;
        *bullets = 20;
        if (player == 2){
            *bullets = 40;
        }
        printf("\nCoins: %d\n", coins);
        printf("Bullets: %d\n\n", *bullets);
    }else if (accept == 'N' || accept == 'n'){
        printf("\nCoins: %d\n", coins);
        printf("Bullets: %d\n\n", *bullets);
    }else{
        SetColor(4);
        printf("Please input a character (Y/N)\n");
        SetColor(7);
        for(int i = 3; i >= exitSeconds; i--){
            sleep(1);
            printf("                                                                          Program exiting in: %d\n", i);
        }
        exit(EXIT_FAILURE);
    }
        return coins;
}
//a visual feature to make it so it seems that something is booting/ loading.
void delayTime(){
    CLEAR_SCREEN;
    sleep(1);
    printf(".");
    sleep(1.2);
    CLEAR_SCREEN;
    printf("..");
    sleep(1.2);
    CLEAR_SCREEN;
    printf("...");
    sleep(1.5);
    CLEAR_SCREEN;
}
//gives me colors :)
void SetColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
//sets the screen to full if you run this on code::blocks or compile through cmds for windows.
void SetFullScreen() {
    keybd_event(VK_MENU, 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x36, KEYEVENTF_KEYUP, 0);
}

//some of these things will not work on unix-systems.

int main(void) {

    SetFullScreen();
    srand(time(NULL));

    //my variables
    int guns;
    int bullets;
    int monsters;
    //int monsterTypeZomebieATK = 5;
    //int monsterTypeZomebieHP = 100;
    //int monsterTypeGhostATK = 10;
    //int monsterTypeGhostHP = 150;
    //int monsterTypeBrutusATK = 15;
    //int monsterTypeBrutusHP = 250;
    //int BOSSRoboRabbitATK = 25;
    //int BOSSRoboRabbitHP = 500;
    //int zombie;
    //int ghost;
    //int brutus;
    int player;
    //int playerHP = 100;
    //int playerATK = 10;
    int coins;
    char proceed;
    int exitSeconds = 0;
    //int playerChoice[] = {0, 1, 2};

    //getting the player count and deciding somethings.
    printf("Number of players (1-2): " );
    scanf(" %d", &player);

    if (player == 1) {
        guns = 1;
        bullets = 20;
    } else if (player == 2) {
        guns = 2;
        bullets = 40;
    } else {
        SetColor(4);
        printf("Invalid number of players.\n");
        SetColor(7);
        printf("Please pick a player number between 1 and 2 and try again.\n");
        return 1;
    }

    delayTime();

    if (player == 2){
        printf("Players: %d, Bullets: %d, Guns: %d\n\n\n", player, bullets, guns);
    }else{
        printf("%d Player, Bullets: %d, %d Gun\n\n\n", player, bullets, guns);
    }
    //waveBETA starts
    monsters = rand() % 20 + 1;

    if(player == 2){
        monsters = rand() % 40 + 1;
    }

    bullets = waveBETA(monsters, bullets);
    coins = runWaveBETA(monsters, coins , player, bullets);

    if(bullets == 0){
        exit(EXIT_FAILURE);
    }
    //ends

    //reload feature
    char accept;

    printf("Do you wish to spend 10 coins to reload? Y/N.\n\n");
    printf("Player: ");
    scanf(" %c", &accept);

    coins = acceptingTheTerms(coins, accept, &bullets, player, exitSeconds);
    //the rest is basic
    printf("Starting from this point onwards the player(s) will receive ATK and HP that will start at a base stats of 10 ATK and 100 HP per player.\n\n");
    printf("If you understand the terms and wish to proceed, press any key to continue, else close out of the complier.\n");
    _getch();


    printf("\n\nThis concludes the BETA version.\nOnwards Shall ye fight, for glory, fear naught.\n");
    sleep(3);
    delayTime();

    if(player == 2){
        printf("Welcome, Player 1 and 2.\n\nCurrently, in total, you both have %d bullets, %d guns, and %d coins.\nSo far, you both have defeated %d monsters.\n\nShe was not expecting this...\n\nNonetheless, things will change now, so be prepared.\n\n\n", bullets, guns, coins, monsters);
        sleep(3);
        printf("Welcome here.\n");
    }else{
        printf("Welcome, Player.\n\nCurrently, in total, you have %d bullets, %d gun, and %d coins.\nSo far, you have defeated %d monsters.\n\nShe was not expecting this...\n\nNonetheless, things will change now, so be prepared.\n\n\n", bullets, guns, coins, monsters);
        sleep(3);
        printf("Welcome here.\n");
    }

    sleep(5);
    CLEAR_SCREEN;

    //calls/logic for the wave1 func
    /*
    zombie = 6;
    ghost = 4;
    brutus = 2;

    if(playerChoice == playerChoice[0]){
        waveIchi(monsterTypeZomebieATK, monsterTypeZomebieHP, zombie, player, bullets, playerHP, playerATK);
    }*/

    return 0;
}
