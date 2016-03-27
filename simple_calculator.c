// The number that input must be -1<N<10.

#include <stdio.h>
#include <stdlib.h>

struct node {
  char how_to;
  int need;
  int right_child;
  struct node *left_child;
  struct node *parent;
};

struct node *head;
struct node *end_tmp;

int main()
{
    int ai, end_nu;
    char input[101];
    struct node *tmp;

    head = NULL;

    for(ai = 0; ai < 101; ai++)
        input[ai] = '\0';

    scanf("%s", input);

    end_nu = input[0] - '1';
    end_nu++;

    for(ai = 1; ai < 101; ai += 2)
        if(input[ai] != '\0'){
            tmp = (struct node *)malloc(sizeof(struct node));

            if(head == NULL){
                tmp->left_child = (struct node *)malloc(sizeof(struct node));
                head = tmp;
                end_tmp = tmp->left_child;
            }
            else{
                tmp->left_child = head;
                head = tmp;
            }

            tmp->right_child = input[ai + 1] - '1';
            tmp->right_child++;
            tmp->how_to = input[ai];
            tmp->left_child->parent = tmp;
        }

    head->parent = NULL;

    ai = -1;
    tmp = head;

    while(tmp == end_tmp) {
        ai++;
        tmp->need = ai;
        tmp = tmp->left_child;
    }

    tmp = end_tmp;

    while(tmp != head){
        printf("%d\n", end_nu);
        if(tmp->parent->how_to == '+')
            end_nu = end_nu + tmp->parent->right_child;
        if(tmp->parent->how_to == '-')
            end_nu = end_nu - tmp->parent->right_child;
        if(tmp->parent->how_to == '*')
            end_nu = end_nu * tmp->parent->right_child;
        if(tmp->parent->how_to == '/')
            end_nu = end_nu / tmp->parent->right_child;
        tmp = tmp->parent;
    }

    printf("%d\n", end_nu);
}
