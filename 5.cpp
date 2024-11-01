
#include <iostream>
#include <string>
using namespace std;

void Task1()
{
#include <iostream> using namespace std; void main ()
    {
        int i = 0, j; 
        while (i < 3) {
            cout << "\nOut!!!\n"; 
            j = 0;
            while (j < 3) {
                cout << "\nIn!!!\n"; 
                j++;
            } 
            i++;
        }
        cout << "\nEnd!!!\n";
    }

}
void Task2()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << i * j << "\t";
        }
        cout << "\n\n";
    }


}

void Task3()
{
#include <iostream> using namespace std; void main(){
    int str;
    int star_count; int length = 20; str = 1;
    while (str <= length)
    {
        star_count = 1; while (star_count <= length)
        {
            cout << "*"; star_count++;
        }
        cout << "\n"; str++;
    }
    

}

void exer1()

       {
    bool isdificlt = false;
 for (int n = 2; n <= 100; n++) {
     for (int x = 2; x < n; x++) {
         isdificlt = false;
         if (n % x  == 0) {
             isdificlt = true;
             break;
         }
     }
     if (isdificlt == false) {
         cout << "simple " << n << endl;
 }
 

void exer2()
{
    int width, height;

    cout << "Enter width: ";
    cin >> width;

    cout << "Enter height: ";
    cin >> height;

    for (int i = 0; i < width; i++) {
        cout << "*";
    }
    cout << endl;

    for (int i = 1; i < height - 1; i++) {
        cout << "*";
        for (int j = 1; j < width - 1; j++) {
            cout << " ";
        }
        cout << "*" << endl;
    }

    for (int i = 0; i < width; i++) {
        cout << "*";
    }
    cout << endl;

 }


void exer3()
{
    int x = 2, i, j;

    cout << " pn  vt  sr  ch  pt  sb  vs \n";

    for (i = 1, j = 1; i < 32; i++)
    {
        if (i == 1 && j < x)
        {
            cout << "    ";
            i--;
        }
        else {
            cout << " ";
            if (i < 10) {
                cout << " "; 
            }
            cout << i << " ";
        }

        if (j++ > 6)
        {
            j = 1;
            cout << "\n";
        }
    }
}


int main()
{
    //Task1();
    //Task2();
    //Task3();
    //exer1();
    exer2();
    //exer3();
}




