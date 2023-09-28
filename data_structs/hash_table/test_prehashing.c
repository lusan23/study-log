#include <stdio.h>
#include <stdlib.h>
#include"hash.h"
int test_prehashing(char filename[300])
{
  int max_line_length = 1000;
    FILE    *textfile;
    char    line[max_line_length];
     
    textfile = fopen(filename, "r");
    if(textfile == NULL)
        return 1;
     
    while(fgets(line, max_line_length, textfile))
    {
        printf("the hash of %s is: %d\n", line, preHashing(line, 'd'));
    }
     
    fclose(textfile);
}
