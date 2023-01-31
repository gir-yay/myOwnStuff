#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int random(){
	
	srand(time(NULL));
	int n;
	do{
	 n = rand() % 4 ;
	}while(n==0);
	
		return n;	
}

void emptyBuffer()
	{
 		int c = 0;
		while (c != '\n' && c != EOF)
		{	
			c = getchar();
		}	
 	}

	typedef enum Choice Choice;
	enum Choice{
		SCISORS =1 , STONE =2 , LEAF =3
	};


main(){
	Choice bot; // choice of the bot based on the random number generated
	Choice user ; // choice of the user

	char const* choice[]={"scisors","stone","leaf"}; // helps me have not only the numeric value of an enum
	
	int bot_score=0;
	int user_score=0;
	
	int again; // do u want to play again
			
	int playing =1;  // if again ==0 then playing = 0
	
	
	while(playing)
	{
					printf("\n\n__________________THE GAME HAS STARTED_________________\n\n");
		printf("\nChoose yours:\n");
		printf("\nscisors (1)\tstone (2)\tleaf (3)\n");
		do {
		
			scanf("%d",&user);
			emptyBuffer();
		
	}while(user!=1 && user!=2 && user!=3);
		
		bot = random();
		
	
		printf("\n---------------------------------------------------------\n");

		printf("\nYOU\t\t\tBot\n");
		printf("\n%s\t\t\t%s\n",choice[user-1],choice[bot-1]);
		
	if(user==bot){
		printf("\nBoth of you has chosen the same thing!\n");
	}
	else if((bot == LEAF && user==STONE) || (bot == STONE && user==SCISORS) || (bot == SCISORS && user==LEAF)){
		bot_score++;
		printf("\nYOU HAVE LOST!\n");
	}
	else if(( user == LEAF && bot==STONE) || (user == STONE && bot==SCISORS) || (user == SCISORS && bot==LEAF)){
		user_score++;
		printf("\nYOU HAVE WON!\n");
	}
		printf("\n---------------------------------------------------------\n");
		printf("\nSCORES:\n");
		printf("\nYOU\t\t\tBot\n");
		printf("\n%d\t\t\t%d\n",user_score,bot_score);
		
		
		printf("\n---------------------------------------------------------\n");

	
		do{
			printf("\nDO YOU WANT TO PLAY AGAIN ?       YES[1]  NO[0] \t");
			scanf("%d",&again);
			emptyBuffer();
			
		}while(again!=0 && again!=1);
			if(again==0)
			{
				playing=0;
			}
			
			
		}
		
	
	
	return 0;
}

