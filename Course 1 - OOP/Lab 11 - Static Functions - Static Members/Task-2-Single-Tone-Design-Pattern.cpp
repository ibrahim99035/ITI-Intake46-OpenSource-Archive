#include <iostream>
using namespace std;

class SingleTone{
    static SingleTone* Obj;
    SingleTone() {}
public:
    static SingleTone* getObj(){
        if(Obj == NULL){
            Obj = new SingleTone();
        }
        return Obj;
    }
};

SingleTone* SingleTone::Obj = NULL;

int main(){
    cout<<"===================Singleton Object Test===================\n";

    SingleTone* s1 = SingleTone::getObj();
    cout<<"Object 1 -> "<<s1<<"\n";

    SingleTone* s2 = SingleTone::getObj();
    cout<<"Object 2 -> "<<s2<<"\n";

    SingleTone* s3 = SingleTone::getObj();
    cout<<"Object 3 -> "<<s3<<"\n";

    cout<<"===========================================================\n";

    return 0;
}
