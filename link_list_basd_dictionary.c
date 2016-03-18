#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char english[20];
  char chinese[80];
  struct node *next;
};

struct node *first_letter[26];

int main()
{
    int ai, bi, ci, need;
    struct node *tmp;
    char str[20];
    char str2[80];
    char str3[100];
    char firstch;
    char imput[20];

    for(ai = 0; ai < 26; ai++)
        first_letter[ai] = NULL;

    FILE *fp;

    fp = fopen("main.txt", "r");

    while(fgets(str3, sizeof(str3), fp)){
  //      printf("%s\n", str3);

        for(ai = 0; ai < 20; ai++)
            str[ai] = '\0';

        for(ai = 0; ai < 80; ai++)
            str2[ai] = '\0';

        ai = 0;

        while(str3[ai] != ' '){
            str[ai] = str3[ai];
            ai++;
        }

        ai ++;
        bi = 0;

        for(ci = 0; ci != 1; ci += 0)
            if(str3[ai] != '\0'){
                str2[bi] = str3[ai];
                ai++;
                bi++;
            }
            else
                break;

        firstch = str[0];
        need = firstch - 'a';

        tmp = (struct node *)malloc(sizeof(struct node));

        strcpy(tmp->chinese, str2);
        strcpy(tmp->english, str);

        if(first_letter[need] == NULL)
            tmp->next = NULL;
        else
            tmp->next = first_letter[need];

        first_letter[need] = tmp;

     //   printf("%s  %s\n",tmp->english, tmp->chinese);
    }
/*
    for(ai = 0; ai < 26; ai++){
        tmp = first_letter[ai];
        while(tmp->next != NULL){
            printf("%s  ", tmp->english);
            tmp = tmp->next;
        }
        printf("\n");
    }
*/
    printf("imput: ");
    scanf("%s", imput);

    need = imput[0] - 'a';

    tmp = first_letter[need];

    while(1){
        if(strcmp(tmp->english, imput) == 0 || tmp->next == NULL)
            break;
        else
            tmp = tmp->next;
    }

    if(strcmp(tmp->english, imput) == 0)
        printf("%s\n", tmp->chinese);
    else
        printf("The word you input is not in the dictionary.\n");

    fclose(fp);

    return(0);
}
