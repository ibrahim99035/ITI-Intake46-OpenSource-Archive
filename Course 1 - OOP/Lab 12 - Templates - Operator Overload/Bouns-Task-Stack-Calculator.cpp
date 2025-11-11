#include <iostream>
using namespace std;

class NumStack{
    int* data;
    int top;
    int size;
public:
    NumStack(){
        size = 100;
        data = new int[size];
        top = -1;
    }

    ~NumStack(){
        delete[] data;
    }

    void push(int val){
        if(top < size - 1){
            top++;
            data[top] = val;
        }
    }

    int pop(){
        if(top >= 0){
            int val = data[top];
            top--;
            return val;
        }
        return 0;
    }

    int peek(){
        if(top >= 0){
            return data[top];
        }
        return 0;
    }

    int isEmpty(){
        return top == -1;
    }
};

class OpStack{
    char* data;
    int top;
    int size;
public:
    OpStack(){
        size = 100;
        data = new char[size];
        top = -1;
    }

    ~OpStack(){
        delete[] data;
    }

    void push(char val){
        if(top < size - 1){
            top++;
            data[top] = val;
        }
    }

    char pop(){
        if(top >= 0){
            char val = data[top];
            top--;
            return val;
        }
        return '\0';
    }

    char peek(){
        if(top >= 0){
            return data[top];
        }
        return '\0';
    }

    int isEmpty(){
        return top == -1;
    }
};

int isDigit(char c){
    return c >= '0' && c <= '9';
}

int precedence(char op){
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

int calculate(int a, int b, char op){
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return a / b;
    return 0;
}

void applyOp(NumStack& nums, OpStack& ops){
    int b = nums.pop();
    int a = nums.pop();
    char op = ops.pop();
    int result = calculate(a, b, op);
    nums.push(result);
}

int evaluate(char* expr){
    NumStack nums;
    OpStack ops;

    int i = 0;
    while(expr[i] != '\0'){
        if(isDigit(expr[i])){
            int num = 0;
            while(isDigit(expr[i])){
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            nums.push(num);
        }
        else if(expr[i] == '('){
            ops.push(expr[i]);
            i++;
        }
        else if(expr[i] == ')'){
            while(!ops.isEmpty() && ops.peek() != '('){
                applyOp(nums, ops);
            }
            ops.pop();
            i++;
        }
        else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'){
            while(!ops.isEmpty() && ops.peek() != '(' && precedence(ops.peek()) >= precedence(expr[i])){
                applyOp(nums, ops);
            }
            ops.push(expr[i]);
            i++;
        }
        else{
            i++;
        }
    }

    while(!ops.isEmpty()){
        applyOp(nums, ops);
    }

    return nums.pop();
}

int main(){
    char expr[200];

    cout << "Expression Evaluator\n";
    cout << "Enter expression: ";
    cin >> expr;

    int result = evaluate(expr);

    cout << "\nExpression: " << expr << "\n";
    cout << "Result: " << result << "\n";

    return 0;
}
