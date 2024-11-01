#include <string>
#include <iostream>
using namespace std;
void  exer1()
{
    int mas[10] = {};
    for (int i = 0; i < 10; i++) {
        mas[i] = rand() % 100;
        cout << mas[i] << endl;
    }
    cout << endl;
    for (int i = 9; i >= 0; i--) {
        cout << mas[i] << endl;
    }
}

void  exer2()
{
    int mas[10] = {};
    for (int i = 0; i < 10; i++) {
        mas[i] = rand() % 10;
        cout << mas[i] << endl;
    }
    cout << endl;
    int sumCH = 0;
    for (int i = 0; i < 10; i++) {
        if (mas[i] % 2 == 0)
            sumCH += mas[i];
    }
    int sumneCH = 0;
    for (int i = 0; i < 10; i++) {
        if (mas[i] % 2 != 0)
            sumneCH += mas[i];
    }
    cout << sumCH << endl;
    cout << sumneCH << endl;
}

void  exer3()
{
    int mas[10] = {};
    for (int i = 0; i < 10; i++) {
        mas[i] = rand() % 10;
        cout << mas[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        int kolichestvo = 0;
        for (int j = 0; j < 10; j++) {
            if (mas[i] == mas[j])
                kolichestvo++;
        }
        if (kolichestvo > 1)
            cout << mas[i] << " repaet " << kolichestvo << endl;
    }
    
}

void  exer4()
{
    int mas[10] = {};
    for (int i = 0; i < 10; i++) {
        mas[i] = rand() % 34;
        cout << mas[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        if (mas[i] % 2 != 0)
            if (mas[i] < mas[i + 1])
                cout << mas[i] << endl;
    }
}

int main()
{
    exer1();
    exer2();
    exer3();
    exer4();
}
