
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct my_bitfield_t
{
  int b1 : 23; // two bits, these are on the lowest order in memory, i.e., bit 0 and 1
  int b2 : 8;
  int b3 : 1;
};

union my_union_t
{
  struct my_bitfield_t b;
  float i;
};

int print_float(int signbit[], int exponent[], int mantissa[])
{
  printf("%d|", signbit[0]);
  for (int i = 0; i < 8; i++)
  {
    printf("%d", exponent[i]);
  }
  printf("|");

  for (int i = 0; i < 23; i++)
  {
    printf("%d", mantissa[i]);
  }
  return 0;
}


int main(int argc, char ** argv)
{
  union my_union_t u;
  int mantissa[23];
  int exponent[8];
  int signbit[1];

  if (argc == 1 || argc > 2)
  {
    printf("Error: One floating point number not supplied.\n");
    return 1;
  }
  u.i = atof(argv[1]);
  int temp_mantissa = u.b.b1;
  int temp_exponent = u.b.b2;
  int temp_signbit = u.b.b3;

//finding signbit
  signbit[0] = temp_signbit & 1;

//finding exponent
  for (int i = 7; i >= 0; i--)
  {
    exponent[i] = temp_exponent & 1;
    temp_exponent = temp_exponent >> 1;
  }

//finding mantissa
  for (int i = 22; i >= 0; i--)
  {
    mantissa[i] = temp_mantissa & 1;
    temp_mantissa = temp_mantissa >> 1;
  }
  print_float (signbit, exponent, mantissa);
  return 0;
}
