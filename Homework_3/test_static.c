/* File: test_static.c */
#include "matrix_static.h"

int main() 
{
  static T data[] = {1,2,3,4};
  matrix  a,b;
  a = create_initvals(2,2,data);
  b = create_empty(2,2);
  equate(&a,&b);
  printf("\n Matrix a:");
  matrix_print(a);
  printf("\n Matrix b:");
  matrix_print(b);
  printf("\n a+b:");
  matrix_print(add(a,b));
  
  printf("\n Matrix a:");
  matrix aTransposed;
  aTransposed = transpose(&a);
  matrix_print(aTransposed);
  printf("\n Matrix b:");
  matrix_print(b);
  printf("\n a+b:");
  matrix_print(add(aTransposed,b));
  
  static T newData[] = {3, 2, 8, 7, 1, 1, 2, 4, 4, 1, 1, 2};
  matrix z;
  z = create_initvals(3, 4, newData);
  matrix_print(z);
  matrix z_transposed;
  z_transposed = transpose(&z);
  matrix_print(z_transposed);
 
  return 0;
}

