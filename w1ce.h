#ifndef W1CE_H
#define W1CE_H

#include <stdbool.h>

bool         w1_isfile (const char* path);
bool         w1_isdir  (const char* path);
unsigned int w1_abspath(const char* path, char* buf, unsigned int buf_length);
int          w1_getch  ();

#endif

