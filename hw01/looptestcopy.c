/*
      date:  January 24, 2014
      name:  John Green
  homework:  01
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;

    /* unseeded; do this in your homework */
    for(i = 0; i < 10; i++)
        printf("%d, ", rand());

    printf("\n\n");

    /* this seeds the random number generator; DON'T DO THIS IN YOUR HOMEWORK */
    srand(time(NULL));
    for(i = 0; i < 10; i++)
        printf("%d, ", rand());

    printf("\n");
}

