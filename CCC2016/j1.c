#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int i, k;
    int answer;
    char j;

    k = 0;

    for(i = 0; i < 12; i += 1){
     //   printf("%d ", i);
        scanf("%c", &j);
        if(j == 'W')
            k++;
    }

    if(k == 5 || k == 6)
        printf("1\n");
    if(k == 3 || k == 4)
        printf("2\n");
    if(k == 1 || k == 2)
        printf("3\n");
    if(k == 0)
        printf("-1\n");

}
