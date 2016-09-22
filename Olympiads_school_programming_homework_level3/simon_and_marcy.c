/*
Haoda He 2016/9/21
Simon and Marcy
https://dmoj.ca/problem/valday15p2
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
int ia, ib;
int first_nu, second_nu;

scanf("%d", &first_nu);
scanf("%d", &second_nu);

int chart[first_nu][second_nu];
int chart2[first_nu][2];

for(ia = 0; ia < first_nu; ia++)
    for(ib = 0; ib < second_nu; ib++)
        chart[ia][ib] = 0;

for(ia = 0; ia < first_nu; ia++){
    scanf("%d", &chart2[ia][0]);
    scanf("%d", &chart2[ia][1]);
}

for(ia = 0; ia < first_nu; ia++){
    for(ib = 0; ib < second_nu; ib++)
        if(ib + 1 >= chart2[ia][1]){
            if(ia == 0)
                chart[ia][ib] = chart2[ia][0];
            else
                if(ib - chart2[ia][1] > 0){
                    if(chart[ia - 1][ib - chart2[ia][1]] + chart2[ia][0] > chart[ia - 1][ib])
                        chart[ia][ib] = chart[ia - 1][ib - chart2[ia][1]] + chart2[ia][0];
                    else
                        chart[ia][ib] = chart[ia - 1][ib];
                }
                else
                    if(chart2[ia][0] > chart[ia - 1][ib])
                        chart[ia][ib] = chart2[ia][0];
                    else
                        chart[ia][ib] = chart[ia - 1][ib];
        }
        else
            if(ia != 0)
                chart[ia][ib] = chart[ia - 1][ib];
}
/*
for(ia = 0; ia < first_nu; ia++){
    for(ib = 0; ib < second_nu; ib++)
        printf(" %d", chart[ia][ib]);
    printf("\n");
}
*/

printf("%d", chart[first_nu - 1][second_nu - 1]);
}
