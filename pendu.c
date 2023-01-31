#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 50
#define MAX_ROUND 10



// a way to solve buffer overflow
char read_char(){
	char c=0;
	c=getchar();
	while (getchar() != '\n') ; 
	return c;
		
}


// write a word as stars without assigning stars as a value , l is the word's length
void stars(int l){
	int i;
	printf("\nGUESS THE WORD ");
	for(i=0;i<l;i++){
		printf("*");
	}
	printf("\n\n");
}

// find a character in a word , it returns 1 if the char is found and 0 if not
int find(const char* word ,int c){
	char* find =NULL;
	find = strchr(word ,c);
	if(find != NULL){
		return 1 ;
	}else {
		return 0;
	}
}

// it prints a word , l is the word's length
void print_t(const char* word , int l){
	int i;
	for(i=0;i<l;i++){
		printf("%c",word[i]);
	}
	
}

// assigning stars as a value to a word , l is a word's length
void assign( char* word,int l){
	int i;
	for(i=0;i<l;i++){
		word[i]='*';
	}
}


	// generate a random number < max 
int random(int max){
	
	srand(time(NULL));
	int n;
	 n = rand() % max ;
	
		return n;	
}

	// counting number of words in a file that contains a word per line
int fnbr_words(FILE* fichier ) {
	char c =0;
	int counter=0;
	do{
	c=fgetc(fichier);
	if(c=='\n'){
		counter++;
	}
	}while(c != EOF);
	return counter;
}



main(){
		// if it is 0 , you get out of the game : line 128 and line 131
	int playing ='y'; 
	int length =0; 
		// the character that the user guess
	int choice=0 ; 
		// the number of trials,I didn't give it a value here coz I wanted it to be reset whenever we play again
	int round; 
		// the word we read from the file words.txt
	char word[MAX];
		// the word under revealing
	char revealed[MAX];
	
		// code needed to generate random words
	int nbr_words =0;
	int rand =0;
	int character =0;
	
		// process of opning a file
	FILE* fichier = NULL;
	fichier = fopen("Files/words.txt","r");	
		// if it is opened then...
	if (fichier != NULL)
	{
		nbr_words =	fnbr_words(fichier);
		while(playing=='y')
		{
			printf("\n\n_______THE GAME HAS STARTED________\n\n");
			
			rand = random(nbr_words);
			rewind(fichier);
			while (rand > 0)
			{
				character = fgetc(fichier);
				if (character == '\n')
				rand--;
			}
					// put the word that we have read in the variable word
				fgets(word,MAX,fichier);
		
					// to get rid of '\n' of enter in the file as fgets gets the whole line
				word[strlen(word)-1]='\0';
				length = strlen(word); 
				stars(length);
				assign(revealed , length);
				round = MAX_ROUND;
				
				while(round>0 && find(revealed,'*')==1 )
				{
						/* we can use capitals if we #include<ctype.h> 
							we write our file in capitals
							we add toupper() to read_char() while creation
						*/
					printf("SELECT A LETTER [NO CAPITALS]\t"); 
					choice = read_char();
					printf("\n");
			
					int found=0;
					found=find(word,choice);
						if(found==1)
						{
							int i;
							for(i=0;i<length ; i++)
							{
								if(word[i]==choice)
								{
									revealed[i]=choice;
								}
							}
							printf("\n\n");
							print_t(revealed , length);	
							printf("\n\n");
						}else{
							round--;
							printf("\nYOU  HAVE %d TRIALS...\n\n",round);
						}
				}
				
		
		
			if(round==0 && find(revealed,'*')==1)
			{
				printf("YOU HAVE LOST !\n\n");
			}
			else if(round !=0 && find(revealed,'*')==0 )
			{
				printf("CONGRATS, YOU HAVE WON! \n\n");
			}
			printf("DO YOU WANT TO TRY AGAIN ?       YES[y]  NO[n] \t");
			playing= read_char();
		
		}	
				// the user do not wanna play anymore
			if (playing=='n')
			{
				fclose(fichier);
				exit(0);
			}
	}else{
			// the file could not be opened for some reasons , maybe it does not exist
		printf("\nERROR FILE CANNOT BE OPENED :/ \n");
		exit(0);
	}
	
	return 0;
}
