#include <iostream>
#include <string.h>

using namespace std;

class Employee{
    int id;
    string name;
    int age;
    float salary;
public:
    //id
    void setId(int inputId){
        if(inputId > 0){
            id = inputId;
        }else{
            cout<<"Unable to process this id\n";
        }
    }
    int getId(){
        return id;
    }

    //name
    void setName(string inputName){
        name = inputName;
    }
    string getName(){
        return name;
    }

    //age
    void setAge(int inputAge){
        if(inputAge >= 20){
            age = inputAge;
        }else{
            cout<<"Unable to process this age\n";
        }
    }
    int getAge(){
        return age;
    }

    //salary
    void setSalary(float inputSalary){
        if(inputSalary >= 1000){
            salary = inputSalary;
        }else{
            cout<<"Unable to process this salary\n";
        }
    }
    float getSalary(){
        return salary;
    }

    //Print
    void print(){
        cout<<"Employee "<<name<<" (id."<<id<<") "<<"with the age "<<age<<" has salary: "<<salary<<"$.\n";
    }
};

int main()
{
    cout<<"===================Employees Portal===================\n\n";
    int id;
    string name;
    int age;
    float salary;

    Employee InputEmployee;

    cout<<"Id: ";
    cin>>id;
    if(id<0){
        cout<<"id has to be above 0 - Try Again: ";
        cin>>id;
    }
    InputEmployee.setId(id);

    cout<<"Name: ";
    cin>>name;
    InputEmployee.setName(name);

    cout<<"Age: ";
    cin>>age;
    if(age<20){
        cout<<"age has to be above or equal 20 - Try Again: ";
        cin>>age;
    }
    InputEmployee.setAge(age);

    cout<<"Salary: ";
    cin>>salary;
    if(salary<1000){
        cout<<"salary has to be above or equal 1000$ - Try Again: ";
        cin>>salary;
    }
    InputEmployee.setSalary(salary);

    InputEmployee.print();

    return 0;
}