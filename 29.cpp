#include <iostream>
#include <windows.h>
#include <filesystem>
#include <direct.h>
#include <stdio.h>
#include <fstream>

using namespace std;
using namespace std::filesystem;

// Переименовать существующую директорию
void RenameDirectory()
{
	char oldName[50], newName[50];

	// В одной переменной запомним существующее имя (oldName), 
	cout << "Enter old name:";
	cin >> oldName;

	// А в другой новое имя(newName)
	cout << "Enter new name:";
	cin >> newName;

	// Произведем переименование и проверку результата
	if (rename(oldName, newName) != 0)
		cout << "Error!\n Couldn't rename directory.\n\n";
	else
		cout << "Ok...\n\n";
}

// Удалить существующую директорию
void RemoveDirectory()
{
	char Name[50];
	// Получаем имя и путь к удаляемой директории
	cout << "Enter name:";
	cin >> Name;

	//Удаляем директорию и проверяем результат	
	if (_rmdir(Name) == -1)
		cout << "Error!\n Couldn't remove directory.\n";
	else
		cout << "Ok...\n";
}
// Создать директорию
void CreateDirectory()
{
	char Name[50];
	// Получаем имя и путь к создаваемой директории
	cout << "Enter name:";
	cin >> Name;

	//Создаем директорию и проверяем результат	
	if (_mkdir(Name) == -1)
		cout << "Error!\n Couldn't create directory.\n";
	else
		cout << "Ok...\n";
}


void katalogy()
{
	// предлагаем выбрать пункт меню для выполнения
	cout << "Please, select preffer number...\n";

	//выбор пользователя
	char ch;
	do {
		// Переименовать
		cout << "\n1 - Rename\n";
		// Удалить   
		cout << "2 - Remove\n";
		// Создать
		cout << "3 - Create\n";
		// Выход
		cout << "0 - Exit\n\n";
		cin >> ch;

		// анализируем и вызываем 
		// соответствующую  функцию
		switch (ch)
		{
		case '1':
			RenameDirectory();
			break;
		case '2':
			RemoveDirectory();
			break;
		case '3':
			CreateDirectory();
			break;
		}
	} while (ch != '0');      // Выход из программы
}


//void copy_directory(string name, string copy_name) {
//
//	copy(name, copy_name, copy_options::recursive);
//	cout << "Yes" << endl;
//
//}

void go(string name, string rename_name) {
	rename(name, rename_name);
	cout << "Yes" << endl;
}

void remove_directory()
{
	char name[50];
	cout << "Enter name:";
	cin >> name;

	if (_rmdir(name) == -1)
		cout << "Error!" << endl;
	else
		cout << "Yes" << endl;
}


void exercise_1() {
	//copy_directory("asdf", "fda");
	//go("asdf", "fda"); //РАБОТАЕТ БУХАЕМ
	//remove_directory();
}








int main() {
	//katalogy();
	//exercise_1();
	ofstream file("fiels.txt");
	if (file.is_open()) {
		file << "asdfasdf" << endl;
		file.close();
	}
}


