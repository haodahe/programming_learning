#include <stdio.h>
#include <stdlib.h>

int main()
{
    int days, i;

    scanf("%d", &days);

    int first_max, second_max;

    int first_chart[days];
    int second_chart[days];

    for(i = 0; i < days; i ++){
        scanf("%d", &first_chart[i]);
    }

    for(i = 0; i < days; i ++){
        scanf("%d", &second_chart[i]);
    }

    int answer = 0;
    first_max = second_max = 0;

    for(i = 0; i < days; i ++){
        first_max += first_chart[i];
        second_max += second_chart[i];

        if(first_max == second_max)
            answer = i + 1;
    }

    printf("%d", answer);

}
