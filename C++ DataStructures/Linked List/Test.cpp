#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student
{
    int id;
    string name;
    int age;
    public:
    void setName()
    {
        cout<<"Name : ";
        getline(cin,this->name);
    }
    void setAge()
    {
        cout<<"Age : ";
        cin>>this->age;
        cin.ignore();
    }
    void setId()
    {
        cout<<"Id : ";
        cin>>this->id;
        cin.ignore();
    }
    void getName()
    {
        cout<<"Name : "<<this->name<<endl;
    }
    void getAge()
    {
        cout<<"Age : "<<this->age<<endl;
    }
    void getId()
    {
        cout<<"Id : "<<this->id<<endl;
    }
};

class Employee
{
    int id, age;
    string name;
    
    public:
    void setData(Employee e[], int n) //array of objects as argument
    {
        for(int i = 0 ; i < n ; i++)
        {
         cout<<"Name : ";
         getline(cin,e[i].name);

         cout<<"Age : ";
         cin>>e[i].age;
        
         cout<<"Id : ";
         cin>>e[i].id;

         cin.ignore();
        }
    }

    void showData(Employee e[], int n)
    {
        for(int i = 0 ; i < n ; i++)
        {
         cout<<"Name : "<<e[i].name<<endl;
         cout<<"Age : "<<e[i].age<<endl;
         cout<<"Name : "<<e[i].id<<endl;
         
        }
    }

};

int main()
{
    Student stu[4]; //array of Objects
    for(int i = 0 ; i < 4 ; i++)
    {
        stu[i].setName();
        stu[i].setAge();
        stu[i].setId();
    }
    for(int i = 0 ; i < 4 ; i++)
    {
        stu[i].getName();
        stu[i].getAge();
        stu[i].getId();
    }

    Employee emp, e[3];

    emp.setData(e,3); // passing array of objects as arguments
    emp.showData(e,3);
    return 0;
}