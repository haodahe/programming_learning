/*
Author: HAODA HE
Date: 2016/03/06
Description: create a link list, append, insert, delete, print, and quit
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int number;
  struct node *next;
};

int main()
{
    char firstchar;
    int firstnu, secondnu;
    struct node *tmp;
    struct node *head, *tail;
    struct node *p;
    struct node *dmp, *dmp2;
    struct node *imp, *imp2, *imp3;

    head = tail = dmp = NULL;

    while(1){
        scanf("%c", &firstchar);

        if(firstchar == 'Q')
            return 0;

        if(firstchar == 'I')
            scanf("%d", &secondnu);

        scanf("%d", &firstnu);

        if(firstchar == 'A'){
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->number = firstnu;
            tmp->next = NULL;

            if(head == NULL)
                head = tail = tmp;
            else {
                tail ->next = tmp;
                tail = tmp;
           }
        }
        if(firstchar == 'D'){
            dmp = dmp2 = head;

            while(dmp->number != firstnu){
                if(dmp->next == NULL)
                    break;
                dmp = dmp->next;
            }

            if(dmp->number == firstnu){
                if(head != dmp){
                    while(dmp2->next != dmp)
                        dmp2 = dmp2->next;
                    dmp2->next = dmp->next;
                }
                else
                    head = dmp->next;

                free(dmp);
            }
        }
        if(firstchar == 'I'){
            imp = head;
            imp2 = (struct node *)malloc(sizeof(struct node));

            if(head->number != firstnu){
                while(imp->next->number != firstnu)
                    imp = imp->next;

                imp3 = imp->next;
                imp->next = imp2;
                imp2->next = imp3;
                imp2->number = secondnu;
            }
            else{
                imp2->next = head;
                head = imp2;
                head->number = secondnu;
            }
        }
        if(firstchar == 'P'){
            p = head;

            while(p != NULL) {
                printf(" %d\n", p->number);
                p = p->next;
            }
        }
    }
}
