/*
      date:  April 10, 2014
      name:  John Green
  homework:  10
     class:  CSE 1320-004
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw10-lib.h"

int main(void)
{
	char *fl_name = "hw10-names.txt", *fl_data = "hw10-data.csv";
	char names[10][16], buffer[100], *line;
	int count = 0, str_count = 0, i, temp;
	FILE *fp;
	
	struct info set[25];
	
	if( (fp = fopen(fl_name, "r")) == NULL )
    {
        return 1;
    }
	while( fgets(buffer, sizeof(buffer), fp) != NULL )
    {
		line = strtok(buffer, "\n");
		strcpy(names[count], line);
		count++;
	}
	fclose(fp);
	
	if( (fp = fopen(fl_data, "r")) == NULL )
    {
        return 1;
    }
	while( fgets(buffer, sizeof(buffer), fp) != NULL )
    {
		line = strtok(buffer, ",");
		strcpy(set[str_count].name, line);
		line = strtok(NULL, "\n");
		strcpy(set[str_count].class, line);
		str_count++;
	}
	fclose(fp);

	sort_names(set, str_count);
	
	for(i = 0; i < count; i++)
	{
		printf("searching for %s",names[i]);
		temp = bin_search(set, 0, str_count, names[i]);
		if(temp == -1)
			printf("not enrolled");
		else
			printf("enrolled in %s",set[temp].class);
		if(i != count-1)
			printf("\n");
	}
	
	printf("\n");
	
    return 0;
}
