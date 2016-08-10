#include <stdio.h>
#include <stdlib.h>

#define max 5

int cheak[max];

struct {
    char name[10];
    char introduction[50];
} point[max];

int main()
{
    int ia, ib, ic, distance, need_nu1, need_nu2, need_nu3;
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
        for(ib = 0; ib < max; ib++){
            need_nu3 = 0;
            for(ic = 0; ic < max; ic++)
                need_nu3 += chart[ic][ib];

            if(need_nu3 == 0 && cheak[ib] == 0){
                printf("%d  ", ib);

                for(ic = 0; ic < max; ic++)
                    chart[ib][ic] = 0;

                cheak[ib] = 1;
                ib = -1;
            }
        }

    printf("\n");

}
