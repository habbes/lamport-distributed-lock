#ifndef __helpers_hpp__
#define __helpers_hpp__

#include <cstdio>

int get_last_result_value(FILE *file);
void write_result_line(FILE *file, const int value, const int node_id);

#endif
