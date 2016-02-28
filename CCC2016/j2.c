#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int i, j, k, l;
    int answer[4][4];

    k = 0;

    for(j = 0; j < 4; j++)
        for(i = 0; i < 4; i++){
           // printf("%d ", i);
            scanf("%d", &answer[j][i]);
        }
/*
    for(j = 0; j < 4; j++){
        for(i = 0; i < 4; i++)
            printf("%d ", answer[j][i]);
        printf("\n");
    }
*/
    l = answer[0][0] + answer[1][0] + answer[2][0] + answer[3][0];

  //  printf("%d\n", l);

    for(i = 0; i < 4; i++)
        if(answer[i][0] + answer[i][1] + answer[i][2] + answer[i][3] != l)
            k = 1;

    for(i = 0; i < 4; i++)
        if(answer[0][i] + answer[1][i] + answer[2][i] + answer[3][i] != l)
            k = 1;

  //  if(answer[0][0] + answer[1][0] + answer[2][0] + answer[3][0] != answer[0][0] + answer[0][1] + answer[0][2] + answer[0][3])
    //    k = 1;

    if(k > 0){
        printf("not magic\n");
    }
    else{
        printf("magic\n");
    }
}
