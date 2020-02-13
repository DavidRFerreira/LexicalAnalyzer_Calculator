//Implementation of a Lexical Analyser for Simple Mathematical Expressions.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define nStates 7
#define nSymbols 6

#define nMaxTokens 20
#define nLenghtNameTokens 20


void deleteBlankSpaces(char* str);
int isItNumber(char n);
int isItOperador(char n);
void DFARecognizer(char* exp, char tokens[][nLenghtNameTokens], int *numTokens);


int main(void)
{
	FILE* input;
	FILE* output;
	char buff[35];
	char tokens[nMaxTokens][nLenghtNameTokens];
	int numTokens = -1;
	int i = 0;


	//Opens a file to read from (input).
	if ((input = fopen("input.txt", "r")) == NULL)
		printf("It was not possible to open the file to read!");
		
	//Opens a file to write to (output).
	if ((output = fopen("output.txt", "w+")) == NULL)
			printf("It was not possible to open the file to write!");	
			

	// Reads line by line from the input file.
	while (fgets(buff, sizeof(buff), input))
	{		
		numTokens = -1;
		
		printf("\n------------------------------------------------------\n");
		printf("INPUT EXPRESSION: %s", buff); //prints the original input to the screen.
		fprintf(output, "\n------------------------------------------------------\n"); 
		fprintf(output, "INPUT EXPRESSION: %s\n", buff);  //prints the original input to the output file.		
		
		deleteBlankSpaces(buff);
		
		fprintf(output, "\nRECOGNIZED TOKENS: \n");
		printf("\nRECOGNIZED TOKENS: \n");
		
		
		DFARecognizer(buff, tokens, &numTokens);
		
		for (i = 0; i <= numTokens; i++)
		{
			printf("%s  ", tokens[i]);
			fprintf(output, "%s  ", tokens[i]);
		}
	}


	fclose(output);
	fclose(input);
	
	return 0;
}




//Deletes the blank spaces from a string.
void deleteBlankSpaces(char* str)
{
	const char* d = str;
	int i = 0;

	do
	{
		while (*d == ' ')
		{
			++d;
			i++;
		}
	} while (*str++ = *d++);
}



//Returns '1' if the argument is a number.
int isItNumber(char n) 
{

	if( n >= '0' && n <= '9' )
	{
		return 1;	
	}

	return 0;
}



//Returns '1' if the argument is an operator.
int isItOperator(char n) 
{
	if ((n == '+') || (n == '-') || (n == '*')
		|| (n == '/'))
	{
		return 1;		
	}

	return 0;
}



//Verifica se é um INTEGER ou um FLOAT.
void DFARecognizer(char* exp, char tokens[][nLenghtNameTokens], int *numTokens)
{
	
	//The first column concerns to the transitions that consume an operator (+, -, / or *).
	//The second column concerns to the transitions that consume a left parentheses.
	//The third column concerns to the transitions that consume a right parentheses.
	//The forth column concerns to the transitions that consume a number.
	//The fifth column concerns to the transitions that consume a point.
	//The sixth column concerns to the transitions that consume any other character.
	
	int transitionTable[nStates][nSymbols] = { {1, 2, 3, 4, -1, -1}, //state 0.
											   {-1, -1, -1, -1, -1, -1}, //state 1.
											   {-1, -1, -1, -1, -1, -1}, //state 2.
											   {-1, -1, -1, -1, -1, -1}, //...
											   {-1, -1, -1, 4, 5, -1},
											   {-1, -1, -1, 6, -1, -1},
											   {-1, -1, -1, 6, -1, -1} };
	

	//Which element indicates if a state is an acceptance state or not.
	int acceptanceStates[nStates] = {-1, 1, 1, 1, 1, -1, 1};										  

	int presentState = 0;
	int lastAcceptedState = 0;
	int inputPosition = 0;
	int flagInteger = 0, flagFloat = 0;


	
	while ((exp[inputPosition] != '\n'))
	{
		flagInteger = 0;
		flagFloat = 0;
		presentState = 0;
		lastAcceptedState = 0;
				
		if (isItOperator(exp[inputPosition]))
		{	
			if (transitionTable[presentState][0] != -1)
			{
				presentState = transitionTable[presentState][0];
			}	
		}
		else if (exp[inputPosition] == '(')
		{	
			if (transitionTable[presentState][1] != -1)
			{
				presentState = transitionTable[presentState][1];
			}	
		}
		else if (exp[inputPosition] == ')')
		{	
			if (transitionTable[presentState][2] != -1)
			{
				presentState = transitionTable[presentState][2];
			}	
		}
		else if (isItNumber(exp[inputPosition]))
		{
			while(1)
			{
				if (isItNumber(exp[inputPosition]))
				{
					if (transitionTable[presentState][3] != -1)
					{
						flagInteger = 1;
			
						presentState = transitionTable[presentState][3];
					}	
				}	
				else if (exp[inputPosition] == '.')
				{
					if (transitionTable[presentState][4] != -1)
					{
						flagFloat = 1;
		
						presentState = transitionTable[presentState][4];
					}	
				}
				else
				{
					break;
				}
				
				inputPosition++;	
			}
		}
		else
		{
			if (transitionTable[presentState][5] != -1)
			{
				presentState = transitionTable[presentState][5];
			}	
		}
		
		
		if (flagInteger != 1 && flagFloat != 1)
		{
			inputPosition++;	
		}
		
		
		//Verify if the new state, after the transition, is an acceptance state.
		if (acceptanceStates[presentState] == 1)
		{
			lastAcceptedState = presentState;
		}
		
		(*numTokens)++;
		
		switch(lastAcceptedState)
		{
			case 1:
			{
				strcpy(tokens[*numTokens], "Operator");
				break;
			}
			case 2:
			{
				strcpy(tokens[*numTokens], "Left-Parentheses");
				break;
			}
			case 3:
			{
				strcpy(tokens[*numTokens], "Right-Parentheses");
				break;
			}
			case 4:
			{
				strcpy(tokens[*numTokens], "Integer");
				break;
			}
			case 6:
			{
				strcpy(tokens[*numTokens], "Float");
				break;
			}
			case -1:
			case 0:
			default:
			{
				strcpy(tokens[*numTokens], "Invalid");
				break;
			}	
			}
		}
	}
