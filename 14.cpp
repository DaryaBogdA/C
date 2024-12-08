#include <iostream>

using namespace std;

void exercise1() {
    const int SIZE = 100;

    char str[SIZE];
    int i = 0;
    char ch;

    cout << "Enter string: ";

    while ((ch = getchar()) != '\n' && i < SIZE - 1) {
        str[i++] = ch;
    }

    str[i] = '\0'; 

    int count = 0;
    while (str[count] != '\0') {
        count++;
    }

    int free = SIZE - count;

    cout << "no free " << count << endl;
    cout << "free " << free << endl;
}




void exercise2() {
    int i = 0;
    int size = 100;
    char* str = new char[size];
    char ch;
    cout << "Enter string: ";

    while ((ch = getchar()) != '\n' && i < size - 1) {
        str[i++] = ch;
    }
    str[i] = '\0';

    char m, n;
    cout << "Enter m: ";
    //m = getchar();
    cin >> m;
    cout << "Enter n: ";
    //n = getchar();
    cin >> n;

    char* substring = new char[n - m + 1];

    for (int i = m; i <= n; i++) {
        substring[i - m] = str[i];
    }
    substring[n - m] = '\0';

    for (int i = 0; i < n - m + 1; i++) {
        cout << substring[i];
    }
}


void exercise3() {
    char str[] = "Hello anf =d hello";
    char m, n;
    cout << "Enter m: ";
    m = getchar();
    //cin >> m;
    cout << "Enter n: ";
    n = getchar();
    //cin >> n;
}



void exercise4() {
    int i = 0;
    int size = 100;
    char* str = new char[size];
    char ch;
    int count = 0;
    cout << "Enter string: ";

    while ((ch = getchar()) != '\n' && i < size - 1) {
        str[i++] = ch;
    }
    str[i] = '\0';

    cout << "Enter symbol ";
    cin >> ch;
 
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
            cout << i + 1 << " ";
        }
    }
    if (count == 0) {
        cout << "No symbol" << endl;
    }
}

void exercise5() {
    int i = 0;
    int size = 100;
    char* str = new char[size];
    char ch;
    cout << "Enter string: ";

    while ((ch = getchar()) != '\n' && i < size - 1) {
        str[i++] = ch;
    }
    str[i] = '\0';

    cout << "Enter symbol ";
    cin >> ch;
    int length = strlen(str);

    for (int i = length; i >= 0; i--) {
        if (str[i] == ch) {
            cout << i + 1;
            break;
        }
    }

}

int main() {
    //exercise1();
    //exercise2();
    //exercise4();
    //exercise5();
}