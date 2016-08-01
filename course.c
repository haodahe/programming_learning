#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define entries 4
#define teacher1 4
#define subject1 5
#define class1 10

struct {
 char name[10];
 char  studentnumber[8];
 char sex[2];   /* M : male   F : female */
 char classnumber[2];
} student[entries];

struct {
 char name[10];
 char teachernumber[8];
 char sex[2];
} teacher[teacher1];

struct {
 char name[10];
 char subjectnumber[2];
 int  credit;
 char time[5];
} subject[subject1];

struct {
 char studentnumber[8];
 char subjectnumber[2];
 int  mark;
} mark[entries];

struct {
 char classnumber[2];
 char name[4];
 char teachernumber[8];
} class[class1];

struct {
 char teachernumber[8];
 char subjectnumber[2];
 char classnumber[2];
} instructor[subject1];

main ()
{

 int a, b, ac, bc, bbc, c, d, ad, bd, cd, dd, ed, e, f, ag, g, h, ai, bi, ci, di, ei, fi, i, j, k, l, teacher2;
 char ah[8];
 char bh[2];

 b = 0;
 d = 0;
 i = 0;
 g = -1;
 ad = 0;
 bd = 0;
 cd = 0;
 dd = 0;
 ed = 0;
 h = 1;
 ai = 0;
 bi = 0;
 ci = 0;
 di = 0;
 ei = 0;
 fi = 0;
 ag = 0;
 teacher2 = 0;

 ah[1] = '1';

 for(a = 0; a < subject1; a++){
   printf("input the %dth subject :[name number credit]", a + 1);
   scanf("%s %s %d", subject[a].name, subject[a].subjectnumber, &subject[a].credit);}

   printf("|name      |number|credit|\n");
   for(a = 0; a < subject1; a++){
     printf("%10s      %2s      %d\n", subject[a].name, subject[a].subjectnumber, subject[a].credit);
   }

 while(b != 4)
{

 b = 0;
 ac = 0;
 c = 0;
 bc = 0;
 g = 0;

   printf("--------------------------------------------------------\n");
   printf("\n");
   printf("             student       : 1\n");
   printf("             teacher       : 2\n");
   printf("             administrator : 3\n");
   printf("             QUIT          : 4\n");
   printf("\n");
   printf("--------------------------------------------------------\n");

   printf("input number:");
   scanf("%d", &b);

   if(b == 3){
     printf("--------------------------------------------------------\n");
     printf("\n");
     printf(" 1. enter class table\n");
     printf(" 2. enter teachers' table\n");
     printf(" 3. enter student's class\n");
     printf(" 4. enter the time of class\n");
     printf(" 5. QUIT\n");
     printf("\n");
     printf("--------------------------------------------------------\n");

     printf("input number:");
     scanf("%d", &g);

     if(g == 1){
       printf("input the %dth class :[name teadteachernumber classnumber](the number of classnumber is %d)", bi + 1, bi + 1);
       scanf("%s %s %s", class[bi].name, class[bi].teachernumber, class[bi].classnumber);
       class[bi].name[3] = '\0';
       bi++;
     }

     if(g == 2){
       printf("input the %dth teacher :[teachernumber subjectnumber classnumber]", di+1);
       scanf("%s %s %s", instructor[di].teachernumber, instructor[di].subjectnumber, instructor[di].classnumber);
       di++;
     }

     if(g == 3){
       printf("input %d student's class :[classnumber]", ei+1);
       scanf("%s", student[ei].classnumber);
       ei++;
     }

     if(g == 4){
       printf("input %dth subject time :", fi+1);
       scanf("%s", subject[fi].time);
       fi++;
     }
   }

   if(b == 2){
     printf("--------------------------------------------------------\n");
     printf("\n");
     printf(" 1. register\n");
     printf(" 2. register student\n");
     printf(" 3. enter mark\n");
     printf(" 4. check mark\n");
     printf(" 5. check student\n");
     printf(" 6. check teacher\n");
     printf(" 7. check class\n");
     printf(" 8. QUIT\n");
     printf("\n");
     printf("--------------------------------------------------------\n");

     printf("input number:");
     scanf("%d", &bc);

     if(bc == 1){
       printf("please input your information: [Name Teachernumber Sex ](your teachernumber is %d)\n", ai + 1);
       scanf("%s %s %s", teacher[ai].name, teacher[ai].teachernumber, teacher[ai].sex);
       teacher[ai].sex[1] = '\0';
       ai++;
       teacher2++;
     }

     if(bc == 2){
       printf("please input the information: [Name Studentnumber Sex](your studentnumber is %d)\n", i + 1);
       scanf("%s %s %s", student[i].name, student[i].studentnumber, student[i].sex);
       student[i].sex[1] = '\0';
       i++;
     }

     if(bc == 3){
       printf("please input the information: [studentnumber subjectnumber mark]");
       scanf("%s %s %d", mark[ci].studentnumber, mark[ci].subjectnumber, &mark[ci].mark);
       ci++;
       g++;
     }

     if(bc == 4){
       if(g == -1)
         printf("The mark teacher doesn't issue yet.\n");
       else{
         printf("--------------------------------------------------------\n");
         printf("\n");
         printf("   |studentnumber|subjectnumber|mark|\n");
         for(a = 0; a < ci; a++)
           printf(" %d.      %8s             %1s   %d  \n", a + 1, mark[a].studentnumber, mark[a].subjectnumber, mark[a].mark);
         printf("\n");
         printf("--------------------------------------------------------\n");
       }
     }

     if(bc == 5){
       printf("--------------------------------------------------------\n");
       printf("\n");
       printf("   |studentnumber|name      |sex|class|\n");
       for(a = 0; a < i; a++)
         printf(" %d.      %8s %10s   %1s    %2s \n", a + 1, student[a].studentnumber, student[a].name, student[a].sex, student[a].classnumber);
       printf("\n");
       printf("--------------------------------------------------------\n");
     }

     if(bc == 6){
     printf("--------------------------------------------------------\n");
     printf("\n");
     printf("    |name     |teachernumber    |sex|     \n");
     for(a = 0; a < teacher2; a++)
       printf(" %d. %10s          %8s   %s  \n", a + 1, teacher[a].name, teacher[a].teachernumber, teacher[a].sex);
     printf("\n");
     printf("--------------------------------------------------------\n");

     }

     if(bc == 7){
     printf("--------------------------------------------------------\n");
     printf("\n");
     printf("   |classnumber|name|teachernumber| \n");
     for(a = 0; a < bi; a++)
       printf(" %d.          %2s  %3s      %8s \n", a + 1, class[a].classnumber, class[a].name, class[a].teachernumber);
     printf("\n");
     printf("--------------------------------------------------------\n");
     }

   }


   if(b == 1){
     printf("--------------------------------------------------------\n");
     printf("\n");
     printf(" 1. register\n");
     printf(" 2. check mark\n");
     printf(" 3. check student\n");
     printf(" 4. make time table\n");
     printf(" 5. QUIT\n");
     printf("\n");
     printf("--------------------------------------------------------\n");

     printf("input number:");
     scanf("%d", &ac);


     if(ac == 1){
       printf("please input your information: [Name Studentnumber Sex](your student number is %d)\n", i + 1);
       scanf("%s %s %c", student[i].name, student[i].studentnumber, &student[i].sex);
       student[i].sex[1] = '\0';
       i++;
     }

     if(ac == 2){
       if(g == -1)
         printf("The mark teacher doesn't issue yet.\n");
       else{
         printf("--------------------------------------------------------\n");
         printf("\n");
         printf("   |studentnumber|subjectnumber|mark|\n");
         for(a = 0; a < ci; a++)
           printf(" %d.      %8s             %1s   %d  \n", a + 1, mark[a].studentnumber, mark[a].subjectnumber, mark[a].mark);
         printf("\n");
         printf("--------------------------------------------------------\n");
       }
     }

     if(ac == 3){
       printf("--------------------------------------------------------\n");
       printf("\n");
       printf("   |studentnumber|name      |sex|class|\n");
       for(a = 0; a < i; a++)
         printf(" %d.      %8s %10s   %1s    %2s \n", a + 1, student[a].studentnumber, student[a].name, student[a].sex, student[a].classnumber);
       printf("\n");
       printf("--------------------------------------------------------\n");
     }

     if(ac == 4){
       if(di < subject1 && ei < entries)
         printf("The information teacher doesn't fill in yet.\n");
       else{
         printf("input your student number.\n");
         scanf("%s",ah);

         k = atoi(ah);

         printf("--------------------------------------------------------\n");
         printf("\n");
         printf(" |%10s|subject   |time |\n", student[k - 1].name); 
         for(a = 0; a < subject1; a++){
           if(strcmp(instructor[a].classnumber, student[k - 1].classnumber) == 0){
             l = atoi(instructor[a].subjectnumber);
             l--;
             printf("                %3s  %5s \n", subject[l].name, subject[l].time);
           }
         }
         printf("\n");
         printf("--------------------------------------------------------\n");
       }
     }
   }

 }

}
