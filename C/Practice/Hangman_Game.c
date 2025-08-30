#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void replace_char(char *string, char replace, char new);
void masking_word(char *string);
bool is_exist(char *string, char find);

int main(){
    char secret_word[] = "banana";
    char masked_word[20];
    char guessed_words[10];
    int lives = 3;

    strcpy(masked_word,secret_word);
    masking_word(masked_word);
    
    int i_guessed_word = 0;
    while (lives >0 && strcmp(masked_word,secret_word)!=0)
    {   

        printf("Current word: %s\n",masked_word);
        printf("Lives: %d\n",lives);

        char word;
        printf("Please enter a character to guess: ");
        scanf(" %c", &word);
        if (is_exist(guessed_words,word))
        {
            printf("You have already guessed the letter %c\n",word);
        }
        else{
            guessed_words[i_guessed_word]=word;
            i_guessed_word++;
            if (is_exist(secret_word,word))
            {
                reveal_word(secret_word,masked_word,word);
            }
            else{
                lives = lives -1;
            }
                      
        }
          
    }
    printf("Current word: %s\n",masked_word);
    return 0;
}

void replace_char(char *string , char replace, char new){
    int slen = strlen(string);
    for (int i =0; i< slen ;i++){
        if (string[i] == replace){
            string[i] = new;
        }
    }
}
void masking_word(char *string){
    int slen = strlen(string);
    for (int i =0; i< slen ;i++){
            string[i]='_';
        }
    }

bool is_exist(char *string, char find){
    int slen = strlen(string);
    for (int i =0; i< slen ;i++){
        if (string[i] == find){
            return true;
        }
    }
    return false;
}

void reveal_word(char *secret_word ,char *masked_word, char found){
    int slen = strlen(secret_word);
    int count = 0;
    for (int i =0; i< slen ;i++){
        if (secret_word[i] == found){
            masked_word[i] = found;
            count++;
        }
    }
    printf("There are %d letters\n",count);
}





