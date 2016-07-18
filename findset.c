#include <stdio.h>
#include <stdlib.h>

#define N 5

void findset(int A[], int B[], int start, int end, int ii)
{

    int i;
    int C[end];

    for(i = 0; i < end; i++){
        C[i] = B[i];
    }

    if(start < end){
        if(start+1 == end){
            for(i = 0; i < ii; i++)
                printf("%d", C[i]);
            printf("\n");
        }
        findset(A, C, start+1, end, ii);


        C[ii] = A[start];
        if(start+1 == end){
            for(i = 0; i < ii + 1; i++)
                printf("%d", C[i]);
            printf("\n");
        }
        findset(A, C, start+1, end, ii + 1);
    }

}



int main()
{
    int A[N];
    int B[N];
    int i;
    for(i=0; i<N; i++){
        A[i] = i+1;
        B[i] = 0;
    }

    findset(A, B, 0, N, 0);
}
