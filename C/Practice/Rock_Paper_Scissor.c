#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char arr[3][10] = {"Rock","Paper","Scissor"};
    int r = rand()%3;
    char player_choice[7];
    printf("Enter Rock/Paper/Scissor: \n");
    scanf("%s",player_choice);
    printf("You chose %s\n",player_choice);

    char bot_choice[10];
    strcpy(bot_choice,arr[r]);
    printf("Bot chose %s\n",bot_choice);
    if ((strcmp(player_choice, "Rock") == 0 && strcmp(bot_choice, "Rock") ==0))
    {
        printf("It's a draw");
    }
    if ((strcmp(player_choice, "Rock") == 0 && strcmp(bot_choice, "Paper") ==0))
    {
        printf("You lose");
    }
    if ((strcmp(player_choice, "Rock") == 0 && strcmp(bot_choice, "Scissor") ==0))
    {
        printf("You win");
    }

}