#include <iostream>
using namespace std;

class String{
private:
    char* data;
    int length;
    int capacity;

    int getLen(char* str){
        int len = 0;
        while(str[len] != '\0'){
            len++;
        }
        return len;
    }

    void copyStr(char* dest, char* src){
        int i = 0;
        while(src[i] != '\0'){
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    void concatStr(char* dest, char* src){
        int i = 0;
        while(dest[i] != '\0'){
            i++;
        }
        int j = 0;
        while(src[j] != '\0'){
            dest[i] = src[j];
            i++;
            j++;
        }
        dest[i] = '\0';
    }

    int compareStr(char* s1, char* s2){
        int i = 0;
        while(s1[i] != '\0' && s2[i] != '\0'){
            if(s1[i] < s2[i]) return -1;
            if(s1[i] > s2[i]) return 1;
            i++;
        }
        if(s1[i] == '\0' && s2[i] == '\0') return 0;
        if(s1[i] == '\0') return -1;
        return 1;
    }

public:
    String(){
        capacity = 10;
        length = 0;
        data = new char[capacity];
        data[0] = '\0';
    }

    String(int cap){
        capacity = cap;
        length = 0;
        data = new char[capacity];
        data[0] = '\0';
    }

    String(char* str){
        length = getLen(str);
        capacity = length + 1;
        data = new char[capacity];
        copyStr(data, str);
    }

    String(String& s){
        length = s.length;
        capacity = s.capacity;
        data = new char[capacity];
        copyStr(data, s.data);
    }

    ~String(){
        delete[] data;
    }

    String& operator=(String& s){
        if(this == &s){
            return *this;
        }

        delete[] data;

        length = s.length;
        capacity = s.capacity;
        data = new char[capacity];
        copyStr(data, s.data);

        return *this;
    }

    String operator+(String& s){
        String result;
        result.length = length + s.length;
        result.capacity = result.length + 1;
        delete[] result.data;
        result.data = new char[result.capacity];

        copyStr(result.data, data);
        concatStr(result.data, s.data);

        return result;
    }

    int operator==(String& s){
        return compareStr(data, s.data) == 0;
    }

    int operator<(String& s){
        return compareStr(data, s.data) < 0;
    }

    int operator>(String& s){
        return compareStr(data, s.data) > 0;
    }

    void toUpper(){
        for(int i = 0; i < length; i++){
            if(data[i] >= 'a' && data[i] <= 'z'){
                data[i] = data[i] - 32;
            }
        }
    }

    void toLower(){
        for(int i = 0; i < length; i++){
            if(data[i] >= 'A' && data[i] <= 'Z'){
                data[i] = data[i] + 32;
            }
        }
    }

    void print(){
        cout << data;
    }
};

int main(){
    String s1;
    String s2(10);
    String s3("ali");

    String str1("Hello");
    String str2("World");

    int choice;

    do{
        cout << "\n====== String Class Menu ======\n";
        cout << "1. Display Strings\n";
        cout << "2. Concatenate (String1 + String2)\n";
        cout << "3. Compare Strings (==)\n";
        cout << "4. Compare Strings (<)\n";
        cout << "5. Compare Strings (>)\n";
        cout << "6. Copy String (String1 = String2)\n";
        cout << "7. Convert String1 to Uppercase\n";
        cout << "8. Convert String1 to Lowercase\n";
        cout << "9. Test Constructors\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "\nString 1: ";
                str1.print();
                cout << "\nString 2: ";
                str2.print();
                cout << "\n";
                break;

            case 2:
                {
                    String result = str1 + str2;
                    cout << "\nConcatenated String: ";
                    result.print();
                    cout << "\n";
                }
                break;

            case 3:
                if(str1 == str2){
                    cout << "\nStrings are EQUAL\n";
                }else{
                    cout << "\nStrings are NOT EQUAL\n";
                }
                break;

            case 4:
                if(str1 < str2){
                    cout << "\nString1 is LESS THAN String2\n";
                }else{
                    cout << "\nString1 is NOT LESS THAN String2\n";
                }
                break;

            case 5:
                if(str1 > str2){
                    cout << "\nString1 is GREATER THAN String2\n";
                }else{
                    cout << "\nString1 is NOT GREATER THAN String2\n";
                }
                break;

            case 6:
                str1 = str2;
                cout << "\nString1 copied from String2\n";
                cout << "String1 is now: ";
                str1.print();
                cout << "\n";
                break;

            case 7:
                str1.toUpper();
                cout << "\nString1 converted to uppercase: ";
                str1.print();
                cout << "\n";
                break;

            case 8:
                str1.toLower();
                cout << "\nString1 converted to lowercase: ";
                str1.print();
                cout << "\n";
                break;

            case 9:
                cout << "\n--- Testing Constructors ---\n";
                cout << "s1 (default): ";
                s1.print();
                cout << "\ns2 (capacity 10): ";
                s2.print();
                cout << "\ns3 (\"ali\"): ";
                s3.print();
                cout << "\n";
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }while(choice != 0);

    return 0;
}
