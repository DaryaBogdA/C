#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <cmath>
using namespace std;

int factorial( int n) {

    if (n == 0) {
        return 1;
    }
   
    else if (n == 1) {
        return 1;
    }

    else {
        return n * factorial(n - 1);
    }
}




//1
void exercise1(int num) {
	int count = 0;
	while (num > 0) {
		num /= 10;
		count++;
	}
	cout<< count << endl;

}

int exercise1WithRecurs(int num) {
	if (num == 0) return 0;
	else return 1 + exercise1WithRecurs(num / 10);
}


//2
void exercise2(int n) {
	double y = 0;
	for (int i = n; i > 0; i--) {
		y = sqrt(y + i);
	}
	cout << y << endl;
}

double exercise2WithRecurs(int num) {
	if (num == 1) return 1;
	return sqrt(num + exercise2WithRecurs(num - 1));
}
//double exercise2WithRecurs(int num, int num2) {
//	if (num == 1) return 1;
//	else {
//		return sqrt(num2 + exercise2WithRecurs(num - 1));
//	}
//}



//3
void exercise3(int n) {
	double s = 0;
	for (double i = 1; i <= n; i++) {
		s += double(1) / factorial(i);
	}
	cout << s << endl;
}

double exercise3WithRecurs(int num) {
	if (num == 1) return 1;
	return double(1) / factorial(num) + exercise3WithRecurs(num - 1);
}



//4
double exercise4WithRecurs(int num) {
	if (num == 1) return 1;
	return double(1) + 0.2 * exercise4WithRecurs(num - 1);
}



//5
double exercise5WithRecurs(int num) {
	if (num == 1) return 1;
	return 1 / (num + exercise4WithRecurs(num - 1));
}
int main() {
	//1
	/*exercise1(1234567890);
	int num = 1234567890;
	cout << exercise1WithRecurs(num);
	return 0;*/

	//2
	//exercise2(7);
	/*double n = 7;
	cout << exercise2WithRecurs(n);
	return 0;*/

	//3
	//exercise3(7);
	/*double n = 7;
	cout << exercise3WithRecurs(n);
	return 0;*/

	//4
	/*double n = 7;
	cout << exercise4WithRecurs(n);
	return 0;*/

	//5
	double n = 7;
	cout << exercise5WithRecurs(n);
	return 0;





}













//int factorial( int n) {
//
//    if (n == 0) {
//        return 1;
//    }
//   
//    else if (n == 1) {
//        return 1;
//    }
//
//    else {
//        return n * factorial(n - 1);
//    }
//}
//
//int main() {
//    int number = 5;
//    int result = factorial(number);
//    cout << "Факториал " << number << "! равен " << result << endl;
//    return 0;
//}




//template <class T> 
//void quickSortR(T a[], long N) {
//	// На входе - массив a[], a[N] - его последний элемент. 
//	// // поставить указатели на исходные места 
//	long i = 0, j = N; 
//	T temp, p; 
//	p = a[ N/2 ]; // центральный элемент 5 
//	// процедура разделения
//	do { 
//		while ( a[i] < p ) i++; 
//		while ( a[j] > p ) j--; 
//		if (i <= j){ 
//			temp = a[i];
//			a[i] = a[j];
//			a[j] = temp;
//			i++; j--;
//		} 
//	}while ( i<=j ); 
//	// рекурсивные вызовы, если есть, что сортировать 
//	if ( j > 0 ) quickSortR(a, j); 
//	if ( N > i ) quickSortR(a+i, N-i); 
//} 
//void main(){ 
//	const long SIZE=10; 
//	int ar[SIZE]; 
//	// до сортировки 
//	for(int i=0;i<SIZE;i++){ 
//		ar[i]=rand()%100; 
//		cout<<ar[i]<<" "; } 
//	cout<<"\n\n"; 
//	quickSortR(ar,SIZE-1); 
//	// после сортировки 
//	for(int i=0;i<SIZE;i++){ 
//		cout<<ar[i]<<" "; } 
//	cout<<"\n\n"; 
//}



