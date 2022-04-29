#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void displayBoard(char[]);
void p1sTurn(char[30],char[9]);
void p2sTurn(char[30],char[9]);
void nextMove(char[30],char[30],char[9]);
void checkForWin(bool*,char[9],char[30],char[30]);
void newBoard(char[9]);


int main(void) {
  char ch2 = 'y';
  char ch = 'y';
  int i = 0;
  bool outcome = false;
  bool* playerResult = &outcome;
  char p1[30];
  char p2[30];
  char board[9] = {'0','1','2','3','4','5','6','7','8'};

  printf("Player One, please enter your name: ");
  scanf("%s",p1);
  printf("Player Two, please enter your name: ");
  scanf("%s",p2);


  while (i>-1){
   for(i=0;i<9;i++){
    p1sTurn(p1,board);
    checkForWin(playerResult,board,p1,p2);
    if(outcome==true){
     printf("\nWould you like to play again? (y/n)");
     scanf("%c", &ch);
     outcome= (ch2='y')?true:false;
     if(outcome==true){
       newBoard(board);
       i=0;
       break;
      } else{
        i=-5;
        break;
       }
    }

   p2sTurn(p2,board);
   checkForWin(playerResult,board,p1,p2);
   if(outcome==true)
   {
     printf("\nWould you like to play again? (y/n)");
     scanf("%c",&ch2);
     outcome= (ch2='y')?true:false;
     if(outcome==true)
     {
       newBoard(board);
       i=0;
       break;
     } else
       {
        i=-5;
        break;
       }
     }
   }
  }
 printf("\n Goodbye ");
  return 0;
}


void displayBoard(char board[9]){
  for(int i=0;i<9;i++){
   if(i== 0||i==3 || i==6){
   printf("\n %c | %c | %c \n",board[i],board[i+1],board[i+2]);
   }
   if(i== 2|| i==4){
     printf("-----------");
   }
 }
}

void checkForWin(bool* pBool,char game[],char name1[30],char name2[30]){
  if(game[0]=='X'&& game[3]=='X'&& game[6]=='X'){
     printf("Player One, %s, wins!", name1);
     *pBool=true;
    }
    else if(game[0]=='Y'&& game[3]=='Y'&& game[6]=='Y'){
     printf("Player Two, %s, wins!", name2); 
     *pBool=true;
    }
    else if(game[1]=='X'&& game[4]=='X'&& game[7]=='X'){
      printf("Player One, %s, wins!",name1);
      *pBool=true;
    }
    else if(game[1]=='Y'&& game[4]=='Y'&& game[7]=='Y'){
     printf("Player Two, %s, wins!", name2);
     *pBool=true;
    }
    else if(game[2]=='X'&& game[5]=='X'&& game[8]=='X'){
      printf("Player One, %s, wins!",name1);
      *pBool=true;
    }
    else if(game[2]=='Y'&& game[5]=='Y'&& game[8]=='Y'){
     printf("Player Two, %s, wins!", name2);
     *pBool=true;
    }
    else if(game[0]=='X'&& game[1]=='X'&& game[2]=='X'){
     printf("Player One, %s, wins!",name1);
     *pBool=true;
    }
    else if(game[0]=='Y'&& game[1]=='Y'&& game[2]=='Y'){
     printf("Player Two, %s, wins!", name2);
     *pBool=true;
    }
    else if(game[3]=='X'&& game[4]=='X'&& game[5]=='X'){
     printf("Player One, %s, wins!",name1);
     *pBool=true;
    }
    else if(game[3]=='Y'&& game[4]=='Y'&& game[5]=='Y'){
     printf("Player Two, %s, wins!", name2); 
     *pBool=true;
    }
    else if(game[6]=='X'&& game[7]=='X'&& game[8]=='X'){
      printf("Player One, %s, wins!",name1);
      *pBool=true;
    }
    else if(game[6]=='Y'&& game[7]=='Y'&& game[8]=='Y'){
     printf("Player Two, %s, wins!", name2); 
     *pBool=true;
    }
    else if(game[0]=='X'&& game[4]=='X'&& game[8]=='X'){
      printf("Player One, %s, wins!",name1);
      *pBool=true;
    }
    else if(game[0]=='Y'&& game[4]=='Y'&& game[8]=='Y'){
     printf("Player Two, %s, wins!", name2);
     *pBool=true;
    }
    else if(game[2]=='X'&& game[4]=='X'&& game[6]=='X'){
      printf("Player One, %s, wins!",name1);
      *pBool=true;
    }
    else if(game[2]=='Y'&& game[4]=='Y'&& game[6]=='Y'){
     printf("Player Two, %s, wins!", name2);
     *pBool=true;
    }
    else{
     *pBool=false;
    }
return ;
}

void p1sTurn(char nameOne[30],char game[9]){
  char c;
 int turn;
 displayBoard(game);
  printf("Player One, %s, pick an empty space: ",nameOne);
  scanf("%d", &turn);
  if(turn>8){
    printf("Invalid input, please use an available number from 0 to 8: ");
  }
  while(game[turn]=='X'|| game[turn]=='Y'){
    printf("Error selecting square, please try again: ");
    scanf("%d", &turn);
    if(game[turn]=='X'|| game[turn]=='Y'){
     continue;
    } 
  }
  game[turn]='X';
 
  return;
}

void p2sTurn(char nameTwo[30],char game[9]){
  int turn; 
  char c;
  displayBoard(game);
  printf("Player two, %s, pick an empty space: ",nameTwo);
  scanf("%d", &turn);
  if(turn>8){
    printf("Invalid input, please use an available number from 0 to 8: ");
  }
  while(game[turn]=='X'|| game[turn]=='Y'){
    printf("Error selecting square, please try again: ");
    scanf("%d", &turn);
    if(game[turn]=='X'|| game[turn]=='Y'){
     continue;
    } 
  }
  game[turn]='Y';
  
 return;
}

void newBoard(char game[9]){
 game[0]='0';
 game[1]='1';
 game[2]='2';
 game[3]='3';
 game[4]='4';
 game[5]='5';
 game[6]='6';
 game[7]='7';
 game[8]='8';
  return;
}