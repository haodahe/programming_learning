#include <stdio.h>
#include <stdlib.h>

main ()
{

 int number, aa, ab, ac, ad, ae, af, ag;

 printf("imput 7 numbers:");
 scanf("%d", &aa);
 scanf("%d", &ab);
 scanf("%d", &ac);
 scanf("%d", &ad);
 scanf("%d", &ae);
 scanf("%d", &af);
 scanf("%d", &ag);

 for(number = 0; number < aa + 1 ||number < ab + 1 ||number < ac + 1 ||number < ad + 1 ||number < ae + 1 ||number < af + 1 ||number < ag + 1; number++){

 if(number == aa)
   printf("%d, ", aa);

 if(number == ab)
   printf("%d, ", ab);

 if(number == ac)
   printf("%d, ", ac);

 if(number == ad)
   printf("%d, ", ad);

 if(number == ae)
   printf("%d, ", ae);

 if(number == af)
   printf("%d, ", af);

 if(number == ag)
   printf("%d, ", ag);

 }

 printf("\n");

}
