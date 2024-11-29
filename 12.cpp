
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;


void swap(int* pOdd, int* pEven) {
	int x = *pOdd;
	*pOdd = *pEven;
	*pEven = x;
}

void result(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void randomNum(int array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10;
		cout << array[i] << " ";
	}
	cout << endl;
}

void sort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] > array[j]) {
				int x = array[i];
				array[i] = array[j];
				array[j] = x;
			}
		}
	}

}

//void associationArray(int array1[], int array3[], int size1, int size2) {
//	for (int i = 0; i < size1; i++) {
//		array3[size2] = array1[i];
//		size2++;
//	}
//}

void associationArray(int* pindexarray1, int* pindexarray2, int* pindexarray3, int size) {
	for (int i = 0; i < size; i++) {
		*pindexarray3 = *pindexarray1;
		pindexarray3++;
		*pindexarray3 = *pindexarray2;
		pindexarray3++;
		pindexarray2++;
		pindexarray1++;
	}

}
void associationArray2(int* pindexarray1, int* pindexarray2, int* pindexarray3, int size) {
	for (int i = 0; i < size; i++) {
		if (*pindexarray1 != *pindexarray2) {
			*pindexarray3 = *pindexarray1;
			pindexarray3++;
			*pindexarray3 = *pindexarray2;
			pindexarray3++;
			pindexarray2++;
			pindexarray1++;

		}
	}

}
int main()
{
	//1 
	/*int m = 6;
	int* array = new int[m];
	randomNum(array, m);
	int* pOdd;
	int* pEven;
	for (int i = 0; i < m; i++) {
		if (array[i] % 2 != 0) {
			if (i != 0) {
				pOdd = &array[i];
				pEven = &array[i - 1];
				swap(pEven, pOdd);
			}
		}
	}
	result(array, m);*/

	//2
	/*int m = 6, n = 7, x = m + n;
	int *array1 = new int[n];
	cout << "1 array" << endl;
	randomNum(array1, n);

	int *array2 = new int[m];
	cout << " 2 array" << endl;
	randomNum(array2, m);
	int *array3 = new int[x];

	cout << "1 sort" << endl;
	sort(array1, n);
	result(array1, n);

	cout << "2 sort" << endl;
	sort(array2, m);
	result(array2, m);

	cout << "3 array" << endl;
	associationArray(array1, array2, array3, x);
	sort(array3, x);
	result(array3, x);*/


	//3
	int m = 6, n = 7, x = m + n;
	int* array1 = new int[n];
	cout << "1 array" << endl;
	randomNum(array1, n);

	int* array2 = new int[m];
	cout << " 2 array" << endl;
	randomNum(array2, m);
	int* array3 = new int[x];

	cout << "3 array" << endl;
	associationArray(array1, array2, array3, x);
	sort(array3, x);
	result(array3, x);

	cout << "3 array 2" << endl;
	associationArray2(array1, array2, array3, x);
	sort(array3, x);
	result(array3, x);

}
