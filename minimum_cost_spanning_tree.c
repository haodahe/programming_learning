// This way made by Prim and Kruskal.

#include <stdio.h>
#include <stdlib.h>

#define max 6

int cheak[max];

struct {
    char name[10];
    char introduction[50];
} point[max];

int main()
{
    int ia, ib, ic, distance, need_nu1, need_nu2, need_nu3, big, nu1, nu2;
    int chart[max][max];
    int chart2[max][max];

    char need1[10];
    char need2[10];
    char need3[10] = "QUIT";

    need_nu3 = 2;

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

    for(ia = 0; ia < max; ia++)
        for(ib = 0; ib < max; ib++)
            chart2[ia][ib] = chart[ia][ib];

    for(ia = 0; ia < max; ia++){
        for(ib = 0; ib < max; ib++)
            printf("%d ", chart[ia][ib]);
        printf("\n");
    }
    printf("\n");

    big = 9999999;

    for(ia = 0; ia < max; ia++)
            for(ib = 0; ib < max; ib++)
                if(chart[ia][ib] != 0 && chart[ia][ib] < big){
                    big = chart[ia][ib];
                    nu1 = ia;
                    nu2 = ib;
                }

    printf("{%d, %d}\n", nu1, nu2);
    cheak[nu1] = cheak[nu2] = 1;
    chart[nu1][nu2] = chart[nu2][nu1] = 0;

    for(ic = 0; ic < 1; ic += 0){
        big = 9999999;
        for(ia = 0; ia < max; ia++)
            for(ib = 0; ib < max; ib++)
                if(chart2[ia][ib] != 0 && chart2[ia][ib] < big){
                    big = chart[ia][ib];
                    nu1 = ia;
                    nu2 = ib;
                }
        if((cheak[nu1] != 0 && cheak[nu2] == 0) || (cheak[nu1] == 0 && cheak[nu2] != 0)){
            printf("{%d, %d}\n", nu1, nu2);
            chart[nu1][nu2] = 0;
            cheak[nu1] = cheak[nu2] = 1;
            need_nu3++;

            for(ia = 0; ia < max; ia++)
                for(ib = 0; ib < max; ib++)
                    chart2[ia][ib] = chart[ia][ib];
        }
        else
            chart2[nu1][nu2] = chart2[nu2][nu1] = 0;

        if(need_nu3 == max)
            break;
    }

}
