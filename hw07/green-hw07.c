/*
      date:  March 10, 2014
      name:  John Green
  homework:  07
     class:  CSE 1320-004
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_set(char ***set, int lines, int per_line);
int build_set(char ***set, char *f_name, int n_perline);
void sort_set(char ***set, int lines, int col);

int main(void)
{
	int lines = 10, n_perline = 5, n_len = 11, i, j;
	char ***set;
	char *f_name = "hw07-data.csv";
	
	set = malloc(lines * n_perline * n_len * sizeof(char *));
	for(i = 0; i < lines; i++)
	{
		set[i] = malloc(n_perline * n_len * sizeof(char*));
		for(j = 0; j < n_len; j++)
			set[i][j] = malloc(n_len * sizeof(char*));
    }
    
    if(build_set(set,f_name,n_perline))
    {
		printf("unable to open %s for reading\n", f_name);
		return 1;
	}
    print_set(set,lines,n_perline);
    printf("\n");    
    sort_set(set,lines,n_perline);    
    print_set(set,lines,n_perline);
    
    for(i = 0; i < lines; i++)
	{
		for(j = 0; j < n_len; j++)
			free(set[i][j]);
		free(set[i]);
    }
    free(set);
    	
    return 0;
}

void print_set(char ***set, int lines, int per_line)
{
	int i, j;

    for(i = 0; i < lines; i++)
	{
        for(j = 0; j < per_line; j++)
			printf("%-11s ", set[i][j]);
		printf("\n");
	}
}

int build_set(char ***set, char *f_name, int n_perline)
{
	char buffer[55], *split = ",", *line;
	int count = 0, i;
	FILE* file;
	
	if( (file = fopen(f_name, "r")) == NULL )
    {
        return 1;
    }
        
    while( fgets(buffer, sizeof(buffer), file) != NULL )
    {		
		line = strtok(buffer, split);
		strcpy(set[count][0], line);
		
		for(i = 1; i < n_perline-1; i++)
		{
			line = strtok(NULL, split);
			strcpy(set[count][i], line);
		}
		
		line = strtok(NULL, "\n");
		strcpy(set[count][i], line);
		count++;
    }
    
    fclose(file);
    
    return 0;
}

void sort_set(char ***set, int lines, int col)
{
	int i, j, x;
	char *swap;
	
	for(x = 0; x < col; x++)
	{
		for(i = 0; i < lines - 1; i++)
		{
			for(j = 0; j < lines - i - 1; j++)
			{
				if(strlen(set[j][x]) > strlen(set[j+1][x]))
				{
					swap = set[j+1][x];
					set[j+1][x] = set[j][x];
					set[j][x] = swap;
				}
				else if(strlen(set[j][x]) == strlen(set[j+1][x]) &&
						strcmp(set[j][x],set[j+1][x]) > 0)
				{
					swap = set[j+1][x];
					set[j+1][x] = set[j][x];
					set[j][x] = swap;
				}
			}
		}
	}
}
