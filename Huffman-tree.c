#include <stdio.h>
#include <stdlib.h>

struct node {
  int number;
  int need;
  struct node *parent;
  struct node *left_child;
  struct node *right_child;
};

void in_order(int main_ch[], int max, struct node *tmps[]){
    int i = 0;
    int ia, ib;
    struct node *tmp;

    while(1){
        if(i == max - 1)
            break;

        if(main_ch[i] > main_ch[i + 1]){
            ia = main_ch[i];
            main_ch[i] = main_ch[i + 1];
            main_ch[i + 1] = ia;

            tmp = tmps[i];
            tmps[i] = tmps[i + 1];
            tmps[i + 1] = tmp;

            if(i != 0)
                i--;
        }
        else
            i++;
    }
}

void prints(char A[], struct node *tmp, int ia, int max){
    int ii;

    if(max != 1){
        if(tmp->left_child == NULL){
            printf("%d   ", tmp->number);

            for(ii = 0; ii < max; ii++)
                if(A[ii] != '2')
                    printf("%c", A[ii]);

            printf("\n");
        }

        ia++;


        if(tmp->left_child != NULL){
            A[ia] = '0';
            prints(A, tmp->left_child, ia, max);
        }

        if(tmp->right_child != NULL){
            A[ia] = '1';
            prints(A, tmp->right_child, ia, max);
        }
    }
    else
        printf("%d   0\n", tmp->number);

}

void print_tree (struct node *A){
  int i;

  for(i = 0; i < A->need; i++)
    printf("=");

  printf("%d\n", A->number);

  if(A->left_child != NULL){
    A->left_child->need = A->need + 1;
    print_tree(A->left_child);
  }

  if(A->right_child != NULL){
    A->right_child->need = A->need + 1;
    print_tree(A->right_child);
  }

}

int main()
{
    int leng_ch, i;
    struct node *tmp;

    printf("input how many number you need:");
    scanf("%d", &leng_ch);

    if(leng_ch == -1)
        return(0);

    int main_ch[leng_ch];
    struct node *tmps[leng_ch];
    char print[leng_ch];

    for(i = 0; i < leng_ch; i++){
        printf("input the %dTH number:", i + 1);
        scanf("%d", &main_ch[i]);

        tmps[i] = (struct node *)malloc(sizeof(struct node));
        tmps[i]->left_child = tmps[i]->right_child = tmps[i]->parent = NULL;
        tmps[i]->number = main_ch[i];
    }

    if(leng_ch != 1)
        while(1){
            in_order(main_ch, leng_ch, tmps);

            if(main_ch[1] == 9999)
                break;

            tmp = (struct node *)malloc(sizeof(struct node));

            tmp->left_child = tmps[0];
            tmp->right_child = tmps[1];
            tmps[1] = NULL;
            tmps[0] = tmp;
            tmp->right_child->parent = tmp->left_child->parent = tmp;
            tmp->number = tmp->right_child->number + tmp->left_child->number;

            main_ch[0] = main_ch[0] + main_ch[1];
            main_ch[1] = 9999;
        }

    for(i = 0; i < leng_ch; i++)
        print[i] = '2';

    tmps[0]->need = 0;

    print_tree(tmps[0]);

    printf("======================================\n");

    prints(print, tmps[0], -1, leng_ch);
}
