#include <iostream>
using namespace std;

class Person {
    int id;
    string name;
    int age;
public:
    Person(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }

    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }

    void setId(int ID){
        id = ID;
    }
    void setName(string Name){
        name = Name;
    }
    void setAge(int Age){
        age = Age;
    }

    void printPerson() {
        cout << "ID: "<<id<<endl;
        cout << "Name: "<<name<<endl;
        cout << "Age: "<<age<<endl;
    }
};

class Employee : public Person {
    float salary;
public:
    Employee(int ID, string Name, int Age, float Salary) : Person(ID, Name, Age) {
        salary = Salary;
    }

    float getSalary(){
        return salary;
    }

    void setSalary(float SalarySet){
        salary = SalarySet;
    }

    void printPerson() {
        Person::printPerson();
        cout<<"Salary: " <<salary<<endl;
    }
};

class Student : public Person {
    float grade;
public:
    Student(int ID, string Name, int Age, float Grade) : Person(ID, Name, Age) {
        grade = Grade;
    }

    float getGrade(){
        return grade;
    }

    void setGrade(float GradeSet){
        grade = GradeSet;
    }

    void printPerson() {
        Person::printPerson();
        cout<<"Grade: "<<grade<<endl;
    }
};

int main() {
    Person person(1, "Ibrahim", 23);
    Employee employee(2, "Amr", 24, 10000);
    Student student(3, "Mahmoud", 20, 75);

    cout << "Person Details:\n\n" ;
    person.printPerson();
    cout <<"\n";

    cout<<"Employee Details:\n\n";
    employee.printPerson();
    cout<<"\n";

    cout << "Student Details:\n\n";
    student.printPerson();

    return 0;
}