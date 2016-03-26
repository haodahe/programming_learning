#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char english[20];
  char chinese[80];
  struct node *left_child;
  struct node *right_child;
};

struct node *head;

int main()
{
    int a, b, c, ai, bi, ci;
    struct node *tmp, *tmp2;
    char str[20];
    char str2[80];
    char input[100];

    FILE *fp;

    fp = fopen("main.txt", "r");

    head = NULL;

    a = 0;

    while(fgets(input, sizeof(input), fp)){
        a++;

        for(ai = 0; ai < 20; ai++)
            str[ai] = '\0';

        for(ai = 0; ai < 80; ai++)
            str2[ai] = '\0';

        ai = 0;
        while(input[ai] != ' '){
            str[ai] = input[ai];
            ai++;
        }

        ai ++;
        bi = 0;

        for(ci = 0; ci != 1; ci += 0)
            if(input[ai] != '\0'){
                str2[bi] = input[ai];
                ai++;
                bi++;
            }
            else
                break;

        tmp = (struct node *)malloc(sizeof(struct node));

        tmp->left_child = NULL;
        tmp->right_child = NULL;

        strcpy(tmp->chinese, str2);
        strcpy(tmp->english, str);

        tmp2 = head;

        c = 0;

        if(a == 1)
            head = tmp;
        else
            while (1){
                if(strcmp(tmp2->english, input) > 0)
                    if(tmp2->left_child == NULL){
                        c = 1;
                        break;
                    }
                    else
                        tmp2 = tmp2->left_child;
                if(strcmp(tmp2->english, input) < 0)
                    if(tmp2->right_child == NULL){
                        c = 2;
                        break;
                    }
                    else
                        tmp2 = tmp2->right_child;
                if(strcmp(tmp2->english, input) == 0)
                    break;
            }

        if(c == 1)
            tmp2->left_child = tmp;

        if(c == 2)
            tmp2->right_child = tmp;

    }

    printf("input the word you want to find: ");
    scanf("%s", input);

    c = 0;

    tmp2 = head;

    while (1){
        if(strcmp(tmp2->english, input) > 0)
            if(tmp2->left_child == NULL)
                break;
            else
                tmp2 = tmp2->left_child;
        if(strcmp(tmp2->english, input) < 0)
            if(tmp2->right_child == NULL)
                break;
            else
                tmp2 = tmp2->right_child;
        if(strcmp(tmp2->english, input) == 0){
            c = 1;
            break;
        }
    }

    if(c == 1)
        printf("%s:%s", input, tmp2->chinese);
    else
        printf("It's not in the dictionary.\n");

    fclose(fp);

}
