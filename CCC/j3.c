#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int find(char A[], int B, int C){
    int i, j, k;

    i = C - B;

    for(i -= 1; i >= 0; i--)
        if(A[B + i] != A[C - i]){
            return 1;
        }

    return 0;
}

int main()
{
    int i, j, k, main_nu, last;
    char answer[40];

    last = 0;

    scanf("%s", answer);
    main_nu = strlen(answer);

    for(i = 0; i < main_nu; i++)
        for(j = main_nu - 1; j >= i; j--){
      //      printf("%d %c     %d %c\n", i, answer[i], j, answer[j]);
            if(answer[i] == answer[j]){
                k = find(answer, i, j);
                if(k == 0 && last - 1 < j - i){
                    last = j - i;
                    last++;
                }
            }
        }
        printf("%d \n", last);

}
