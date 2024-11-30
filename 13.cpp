
#include <iostream> 
using namespace std;
void exercise1() {
    int a, b, c;
    cout << "Enter a ";
    cin >> a;
    cout << "Enter b ";
    cin >> b;
    int* pa = &a;
    int* pb = &b;
    int** paa = &pa;
    int** pbb = &pb;
    c = (**paa) + (**pbb);
    cout << c;
}

void exercise2() {
    int a, b, c;
    string symbol;
    int *pa = &a;
    int *pb = &b;
    cout << "Enter a ";
    cin >> a;
    cout << "Enter b ";
    cin >> b;
    cout << "Enter * or / or - or + ";
    cin >> symbol;
    if (symbol == "*") {
        c = (*pa) * (*pb);
    }
    else if (symbol == "/") {
        c = (*pa) / (*pb);
    }
    else if (symbol == "-") {
        c = (*pa) - (*pb);
    }
    else if (symbol == "+") {
        c = (*pa) + (*pb);
    }
    else{
        cout << "Yoy are stupid." << endl;
    }
    cout << c;
}

void exercise3() {
    int a, c = 1;
    cout << "Enter a ";
    cin >> a;
    int *pa = &a;
    for (int i = 1; i <= *pa; i++) {
        c *= i;
    }
    cout << c;
}

void exercise4() {
    int a, b, c = 1;
    cout << "Enter a ";
    cin >> a;
    cout << "Enter power of a number ";
    cin >> b;
    int* pa = &a;
    int* pb = &b;
    for (int i = 1; i <= *pb; i++) {
        c *= *pa;
    }
    cout << c;
}

void exercise5() {
    int a, b, c = 0;
    cout << "Enter a ";
    cin >> a;
    cout << "Enter b ";
    cin >> b;
    int* pa = &a;
    int* pb = &b;
    int** paa = &pa;
    int** pbb = &pb;

    cout << c;
}


int main() {
    //exercise1();
    //exercise2();
    //exercise3();
    //exercise4();
    exercise5();

}
