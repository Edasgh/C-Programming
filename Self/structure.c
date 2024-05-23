#include <stdio.h>
#include <string.h>
// gcc structure.c -o st
// .\st.exe
struct Student
{
    int id;
    float marks;
    char fav_movie[45];
    char name[35];
};

void main()
{
 struct Student Eshita, Rama,Anita,Ritu;
 Eshita.id=1;
 Eshita.marks=99;
 strcpy(Eshita.fav_movie,"The Avengers Endgame");
 strcpy(Eshita.name,"Eshita Das");
 Rama.id=2;
 Rama.marks=95;
 strcpy(Rama.fav_movie,"The Anaconda");
 strcpy(Rama.name,"Rama Das");
 Anita.id=3;
 Anita.marks=90;
 strcpy(Anita.fav_movie,"Lapaata Ladies");
 strcpy(Anita.name,"Anita Mallick");
 Ritu.id=4;
 Ritu.marks=87;
 strcpy(Ritu.fav_movie,"12th Fail");
 strcpy(Ritu.name,"Ritu Das");

//Quick Quiz : Print all the information of a given student
printf("The student's name is: %s\n",Ritu.name);
printf("The student's id is: %d\n",Ritu.id);
printf("The student's marks is: %.1f\n",Ritu.marks);
printf("The student's favourite movie is: %s\n",Ritu.fav_movie);
}