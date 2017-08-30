/*
      date:  January 24, 2014
      name:  John Green
  homework:  01
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i,j,x;
    double ans, sum_1;

    for(i = 0; i < 4; i++)
    {
		sum_1 = 0;
		/* loop for rows */
		for(j = 0; j < 10; j++)
		{
			x = rand();
			ans = x%10000;
			sum_1 += ans;
			if(j == 9)
			{
				printf("%f", ans);
				printf("%f\n\n", sum_1/10);
				break;
			}
			printf("%f, ", ans);
		}
	}
}

