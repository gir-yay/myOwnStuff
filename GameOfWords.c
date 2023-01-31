#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <time.h>


#define MAX_LINE 150
#define MAX 50


void emptyBuffer();

int read(char* string , int length);

long readLong(char* string , int length);

int random(int max);

// counting number of words in a file that contains a word per line
int fnbr_words(FILE* fichier ) ;


// compare two strings
int compare(const char* string1 ,const char* string2,int length);


main(){
		
	FILE* fichier1=NULL ;
	FILE* fichier2=NULL ;	
	fichier1= fopen("Files/list.txt","r");
	if(fichier1==NULL){
		printf("COULD NOT OPEN THE FILE!!\n");
		exit(0);
	}
	fichier2= fopen("Files/list2.txt","r");
	if(fichier2==NULL){
	printf("COULD NOT OPEN THE FILE!!\n");
	exit(0);
	}
	
	int playing =1;
	
	while(playing==1)
	{
		
			// the word we read from the file words.txt
		char word[MAX];
		int length =0; 

			// the definition that we will read from list2.txt for the 4th option of the menu
		char def[MAX_LINE];
		
		int b;		// just for storing	
		int a=0;
		char answer[10];   // select a number from a menu but given to the function a=readLong(answer,10)
		char again[5];		// yes or noin the end b=readLong(again,5)
		
		char guess[MAX];	// the guess of the player that we will compare to the word chosen randomly
		
		
		
		// code needed to generate random words
		int nbr_words =fnbr_words(fichier1);
		int rand =0;
		int rand2 =0;
		int character=0;


		int help =0; // help of option 2,3 and 4 of the menu
		int correct=0; // if the guess match the word correct <-- 1

		printf("\n\n__________________________THE GAME HAS STARTED____________________________________\n\n");
		
		rand = random(nbr_words);
		
		rand2=rand; // we will need this one when we will want to get a def for a word
		
		rewind(fichier1);
		while (rand > 0)
		{
			character = fgetc(fichier1);
			if (character == '\n')
				rand--;
		}
			// put the word that we have read in the variable word
		fgets(word,MAX,fichier1);
		
			// to get rid of '\n' of enter in the file as fgets gets the whole line
		word[strlen(word)-1]='\0';
		length = strlen(word); 
		
			// the word and the menu	
		printf("MY NAME STARTS WITH %c AND ENDS WITH %c\n",word[0],word[length-1]);
		printf("\n\n______________________THE MENU____________________\n\n");
		printf("1- CHOOSE 1 IF YOU WANT TO TYPE THE ANSWER\n");
		printf("2- CHOOSE 2 IF YOU WANT TO KNOW THE SECOND LETTER\n");
		printf("3- CHOOSE 3 IF YOU WANT THE NUMBER OF LETTERS OF THE WORD\n");
		printf("4- CHOOSE 4 IF YOU WANT TO HAVE A DEFINITION OF THE WORD\n");
		
		while(correct==0)
		{
		
			do{
				printf("\nSELECT A NUMBER FROM THE MENU\t");
				a=readLong(answer,10);
			}while(a<=0 || a>5);
		
			if(a==1)
			{
				printf("\n\nTYPE THE WORD\t");
				read(guess,MAX);
				if(compare(guess,word,length)==1 && help==0)
				{	
					correct=1;
					printf("\nCORRECT! YOU DID IT WITH NO HELP\n");
				}
				else if(compare(guess,word,length)==1 && help==1)
				{
					correct=1;
					printf("\nCORRECT!\n");
				}
				else
				{
					printf("\n\t\tWRONG!\n");
				}
				
			}
			else if(a==2)
			{
				printf("\nTHE SECOND LETTER IS %c\n",word[1]);
				help=1;
			}
			else if(a==3)
			{
				printf("\nIT IS A %d LETTERS LONG WORD!\n",length);
				help=1;
			}
			else if(a==4)
			{
				help=1;
				rewind(fichier2);
				while (rand2 > 0)
				{
					character = fgetc(fichier2);
					if (character == '\n')
					rand2--;
				}
				
					// put the word that we have read in the variable word
				fgets(def,MAX_LINE,fichier2);
				printf("\n%s\n",def);	
						
			}
			
		}
	
		do{
			printf("\nDO YOU WANT TO PLAY AGAIN ?       YES[1]  NO[0] \t");
		
			b=readLong(again,5);
		}while(b!=0 && b!=1);
			if(b==0)
			{
				playing=0;
			}
			
	}	
	
				fclose(fichier1);
				fclose(fichier2);
	
	return 0;
	
	
}

	void emptyBuffer()
	{
 		int c = 0;
		while (c != '\n' && c != EOF)
		{	
			c = getchar();
		}	
 	}

	int read(char* string , int length)
	{
 		if( fgets(string , length , stdin) != NULL)
		{
 			if(string[strlen(string)-1]== '\n')
			{
 				string[strlen(string)-1]='\0';
			}
			else
			{
			 		// the string is longer than the space allowed
				emptyBuffer();
			}
			
			return 1;
			 
		}
		else
		{
	 		emptyBuffer();
	 		return 0;
		}
	}
	

	long readLong(char* string , int length)
	{
 		if(read(string , length))
		{
 			return strtol(string,NULL,10);

 		}
		else
		{
 			return 0;
		}
 
 	}

	int random(int max)
	{
		srand(time(NULL));
		return rand() % max ;	
	}


		// counting number of words in a file that contains a word per line
	int fnbr_words(FILE* fichier ) 
	{
		char c =0;
		int counter=0;
		do
		{
			c=fgetc(fichier);
			if(c=='\n')
			{
				counter++;
			}
			
		}while(c != EOF);
		return counter;
		
	}



	int compare(const char* string1 ,const char* string2,int length)
	{
		int i;
		for (i=0;i<length;i++)
		{
			if(toupper(string1[i])!=string2[i])
			{
				return 0;
			}
		}
		return 1;
		
	}



