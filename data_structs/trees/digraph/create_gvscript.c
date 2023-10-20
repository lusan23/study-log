/*
Set of functions for generating a graphical binary tree
requirement
graphviz for Linux (Ubuntu).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"btdigraph.h"
#include"../trees.h"

void define_digraph(char *command)
{
    char arg[] = "digraph G {\n";
    strcat(command,  arg);
   
}

void end_digraph(char *command)
{
    strcat(command,  "}");
}

void add_connection(char *command, char A[256], char B[256])
{
    strcat(command, "\n");
    strcat(command, A);
    strcat(command, " -> ");
    strcat(command, B);
    strcat(command, "; \n");   
}

void add_double_connection(char *command, char A[256], char B[256], char C[256])
{
    strcat(command, "\n");
    strcat(command, A);
    strcat(command, " -> {");
    strcat(command, B);
    strcat(command, ",");
    strcat(command, C);
    strcat(command, "}");
    strcat(command, "; \n");   
}

void add_leaf(char *command, char A[256])
{
    strcat(command, "\n");
    strcat(command, A);
    strcat(command, "; \n");   
}

void create_img(char filename[50], char img_name)
{
    char cmd[256];

    strcat(cmd, "dot -Tpng" );
    strcat(cmd, filename);
    strcat(cmd, " -o ");
    strcat(cmd, img_name );
    strcat(cmd, ".png");
    
    printf("create img test:%s", cmd);
}

char* create_file(char command[1000], char file_name[100])
{

    char filename[256];
    strcat(filename, file_name);
    strcat(filename, ".gv");

    FILE* fptr = fopen(filename, "w");

    if (fptr == NULL)
    {
        printf("Error opening the file %s\n", filename);
        return NULL;
    }

    fprintf(fptr, command); 
    fclose(fptr);

return filename;
}