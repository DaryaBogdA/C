#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()
#include <algorithm> // для transform

/*struct Node { // Определяем структуру данных "Node" (узел).
	int data;     // Целое число data - хранит данные в узле.
	Node* left, * right; // Указатели left и right - указывают на левое и правое поддеревья соответственно.  

	Node(int data) : data(data), left(nullptr), right(nullptr) {} // Конструктор структуры.  Инициализирует data переданным значением, а left и right - nullptr.
};


Node* binomialTree(int k) { // Рекурсивная функция для построения биномиального дерева. Принимает порядок дерева k и возвращает указатель на корень.
	if (k == 0) { // Базовый случай рекурсии: если порядок 0,
		return new Node(0); // создаем узел с данными 0 и возвращаем его.
	}
	else { // Рекурсивный случай:
		Node* left = binomialTree(k - 1); // Рекурсивно строим левое поддерево порядка k-1.
		Node* right = binomialTree(k - 1); // Рекурсивно строим правое поддерево порядка k-1.
		Node* root = new Node(k); // Создаем корневой узел с данными k.
		root->left = left; // Присоединяем левое поддерево к корню.
		root->right = right; // Присоединяем правое поддерево к корню.
		return root; // Возвращаем указатель на корень построенного дерева.
	}
}


void printTree(Node* root, int level = 0) { // Функция для обхода и печати дерева.  level - уровень вложенности (для форматирования вывода).
	if (root == nullptr) return; // Базовый случай: если узел пуст, ничего не делаем.
	printTree(root->right, level + 1); // Рекурсивно обходим правое поддерево.
	for (int i = 0; i < level; ++i) std::cout << "  "; // Выводим отступы для визуализации уровня вложенности.
	std::cout << root->data << std::endl; // Выводим данные текущего узла.
	printTree(root->left, level + 1); // Рекурсивно обходим левое поддерево.
}


int main() {
	int k = 5; // порядок
	Node* root = binomialTree(k);
	std::cout << "Binomial Tree " << k << ":" << std::endl;
	printTree(root); // Вывод
	return 0;
}


Функции библиотеки stdio.h

FILE *fopen(const char *filename, const char *mode)

int fclose( FILE *stream )

FILE *fp;
// Открытие файла для записи
fp = fopen("my_file.txt", "w");
fclose(fp);


char *fgets( char *string, int n, FILE *stream )

int fputs( const char *string, FILE *stream )

size_t fread( void *buffer, size_t size, size_t count, FILE *stream )

size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream )

int feof( FILE *stream )

int _fileno( FILE *stream )

int fseek ( FILE *stream, int offset [, int whence] )


Функции библиотеки io.h

int _access( const char *path, int mode )

long _filelength( int handle )

int _locking( int handle, int mode, long nbytes )





using namespace std;

int main() {
	string sourceFilePath, destinationFilePath;

	cout << "Введите путь к файлу-источнику: ";
	getline(cin, sourceFilePath); // Используем getline для обработки пробелов в пути

	cout << "Введите путь и имя для файла-копии: ";
	getline(cin, destinationFilePath);

	// Проверка существования файла-источника
	ifstream sourceFile(sourceFilePath, ios::binary);
	if (!sourceFile.is_open()) {
		cerr << "Ошибка: Не удалось открыть файл-источник." << endl;
		return 1; // Возвращаем код ошибки
	}

	// Создание файла-копии
	ofstream destinationFile(destinationFilePath, ios::binary);
	if (!destinationFile.is_open()) {
		cerr << "Ошибка: Не удалось создать файл-копию." << endl;
		sourceFile.close(); // Закрываем исходный файл
		return 1;
	}

	// Копирование данных
	char buffer[1024]; // Буфер для чтения данных
	size_t bytesRead;
	while ((bytesRead = sourceFile.readsome(buffer, sizeof(buffer))) > 0) {
		destinationFile.write(buffer, bytesRead);
	}

	// Проверка на ошибки при записи
	if (destinationFile.fail()) {
		cerr << "Ошибка: Ошибка при записи в файл-копию." << endl;
		sourceFile.close();
		destinationFile.close();
		return 1;
	}

	// Закрытие файлов
	sourceFile.close();
	destinationFile.close();

	cout << "Файл скопирован успешно." << endl;
	return 0; // Возвращаем 0, если все прошло успешно
}





using namespace std;

// Функция для выбора случайного слова из файла
string getRandomWord(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Error no open " << filename << endl;
		return ""; // Возвращаем пустую строку в случае ошибки
	}

	vector<string> words;
	string word;
	while (getline(file, word)) {
		words.push_back(word);
	}
	file.close();

	if (words.empty()) {
		cerr << "Error " << filename << " zero." << endl;
		return "";
	}

	// Инициализация генератора случайных чисел
	srand(time(0));
	return words[rand() % words.size()];
}

int main() {
	string filename = "words.txt";
	string secretWord = getRandomWord(filename);
	if (secretWord.empty()) return 1; // Выход при ошибке чтения файла

	string guessedLetters;
	int maxAttempts = 6;
	int attemptsRemaining = maxAttempts;

	// Преобразуем слово в верхний регистр для единообразия
	transform(secretWord.begin(), secretWord.end(), secretWord.begin(), ::toupper);

	string currentGuess(secretWord.length(), '_');

	while (attemptsRemaining > 0 && currentGuess != secretWord) {
		cout << "\nattempts left: " << attemptsRemaining << endl;
		cout << "Guess the word: " << currentGuess << endl;
		cout << "Guessed letters : " << guessedLetters << endl;

		char guess;
		cout << "Enter letter: ";
		cin >> guess;
		guess = toupper(guess); // Преобразуем в верхний регистр

		bool correctGuess = false;
		if (guessedLetters.find(guess) == string::npos) { // Проверка на повтор буквы
			guessedLetters += guess;
			for (size_t i = 0; i < secretWord.length(); ++i) {
				if (secretWord[i] == guess) {
					currentGuess[i] = guess;
					correctGuess = true;
				}
			}
			if (!correctGuess) {
				attemptsRemaining--;
			}
		}
		else {
			cout << "You have already guessed this letter.." << endl;
		}
	}

	if (currentGuess == secretWord) {
		cout << "\nYou win: " << secretWord << endl;
	}
	else {
		cout << "\nyou lose word: " << secretWord << endl;
	}

	return 0;
}

*/

