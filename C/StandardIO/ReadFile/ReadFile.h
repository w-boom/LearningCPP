#pragma once

#ifdef _cplusplus
extern "C"
{
#endif

int ReadRows(char filename[]);
void read(char fileName[], int rows, int cols, int **data);

#ifdef _cplusplus
}
#endif