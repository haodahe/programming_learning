#include <stdio.h>
#include <stdlib.h>

#define max 13

int cheak[max];

struct {
    char name[10];
    char introduction[50];
} point[max];

void dfs(int A[][max], int B[],  int maxb, int the_point){
    int ii, iii;

    printf("%d ", the_point + 1);
    B[the_point] = 1;

    for(ii = 0; ii < maxb; ii++)
        if(A[the_point][ii] != 0 && B[ii] == 0)
/*
            for(iii = 0; iii < maxb; iii++)
                printf("%d ", B[iii]);
            printf("\n");
*/
            dfs(A, B, maxb, ii);


}

int main()
{
    int ia, ib, distance, need_nu1, need_nu2;
    int chart[max][max];

    char need1[10];
    char need2[10];
    char need3[10] = "QUIT";

    for(ia = 0; ia < max; ia++)
        for(ib = 0; ib < max; ib++)
            chart[ia][ib] = 0;

    for(ia = 0; ia < max; ia++)
        cheak[ia] = 0;

    for(ia = 0; ia < max; ia++){
        printf("input the points(name introduction):");
        scanf("%s", point[ia].name);
        gets(point[ia].introduction);
    }

/*
    for(ia = 0; ia < max; ia++)
        printf("%s , %s\n", point[ia].name, point[ia].introduction);
*/

    for(ia = 0; ia < max; ia += 0){
        printf("input line(name1 name2 distance)('QUIT QUIT 0' for quit):");
        scanf("%s %s %d", need1, need2, &distance);

        if(strcmp(need1, need2) == 0 && strcmp(need1, need3) == 0 && distance == 0)
            break;

        for(ib = 0; ib < max; ib++)
            if(strcmp(need1, point[ib].name) == 0)
                need_nu1 = ib;

        for(ib = 0; ib < max; ib++)
            if(strcmp(need2, point[ib].name) == 0)
                need_nu2 = ib;

        chart[need_nu1][need_nu2] = distance;
    }

    for(ia = 0; ia < max; ia++){
        for(ib = 0; ib < max; ib++)
            printf("%d ", chart[ia][ib]);
        printf("\n");
    }
    printf("\n");

    for(ia = 0; ia < max; ia++)
        if(cheak[ia] != 1){
            dfs(chart, cheak, max, ia);
            printf("\n");
        }

}
