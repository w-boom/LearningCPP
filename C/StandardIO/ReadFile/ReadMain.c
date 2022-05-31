#include <stdio.h>
#include <stdlib.h>

#include "ReadFile.h"

#define MAX  40

#include<stdio.h>
#include<stdlib.h>


void get(char * string, int n)
{
	// wrapper for fgets - read from stdin and replace
	// first newline with null character

	fgets(string, n, stdin);

	while (*string != '\0')
	{
		if (*string == '\n')
		{
			*string = '\0';
			break;
		}
		string++;
	}
}

int main(int argc, char *argv[])
{
	char fileName[MAX];
	int rows;
	int i;
	int j;
	int **data;
	
	printf("Enter a source file:");
	get(fileName, MAX);
	
	if ((rows = ReadRows(fileName)) == 0)
	{
		printf("Could not read data;");
		exit(EXIT_FAILURE);
	}
	
	rows = ReadRows(fileName);
	printf("%d\n", rows);
	
	data = (int **)calloc(rows, sizeof(int *));
	for(i = 0; i < rows; i++)
	{
		data[i] = (int *)calloc(5, sizeof(int)); 
	}
	
	read(fileName, rows, 5, data);
	
	printf("%d", data[3][2]);
	
	for(i = 0; i < rows; i++)
	{
		free(data[i]); 
	}
	free(data);	
	
	system("pause");
	return 0;

}