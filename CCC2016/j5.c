#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int i, j, k, l, m;

    m = 0;

    scanf("%d", &i);
    scanf("%d", &j);

    int answer1[j];
    int answer2[j];

    for(k = 0; k < j; k++)
        scanf("%d", &answer1[k]);

    for(k = 0; k < j; k++)
        scanf("%d", &answer2[k]);

    if(i == 1){
        for(k = 1; k < j; k++)
            if(answer1[k] < answer1[k - 1]){
                l = answer1[k];
                answer1[k] = answer1[k - 1];
                answer1[k - 1] = l;
                if(k != 1)
                    k -= 2;
            }
        for(k = 1; k < j; k++)
            if(answer2[k] < answer2[k - 1]){
                l = answer2[k];
                answer2[k] = answer2[k - 1];
                answer2[k - 1] = l;
                if(k != 1)
                    k -= 2;
            }
        for(k = 0; k < j; k++){
            if(answer1[k] > answer2[k])
                m += answer1[k];
            else
                m += answer2[k];
        }
    }
    else{
        for(k = 1; k < j; k++)
            if(answer1[k] < answer1[k - 1]){
                l = answer1[k];
                answer1[k] = answer1[k - 1];
                answer1[k - 1] = l;
                if(k != 1)
                    k -= 2;
            }
        for(k = 1; k < j; k++)
            if(answer2[k] > answer2[k - 1]){
                l = answer2[k];
                answer2[k] = answer2[k - 1];
                answer2[k - 1] = l;
                if(k != 1)
                    k -= 2;
            }
        for(k = 0; k < j; k++){
            if(answer1[k] > answer2[k])
                m += answer1[k];
            else
                m += answer2[k];
        }
    }

        printf("%d \n", m);

}
