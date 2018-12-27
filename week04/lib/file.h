#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include <stdlib.h>

int cat(char *name);
int cat_file(FILE *file);
int cp(char *namein, char *nameout);

int load(char *name);

#endif
