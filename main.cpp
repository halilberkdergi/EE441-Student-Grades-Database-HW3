#include <iostream>
#include "BTreeNode.h"
#include "Student.h"
using namespace std;
int searchStudent(int ID, BTreeNode<Student>* Tree, bool& valid)
{
    while ( !(  Tree->Children[0] == NULL &&
                Tree->Children[1] == NULL &&
                Tree->Children[2] == NULL ) )
           {
               for(int i =0 ; i<2; i ++)
               {
                   if(ID == Tree->data[i].studentID)
                   {
                       valid = Tree->data[i].record_valid;
                       return Tree->data[i].index;
                   }
               }

               if(ID < Tree->data[0].studentID)  //saða git
               {
                   Tree=Tree->Children[0];
               }

               if ( ID > Tree->data[0].studentID && ID < Tree->data[1].studentID) //ortadakine git
               {
                  Tree = Tree->Children[1];

               }

               if(ID < Tree->data[1].studentID) // sola git
               {
                   Tree = Tree->Children[2];
               }
           }
    valid=false; //If no Student object is found with a matching studentID,
    return -1;   //searchStudent returns -1 and sets v=false.

}

void PrintStudent (int ID, StudentRecord* Database, BTreeNode<Student>* Tree)
{
    bool x;
    int index_x= searchStudent(ID,Tree,x);
    if ( x == false )
    {
        cerr<<"Student record does not exist"<<endl;  // If the student does not exist in the database some
    }                                                 //error message is printed on the screen.
    else
    {
        cout<<"studentName:";
        for(int i =0; i<100; i++)                     //Otherwise studentName and
        {                                             //studentGrades are printed on the screen.
            if((Database+index_x)->studentName[i] != NULL)
            {
                cout<<(Database+index_x)->studentName[i];
            }
            else
                break;
        }

        cout<<"\nstudentGrades:";

        for(int k =0 ; k<3;k++)
        {
            cout<<(Database+index_x)->studentGrades[k]<<" ";
        }

    }
}

void UpdateStudentGrades (int ID, int * grades, StudentRecord* Database, BTreeNode<Student>* Tree)
{
    bool x;
    int index_x= searchStudent(ID,Tree,x);
    if (x == false)
    {
        cerr<<"Student record does not exist"<<endl;  //If the student does not exist in the database
    }                                                 // some error message is printed on the screen.
    else
    {
        for(int k =0 ; k<3;k++)                         //Otherwise the studentGrades of the student is updated
        {
            (Database+index_x)->studentGrades[k] = grades[k];
        }
    }

}

void InsertStudent(int ID, char* Name, int* grades, StudentRecord* Database, BTreeNode<Student>* Tree)
{

    bool x;
    int index_x= searchStudent(ID,Tree,x);
    if (x == true)
    {
        cout<<"Student record already exist"<<endl;   // If the record already exists in the database, the function returns.
        return;
    }
    else
    {
          int i=0;
          while (((Database+i)->valid != true) && i < 100 ) // find empty location
          {
              i++;
          }
          int new_index = i++;      //new index 'i'

        if(new_index == 100) //If there is no empty location you will produce an error message.
        {
            cerr<<"No empty location"<<endl;
        }
        else
        {
          StudentRecord NewRecord(true, ID,Name, grades[0] , grades[1], grades[2]);

          *(Database+new_index)=NewRecord;

          Student NewStudent(ID,true,new_index);

           while ( !(  Tree->Children[0] == NULL &&             //find tree acording the ID
                       Tree->Children[1] == NULL &&
                       Tree->Children[2] == NULL ) )
                    {

                       if(ID < Tree->data[0].studentID)  //saða git
                       {
                           Tree=Tree->Children[0];
                       }

                       if ( ID > Tree->data[0].studentID && ID < Tree->data[1].studentID) //ortadakine git
                       {
                          Tree = Tree->Children[1];

                       }

                       if(ID < Tree->data[1].studentID) // sola git
                       {
                           Tree = Tree->Children[2];
                       }
                    }
           if(Tree->data[1].index == -1)
           {
               Tree->data[1].studentID=ID;
               Tree->data[1].record_valid=true;
               Tree->data[1].index=new_index;

           }
           if(Tree->data[0].index == -1)
           {

               Tree->data[0].studentID=ID;
               Tree->data[0].record_valid=true;
               Tree->data[0].index=new_index;

           }

        }

    }

}

int main(void)
{


}
