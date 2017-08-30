/*
      date:  January 30, 2014
      name:  John Green
  homework:  02
     class:  CSE 1320-004
*/

#include <stdio.h>
#include <stdlib.h>

int div_count(int,int);

int main(void)
{
	int i,int_1,int_2,div_1,div_2,most_div,most_int,sum = 0,temp;
	double count = 0.0;
	
	printf("enter a positive integer: ");
	scanf("%d", &int_1);
	printf("enter a second, greater positive integer: ");
	scanf("%d", &int_2);
	printf("\n");
	
	div_1 = div_count(int_1,0);
	div_2 = div_count(int_2,0);
	
	if(div_1 == div_2)
	{
		printf("%d and %d have the same number of divisors\n\n",int_1,int_2);
	}
	else
	{
		if(div_1 > div_2)
		{
			printf("%d has more divisors than %d\n\n",int_1,int_2);
		}
		else
		{
			printf("%d has more divisors than %d\n\n",int_2,int_1);
		}
	}
	
	
	most_int = int_1;
	most_div = div_count(most_int,0);
	
	for(i = int_1; i <= int_2; i++)
	{
		printf("%2d: ",i);
		temp = div_count(i,1);
		sum += temp;
		count += 1;
		if(i == int_2)
		{
			printf("\n");
		}
		if(temp > most_div)
		{
			most_int = i;
			most_div = div_count(i,0);
		}
	}
	
	printf("the average number of divisors is %1.2f\n",sum/count);
	printf("%d has the most with %d divisors\n",most_int,most_div);
	
	return 0;
}

int div_count(int a,int print)
{
	int i,x = 0;
	
	for(i = 1; i <= a; i++)
	{
		if(a%i == 0)
		{
			if(print)
			{
				if(i == a)
				{
					printf("%d\n",i);
				}
				else
				{
					printf("%d, ",i);
				}
			}
			x += 1;
		}
	}
	return x;	
}
