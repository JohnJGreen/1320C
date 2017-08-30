/*
      date:  March 28, 2014
      name:  John Green
  homework:  08
     class:  CSE 1320-004
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prnt(char** set, int count, char *input, int lines);

int main(int argc, char* argv[])
{
	int mult = 4, lines, count = 0;
	char buffer[100], **temp, *line, *input, *f_name, **set;
	FILE* file;
	
	if(argc != 4)
	{
		printf("  usage: executable [h/t/b/s] number filename\n");
		printf("example: ./brezeale-hw08 h 10 somefile.txt\n");
		return 1;
	}
	lines = atoi(argv[2]);
	f_name = argv[3];
	input = argv[1];
	
	set = malloc(mult*sizeof(char*));
	
	if( (file = fopen(f_name, "r")) == NULL )
    {
        return 1;
    }
	
	while( fgets(buffer, sizeof(buffer), file) != NULL )
    {	
		if(count == mult-1)
		{
			mult = mult*2;
			printf("reached limit...increasing potential strings to %d\n",mult);
			temp = realloc(set, mult*sizeof(char*));
			if(temp != NULL)
			{
				set = temp;
			}
			else
			{
				printf("unable to reallocate\n");
				exit(1);
			}
		}			
		line = strtok(buffer, "\0");
		set[count] = malloc( (strlen(line)+1)*sizeof(char) );
		strcpy(set[count], line);
		count++;
	}
	fclose(file);
	
	prnt(set, count, input, lines);
	
    return 0;
}

void prnt(char** set, int count, char *input, int lines)
{
	int i,j;
	char *x[4] = {"h","t","b","s"}, *swap;
	
	if(strcmp(x[0],input) == 0)
	{
		if(lines > count)
			lines = count;
		for(i = 0; i < lines; i++)
			printf("%s", set[i]);
	}
	else if(strcmp(x[1],input) == 0)
	{
		if(lines > count)
			lines = count;
		for(i = (count-lines); i < count; i++)
			printf("%s", set[i]);
	}
	else if(strcmp(x[2],input) == 0)
	{
		if(lines*2 >= count)
		{
			for(i = 0; i < count; i++)
				printf("%s", set[i]);
		}
		else
		{
			for(i = 0; i < lines; i++)
				printf("%s", set[i]);
			for(i = (count-lines); i < count; i++)
				printf("%s", set[i]);
		}
	}
	else if(strcmp(x[3],input) == 0)
	{
		for(i = 0; i < count-1; i++)
		{
			for(j = 0; j < count-i-1; j++)
			{
				if(strcmp(set[j],set[j+1]) > 0)
				{
					swap = set[j+1];
					set[j+1] = set[j];
					set[j] = swap;
				}
			}			
		}
		for(i = 0; i < count; i++)
			printf("%s", set[i]);
	}
}
