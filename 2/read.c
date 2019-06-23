#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "read.h"
double f(int i,int j);
double f(int i,int j)
{
    return fabs(i-j);
}
int read_matrix (const char* name, double* a,int n,int m)
{
    FILE*fp;
    int i,j;
    if(!(fp=fopen(name,"r")))
        return -1;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            if(fscanf(fp,"%lf",a+i*n+j)!=1)
            {
                fclose(fp);
                return -2;
            }
        }
    fclose(fp);
    return 0;
}
void init_matrix (double* a,int n,int m)
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        a[i*n+j]=f(i,j);

}
#define MAX_N 8
void print_matrix(double* a,int n,int m)
{
    int i,j;
    int n_max=(n>MAX_N?MAX_N:n);
    int m_max=(m>MAX_N?MAX_N:m);
    for(i=0;i<m_max;i++)
    {
        for(j=0;j<n_max;j++)
            printf("  %.2f",a[i*n+j]);
        printf("\n");
    }
}
void print_vector(double* a,int n)
{
    int i;
    for(i=0;i<n;i++)
      {
          printf("  %.2f",a[i]);
          printf("\n");
      }
}
