#include <string.h>
#include <stdio.h>
#include <math.h>
#include "my_lib.h"

int my_atoi(char *c)
{
int asciizero = 48; /**<ASCII value for number 0 */
int sign = 1;
int strlength = strlen(c);
int number[strlength]; /*<Array used to store each string digit as an integer */
int value=0; /*< Holds final numeric value of string converted to integer */
int i;
int start = 0;

if (c[0] == '-')
{
  sign = -1;
  start = 1;
  strlength = strlength -1;
}

for (i=0;i<strlength;i++)
{
number[i] =(int) c[start + i]; /*First fill array with each ASCII value of character*/
number[i] =number[i] - asciizero; /*Convert each digit of string to actual numeric value*/
value = value + number[i]*pow(10,strlength-i-1); /*<Evaluate value of each digit by multiplying by appropriate power of 10 */
}
if (sign == -1)
{
  value = value * -1;
}
return value;
}

/**
*@section DESCRIPTION
*
* Implementation of function declared in header file
* This function finds the highest numerical value from a list of integers,
*@param x[] is an array of the integers passed to the function
*
*@param numbers is a count of the numbers in array x[]
*
*@returns the maximum integer from the array.
*/

float my_max(int x[], int numbers)
{
  int max = x[0];
  int i;

  for (i = 1; i < numbers; i++ )
  {
    if (x[i] > max)
    {
      max = x[i];
    }
  }

  return max;
}

/**
*@section DESCRIPTION
*
* Implementation of function declared in header file
*
* This function finds the mean of a list of integers.
*
*@param x[] is an array of the integers passed to the function
*
*@param numbers is a count of the number of numbers in array x[]
*
*@returns the mean of numbers in given array as floating point number.
*/

float my_mean(int x[], int numbers)
{
  float mean;
  float sum = 0;
  int i;

  for (i = 0; i < numbers; i++)
  {
    sum += x[i];
  }
  mean = sum / numbers;
  return mean;
}

/**
*@section DESCRIPTION
*
* Implementation of function declared in header file
* This function finds the standard deviation of a list of integers.
* This function also makes use of the mean function to calculate the standard deviation.
*@param x[] is an array of the integers passed to the function
*@param numbers is a count of the number of numbers in array x[]
*
*@returns the standard deviation of numbers in given array as floating point number.
*/

float my_sd(int x[], int numbers)
{
  float average, variance, sd;
  int i;
  float Sxx = 0;

  average = my_mean(x, numbers);

  for (i = 0; i < numbers; i++)
  {
    Sxx += pow(x[i] - average, 2);
  }
  variance = Sxx / numbers;
  sd = sqrt(variance);
  return sd;
}
