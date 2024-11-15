
#include <iostream>
#include<stdlib.h> 
using namespace std;
void sort(int A[], int size, int choice) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (choice) {

                if (A[i] < A[j]) {
                    int x = A[i];
                    A[i] = A[j];
                    A[j] = x;
                }
            }
            else {
                
                if (A[i] > A[j]) {
                    int x = A[i];
                    A[i] = A[j];
                    A[j] = x;
                }
            }
        }
    }
}


void exercise1() {

    const int size = 10;
    int A[size];
    int choice;
    cout << "Choice 1 - descending, 0 - ascending ";
    cin >> choice;
    for (int i = 0; i < size; i++) {
            A[i] = rand() % 100;
            cout << A[i] << " ";
    }
    cout << endl;
   
    sort(A, size, choice);

    cout << "Result " << endl;
    for (int i = 0; i < size; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}






void exercise2() {

    const int size = 20;
    int A[size];
    
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 41 - 20;
        cout << A[i] << " ";
    }
    cout << endl;
    int leftNegative = -1, rightNegative = -1;
    for (int i = 0; i < size; i++) {
        if (A[i] < 0) {
            leftNegative = i;
            break;
        }
    }
    for (int i = size - 1; i > 0; i--) {
        if (A[i] < 0) {
            rightNegative = i;
            break;
        }
    }
    cout << leftNegative << " " << rightNegative << endl;

    for (int i = leftNegative; i < rightNegative - 1; i++) {
        for (int j = i + 1; j < rightNegative - 1; j++) {
            if (A[i] > A[j]) {
                int x = A[i];
                A[i] = A[j];
                A[j] = x;
            }
        }
    }

    cout << "Result " << endl;
    for (int i = 0; i < size; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}





void exercise3() {

    const int size = 20;
    int A[size];

    for (int i = 0; i < size; i++) {
        A[i] = rand() % 20 + 1;
        cout << A[i] << " ";
    }
    cout << endl;
    // 1
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int x = A[i];
        A[i] = A[j];
        A[j] = x;
    }
    cout << "1) Result " << endl;
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;
    //2
    int k = rand() % 20 + 1;
    int indexK = -1;
    for (int i = 0; i < size; i++) {
        if (A[i] == k) {
            indexK = i;
        }
    }
    cout << "2) Result " << endl << k << " " << indexK << endl << endl;
    //3
     
    for (int i = 0; i < indexK - 1; i++) {
        for (int j = i + 1; j < indexK; j++) {
            if (A[i] < A[j]) {
                int x = A[i];
                A[i] = A[j];
                A[j] = x;
            }
        }
    }

    for (int i = indexK + 1; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (A[i] > A[j]) {
                int x = A[i];
                A[i] = A[j];
                A[j] = x;
            }
        }
    }





    cout << "3) Result " << endl;
    for (int i = 0; i < size; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    exercise1();
    exercise2();
    exercise3();
}

