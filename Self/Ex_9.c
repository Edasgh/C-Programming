#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// gcc Ex_9.c -o Ex_9

/*
Rock,paper,scissors game in c
three choices : 0. Rock ,1. Paper and 2. Scissor
First user chooses any of these choices
and computer chooses randomly (generate a random number between 0 to 2)

Rock vs Paper => Paper wins, //same as paper & rock
Rock vs Scissor => Rock Wins,
Paper vs Scissor => Scissor wins,

The program (game) will run 3 times


 */

void main()
{
    int runTime = 3;
    int userChoice, compChoice;
    int userScore = 0, compScore = 0;

    printf("Hello, welcome to the rock , paper, scissors game\n");
    printf("This game is between you and computer.\n");
    printf("\n");
    printf("\n");

    for (int i = 0; i < runTime; i++)
    {
        printf("You've got three choices :\n press 0 to choose rock , press 1 to choose paper, press 2 to choose scissor\n");

        scanf("%d", &userChoice);
        if (userChoice == 1 || userChoice == 2 || userChoice == 0)
        {

            srand(time(NULL));
            compChoice = round(rand() % 3);

            switch (userChoice)
            {
            case 0:
                printf("You've chosen Rock\n");
                break;

            case 1:
                printf("You've chosen Paper\n");
                break;
            case 2:
                printf("You've chosen Scissor\n");
                break;
            }

            printf("Computer chooses...\n");
            switch (compChoice)
            {
            case 0:
                printf("The Computer has chosen Rock\n");
                break;

            case 1:
                printf("The Computer has chosen Paper\n");
                break;
            case 2:
                printf("The Computer has chosen Scissor\n");
                break;
            }

            if ((userChoice == 0 && compChoice == 2) || (userChoice == 1 && compChoice == 0) || (userChoice == 2 && compChoice == 1))
            {
                printf("You win!\n");
                userScore += 1;
            }
            else if (userChoice == compChoice)
            {
                printf("Match draw!\n");
            }
            else
            {
                printf("Computer wins!\n");
                compScore += 1;
            }

            printf("You : %d  | Computer : %d \n", userScore, compScore);
        }
        else
        {
            printf("Invalid choice!\n");
            printf("Total => \n You : %d  | Computer : %d \n", userScore, compScore);
            return;
        }
    }
}