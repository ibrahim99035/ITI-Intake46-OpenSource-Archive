#include <iostream>
using namespace std;

template<class t>

void Swap(t& x, t& y){
		t temp = x;
		x  = y;
		y = temp;
}

int main(){
		int a =  10, b = 20;
		float x = 30.5, y = 25.7;

		cout<<"Integers Befor Swapping: \na = "<<a<<", b = "<<b<<endl;
		Swap<int>(a, b);
		cout<<"Integers After Swapping: \na = "<<a<<", b = "<<b<<endl;

		cout<<"Floats Befor Swapping: \nx = "<<x<<", y = "<<y<<endl;
		Swap<float>(x, y);
		cout<<"Floats After Swapping: \nx = "<<x<<", y = "<<y<<endl;

		return 0;
}
