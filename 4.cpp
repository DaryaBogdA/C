
#include <iostream>
#include <string>
using namespace std;

void Task1()
{
    int num, res;
    cout << "Enter number: ";
    cin >> num;
    res = 0;
    do {
        num /= 10;
        res++;
    } while (num > 0);
    cout << " number " << res;
}
void Task2()
{
    int num, res, obratno;
    cout << "Enter number: ";
    cin >> num;
    obratno = 0;
    do {
        res = num % 10;
        obratno = obratno * 10 + res;
        num /= 10;
    } while (num > 0);
    cout << " number " << obratno;
}

void Task3()
{
    int num, res, chislo;
    cout << "Enter number: ";
    cin >> num;
    res = 0;
    do {
        {
            chislo = num % 10;
            res = res + chislo;
            num /= 10;
        }
    } while (num > 0); 
    cout << " number " << res;
}

int main()
{
    Task1();
    Task2();
    Task3();
}
