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
    double t,res;
    const char* name=0;
    if(!(argc==3)||n=atoi(argv[1])<=0||m=atoi(argv[2]))
    {
        printf("Usage %s n <file>\n",argv[0]);
        return 1;
    }
    if(argc==4)
        name=argv[3];
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
    if(name)
    {
        int ret;
        ret=read_matrix(name,a,n,n);
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

    } else init_matrix(a,n,n);
    printf("MATRIX A:\n");
    print_matrix(a,n,n);
    printf("VECTOR x0:\n");
    init_matrix(x0,n,1);
    print_vector(x0,n);
    t=clock();
    res=solve(a,x0,n,m);
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf("OTVET:%.2f\n",res);
    printf("Elapse time=%.2f\n",t);
    free(a);
    free(x0);
    return 0;
}
