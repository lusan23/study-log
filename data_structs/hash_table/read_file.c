#include <stdio.h>
#include <stdlib.h>

void read_file(void)
{
  int max_line_length = 1000;
    FILE    *textfile;
    char    line[max_line_length];
     
    textfile = fopen("readme.txt", "r");
    if(textfile == NULL)
        return 1;
     
    while(fgets(line, max_line_length, textfile)){
        printf(line);
    }
     
    fclose(textfile);
}
