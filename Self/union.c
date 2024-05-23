# include <stdio.h>
# include <string.h>
//Author : Eshita Das
// gcc union.c -o un

/* 
struct Student
{
 int id;
 float marks;
 char name[35];
};

*/


union Student
{
 int id;
 float marks;
 char name[35];
};


int main()
{
union Student s1, s2, s3;
//struct Student s1, s2, s3;
s1.id=49;
s1.marks=56.9;
strcpy(s1.name,"Ritu Das");
s2.id=90;
s2.marks=90.8;
strcpy(s2.name,"Shreya Pal");
s3.id=78;
s3.marks=89.9;
strcpy(s3.name,"Piya Dolui");

printf("The student s1's id is %d\n",s1.id);
printf("The student s1's marks is %.1f\n",s1.marks);
printf("The student s1's name is %s\n",s1.name);
printf("The student s2's id is %d\n",s2.id);
printf("The student s2's name is %s\n",s2.name);
printf("The student s2's marks is %.1f\n",s2.marks);
printf("The student s3's id is %d\n",s3.id);
printf("The student s3's name is %s\n",s3.name);
printf("The student s3's marks is %.1f\n",s3.marks);

printf("The size of the union is %lu\n",sizeof(s1)); //36
//printf("The size of the structure is %lu\n",sizeof(s1)); //44

//only names are getting prioritised and taken in unions cz, they're defined last | names are the latest defined values here in unions
return 0;
}
