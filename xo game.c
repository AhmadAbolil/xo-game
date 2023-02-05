#include <stdio.h>

typedef enum {false, true} bool;
void initTheBoard();
void initTheVerifyBoard();
void displayBoard();
bool isEqualGame();
bool verifySelection(int,int);
void checkForWin(char);

//global variables
char board[ 8 ] ,WonPlayer = ' ';
int verifyBoard[ 8 ];
int currentPlayer = 1;

//begin main function
int main() {

    int square;    

    initTheBoard();
    initTheVerifyBoard();

    displayBoard();

    while(WonPlayer == ' ' && isEqualGame() == false) {

       if(currentPlayer == 1) {

          printf("\nPlayer X\n");    
          printf("Enter an available square (1..9)");
          scanf("%d", &square);  

          if(verifySelection(square, currentPlayer))  {
 
             currentPlayer = 2;
   
          }

       } else {

          printf("\nPlayer O\n");
          printf("Enter an available square (1..9)");
          scanf("%d", &square);  
          if(verifySelection(square, currentPlayer))  {
 
             currentPlayer = 1;
   
          }

       }

       displayBoard();
       if (currentPlayer == 1){
           checkForWin('O');
       }else
        checkForWin('X');
       

    }//end for loop

 
   return (0);
};

void initTheBoard() {
    int i;
    for(i = 0; i < 9; i++) board[ i ] = ' ';
};

void initTheVerifyBoard() {
    int i;
    for(i = 0; i < 9; i++) verifyBoard[ i ] = 0;
};

void displayBoard() {
     printf("\t|\t|\n");
     printf("%c\t|%c\t|%c\n", board[0], board[1], board[2]);
     printf("*******|*******|*******\n");
     printf("\t|\t|\n");
     printf("%c\t|%c\t|%c\n", board[3], board[4], board[5]);
     printf("*******|*******|*******\n");
     printf("%c\t|%c\t|%c\n", board[6], board[7], board[8]);
     printf("\t|\t|\n");
};

bool verifySelection(int square, int player) {
    bool valid = false;
     if( board[square-1] == ' ') {
         valid = true;
         if (player == 1)
         {
             board[ square - 1 ] = 'X';
             verifyBoard[ square - 1 ] = 100;
         }
         else{
             board[ square - 1 ] = 'O';
             verifyBoard[ square - 1 ] = -1;
         }
     }
     return valid;  
     
}

// check if current player win (have 8 options to win)
void checkForWin(char playerToCheck) {

     int i,
     contor = 0;
   
     if(board[ 0 ] == playerToCheck &&  board[ 1 ] == playerToCheck && board[ 2 ] == playerToCheck ) {

        WonPlayer = playerToCheck;

     } else if(board[ 3 ] == playerToCheck && board[ 4 ] == playerToCheck && board[ 5 ] == playerToCheck) {

        WonPlayer = playerToCheck;

     } else if(board[ 6 ] == playerToCheck && board[ 7 ] == playerToCheck && board[ 8 ] == playerToCheck) {

        WonPlayer = playerToCheck;

     } else if(board[ 0 ] == playerToCheck && board[ 3 ] == playerToCheck && board[ 6 ] == playerToCheck) {

        WonPlayer = playerToCheck;

     } else if(board[ 1 ] == playerToCheck && board[ 4 ] == playerToCheck && board[ 7 ] == playerToCheck) {

        WonPlayer = playerToCheck;

     } else if(board[ 2 ] == playerToCheck && board[ 5 ] == playerToCheck && board[ 8 ] == playerToCheck) {

        WonPlayer = playerToCheck;

     } else if(board[ 0 ] == playerToCheck && board[ 4 ] == playerToCheck && board[ 8 ] == playerToCheck) {

        WonPlayer = playerToCheck;

     } else if(board[ 2 ] == playerToCheck && board[ 4 ] == playerToCheck && board[ 6 ] == playerToCheck) {

        WonPlayer = playerToCheck;
     }


     


     if(WonPlayer != ' ') {

        printf("\n  *** Player %c WON ***\n", WonPlayer);
        return;
     }
     
}

// check if the game is equal and done by using the verifyBoard
bool isEqualGame(){
   int equalGameOption = 0 ;
   int group1 = verifyBoard[ 0 ] + verifyBoard[ 1 ]  + verifyBoard[ 2 ];
   int group2 = verifyBoard[ 3 ] + verifyBoard[ 4 ]  + verifyBoard[ 5 ];
   int group3 = verifyBoard[ 6 ] + verifyBoard[ 7 ]  + verifyBoard[ 8 ];
   int group4 = verifyBoard[ 0 ] + verifyBoard[ 3 ]  + verifyBoard[ 6 ];
   int group5 = verifyBoard[ 1 ] + verifyBoard[ 4 ]  + verifyBoard[ 7 ];
   int group6 = verifyBoard[ 2 ] + verifyBoard[ 5 ]  + verifyBoard[ 8 ];
   int group7 = verifyBoard[ 0 ] + verifyBoard[ 4 ]  + verifyBoard[ 8 ];
   int group8 = verifyBoard[ 2 ] + verifyBoard[ 4 ]  + verifyBoard[ 6 ];
   if((group1 == 99) || (group1 == 98) ||  (group1 == 199)) {
       equalGameOption = equalGameOption +1;
   }else
        return false;
   if((group2 == 99) || (group2 == 98) ||  (group2 == 199)) {
       equalGameOption = equalGameOption +1;
   }else
        return false;
   if((group3 == 99) || (group3 == 98) ||  (group3 == 199)) {
       equalGameOption = equalGameOption +1;
   }else
        return false;
   if((group4 == 99) || (group4 == 98) ||  (group4 == 199)) {
       equalGameOption = equalGameOption +1;
   }else
        return false;
   if((group5 == 99) || (group5 == 98) ||  (group5 == 199)) {
       equalGameOption = equalGameOption +1;
   }else
        return false;
   if((group6 == 99) || (group6 == 98) ||  (group6 == 199)) {
       equalGameOption = equalGameOption +1;
   }else
        return false;
   if((group7 == 99) || (group7 == 98) ||  (group7 == 199)) {
       equalGameOption = equalGameOption +1;
   }else
        return false;
   if((group8 == 99) || (group8 == 98) ||  (group8 == 199)) {
       equalGameOption = equalGameOption +1;
   }else
        return false;
   if (equalGameOption == 8)
   printf("\nEqual Game !!\n");
        return true;
}