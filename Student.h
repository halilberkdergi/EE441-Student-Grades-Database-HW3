#ifndef STUDENT_H
#define STUDENT_H
#include <string.h>

class Student
{
    public:
        int studentID;
        bool record_valid;
        int index;
        Student (int ID=0, bool valid=false, int i=-1);         //constructor
};
Student::Student(int ID, bool valid, int i):studentID(ID), record_valid(valid),index(i)
{

}

class StudentRecord
{
    public:
        bool valid;
        int studentID;
        char studentName [100];
        int studentGrades[3];       /*array element i stores the grade of course id i (course ids are selected from 0 to 2).*/
        StudentRecord (  bool v=false,
                         int ID=0,
                         char* name="",
                         int grade1=0,
                         int grade2=0,
                         int grade3=0);//constructor
};
StudentRecord::StudentRecord(bool v, int ID, char* name, int grade1, int grade2, int grade3)
{
     valid=v;
     studentID=ID;

     for(int i = 0 ; i < strlen(name);i++)
     {
         *(studentName+i)=*(name+i);
     }

     studentGrades[0]=grade1;
     studentGrades[1]=grade2;
     studentGrades[2]=grade3;
}
#endif // STUDENT_H
