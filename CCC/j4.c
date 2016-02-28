#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int i, j, k, time1, time2, time3, time4;
    int answer;
    char dont_need[5];
    char yes[2];
    int l;

    l = 0;

    scanf("%s", &dont_need);

    yes[0] = dont_need[0];
    yes[1] = dont_need[1];

    time1 = atoi(yes);

    yes[0] = dont_need[3];
    yes[1] = dont_need[4];

    time2 = atoi(yes);

    for(i = 0; i != 1; i += 0){
        if(time1 == 7 || time1 == 8 || time1 == 9 || time1 == 15 || time1 == 16 || time1 == 17 || time1 == 18)
            l++;
        else
            l += 2;

        time2 += 1;
        if(time2 == 60){
            time2 = 0;
            time1++;
        }

        if(l == 240)
            break;

    }

    if(time1 >= 24)
        time1 -= 24;


    if(time1 < 10)
        printf("0%d", time1);
    else
        printf("%d", time1);
    printf(":");

    if(time2 < 10)
        printf("0%d", time2);
    else
        printf("%d", time2);
        printf("\n");
}
