/* put your function declarations, structure definitions, #defines, etc.
   in this file

   each file needing any of those things should include this file.

   below are some examples
*/

struct info 
{
	char name[16];
	char class[10];
};

void sort_names(struct info set[], int count);
int bin_search(struct info set[], int low, int high, char *name);
