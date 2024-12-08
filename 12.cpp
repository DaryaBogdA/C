
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

int* associationArray(int* pindexarray1, int* pindexarray2, int size) {
	int* pindexarray3 = new int[size];
	for (int i = 0; i < size; i++) {
		*pindexarray3 = *pindexarray1;
		pindexarray3++;
		*pindexarray3 = *pindexarray2;
		pindexarray3++;
		pindexarray2++;
		pindexarray1++;
	}

	return pindexarray3;
}




int size(const int* arr, int size) {
    return size;
}
//все
int* association(const int* arrA, int n, const int* arrB, int m) {
    int* mergedArr = new int[n + m];
    for (int i = 0; i < n; i++) {
        mergedArr[i] = arrA[i];
    }
    for (int i = 0; i < m; i++) {
        mergedArr[n + i] = arrB[i];
    }
    return mergedArr;
}


// общие
int* common_elements(const int* arrA, const int* arrB, int n,  int m) {
    int* common = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrA[i] == arrB[j]) {
                common[count++] = arrA[i];
                break;
            }
        }
    }
    int* result = new int[count];
    for (int i = 0; i < count; i++) {
        result[i] = common[i];
    }
    return result;
}

// эл не в В

int* elements_not_in_B(const int* arrA, int n, const int* arrB, int m) {
    int* result = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (arrA[i] == arrB[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[count++] = arrA[i];
        }
    }
    int* finalResult = new int[count];
    for (int i = 0; i < count; i++) {
        finalResult[i] = result[i];
    }
    return finalResult;
}

// эл не в A
int* elements_not_in_A(const int* arrA, int n, const int* arrB, int m) {
    int* result = new int[m];
    int count = 0;
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arrB[i] == arrA[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[count++] = arrB[i];
        }
    }
    int* finalResult = new int[count];
    for (int i = 0; i < count; i++) {
        finalResult[i] = result[i];
    }
    return finalResult;
}


// обьед не общих
int* unification_of_noncommon(const int* arrA, int n, const int* arrB, int m) {
    int* elementsA = elements_not_in_B(arrA, n, arrB, m);
    int countA = n;
    int* elementsB = elements_not_in_A(arrA, n, arrB, m);
    int countB = m;

    int* result = new int[countA + countB];
    for (int i = 0; i < countA; i++) {
        result[i] = elementsA[i];
    }

    for (int i = 0; i < countB; i++) {
        result[countA + i] = elementsB[i];
    }

    return result;
}


void result(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main()
{
	//1 
	/*int m = 6;
	int* array = new int[m];
	randomNum(array, m);
	int* pOdd;
	int* pEven;
	for (int i = 1; i < m; i++) {
		if (array[i] % 2 != 0) {
				pOdd = &array[i];
				pEven = &array[i - 1];
				swap(pEven, pOdd);
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

	cout << "1 sort" << endl;
	sort(array1, n);
	result(array1, n);

	cout << "2 sort" << endl;
	sort(array2, m);
	result(array2, m);

	cout << "3 array" << endl;
	int *array3 = associationArray(array1, array2, x);
	sort(array3, x);
	result(array3, x);*/


	//3
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    int* arrA = new int[n];
    int* arrB = new int[m];
    cout << "Array A " << endl;
    for (int i = 0; i < n; ++i) {
        arrA[i] = rand() % 10;
        cout << arrA[i] << " ";
    }
    cout << endl;
    cout << "Array B " << endl;
    for (int i = 0; i < m; ++i) {
        arrB[i] = rand() % 10;
        cout << arrB[i] << " ";
    }
    cout << endl;

    cout << "Association ";
    int* paragraph1 = association(arrA, n, arrB, m);
    result(paragraph1, n + m);

    cout << "Common Elements ";
    int* paragraph2 = common_elements(arrA, arrB, n, m);
    result(paragraph2, size(paragraph2, min(n, m)));

    cout << "Elements of A, not in B: ";
    int* paragraph3 = elements_not_in_B(arrA, n, arrB, m);
    result(paragraph3, size(paragraph3, n));

    cout << "Elements of B, not in A: ";
    int* paragraph4 = elements_not_in_A(arrA, n, arrB, m);
    result(paragraph4, size(paragraph4, m));

    cout << "Combining elements that are not common: ";
    int* paragraph5 = unification_of_noncommon(arrA, n, arrB, m);
    result(paragraph5, size(paragraph5, n + m));

}


