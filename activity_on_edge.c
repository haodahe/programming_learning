#include <stdio.h>
#include <stdlib.h>

#define max 6

int cheak[max];

struct {
    char name[10];
    char introduction[50];
    int nu1;
    int nu2;
} point[max];

int main()
{
    int ia, ib, ic, distance, need_nu1, need_nu2, need_nu3, need_nu4, need_nu5;
    int chart[max][max];
    int chart2[max][max];
    int cheak_int[max];

    char need1[10];
    char need2[10];
    char need3[10] = "QUIT";

    for(ia = 0; ia < max; ia++)
        point[ia].nu1 = point[ia].nu2 = 0;

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

    for(ia = 0; ia < max; ia++)
        for(ib = 0; ib < max; ib++){
            need_nu3 = 0;
            for(ic = 0; ic < max; ic++)
                need_nu3 += chart[ic][ib];

            if(need_nu3 == 0 && cheak[ib] == 0){
                for(ic = 0; ic < max; ic++)
                    if((chart[ib][ic] + point[ib].nu1 > point[ic].nu1) && chart[ib][ic] != 0)
                        point[ic].nu1 = point[ib].nu1 + chart[ib][ic];

                for(ic = 0; ic < max; ic++)
                    chart[ib][ic] = 0;

                cheak_int[ia] = ib;

                cheak[ib] = 1;
                ib = -1;

                need_nu4 = ib;

                break;
            }
        }

    for(ia = 0; ia < max; ia++)
        for(ib = 0; ib < max; ib++)
            chart[ia][ib] = chart2[ia][ib];

    for(ia = 0; ia < max; ia++)
        point[ia].nu2 = point[max - 1].nu1;

    for(ia = max - 1; ia > 0; ia--){
        need_nu4 = cheak_int[ia];
        for(ic = 0; ic < max; ic++){
            need_nu5 = point[need_nu4].nu2 - chart[ic][need_nu4];
            if(need_nu5 < point[ic].nu2 && chart[ic][need_nu4] != 0){
                point[ic].nu2 = point[need_nu4].nu2 - chart[ic][need_nu4];
            }
        }
    }

    printf("\n");

    for(ia = 0; ia < max; ia++)
        if(point[ia].nu1 == point[ia].nu2)
            printf("%s  ", point[ia].name);

    printf("\n");

}
