#include <stdio.h>
#include <stdlib.h>


int f(int x)
{
 int sum;


 if(x == 0) {
 sum = 0; }

 if(x == 1) {
 sum = 1; }

 if(x > 1) {
 sum = f(x - 1) + f(x - 2); }

 return sum;

}

main()
 {
 int x, sum;

 printf("input x:");
 scanf("%d", &x);

 sum = f(x);

 printf("%d\n", sum);

 }
