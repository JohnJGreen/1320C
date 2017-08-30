/*
      date:  Febuary 5, 2014
      name:  John Green
  homework:  03
     class:  CSE 1320-004
*/

#include <stdio.h>
#include <stdlib.h>

void long_word(char[],int[]);

int main(void)
{
	char s1[] = "This is one of Several strings2use.";
	char s2[] = "This sample has less than 987654321 leTTers.";
	char s3[] = "Is thIs a string?  (definitely)";
	char s4[] = "Twitter loves its hashtags #twitterlove";
	char s5[] = "123 four five.";
	int c[3] = {0,0,0};
	
	c[0] = sizeof(s1)/sizeof(s1[0]);
	long_word(s1,c);
	printf("string  1: words =%3d, longest =%4d characters\n",c[2],c[1]);
	
	c[0] = sizeof(s2)/sizeof(s2[0]);
	long_word(s2,c);
	printf("string  2: words =%3d, longest =%4d characters\n",c[2],c[1]);
	
	c[0] = sizeof(s3)/sizeof(s3[0]);
	long_word(s3,c);
	printf("string  3: words =%3d, longest =%4d characters\n",c[2],c[1]);
	
	c[0] = sizeof(s4)/sizeof(s4[0]);
	long_word(s4,c);
	printf("string  4: words =%3d, longest =%4d characters\n",c[2],c[1]);
	
	c[0] = sizeof(s5)/sizeof(s5[0]);
	long_word(s5,c);
	printf("string  5: words =%3d, longest =%4d characters\n",c[2],c[1]);
	
	return 0;
}

void long_word(char s[],int counts[])
{
	int lenght = counts[0];
	int i,len = 0,words = 0,count = 0;
	counts[1] = 0;
	counts[2] = 0;
	
	while( s[i] != '\0')
	{
		if((s[i] >= 'a') && (s[i] <= 'z'))
		{
			count++;
		}
		else if((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			count++;
		}
		else
		{
			if(count > len)
			{
				len = count;
			}
			else if(count == 0)
			{
				continue;
			}
			count = 0;
			words++;
		}
	}
	counts[1] = len;
	counts[2] = words;	
}
