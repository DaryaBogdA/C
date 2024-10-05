#include <iostream>
#include <locale.h>

using namespace std;
int main(int argc, char** argv) {

    /*setlocale(LC_ALL, "Russian");
   
    int x;
    cout << "Enter number x: " << endl;
    cin >> x;
    if (x % 2 == 0) {
        cout << "Even number " << x << endl;
    }
    else {
        cout << "Odd number " << x << endl;
    }
   




    int n;
    cout << "Enter number n " << endl;
    cin >> n;

    int digits = 0, temp = n;
    while (temp > 0) {
        temp /= 10;
        digits++;
    }


    int summa = 0;
    temp = n;
    while (temp > 0) {
        summa += temp % 10;
        temp /= 10;
    }
    cout << "Number of digits " << n << ": " << digits << endl;
    cout << "Summa " << n << ": " << summa << endl;
    





    double num, res;
    char choice;
    cout << "Enter number: " << endl;
    cin >> num;
    cout << "Where do you want to transfer? " << endl;
    cout << "1 Duim in cm " << endl;
    cout << "2 Cm in duim " << endl;
    cin >> choice;
    switch (choice)
    {
        case '1':
            res = num * 2.54;
            break;
        case '2':
            res = num * 0.393701;
            break;
    default:
        cout << "ti eblan? " << endl;
        break;
    }
    cout << "Rezultat " << res << endl;
     */







    int money = 0;


    // Первый вопрос
    cout << "Hello\n This is a game who wants to become a millionaire\n You can win 1 000 000$,\nI wish you good luck!!!\n";
    cout << "Question 1: How old is Daria Bogdanochich?" << endl;
    cout << "1. 14" << endl;
    cout << "2. 16" << endl;
    cout << "3. 18" << endl;
    cout << "4. 5" << endl;

    int choice1;
    cin >> choice1;

    switch (choice1) {
    case 1:
        cout << "No, ti loh " << endl;
        break;
    case 2:
        cout << "yes you get 1000$" << endl;
        money += 1000;
        break;
    case 3:
        cout << "No, ti loh " << endl;
        break;
    case 4:
        cout << "No, ti loh " << endl;
        break;
    default:
        cout << "No, ti loh " << endl;
    }

    // Второй вопрос
    cout << "Where does Daria Bogdanovich study?" << endl;
    cout << "1. I DONT KNOW" << endl;
    cout << "2. NOTHIND" << endl;
    cout << "3. SCHOOL" << endl;
    cout << "4. MGKCT" << endl;

    int choice2;
    cin >> choice2;

    switch (choice2) {
    case 1:
        cout << "No, ti loh" << endl;
        money -= 1000;
        break;
    case 2:
        cout << "No, ti loh" << endl;
        money -= 1000;
        break;
    case 3:
        cout << "No, ti loh" << endl;
        money -= 1000;
        break;
    case 4:
        cout << "yes its coreect" << endl;
        money += 100000;
        break;
    default:
        cout << "No, ti loh" << endl;
    }

    // Итог
    cout << " You get: " << money << " $" << endl;

    return 0;
}












