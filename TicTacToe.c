#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int board[3][3]={0};

void resetBoard();

void printBoard();

void emptyBuffer();

void playerMove();

int random();

void computerMove();

int endOfGame();


char checkWinner();



main(){
int again =0; // do you want to play again

int playing =1 ; // if again == 1 then playing keep == 1

int start =4; // if the player starts first , the bot will start first in the next round

while(playing){
	printf("\n______________TIC TAC TOE______________\n\n");
	resetBoard();
	printBoard();
	
	
	do{
		if (start%2==0){
		
			playerMove();
			start++;
			printBoard();
		}
		else
		{
			computerMove();
			start++;
			printBoard();
		}
		
	}while(!endOfGame() && checkWinner()==0);
	
	
	
	
	if(checkWinner()=='X'){
		printf("\nYOU HAVE WON!\n");
	}
	else if(checkWinner()=='O')
	{
		printf("\nYOU HAVE LOST!\n");
	}
	else{
		printf("\nIT IS A TIE!\n");
	}
	
	printf("\n\nDO YOU WANT TO PLAY AGAIN? [Y/N]: \t");	
	scanf("%c",&again);
	emptyBuffer();
	
	if(toupper(again)=='N')
	{
		playing = 0 ;
		printf("\nTHANKS FOR PLAYING ,IT WAS FUN!\n");
		
	}
	
}


	return 0;
}

void resetBoard(){
	int i,j;
	for (i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j]=0;
		}
	}
	
}

void printBoard(){
		int i,j;
		printf("\n    1\t  2\t3\n");
		printf("  ------------------\n");
	for (i=0;i<3;i++){
		
		printf("%d ",i+1);
		
		for(j=0;j<3;j++){
			printf("|");
			printf("  %c  ",board[i][j]);
		}
		
		printf("|");

		printf("\n  ------------------\n");
	}
	
}

int endOfGame(){
		int i,j;
	for (i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==0){
				return 0; // not the end of game yet
			}
		}
	}
	return 1;  //  end of game
}

void playerMove()
{	int row , column ;
	do{	
		printf("\nCHOOSE AN EMPTY CASE:\n");
		printf("\nROW NUMBER:\t");
		scanf("%d",&row);
		emptyBuffer();
		
		printf("\nCOLUMN NUMBER:\t");
		scanf("%d",&column);
		emptyBuffer();
		
	}while(board[row-1][column-1]!=0); // till it is an empty case
		
		board[row-1][column-1]='X';

	
}

int random()
	{
		srand(time(NULL));
		return rand() % 3 ;	
	}

void computerMove()
{	int row , column ;
	do{
		row=random();
		column=random();
		
	}while(board[row][column]!=0); // till it is an empty case
	
	board[row][column]='O';
}



char checkWinner(){
	int i;
	
	// check horizontally
	for(i=0;i<3;i++){
		if(board[i][0]==board[i][1] && board[i][2]==board[i][1]){
			return board[i][1];
		}
	}
	
	// check vertically
	for(i=0;i<3;i++){
		if(board[0][i]==board[1][i] && board[2][i]==board[1][i]){
			return board[1][i]; // return 'X' or 'O'
		}
	}
	
	// check diagonals
	if(board[0][0]==board[1][1]&&board[2][2]==board[1][1]){
		return board[1][1];
	}else if(board[0][2]==board[1][1]&&board[2][0]==board[1][1])
	{
		return board[1][1];  // return 'X' or 'O'
	}
	
	return 0; // it is a tie
		
	}
	



void emptyBuffer()
	{
 		int c = 0;
		while (c != '\n' && c != EOF)
		{	
			c = getchar();
		}	
 	}

















