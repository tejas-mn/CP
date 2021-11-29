#include<iostream>
#include<string.h>

using namespace std;

/*Class Definition*/

class StudentInfo
{
    int roll_no;

    /*String class*/
    string name;

    /*Defining Member functions inside class*/

    public:

        void setInfo(int roll,string n)
        {
            roll_no=roll;
            name=n;
        }

        void showInfo()
        {
            cout<<"Name: "<<name<<"\n";
            cout<<"Roll No: "<<roll_no<<"\n";
        }
};

int main()
{
    /*Creating multiple objects*/

    StudentInfo student1,student2;

    student1.setInfo(120,"Amit");
    student2.setInfo(130,"Arpit");

    student1.showInfo();
    student2.showInfo();

    return 0;
}
