/* Name:Chayathorn Terataninan
 * ID: 6280945
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double compute_det(int **a, int n) {
    
  if (n==1)
  {
    return a[0][0];
  }
  else
  {
  int c = 0;
  int d = 0;
  int one = 1;
  double determinant=0;
     int** minor = (int**)malloc(sizeof(int*)*(n-1));
     for (int i = 0; i < n-1; i++)
     {
       minor[i] = (int*) malloc(sizeof(int)*(n-1));
     }
     for (int i = 0; i < n; i++)
     {
      
       for (int j = 0; j < n; j++)
       {
         if(i!=j){
         for (int k = 1; k < n; k++)
         {
             minor[c][k-1] = a[j][k];
          }
          c++; 
        }        
      }
       determinant = determinant + one*(a[i][0]*compute_det(minor,n-1));
       one = -1*one;
       c=0;
    }
    for (int i = 0; i < n-1; i++)
    {
      free(minor[i]);
    }
    free(minor);
  return determinant;
  }
}

/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(void) {
  int input = 0;
  
  scanf("%d", &input);
  int** m = (int**) malloc(sizeof(int*)*input);
  for (int i = 0; i < input; i++)
  {
    m[i] = (int*) malloc(sizeof(int)*input);
  }
  for (int i = 0; i < input; i++)
  {
    for (int j = 0; j < input; j++)
    {
      scanf("%d",&m[i][j]);
    }
  }
  double det = 0;
  det = compute_det(m,input);
  printf("det = %f\n", det);
  for (int i = 0; i < input; i++)
  {
    free(m[i]);
  }
  free(m);
}
