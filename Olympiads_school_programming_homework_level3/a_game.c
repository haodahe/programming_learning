#include <stdio.h>
#include <stdlib.h>

int main()
{
    long ia, ib, ic;
    long first_nu, second_nu;

    scanf("%ld", &first_nu);
    scanf("%ld", &second_nu);

    first_nu++;
    second_nu++;

    long chart[2][second_nu];
    long chart2[first_nu][6];

    for(ia = 0; ia < 2; ia++)
        for(ib = 0; ib < second_nu; ib++)
            chart[ia][ib] = 0;

    for(ia = 0; ia < first_nu; ia++)
        for(ib = 0; ib < 6; ib++)
            chart2[ia][ib] = 0;

    for(ia = 1; ia < first_nu; ia++)
        for(ib = 0; ib < 6; ib++)
            scanf("%ld", &chart2[ia][ib]);
/*
    for(ia = 1; ia < first_nu; ia++){
        for(ib = 0; ib < 6; ib++)
            printf("%d ", chart2[ia][ib]);
        printf("\n");
    }
*/
    for(ia = 1; ia < first_nu; ia++){

        for(ic = 0; ic < second_nu; ic++)
            chart[0][ic] = chart[1][ic];

        for(ib = 0; ib < 5; ib += 2)
            for(ic = 1; ic < second_nu; ic++){
   //             printf("%d %d %d %d %d %d\n", ic, chart2[ia][ib], chart[ia][ic], chart2[ia][ib + 1] + chart[ia][ic - chart2[ia][ib]], chart[ia - 1][ic], chart2[ia][ib + 1] + chart[ia][ic - chart2[ia][ib]]);
                if(ic >= chart2[ia][ib]){
                    if(chart[1][ic] < chart2[ia][ib + 1] + chart[0][ic - chart2[ia][ib]] && chart[0][ic] < chart2[ia][ib + 1] + chart[0][ic - chart2[ia][ib]]){
                        chart[1][ic] = chart2[ia][ib + 1] + chart[0][ic - chart2[ia][ib]];
                    }
                    else{
                        if(chart[1][ic] < chart[0][ic])
                        chart[1][ic] = chart[0][ic];
                    }
                }
            }
    }

    for(ia = 0; ia < 2; ia++){
        for(ib = 0; ib < second_nu; ib++)
            printf(" %d", chart[ia][ib]);
        printf("\n");
    }


printf("%ld", chart[1][second_nu - 1]);

}
