/*
      date:  January 24, 2014
      name:  John Green
  homework:  01
     class:  CSE 1320-004
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i,j,x,count;
    double temp,ans,sum_1;
    
	/* loop for collums */
    for(i = 0; i < 10; i++)
    {
		sum_1 = 0;
		count = 0;
		/* loop for rows */
		for(j = 0; j < 4; j++)
		{
			x = rand();
			temp = x%10000; 
			ans = temp/100; /* create number 0.0 - 99.99 */
			if(ans <= 67.0)
			{
				printf("%7s","");
			}
			else
			{
				printf("%-7.2f", ans);
				count += 1;
				sum_1 += ans;
			}
			if(j == 3)
			{
				if(count == 0)
				{
					printf("|\n");
					break;
				}
				
				printf("%s %-3.2f\n","| ", sum_1/count);
				break;
			}
		}
	}
}

