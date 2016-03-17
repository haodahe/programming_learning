#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

struct node {

    char name[10];
    struct node *next;
};

struct node *pointer[N];

int main()
{
    int i, key;
    char firstch;
    struct node *t, *p, *dmp, *dmp2, *imp, *imp2;
    char name[10];
    char secname[10];
    for(i=0; i<N; i++)
        pointer[i] = NULL;

    while(1){
        scanf("%s", name);
        scanf("%d ", &key);
        scanf("%c", &firstch);

        if(firstch == 'I')
            scanf("%s", secname);

     //   printf("%s\n", secname);


        if(strcmp(name, "quit") == 0 && key == -1 && firstch == 'Q') {
            for(i=0; i<N; i++)
            {
                if(pointer[i]!=NULL){
                    p = pointer[i];
                    while(p!=NULL){
                        printf("%s ", p->name);
                        p = p->next;
                    }
                    printf("\n");
                }
            }
            break;
        }

        if(firstch == 'A'){
            t = (struct node *)malloc(sizeof(struct node));
            strcpy(t->name, name);
            t->next = NULL;

            if(pointer[key] == NULL){
                    pointer[key] = t;
            }
            else{
                p = pointer[key];
                while(p->next != NULL)
                    p = p->next;

                p->next = t;
            }
        }

        if(firstch == 'D'){
            dmp = dmp2 = pointer[key];

            while(1) {
                if(strcmp(dmp->name, name) != 0)
                    dmp = dmp->next;
                else
                    break;
            }

            if(dmp->name != pointer[key]->name){
                while(1) {
                    if(dmp2->next->name != dmp)
                        dmp2 = dmp2->next;
                    else
                        break;
                }

                dmp2->next = dmp->next;
            }
            else{
                pointer[key] = dmp->next;
            }
            free(dmp);
        }

        if(firstch == 'I'){
            t = (struct node *)malloc(sizeof(struct node));
            strcpy(t->name, name);

            imp = imp2 = pointer[key];

            while(1) {
                if(strcmp(imp->name, secname) != 0)
                    imp = imp->next;
                else
                    break;
            }

            if(imp->name != pointer[key]->name){
                while(1) {
                    if(imp2->next->name != imp)
                        imp2 = imp2->next;
                    else
                        break;
                }

                imp2->next = t;
            }
            else
                pointer[key] = t;

            t->next = imp;
        }
    }
}
