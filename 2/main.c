#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "read.h"
#include "solve.h"
int main(int argc, char** argv)
{
    int n,m;
    double* a;
    double* x0;
    double* x;
    double* b;
    double t,p;
    const char* name=0;
    if(!(argc==4)||n=atoi(argv[1])<=0||m=atoi(argv[2]))
    {
        printf("Usage %s n <file>\n",argv[0]);
        return 1;
    }
    if(argc==5)
        name=argv[4];
    if(!(a=(double*)malloc(n*n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(x0=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(b=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(x=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(name)
    {
        int ret;
        ret=read_matrix(name,a,n);
        if(ret<0)
        {
            switch(ret)
            {
                case -1: printf("Cannot open %s\n",name); break;
                case -2: printf("Cannot read %s\n",name);break;
                default: printf("Unknown error %d in %s\n",ret,name);
            }
            free(a);
            return 3;
        }

    } else init_matrix(a,n);
    t=atoi(argv[3]);
    printf("MATRIX A:\n");
    print_matrix(a,n);
    printf("VECTOR x0:\n");
    init_matrix(x0,n);
    print_vector(x0,n);
    printf("VECTOR b:\n");
    init_matrix(b,n);
    print_vector(b,n);
    p=clock();
    solve(a,x0,b,x,n,m,t);
    p=(clock()-p)/CLOCKS_PER_SEC;
    printf("VECTOR x:\n");
    print_vector(x,n);
    printf("Elapse time=%.2f\n",p);
    free(a);
    free(x0);
    free(b);
    return 0;
}
