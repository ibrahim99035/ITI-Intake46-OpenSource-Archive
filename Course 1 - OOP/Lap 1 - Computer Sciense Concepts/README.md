# **OOP Lab 1 – Computer Science Concepts**

This lab introduces **core programming and ASCII manipulation concepts in C++**.
It focuses on functions, data types, condition handling, loops, and conversions between characters and integers.

---

## **Task 1: Arithmetic Operations**

**File:** `Task-1-ArthemeticOperations.cpp`

### **Purpose**

This task practices **function creation, parameter passing, and arithmetic logic**.
It takes two integers from the user and performs all five major arithmetic operations:

1. Addition
2. Subtraction
3. Division (with error handling)
4. Multiplication
5. Modulus (remainder)

---

### **Code Sample**

```cpp
#include <iostream>
using namespace std;

int addition(int x, int y) { return x + y; }

int subtract(int x, int y) {
    return (x > y) ? x - y : y - x;
}

int division(int x, int y) {
    if (x == 0 || y == 0) {
        cout << "ZERO DIVISION ERROR" << endl;
        return 0;
    }
    return (x > y) ? x / y : y / x;
}

int multiplication(int x, int y) { return x * y; }

int modulus(int x, int y) {
    if (x == 0 || y == 0) {
        cout << "MODULUS BY ZERO ERROR" << endl;
        return 0;
    }
    return (x > y) ? x % y : y % x;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "Addition: " << addition(x, y) << endl;
    cout << "Subtraction: " << subtract(x, y) << endl;
    cout << "Division: " << division(x, y) << endl;
    cout << "Multiplication: " << multiplication(x, y) << endl;
    cout << "Modulus: " << modulus(x, y) << endl;

    return 0;
}
```

---

### **Explanation**

* **Functions**: Each arithmetic operation is separated into its own function to illustrate modular programming.
* **Division Check**: The program prevents division by zero and prints a custom error message.
* **Order Independence**: Operations handle both input orders (x > y or y > x).
* **Modularity Benefit**: Each operation can be reused in other programs or projects.

---

### **Sample Output**

```
Enter two numbers: 8 3
Addition: 11
Subtraction: 5
Division: 2
Multiplication: 24
Modulus: 2
```

---

## **Task 2: Character → Integer Conversion**

**File:** `Task-2-Character-to-Integer.cpp`

### **Purpose**

This program demonstrates how a **character is stored as an integer (ASCII code)** in memory.
Each character corresponds to a unique ASCII number.

---

### **Code Sample**

```cpp
#include <iostream>
using namespace std;

int main() {
    char c;
    for (int i = 0; i < 5; i++) {
        cout << "Enter a character: ";
        cin >> c;

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            cout << "ASCII of " << c << " = " << int(c) << endl;
        } else {
            cout << "Invalid input. Only letters allowed." << endl;
        }
    }
    return 0;
}
```

---

### **Explanation**

* **Type Conversion**: When you use `int(c)`, C++ automatically converts the character into its ASCII integer code.
* **Validation**: Checks if the input is an English alphabet letter using ASCII ranges:

  * `'A'–'Z'` → 65–90
  * `'a'–'z'` → 97–122
* **Purpose**: Prevents numbers and special symbols from being entered.

---

### **Sample Output**

```
Enter a character: A
ASCII of A = 65
Enter a character: z
ASCII of z = 122
Enter a character: 5
Invalid input. Only letters allowed.
```

---

## **Task 3: Integer → Character Conversion**

**File:** `Task-3-Integer-to-Character.cpp`

### **Purpose**

This task demonstrates **type casting from an integer to a character** using ASCII mapping.
It shows how computers represent characters internally using numeric values.

---

### **Code Sample**

```cpp
#include <iostream>
using namespace std;

int main() {
    int num;
    for (int i = 0; i < 5; i++) {
        cout << "Enter a number: ";
        cin >> num;

        cout << "Character of " << num << " = " << char(num) << endl;
    }
    return 0;
}
```

---

### **Explanation**

* **Casting**: `char(num)` converts the integer into a character using the ASCII table.
* **ASCII Range**:

  * Printable characters range from **32–126**.
  * Example:

    * 65 → `A`
    * 97 → `a`
    * 48 → `0`
* If the user enters values outside 0–127, results may vary depending on the compiler.

---

### **Sample Output**

```
Enter a number: 65
Character of 65 = A
Enter a number: 97
Character of 97 = a
```

---

## **Task 4: Uppercase ↔ Lowercase Conversion**

**File:** `Task-4-Uppercase-Lowercase.cpp`

### **Purpose**

This task converts **uppercase letters to lowercase and vice versa** using ASCII arithmetic.
It shows how character encoding can be manipulated mathematically.

---

### **Code Sample**

```cpp
#include <iostream>
using namespace std;

int main() {
    char c;
    for (int i = 0; i < 5; i++) {
        cout << "Enter a character: ";
        cin >> c;

        if (c >= 'A' && c <= 'Z') {
            cout << "Lowercase: " << char(c + 32) << endl;
        } else if (c >= 'a' && c <= 'z') {
            cout << "Uppercase: " << char(c - 32) << endl;
        } else {
            cout << "Invalid input. Enter letters only." << endl;
        }
    }
    return 0;
}
```

---

### **Explanation**

* In the **ASCII table**, uppercase and lowercase letters differ by **32** in value.

  * `'A'` (65) → `'a'` (97)
  * `'B'` (66) → `'b'` (98)
* To convert:

  * **Uppercase → Lowercase** → Add 32
  * **Lowercase → Uppercase** → Subtract 32
* Non-letter inputs (numbers, symbols) are ignored with a warning.

---

### **Sample Output**

```
Enter a character: A
Lowercase: a
Enter a character: z
Uppercase: Z
Enter a character: 3
Invalid input. Enter letters only.
```

---

## **Compilation & Execution Commands**

To compile and run each task using `g++`:

```bash
g++ Task-1-ArthemeticOperations.cpp -o task1
./task1
```

Repeat for others:

```bash
g++ Task-2-Character-to-Integer.cpp -o task2
./task2

g++ Task-3-Integer-to-Character.cpp -o task3
./task3

g++ Task-4-Uppercase-Lowercase.cpp -o task4
./task4
```

---

## **Key Concepts Practiced**

| Concept                        | Explanation                                                         |
| ------------------------------ | ------------------------------------------------------------------- |
| **Functions**                  | Modular structure for reusable code.                                |
| **Conditionals (`if`/`else`)** | Logical flow control and validation.                                |
| **Loops**                      | Automating multiple inputs (5 iterations).                          |
| **Type Casting**               | Converting between data types (`char ↔ int`).                       |
| **Error Handling**             | Preventing invalid or dangerous operations (like dividing by zero). |
| **ASCII Table Usage**          | Understanding how text is represented as numeric codes in memory.   |

