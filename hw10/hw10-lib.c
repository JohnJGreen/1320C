/*  put your function definitions in this file 

    any other libraries (e.g., stdio.h) needed by the functions in this file
    should be included
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw10-lib.h"


void sort_names(struct info set[], int count)
{
	int i, j;
	struct info swap;
	
	for(i = 0; i < count-1; i++)
	{
		for(j = 0; j < count-i-1; j++)
		{
			if(strcmp(set[j].name,set[j+1].name) > 0)
			{
				swap = set[j];
				set[j] = set[j+1];
				set[j+1] = swap;
			}
		}
	}
	
}

int bin_search(struct info set[], int low, int high, char *name)
{
	int mid;
	
	mid = (high - low)/2 + low;
	
	if(low > high)
	{
		return -1;
	}
	
	printf(".");
		
	if(strcmp(set[mid].name, name) == 0)
	{
		return mid;
	}
	else if(strcmp(name,set[mid].name) > 0)
	{
		return bin_search(set, mid + 1, high, name);
	}
	else
	{
		return bin_search(set, low, mid - 1, name);
	}
}
