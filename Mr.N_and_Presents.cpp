#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max_number, ia, ib, number, count, count2;
    char input;
    const int MAX = 100000;

    scanf("%d", &max_number);

    int chart[MAX];
    int chart2[MAX];

    for(ia = 0; ia < MAX; ia ++)
        chart[ia] = chart2[ia] = -1;

    count = count2 = 0;

    for(ia = 0; ia < max_number; ia ++){
        scanf(" %c", &input);

        if(input == 'F'){
            scanf("%d", &chart2[count2 ++]);
        }
        if(input == 'E'){
            scanf("%d", &chart[count ++]);
        }
        if(input == 'R'){
            scanf("%d", &number);

            for(ib = 0; ib < count; ib ++)
                if(chart[ib] == number){
                    chart[ib] = -1;
                    break;
                }
            for(ib = 0; ib < count2; ib ++)
                if(chart2[ib] == number){
                    chart2[ib] = -1;
                    break;
                }

        }
    }
    for(ia = count2; ia >= 0; ia --)
        if(chart2[ia] != -1)
            printf("%d\n", chart2[ia]);

    for(ia = 0; ia < count; ia ++)
        if(chart[ia] != -1)
            printf("%d\n", chart[ia]);

}
