#include <stdio.h>
#include <string.h>
#include <math.h>
#include "my_lib.h"

enum operations {OP_MAX, OP_MEAN, OP_SD};


int main(int argc, char **argv)
{
int numbers = argc - 2;
int x[numbers];
int i;
float result;
enum operations op_var;
int setpointer;
float (*fp[])(int *,int) = {my_max, my_mean, my_sd};

//setting operations
if ( strcmp (argv[1], "max") == 0 )
{
  op_var = OP_MAX;
}
else if ( strcmp (argv[1], "mean") == 0 )
{
  op_var = OP_MEAN;
}
else if ( strcmp (argv[1], "sd") == 0 )
{
  op_var = OP_SD;
}
else
{
  printf("Error: Invalid Operator. \n");
  return 1;
}

switch (op_var)
{
  case (OP_MAX):
    setpointer = OP_MAX;
    break;
  case (OP_MEAN):
    setpointer = OP_MEAN;
    break;
  case (OP_SD):
    setpointer = OP_SD;
    break;
}

for (i = 0;i < numbers; i++)
{
  x[i] = my_atoi(argv[i+2]);
}

result = (*fp[setpointer])(x,numbers);
printf("%.1f\n", result);
return 0;
}
