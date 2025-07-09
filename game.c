#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
void game(int target_number){
    
    int guess;
    int attempt=0;
    
    while (attempt<3){
        printf("Please enter any number : ");
        scanf("%d",&guess);
        if(target_number==guess){
            int score=(3-attempt)*10;
            printf("You have guessed it right\n");
            printf("Your score is : %d\n",score);
            break;
        }
        else if(target_number<guess && attempt<2){
            if((guess-target_number)<=10){
                printf("Your number is greater than the actual number.Try again you are close enough.\n");
            }
            else{
                printf("Please try again later. Your number is greater than the actual number.\n");
            }
        }
        else{
            if((target_number-guess)<=10 && attempt<2){
                 printf("Your number is less than the actual number.Try again you are close enough.\n");
            }
            else if(target_number>guess && attempt<2){
                 printf("Please try again later. Your number is less than the actual number.\n");
            }
        }
        attempt++;
        if(attempt==3 && guess!=target_number){
            printf("All your attempts are over. The correct number was %d\n",target_number);
        }
        
    }
}
int main(){
    int target_number;
    srand(time(NULL));
    target_number=rand()%100+1;
    printf("Welcome to number guessing game!\n");
    printf("You can guess number between 1 and 100\n");
    printf("You have only 3 attempts to guess it correctly.\n");
    
    game(target_number);

    return 0;
}