#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "solve.h"
void mult(double* a,double* b,double* c,int n,int m)
{
    int i,j,p;
    double sum=0;
    for (i=0;i<m;i++)
    {
       p=i*n;
       for(j=0;j<n;j++)
          sum=sum+a[p+j]*b[j];
       c[i]=sum;
       sum=0;
    }
}
void x_k(double* a,double* b,double* x0,double* xk,int n,double* d)
{
    int i;
    mult(a,x0,xk,n,n);

    for (i=0;i<n;i++)
    {
        xk[i]=(b[i]-xk[i])/d[i];

    }

}
void solve(double* a,double* x0,double* b,double* x,int n,int m,double t)
{
    int i,j;
    double* xk;
    double* d;
    xk=(double*)malloc(n*sizeof(double));
    d=(double*)malloc(n*sizeof(double));
    for(i=0;i<n;i++)
        d[i]=a[i*n+i];
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
         a[i*n+j]=t*a[i*n+j];
    for(i=0;i<n;i++)
        {
            b[i]=t*b[i];
            a[i*n+i]=a[i*n+i]-d[i];
        }
    for (i=1;i<=m;i++)
    {
         x_k(a,b,x0,xk,n,d);
          for(j=0;j<n;j++)
             x0[j]=xk[j];

    }
    for(j=0;j<n;j++)
        x[j]=xk[j];
    free(xk);
    free(d);

}
