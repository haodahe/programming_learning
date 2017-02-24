#include <stdio.h>
#include <stdlib.h>

void in_order(int max_number, int chart[]){
    int i, j, number;

    for(i = 0; i < max_number - 1; i ++){
/*
        for(j = 0; j < max_number; j ++){
            printf("%d-", chart[j]);
        }
        printf("\n");
*/
        if(chart[i] > chart[i + 1]){
            number = chart[i];
            chart[i] = chart[i + 1];
            chart[i + 1] = number;

            if(i != 0)
                i = i - 2;
        }
    }
}

int main()
{
    int max_number, i, low, max;

    scanf("%d", &max_number);

    int chart[max_number];

    for(i = 0; i < max_number; i ++){
        scanf("%d", &chart[i]);
    }

    if(max_number <= 1)
        printf("%d", chart[0]);
    else{
        in_order(max_number, chart);

        if(max_number % 2 == 0){
            low = (max_number / 2) - 1;
            max = max_number / 2;
        }
        else{
            low = max_number / 2;
            max = (max_number / 2) + 1;
        }

        for(i = 0; i < (max_number / 2) + 1; i ++){
            if(low >= 0)
                printf("%d ", chart[low]);
            if(max < max_number)
                printf("%d ", chart[max]);

            //printf("%d %d ", chart[low], chart[max]);
            low--;
            max++;
        }
    }
}
