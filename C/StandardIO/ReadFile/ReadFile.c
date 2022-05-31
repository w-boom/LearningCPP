#include <stdio.h>
#include <stdlib.h>

int ReadRows(char filename[])
{
	char ch;
	unsigned int rows = 1;
	FILE *fp;
	
	if((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Could not open file %s for read.\n", filename);
		exit(EXIT_FAILURE);
	}
	
	while((ch = getc(fp)) != EOF)
	{
		if(ch == '\n')
			rows++;		
	}
	
	fclose(fp);
	return rows;	
}

void read(char fileName[], int rows, int cols, int **data)
{    
	FILE *fp;
	char ch;
	int i;
	int j;
	
	if((fp = fopen(fileName, "r")) == NULL)
	{
		printf("Could not open file %s for read.\n", fileName);
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			fscanf(fp, "%d", &data[i][j]);
		}
	}
	
	fclose(fp);
	return;
}