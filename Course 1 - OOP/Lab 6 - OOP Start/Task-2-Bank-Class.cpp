#include <iostream>
#include <string>
using namespace std;

class BankCustomer{
    int id;
    string name;
    float balance;
public:
    BankCustomer(){
        balance = 0;
    }

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

    void setName(string inputName){
        name = inputName;
    }
    string getName(){
        return name;
    }

    float getBalance(){
        return balance;
    }
    void withdraw(float amount){
        if(amount > balance){
            cout<<"Unable to process your request - you requested "<<amount - balance<<" above your balance\n";
        }else{
            balance -= amount;
        }
    }
    void deposit(float amount){
        balance += amount;
    }
    void print(){
        cout<<"Customer ("<<id<<") - "<<name<<" - Balance: "<<balance<<"$.\n";
    }
};

int main()
{
    cout<<"===========================Bank Portal===========================\n\n";
    cout<<"Signup A Customer\n";

    int id;
    string name;
    float balance;

    BankCustomer customer;

    cout<<"Id: ";
    cin>>id;
    if(id<0){
        cout<<"id has to be above 0 - Try Again: ";
        cin>>id;
    }
    customer.setId(id);

    cout<<"Name: ";
    cin>>name;
    customer.setName(name);

    cout<<"Customer Has been added!\n";

    customer.print();
    cout<<"\n\n";

    int choice;
    cout<<"Actions You Can Perform: \nTo Get Balance Enter 1.\nTo Withdraw Enter 2.\nTo Deposit 3.\nTo Exit Enter 0.\n";

    do{
        float CustomerBalance = 0;
        float ProcessAmount  = 0;

        cout<<"Your Choice: ";
        cin>>choice;

        if(choice<0||choice>3){
           cout<<choice<<" is not a valid choice\n Try again: ";
           cin>>choice;
        }else if(choice == 1){
            CustomerBalance = customer.getBalance();
            cout<<"Your Balance: "<<CustomerBalance<<"$\n";
        }else if(choice == 2){
            cout<<"Amount: ";
            cin>>ProcessAmount;
            if(ProcessAmount > customer.getBalance()){
                cout<<"Unable to process your request - you requested "<<ProcessAmount - customer.getBalance()<<" above your balance\n";
                cout<<"Try Again: ";
                cin>>ProcessAmount;
            }
            customer.withdraw(ProcessAmount);
            cout<<"Process Success - Now you have "<<customer.getBalance()<<" in your account\n";
        }else if(choice == 3){
            cout<<"Amount: ";
            cin>>ProcessAmount;
            customer.deposit(ProcessAmount);
            cout<<"Process Success - Now you have "<<customer.getBalance()<<" in your account\n";
        }else{
            break;
        }
    }while(choice != 0);
    return 0;
}