#include <stdio.h>
#include <stdlib.h>
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
    if(!(xk=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    for (i=1;i<=m;i++)
    {
         x_k(a,x0,xk,n,n);
          for(j=0;j<n;j++)
             x0[j]=xk[j];

    }
    x_k(a,xk,x0,n,n);
     for(j=0;j<n;j++)
         {
            s=s+xk[j]*xk[j];
            t=t+x0[j]*xk[j];
         }
    free(xk);
    res=t/s;
return (res);
}
