#include <stdio.h>
#include <stdlib.h>

int f(int x)
{
  int z;

  if(x == 0){
  z = ; }

  if(x == 1){
  z = ; }

  return z;

}
main()
{

  int a[200];
  int b[200];
  int c[200];
  int h, e, f, i;

  e = 0;

  while (e == 0) {
    printf("input the number of layer:");
    scanf("%d", &h);
    i = h;
    f = 0;

    if(h > 0){
      while(h > 1 && f < h){
        a[f] = h;
        f++;
        h--;
      }
      e = 1;











/*
      printf("|\n");
      printf("|");
	for(f = 0; f < i ; f++){
	  printf("%d ", a[f]);
	}

      printf("\n");
      printf("|\n");


      printf("\n");
      printf("|\n");
*/



    }

    else{


     if(h != -1)
      printf("your number is not correct.\n");
     else
      e = 1;
    }
  }
}
