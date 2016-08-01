#include <stdio.h>
#include <stdlib.h>

#define max 8

int cheak[max];

struct {
    char name[10];
    char introduction[50];
} point[max];

void bfs(int A[][max], int B[], int C[], int the_point, int number){
    int ia, ib;

    printf("%s ", point[the_point].name);
/*
    for(ib = 0; ib < max; ib++)
        printf("%d ", B[ib]);
    printf("     ");

    for(ib = 0; ib < max; ib++)
        printf("%d ", C[ib]);
    printf("     ");
*/
    B[the_point] = 1;

    for(ia = 0; ia < max; ia++)
        if(A[the_point][ia] != 0 && B[ia] == 0){
            C[number] = ia;
            B[ia] = 1;
            number++;
        }
/*
    for(ib = 0; ib < max; ib++)
        printf("%d ", C[ib]);
    printf("\n");
*/
    if(C[0] != 0){
        the_point = C[0];
        number--;

        for(ia = 0; ia < max - 1; ia++)
            C[ia] = C[ia + 1];

        C[max - 1] = 0;

        bfs(A, B, C, the_point, number);
    }
}

int main()
{
    int ia, ib, distance, need_nu1, need_nu2;
    int chart[max][max];
    int line_up[max];

    char need1[10];
    char need2[10];
    char need3[10] = "QUIT";

    for(ia = 0; ia < max; ia++)
        for(ib = 0; ib < max; ib++)
            chart[ia][ib] = 0;

    for(ia = 0; ia < max; ia++)
        cheak[ia] = line_up[ia] = 0;

    for(ia = 0; ia < max; ia++){
        printf("input the points(name introduction):");
        scanf("%s", point[ia].name);
        gets(point[ia].introduction);
    }

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

    bfs(chart, cheak, line_up, 0, 0);
}
