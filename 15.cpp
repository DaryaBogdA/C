#include <iostream>
using namespace std;
void pr2()
{
	int i;
	// Переменные для описания характеристик массивов.
	int m1 = 5, m2 = 5;

	int** pArr = new int* [m1];
	for (i = 0; i < m1; i++)
		pArr[i] = new int[m2];
	pArr[3][3] = 100;
	cout << pArr[3][3] << "\n";

	for (i = 0; i < m1; i++)
		delete[]pArr[i];
	delete[]pArr;

}


void pr3(){
	 int i, j;
	// Переменные для описания характеристик массивов.
	int m1 = 5, m2 = 5, m3 = 2;

	// указатель на указатель на указатель :)
	int*** ppArr;
	// Создание массива
	ppArr = new int** [m1];
	for (i = 0; i < m1; i++)
		ppArr[i] = new int* [m2];
	for (i = 0; i < m1; i++)
		for (j = 0; j < m2; j++)
			ppArr[i][j] = new int[m3];

	ppArr[1][2][3] = 750;
	cout << ppArr[1][2][3] << "\n";
	// Удаление в последовательности, обратной созданию
	for (i = 0; i < m1; i++)
		for (j = 0; j < m2; j++)
			delete[]ppArr[i][j];
	for (i = 0; i < m1; i++)
		delete[]ppArr[i];
	delete[] ppArr;
}



void act1(char* name)
{
    cout << "Create file..." << name;
}
void act2(char* name)
{
    cout << "Delete file... " << name;
}
void act3(char* name)
{
    cout << "Read file... " << name;
}
void act4(char* name)
{
    cout << "Mode file... " << name;
}
void act5(char* name)
{
    cout << "Close file... " << name;
}
void pr4()
{
    // Создание и инициализация массива указателей
    void (*MenuAct[5])(char*) = { act1, act2, act3, act4,
   act5 };
    int number; // Номер выбранного пункта меню.
    char FileName[30]; // Строка для имени файла.
    // Реализация меню
    cout << "\n 1 - Create";
    cout << "\n 2 - Delete";
    cout << "\n 3 - Read";
    cout << "\n 4 - Mode";
    cout << "\n 5 - Close";
    while (1) // Бесконечный цикл.
    {
        while (1)
        { /* Цикл продолжается до ввода правильного
       номера.*/
            cout << "\n\nSelect action: ";
            cin >> number;
            if (number >>= 1 && number <= 5) break;
       
                cout << "\nError number!";
        }
        if (number != 5)
        {
            cout << "Enter file name: ";
            cin >> FileName; // Читать имя файла.
        }
        else break;
        // Вызов функции по указателю на нее:
        (*MenuAct[number - 1])(FileName);
    } // Конец бесконечного цикла.
}




























void columns(int** matrix, int cols, int rows, int index) {
    for (int i = 0; i < rows; i++) {
        for (int j = cols - 1; j > index; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][index] = 0;
    }
}

void rowns(int**& matrix, int cols, int rows, int index) {
    int** newMatrix = new int* [rows + 1]; 
    for (int i = 0; i <= rows; i++) {
        newMatrix[i] = new int[cols]; 
        if (i < index) { 
            for (int j = 0; j < cols; j++) { 
            newMatrix[i][j] = matrix[i][j]; 
            } 
        }
        else if (i == index) {
            for (int j = 0; j < cols; j++) {
                newMatrix[i][j] = 0; 
            }
        }
        else {
            for (int j = 0; j < cols; j++) {
                newMatrix[i][j] = matrix[i - 1][j];
            }
        }
    }
   
    matrix = newMatrix;

}

void exercise1() {
    int cols = 5, rows = 8;
    int** pArr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        pArr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pArr[i][j] = 1;
            cout << pArr[i][j] << " ";
        }
        cout << endl;
    }

    int choice, index;
    while (true) {
        cout << "What to add: columns (1) or rows (2): ";
        cin >> choice;
        cout << "Enter index: ";
        cin >> index;
        if (choice == 1) {
            columns(pArr, cols, rows, index);
            break;
        }
        else if (choice == 2) {
            rowns(pArr, cols, rows, index);
            break;
        }
        else{
            cout << "Are ypu stupid?" << endl;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << pArr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] pArr[i];
    }
    delete[] pArr;
}












//строки 
void shift_rows(int **matrix, int rows, int cols, int shifts) {
    for (int i = 0; i < shifts; i++) {
        int *temp = matrix[rows - 1]; 
        for (int j = rows - 1; j > 0; j--) { 
            matrix[j] = matrix[j - 1]; 
        } 
        matrix[0] = temp; 
    } 
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
} //столбики
void shift_cols(int **matrix, int rows, int cols, int shifts) {
    for (int i = 0; i < shifts; i++) {
        for (int j = 0; j < rows; j++) { 
            int temp = matrix[j][cols - 1]; 
            for (int k = cols - 1; k > 0; k--) { 
                matrix[j][k] = matrix[j][k - 1]; 
            } 
            matrix[j][0] = temp; 
            }
        }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}









void exercise2() {
    int rows = 5, cols = 5; 
    int** matrix = new int* [rows];
    cout << "Our matrix" << endl;
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 10;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int shifts;
    cout << "Enter line shifts: "; 
    cin >> shifts;
    cout << "Matrix after line shifts:" << endl;
    shift_rows(matrix, rows, cols, shifts);

    cout << "Enter columns shifts: "; 
    cin >> shifts;
    cout << "Matrix after columns shifts:" << endl;
    shift_cols(matrix, rows, cols, shifts);
    

    for (int i = 0; i < rows; ++i) { 
        delete[] matrix[i]; 
    } 
    delete[] matrix; 

}








int main() {
	//pr2();
	//pr3();
    pr4();
    //exercise1();
    //exercise2();
}
