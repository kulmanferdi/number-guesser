//import header files
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//pre-compiler definitions
#define LEGENDARY 1
#define GREAT MAX * 0.3
#define GOOD MAX * 0.5
#define POOR MAX * 0.7

//enums for guess range and version control
enum GUESS 
{
    MIN = 1,
    MAX = 10
};
enum VERSION
{
    MAJOR = 1,
    MINOR = 3,
    PATCH = 1
};

//unique tpye definitions
typedef float real;
typedef bool bit;

//function headers
void printResult(real avg);

//main method, entry point
int main(void)
{
    //variable declarations
    uint8_t playAgain, title [] = {"Number Guesser Game"};
    uint16_t guess, tries, number, round = 0;
    real sumGuess = 0, previousSum, result;
    bit notNumber;

    do {
        notNumber = 0;

        start:
            //start of the game
            ++round;
            system("clear");
            printf("%s\nCurrent round: %d\n\n", title, round);
            printf("Guess a number between %d and %d\n", MIN, MAX);
            srand(time(NULL));
            number = rand() % MAX + 1;
            tries = 1;
            do {
                do {
                    printf("%d. guess: ", tries);
                    scanf("%hd", &guess);
                    if (isdigit(guess))
                    {
                        notNumber = 1;                
                        printf("Entered input is not a number. Invalid round.\n");
                        sumGuess = previousSum;
                        uint8_t errorChar;
                        do{            
                            printf("Do you want to start again or end the game [s/e]: ");
                            getchar();
                            scanf("%c", &errorChar);
                            errorChar = toupper(errorChar);
                        } while (errorChar != 'S' && errorChar != 'E');
                        if(errorChar == 'S') goto start;                    
                        if(errorChar == 'E') goto end;
                    }                
                    if(notNumber == 1) break;
                } while (guess < MIN | guess > MAX);            
                ++tries;
                ++sumGuess;       
                number > guess ? printf("Bigger.\n") :
                number < guess ? printf("Smaller.\n") :
                printf("Correct! It is %d!\nNumber of tries: %d\nAverage number of guesses: %.1f\n", number, tries, sumGuess / round);
            } while (guess != number | notNumber == 1);
            do{            
                printf("Do you want to play again? [y/n]: ");
                getchar();
                scanf("%c", &playAgain);
                playAgain = toupper(playAgain);
            } while (playAgain != 'N' && playAgain != 'Y');
            previousSum = sumGuess;
    } while (playAgain == 'Y');
    end:
        //endscreen and result
        result = sumGuess / round;
        system("clear");
        printf("%s\n\nRounds played: %d\nYour average: %.1f\nPerformance rating: ", title, round, result);
        printResult(result);
        printf("\nThanks for playing!\nVersion: %d.%d.%d\n", MAJOR, MINOR, PATCH);
         
    return 0;
}

//function implementation
void printResult(real avg)
{
    if(avg == LEGENDARY) printf("YOU. ARE. GODLIKE.\n");
    else if(avg <= GREAT) printf("Decent game.\n"); 
    else if(avg <= GOOD) printf("This was good.\n");
    else if(avg <= POOR) printf("It was not good at all, not gonna lie.\n");
    else printf("You better take a very long break.\n");
}
