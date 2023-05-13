/* Write class declarations and member function definitions for a C++ base
class to represent an Employee (emp-code, name).
Derive two classes as Fulltime (daily rate, number of days, salary) and
Parttime (number of working hours, hourly rate, salary).
Write a menu driven program to:
1. Accept the details of ‘n’ employees.
2. Display the details of ‘n’ employees.
3. Search a given Employee by emp-code.
*/
#include<iostream>
#include<cstring>
using namespace std;
class Employee
{
    protected:
      int emp_code;
      char emp_name[20];
    public:
       int get_emp_id()
       {
           return emp_code;
       }
       void get()
       {
           cout<<"Enter Employee ID    :";
           cin>>emp_code;
           cout<<"Enter Employee Name  :";
           cin>>emp_name;
       }
};
class Fulltime : public Employee
{
   private:
    float daily_rate,salary;
    int no_of_days;
   public:
    void cal_salary()
    {
        salary=daily_rate*no_of_days;
    }
    void get_data()
    {
        cout<<"Enter number of days ";
        cin>>no_of_days;
        cout<<"Enter daily rate ";
        cin>>daily_rate;
        cout<<endl;

    }
    void display()
    {
        cout<<"Employee number      :"<<emp_code<<endl;
        cout<<"Employee name        :"<<emp_name<<endl;
        cout<<"Salary               :"<<salary<<endl;
        cout<<"Status               : FULLTIME"<<endl;
        cout<<endl;
        cout<<"........................................"<<endl;
    }
};
class Parttime : public Employee
{
   private:
     int work_hours;
     float hourly_rate,salary;
   public:
     void cal_salary1()
     {
         salary=work_hours*hourly_rate;
     }
    void get_data1()
    {
        cout<<"Enter number of hours ";
        cin>>work_hours;
        cout<<"Enter hour rate ";
        cin>>hourly_rate;
        cout<<endl;
    }
     void display1()
    {
        cout<<"Employee number      :"<<emp_code<<endl;
        cout<<"Employee name        :"<<emp_name<<endl;
        cout<<"Salary               :"<<salary<<endl;
        cout<<"Status               : PARTTIME"<<endl;
        cout<<endl;
        cout<<"........................................"<<endl;
    }
};
int main()
{
    int i,choice;
    Fulltime f1[5];
    Parttime p1[5];
    int var=0,var1=0;
    while(1)
    {
    cout<<"1. Enter Record "<<endl;
    cout<<"2. Display Record "<<endl;
    cout<<"3. Search Record "<<endl;
    cout<<"4. Quit "<<endl<<endl<<".................................................."<<endl;
    cout<<"Enter a choice ";
    cin>>choice;
    switch(choice)
    {
       case 1:
              int x;
              cout<<endl<<"1. FULLTIME ";
              cout<<endl<<"2. PARTTIME "<<endl;
              cout<<"Enter your choice ";
              cin>>x;
              switch(x)
              {
                 case 1:
                      f1[var].get();
                      f1[var].get_data();
                      f1[var].cal_salary();
                      var++;
                      break;
                 case 2:
                      p1[var1].get();
                      p1[var1].get_data1();
                      p1[var1].cal_salary1();
                      var1++;
                      break;
              }
              break;
       case 2:
             if(var==0 && var1==0)
                cout<<"Empty List "<<endl<<endl;
             else
             {
                 for(i=0;i<var;i++)
                 {
                     f1[i].display();
                 }
                 for(i=0;i<var1;i++)
                 {
                     p1[i].display1();
                 }
             }
              break;
       case 3:
              int a;
              if(var==0 && var1==0)
              {
                  cout<<"List is empty "<<endl;
              }
              else
              {
              cout<<endl<<" Enter Employee ID ";
              cin>>a;
              for(i=0;i<var;i++)
              {
                  if(a==f1[i].get_emp_id())
                    f1[i].display();
              }
              for(i=0;i<var1;i++)
              {
                  if(a==p1[i].get_emp_id())
                    p1[i].display1();
              }
              }
              break;
       case 4:
              exit(0);
       default:
            cout<<"Invalid input "<<endl<<endl;
    }
    }
    return 0;
}
