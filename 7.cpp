#include<iostream> 
#include<stdlib.h> 
// в этом файле содержатся rand и srand 
#include<time.h> 
using namespace std;
void exirsize1() {
	const int m = 3;
	const int n = 4;
	int count = 0;
	int A[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = rand() % 100;
			cout << A[i][j] << " ";
		}
		cout << "\n\n";
	}
	cout << "\n\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] == 0)
				count++;
		}
	}
	cout << "Number of zeros in the matrix: " << count << endl;
}



void exirsizeA() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 4; j >= i; j--) {
			matrix[i][j] = 1;

		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}




void exirsizeB() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			matrix[i][j] = 1;

		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}


void exirsizeC() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i <= j && i + j <= 4) {
				matrix[i][j] = 1;
			}

		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}





void exirsizeD() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= j && i + j >= 4) {
				matrix[i][j] = 1;
			}

		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}


void exirsizeE() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == 4 || (i == 1 && j >= 1 && j <= 3) || (i == 3 && j >= 1 && j <= 3) || (i == 2 && j == 2)) {
				matrix[i][j] = 1;
			}

		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}



void exirsizeF() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0 || j == 4 || (j == 1 && i >= 1 && i <= 3) || (j == 3 && i >= 1 && i <= 3) || (j == 2 && i == 2)) {
				matrix[i][j] = 1;
			}

		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}


void exirsizeG() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j <= n - i - 1) {
				matrix[i][j] = 1;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}









void exirsizeH() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 4; j >= i; j--) {
			if (j >= n - i - 1) {
				matrix[i][j] = 1;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}








void exirsizeI() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {

			matrix[i][j] = 1;

		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}



void exirsizeK() {
	const int n = 5;
	int matrix[n][n];


	for (int i = 0; i < n; i++) {
		for (int j = 4; j >= 4 - i; j--) {
			if (j >= 0 && j < n) {
				matrix[i][j] = 1;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 1) {
				matrix[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}





int main()
{
	//exirsize1();

	//exirsizeA();
	//exirsizeB();
	//exirsizeC();
	//exirsizeD();
	//exirsizeE();
	//exirsizeF();
	//exirsizeG();
	//exirsizeH();
	//exirsizeI();
	//exirsizeK();

}