#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#define MIN_GUESS 1
#define MAX_GUESS 10
#define LEGENDARY 1
#define GREAT MAX_GUESS*0.3
#define GOOD MAX_GUESS*0.5
#define POOR MAX_GUESS*0.7
#define CURRENT_VERSION "1.0.0"
typedef float real;
int main(void)
{
    int8_t playAgain, title [] = {"Number Guesser Game"};
    int16_t guess, tries, number, round=0;
    real sumGuess=0;    
    do {
        ++round;
        system("clear");
        printf("%s\nRound: %d\n\n",title,round);
        printf("Guess a number between %d and %d\n",MIN_GUESS,MAX_GUESS);
        srand(time(NULL));
        number = rand() % MAX_GUESS + 1;
        tries = 0;
        do {
            do {
                printf("%d. guess: ",tries+1);
                scanf("%hd", &guess);
            } while (guess < MIN_GUESS | guess > MAX_GUESS);
            ++tries;
            ++sumGuess;            
            number == guess ? 
                printf("Correct! It is %d!\nNumber of tries: %d\nAverage number of guesses: %.1f\n",number,tries,sumGuess/round) :
                number > guess ?
                    printf("Bigger.\n") :
                    printf("Smaller.\n");
        } while (guess != number);
        do{            
            printf("Do you want to play again? [y/n]: ");
            getchar();
            scanf("%c", &playAgain);
        } while (toupper(playAgain) != 'N' && toupper(playAgain) != 'Y');
    } while (toupper(playAgain) == 'Y');   
    system("clear");
    printf("%s\n\nRounds played: %d\nYour average: %.1f\n\n",title,round,sumGuess/round);
    if(sumGuess/round == LEGENDARY) printf("YOU ARE AMAZING. You can't miss.\n");
    else if(sumGuess/round <= GREAT) printf("Decent game. Well played.\n"); 
    else if(sumGuess/round <= GOOD) printf("Not that bad, nor great either.\n"); 
    else if(sumGuess/round <= POOR) printf("You could have done better, but still managed to guess them all.\n");
    else printf("You better take a long break.\n");
    printf("Thanks for playing!\n\nGame version: %s\n",CURRENT_VERSION);
    return 0;
}