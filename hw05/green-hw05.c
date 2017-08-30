/*
      date:  Febuary 23, 2014
      name:  John Green
  homework:  05
     class:  CSE 1320-004
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_set(char*);

int main(int argc, char* argv[])
{
	int start, finish, i;
	char *name = "hw05-data-", *txt = ".txt", file[100];
	
	if(argc != 3)
	{
		printf("usage: executable startInt stopInt\n");
		return 0;
	}
	
	start = atoi(argv[1]);
	finish = atoi(argv[2]);
	
	for(i = start; i <= finish; i++)
	{
		sprintf(file,"%s%d%s",name, i, txt);
		if(file_set(file))
		{
			printf("unable to open %s for reading\n",file);
			return 0;
		}
	}
	
    return 0;
}

int file_set(char* f_name)
{
	FILE* file;
	int num = 0, min = 100, max = 0, sum = 0, count = 0, i;
	double  varsum = 0.0,num_ls[30] , mean = 0.0, var = 0.0;
	char buffer[50], *split = "$", *line;
	
	if( (file = fopen(f_name, "r")) == NULL )
    {
        return 1;
    }
    
    while( fgets(buffer, sizeof(buffer), file) != NULL )
    {
		line = strtok(buffer, split);
		line = strtok(NULL, split);
        num = atoi(line);
        sum += num;
        if(num > max)
			max = num;
		if(num < min)
			min = num;  
		num_ls[count] = num;
		
		count++;
    }
    
    fclose(file);
    
    mean = sum/(count*1.0);
    
    for(i=0; i<count; i++)
		varsum += (num_ls[i] - mean)*(num_ls[i] - mean);

	var = varsum/(count-1.0);
	
	printf("%-18s: min =%4d, max =%4d, mean =%7.2f, variance =%9.2f\n",f_name,min,max,mean,var);
    
    
    
    return 0;
}
