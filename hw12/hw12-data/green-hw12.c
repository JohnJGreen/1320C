/*
      date:  April 25, 2014
      name:  John Green
  homework:  12
     class:  CSE 1320-004
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>


struct data {
    int course_num;
    int year;
    int week_1;
    int week_2;
    int week_3;
    int week_4;
    int week_5;
    int week_6;
    int week_7;
    int week_8;
    int week_9;
    int week_10;
    int week_11;
    int week_12;
    int week_13;
    int week_14;
};

int get_data(char *p, struct data set[] ,int count);
void count_data(char *p, struct data set[] ,int count);
void add_data(struct data set[], int count, double date);
void print_data(struct data set[], int count);
void init_data(char *p, struct data set[] , int year, int class,int count);
int exists_data(struct data set[] , int year, int class, int count);
void sort_data(struct data set[], int count);

int main(void)
{	
	glob_t  paths;  
    int     csource, size = 2, count = 0;
    char    **p;
    struct data *set, *temp;
    
    set = malloc( size*sizeof(struct data) );

    csource = glob("*-cse*.csv", 0, NULL, &paths);
     
    if (csource == 0)
    {
        for (p=paths.gl_pathv; *p != NULL; ++p)
        {
			if(size-1 == count)
			{
				size *= 2;
				temp = realloc(set, size*sizeof(struct data));
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
			count += get_data(*p, set, count);
		}
        globfree(&paths);
    }
    
    sort_data(set, count);
    print_data(set, count);
    free(set);

	return 0;

}

int get_data(char *p, struct data set[] ,int count)
{
	char *t_name, *line;
	int year, class, exist;
	
	t_name = malloc(sizeof(*p));
	strcpy(t_name, p);
	line = strtok(t_name,"-");
	year = atoi(line);
	line = strtok(NULL,"e");
	line = strtok(NULL,".");
	class = atoi(line);
	
	exist = exists_data(set, year, class, count);
	if(exist != -1)
	{
		count_data(p, set, exist);
		return 0;
	}
	else
	{	
		init_data(p, set, year, class, count);
		return 1;
	}
	free(t_name);
}

void count_data(char *p, struct data set[] ,int index)
{
	char buffer[300], *line, *t_line;
	int l_flag = 0;
	double date;
	FILE* file;
	
	if( (file = fopen(p, "r")) == NULL )
    {
        exit(2);
    }
        
    while( fgets(buffer, sizeof(buffer), file) != NULL )
    {	
		date = 0.0;	
		if(l_flag != 0)
		{
			t_line = strtok(buffer, ",");
			while(t_line != NULL)
			{
				line = t_line;
				t_line = strtok(NULL, ",");
			}
			
			line = strtok(line, "/");
			date += atoi(line);
			line = strtok(NULL, "/");
			date += (atoi(line)/100.0);
			add_data(set, index, date);
		}
		l_flag = 1;
    }
    fclose(file);
}

void add_data(struct data set[], int index, double date)
{
	if(date <= 6.01)
		set[index].week_1 += 1;
	if(date <= 6.08)
		set[index].week_2 += 1;
	if(date <= 6.15)
		set[index].week_3 += 1;
	if(date <= 6.22)
		set[index].week_4 += 1;
	if(date <= 6.29)
		set[index].week_5 += 1;
	if(date <= 7.06)
		set[index].week_6 += 1;
	if(date <= 7.13)
		set[index].week_7 += 1;
	if(date <= 7.20)
		set[index].week_8 += 1;
	if(date <= 7.27)
		set[index].week_9 += 1;
	if(date <= 8.03)
		set[index].week_10 += 1;
	if(date <= 8.10)
		set[index].week_11 += 1;
	if(date <= 8.17)
		set[index].week_12 += 1;
	if(date <= 8.24)
		set[index].week_13 += 1;
	set[index].week_14 += 1;
}

void print_data(struct data set[], int count)
{
	int i;
	
	printf("course,year,06/01,06/08,06/15,06/22,06/29,07/06,07/13,");
	printf("07/20,07/27,08/03,08/10,08/17,08/24,12/31\n");
	for(i = 0; i < count; i++)
	{
		printf("%d,%d,",set[i].course_num, set[i].year);
		printf("%d,%d,%d,",set[i].week_1 , set[i].week_2, set[i].week_3);
		printf("%d,%d,%d,",set[i].week_4 , set[i].week_5, set[i].week_6);
		printf("%d,%d,%d,",set[i].week_7 , set[i].week_8, set[i].week_9);
		printf("%d,%d,%d,",set[i].week_10 , set[i].week_11, set[i].week_12);
		printf("%d,%d\n",set[i].week_13, set[i].week_14);
	}
}

int exists_data(struct data set[] , int year, int class, int count)
{
	int i;
	
	for(i = 0; i <= count; i++)
	{
		if( (year == set[i].year) && (class == set[i].course_num) )
			return i;
	}
	return -1;
}

void init_data(char *p, struct data set[] , int year, int class,int count)
{
	struct data item;
	
	item.course_num = class;
    item.year = year;
    item.week_1 = 0;
    item.week_2 = 0;
    item.week_3 = 0;
    item.week_4 = 0;
    item.week_5 = 0;
    item.week_6 = 0;
    item.week_7 = 0;
    item.week_8 = 0;
    item.week_9 = 0;
    item.week_10 = 0;
    item.week_11 = 0;
    item.week_12 = 0;
    item.week_13 = 0;
    item.week_14 = 0;
    
    set[count] = item;
    count_data(p, set , count);
}

void sort_data(struct data set[], int count)
{
	int i, j;
	struct data swap;
	
	for(i = 0; i < count-1; i++)
	{
		for(j = 0; j < count-i-1; j++)
		{
			if(set[j].course_num > set[j+1].course_num)
			{
				swap = set[j];
				set[j] = set[j+1];
				set[j+1] = swap;
			}
		}
	}
	for(i = 0; i < count-1; i++)
	{
		for(j = 0; j < count-i-1; j++)
		{
			if( (set[j].course_num == set[j+1].course_num) && 
				(set[j].year > set[j+1].year) )
			{
				swap = set[j];
				set[j] = set[j+1];
				set[j+1] = swap;
			}
		}
	}
}







