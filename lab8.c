/* ONOMATEPWNYMO: PAPOUTSOGLOU AIKATERINH
	AEM: 03682          
 */
#include"lab8.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//declaration of functions 
int Arguments_Function (int argc, char *argv[],  
						int Integer_Array[MAX_NUMBERS],int *number_arg_pointer , 
						char Words_Array[MAX_WORDS][WORD_WIDTH], int *word_arg_pointer );
void Renaturation_integers_function (int Integer_Array[MAX_NUMBERS], int number_integers);
void printing_integers_function (int Integer_Array[MAX_NUMBERS], int number_integers);
int Remove_Character_function (char Word_Array[MAX_WORDS][WORD_WIDTH],
							int number_words,char future_removed_letter);
void printing_new_words_function (char Words_Array[MAX_WORDS][WORD_WIDTH],
									  int number_words);


//function managment of arguments
int Arguments_Function (int argc, char *argv[],  
						int Integer_Array[MAX_NUMBERS],int *number_arg_pointer , 
						char Words_Array[MAX_WORDS][WORD_WIDTH], int *word_arg_pointer )
	{
		int i, number_integers=0, number_words=0;

for (i=1; i<argc; i+=2)
	{		
//case -word
		if ((strcmp(argv[i],"-word")==0) && (argc>i+1))
			{
				if (number_words<MAX_WORDS)
				{
				strncpy(Words_Array[number_words],argv[i+1],WORD_WIDTH-1);
				number_words++;
				}
				
			}
//case -number				
		else if ((strcmp(argv[i],"-number")==0) && (argc>i+1))
			{
				
				if(number_integers< MAX_NUMBERS)
				{
				Integer_Array[number_integers]=atoi(argv[i+1]);
				number_integers++;
				}
				
			}
// case incorect arguments			
		else 
		  	{
				return(-1);
		 	}
	}

		*number_arg_pointer=number_integers;
		*word_arg_pointer=number_words;
		

return 0;
}
//function for organizing the integers into their array 
 void Renaturation_integers_function (int Integer_Array[MAX_NUMBERS], int number_integers)
 	{
		int i, j, help_int;

	for(i=1, j=number_integers-1; i<j;)
		{
			//organising the array with the new documents
			//front to back
			if(Integer_Array[i]<=Integer_Array[0])
				{
					i++;
				}
			else if(Integer_Array[j]<=Integer_Array[0])
				{
					help_int=Integer_Array[i];
					Integer_Array[i]=Integer_Array[j];
					Integer_Array[j]=help_int;
				}
			//back to front	
			if(Integer_Array[j]>Integer_Array[0])
				{
					j--;
				}
			else if(Integer_Array[i]>Integer_Array[0])
				{
					help_int=Integer_Array[j];
					Integer_Array[j]=Integer_Array[i];
					Integer_Array[i]=help_int;
				}
		
		}
 	return ;
 	}
// function for printing the array of the integers
void printing_integers_function ( int Integer_Array[MAX_NUMBERS], int number_integers)
 	{
		int i;
		for(i=0; i<number_integers; i++)
		{
			printf("%d", Integer_Array[i]);
			if (i < number_integers-1) printf(" ");
		}
		if(number_integers>0)
		{
			printf("\n");
		}
			return ;
 	}
//function for removing a character out of a string
int Remove_Character_function (char Word_Array[MAX_WORDS][WORD_WIDTH], int number_words, 
								char future_removed_letter )
	{
		int i, j, counter=0, l;
		for(i=0; i<number_words; i++)
			{
				for(j=0; j<WORD_WIDTH; j++)
					{
						if(Word_Array[i][j]==future_removed_letter)
							{
								for(l=j; l<WORD_WIDTH-1; l++)
									{
										Word_Array[i][l]=Word_Array[i][l+1];									
									}
								counter++;
								j--;
							}
					}
			}
		return(counter);
	}
//function for printing the array of the words 
	void printing_new_words_function (char Words_Array[MAX_WORDS][WORD_WIDTH],
									  int number_words)
		{
			int i;
			for(i=0; i<number_words; i++)
				{
					printf("%s\n", Words_Array[i]);				
				}
		}
//main function
int main (int argc, char *argv[]) 
{
	int Integer_Array[MAX_NUMBERS], res, removed, number_integers=0,\
		number_words=0;
	char Words_Array[MAX_WORDS][WORD_WIDTH]={{'\0'}}, \
		future_removed_letter;



	res=Arguments_Function(argc, argv,  \
				   Integer_Array,&number_integers, \
				   Words_Array, &number_words );
	// case incorect arguments	
	if (res==-1)
	{
		printf("Incorrect arguments.\n");
		return 1;
	}
	//read the integers ,place them into an array and the chamge them
	//according to the algorithm
	Renaturation_integers_function ( Integer_Array, number_integers);
	printing_integers_function ( Integer_Array, number_integers);

	printf("##\n");
	//read and remove the character 
	printf("Char:\n");
	scanf("%c", &future_removed_letter);

	removed=Remove_Character_function (Words_Array, number_words, 
								      future_removed_letter );
	
	//print the number of characters that was removed
	//and the new words
	printf("Removed: %d\n", removed);

	printing_new_words_function (Words_Array, number_words);
		

	return 0;
}
