// This is a AVL tree


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *head;

struct node {
  int number;
  int need;
  struct node *parent;
  struct node *left_child;
  struct node *right_child;
};

void left_left (struct node *A, int i){
  struct node *B;

  B = NULL;

  if(i == 0){
    A->left_child->parent = A->parent;
    A->parent->left_child = A->left_child;
  }
  if(i == 1){
    A->left_child->parent = NULL;
    head = A->left_child;
  }

  A->parent = A->left_child;

  B = A->parent->right_child;

  A->left_child->right_child = A;

  A->left_child = B;

  if(B != NULL)
    B->parent = A;

  if(B != NULL)
    B->parent = A;
}

void left_right (struct node *A, int i){
  struct node *B;
  struct node *C;

  B = NULL;
  C = A->left_child->right_child;

  C->parent = A;

  A->left_child->parent = A->left_child->right_child;
  B = A->left_child->right_child->left_child;
  A->left_child->right_child->left_child = A->left_child;
  A->left_child->right_child = B;
  A->left_child = C;

  if(B != NULL)
    B->parent = C->left_child;

  left_left(A, i);

}

void right_left (struct node *A, int i){
  struct node *B;
  struct node *C;

  B = NULL;
  C = A->right_child->left_child;

  C->parent = A;

  A->right_child->parent = A->right_child->left_child;
  B = A->right_child->left_child->right_child;
  A->right_child->left_child->right_child = A->right_child;
  A->right_child->left_child = B;
  A->right_child = C;

  if(B != NULL)
    B->parent = C->right_child;

  right_right(A, i);

}

void right_right (struct node *A, int i){
  struct node *B;

  B = NULL;

  if(i == 0){
    A->right_child->parent = A->parent;
    A->parent->right_child = A->right_child;
  }
  if(i == 1){
    A->right_child->parent = NULL;
    head = A->right_child;
  }

  A->parent = A->right_child;

  B = A->parent->left_child;

  A->right_child->left_child = A;

  A->right_child = B;

  if(B != NULL)
    B->parent = A;

  if(B != NULL)
    B->parent = A;

}

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

int find (struct node *A, int i){

  if(A == NULL)
    printf("NULL\n");

  if(A->need > i)
    i = A->need;

  if(A->left_child != NULL)
    i = find(A->left_child, i);

  if(A->right_child != NULL)
    i = find(A->right_child, i);

  return (i);

}

void for_need (struct node *A){

 // printf("for_need: %d\n", A->number);

  if(A->left_child != NULL){
    A->left_child->need = A->need + 1;
    for_need(A->left_child);
  }

  if(A->right_child != NULL){
    A->right_child->need = A->need + 1;
    for_need(A->right_child);
  }

}

int main()
{
    int a, b, c, left, right, test, test2, test3;
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
            tmp->parent = NULL;
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

        if(c == 1 || c == 2)
            tmp->parent = tmp2;

        test2 = 0;

        while(tmp != head){
            tmp = tmp->parent;

            left = tmp->need;
            right = tmp->need;

            test3 = tmp->need;

            if(tmp->left_child != NULL)
                left = find(tmp->left_child, 0);
            left = left - test3;
            if(tmp->right_child != NULL)
                right = find(tmp->right_child, 0);
            right = right - test3;

            left -= right;

            if(tmp != head)
                test = 0;
            else
                test = 1;

            if(left < -1){
                left = tmp->right_child->need;
                right = tmp->right_child->need;

                test3 = tmp->right_child->need;


                if(tmp->right_child->left_child != NULL)
                    left = find(tmp->right_child->left_child, 0);
                left = left - test3;
                if(tmp->right_child->right_child != NULL)
                    right = find(tmp->right_child->right_child, 0);
                right = right - test3;

                left -= right;

                if(left < 0)
                    right_right(tmp, test);
                else
                    right_left(tmp, test);


            }
            if(left > 1){
                left = tmp->left_child->need;
                right = tmp->left_child->need;

                test3 = tmp->left_child->need;

                if(tmp->left_child->left_child != NULL)
                    left = find(tmp->left_child->left_child, 0);
                left = left - test3;

                if(tmp->left_child->right_child != NULL)
                    right = find(tmp->left_child->right_child, 0);
                right = right - test3;

                left -= right;

                if(left < 0)
                    left_right(tmp, test);
                else
                    left_left(tmp, test);

            }

            head->need = 0;
            for_need(head);
            print_tree(head);

        }
    }

    print_tree(head);

}
