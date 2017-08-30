/*
      date:  March 2, 2014
      name:  John Green
  homework:  06
     class:  CSE 1320-004
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {
    char course_num[10];
    char course_title[70];
    char mvav_id[20];
    char course_time[25];
    char room[10];
    char instructor[30];
    char dates[25];
};

int main(void)
{
	int ERB[] = {103, 106, 126, 127, 129, 130, 131}, count = 0, temp;
	int erb_set[100], erb_count = 0, i, j, swap, x, y;
	char buffer[200], *split = ",", *line, *line2 , r_temp[10], temp1[10], temp2[10];
	
	struct info set[100];
	
	/* day/time, course in room 103, course in room 106, ..., course in room 131 */
	
	
	while( fgets(buffer, sizeof(buffer), stdin) )
    {
		line = strtok(buffer, split);
		strcpy(set[count].course_num, line);
		line = strtok(NULL, split);
		strcpy(set[count].course_title, line);
		line = strtok(NULL, split);
		strcpy(set[count].mvav_id, line);
		line = strtok(NULL, split);
		strcpy(set[count].course_time, line);
		line = strtok(NULL, split);
		strcpy(set[count].room, line);
		line = strtok(NULL, split);
		strcpy(set[count].instructor, line);
		line = strtok(NULL, split);
		strcpy(set[count].dates, line);
        
		count++;
    }
    
    count--;
    
    while( count )
    {
		strcpy(r_temp, set[count].room);
		temp = strcmp("ERB", strtok(r_temp, " "));

				
		if(temp == 0)
		{
			erb_set[erb_count] = count;
			erb_count++;
		}
		
		
		count--;
	}
	
	
	for(i=0;i<erb_count-1;i++)
	{
		for(j=0;j<(erb_count-i-1);j++)
		{			
			if(strcmp(set[erb_set[j]].course_time, set[erb_set[j+1]].course_time) > 0)
			{
				swap = erb_set[j];
				erb_set[j] = erb_set[j+1];
				erb_set[j+1] = swap;
			}
		}
	}
	
	for(i=0;i<erb_count-1;i++)
	{
		for(j=0;j<(erb_count-i-1);j++)
		{
			if(strcmp(set[erb_set[j]].course_time, set[erb_set[j+1]].course_time) == 0)
			{
				strcpy(temp1,set[erb_set[j]].room);
				line = strtok(temp1," ");
				line = strtok(NULL, " ");
				strcpy(temp2,set[erb_set[j+1]].room);
				line2 = strtok(temp2," ");
				line2 = strtok(NULL, " ");
			
				x = atoi(line);
				y = atoi(line2);
		
				if(x > y)
				{
					swap = erb_set[j];
					erb_set[j] = erb_set[j+1];
					erb_set[j+1] = swap;
				}
			}
		}	
	}
	
	for(i=0;i<erb_count;i++)
	{
		printf("%s", set[erb_set[i]].course_time);
		strcpy(temp1,set[erb_set[i]].room);
		line = strtok(temp1," ");
		line = strtok(NULL, " ");
		for(j=0;j<(sizeof(ERB)/sizeof(ERB[0]))-1;j++)
		{
			if(atoi(line) == ERB[j])
			{
				printf(", %s-%s",set[erb_set[i]].course_num,set[erb_set[i]].room);
				break;
			}
			else
				printf(", ");
		}
		if(atoi(line) == ERB[(sizeof(ERB)/sizeof(ERB[0]))-1])
		{
			printf(", %s-%s\n",set[erb_set[i]].course_num,set[erb_set[i]].room);
			continue;
		}
		while(1)
		{
			if(strcmp(set[erb_set[i]].course_time, set[erb_set[i+1]].course_time) == 0)
			{
				i++;
				if(j < ERB[(sizeof(ERB)/sizeof(ERB[0]))-1])
					j++;
				else
				{
					printf("\n");
					break;
				}	
				
				strcpy(temp1,set[erb_set[i]].room);
				line = strtok(temp1," ");
				line = strtok(NULL, " ");
				
				if(atoi(line) == ERB[j])
				{
					printf(", %s-%s",set[erb_set[i]].course_num,set[erb_set[i]].room);
					continue;
				}
				else
				{
					printf(", ");
				}
				
			}
			else
			{
				printf("\n");
				break;
			}
			
		}
		
	}
	
	
    return 0;
}
