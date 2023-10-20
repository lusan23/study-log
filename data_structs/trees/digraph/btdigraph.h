#ifndef BTDIGRAPH_H
#define BTDIGRAPH_H

void define_digraph(char *command);
void add_connection(char *command, char A[256], char B[256]);
void add_double_connection(char *command, char A[256], char B[256], char C[256]);
void add_leaf(char *command, char A[256]);
void end_digraph(char *command);
char* create_graph_text(void);
char* create_file(char command[1000], char file_name[100]);
void create_img(char filename[50], char img_name);
#endif
