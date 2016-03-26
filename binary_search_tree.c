#include <stdio.h>
#include <stdlib.h>

struct node {
  int number;
  int need;
  struct node *left_child;
  struct node *right_child;
};

void print_tree (struct node *A){

  int i;

  for(i = 0; i < A->need; i++)
    printf("=");

  printf("%d\n", A->number);

  if(A->left_child != NULL)
    print_tree(A->left_child);

  if(A->right_child != NULL)
    print_tree(A->right_child);

}

struct node *head;

int main()
{
    int a, b, c;
    struct node *tmp, *tmp2;

    head = NULL;

    a = 0;

    while (1) {
        a++;
        printf("input #%d number:", a);
        scanf("%d", &b);

        if(b == -1)
            break;

        tmp = (struct node *)malloc(sizeof(struct node));

        tmp->left_child = NULL;
        tmp->right_child = NULL;

        tmp->number = b;

        tmp2 = head;

        c = 0;

        tmp->need = 1;

        if(a == 1){
            head = tmp;
            head->need = 0;
        }
        else{
            while (1){
                if(tmp2->number > b)
                    if(tmp2->left_child == NULL){
                        c = 1;
                        break;
                    }
                    else{
                        tmp2 = tmp2->left_child;
                        tmp->need++;
                    }
                if(tmp2->number < b)
                    if(tmp2->right_child == NULL){
                        c = 2;
                        break;
                    }
                    else{
                        tmp2 = tmp2->right_child;
                        tmp->need++;
                    }
                if(tmp2->number == b)
                    break;
            }
        }

        if(c == 1)
            tmp2->left_child = tmp;

        if(c == 2)
            tmp2->right_child = tmp;
    }

    printf("input the number you want to find:");
    scanf("%d", &b);

    c = 0;

    tmp2 = head;

    while (1){
        if(tmp2->number > b)
            if(tmp2->left_child == NULL)
                break;
            else
                tmp2 = tmp2->left_child;
        if(tmp2->number < b)
            if(tmp2->right_child == NULL)
                break;
            else
                tmp2 = tmp2->right_child;
        if(tmp2->number == b){
            c = 1;
            break;
        }
    }

    if(c == 1)
        printf("Yes\n");
    else
        printf("NO\n");

    print_tree(head);

}
