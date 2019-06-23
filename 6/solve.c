#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "solve.h"
void x_k(double* a,double* b,double* c,int n,int m)
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
double solve(double* a,double* x0,int n,int m)
{
    int i,j;
    double res,s=0,t=0;
    double* xk;
    double* at;
    xk=(double*)malloc(n*sizeof(double));
    at=(double*)malloc(n*n*sizeof(double));
    for(j=0;j<n;j++)
          xk[j]=x0[j];
    for (i=0;i<n;i++)
    {
      for(j=i;j<n;j++)
      {
          at[i*n+j]=a[j*n+i];
          at[j*n+i]=a[i*n+j];

      }
    }
    for (i=1;i<=m;i++)
    {
         x_k(a,xk,x0,n,n);
         x_k(at,x0,xk,n,n);


    }

    x_k(a,xk,x0,n,n);
    x_k(at,x0,a,n,n);
     for(j=0;j<n;j++)
         {
            s+=xk[j]*xk[j];
            t+=a[j]*xk[j];
         }
    free(xk);
    free(at);
    res=t/s;
return (res);
}
