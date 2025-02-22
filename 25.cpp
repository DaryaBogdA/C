#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
using namespace std;
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    void print() const {
        cout << real << "+" << imag << "i" << endl;
    }
};

void exercize_1() {

    Complex digit_1(5, 7);
    Complex digit_2(4, 6);
    Complex summa = digit_1 + digit_2;
    Complex subtraction = digit_1 - digit_2;
    Complex multiplication = digit_1 * digit_2;

    cout << "Number 1: ";
    digit_1.print();
    cout << "Number 2: ";
    digit_2.print();
    cout << "Summa: ";
    summa.print();
    cout << "Subtraction: ";
    subtraction.print();
    cout << "Multiplication: ";
    multiplication.print();
}


class Take {
public:
    int cards[11];
    int card_count;

    Take() {
        card_count = 0;
    }

    void addCard() {
        int value = (rand() % 13) + 1;
        if (card_count < 11) {
            cards[card_count++] = value;
        }
    }

    int getTotal() {
        int total = 0;
        int aces = 0;
        for (int i = 0; i < card_count; ++i) {
            int value = cards[i];
            if (value == 11) {
                value = 2; // J = 2
            }
            else if (value == 12) {
                value = 3; // Q = 3
            }
            else if (value == 13) {
                value = 4; // K = 4
            }
            if (value == 1) aces++; // Ace
            total += value;
        }
        return total;
    }
};

void win(Take player_1, Take player_2) {
    if (player_1.getTotal() == 21) {
        cout << "Player 1 win  " << endl;
    }
    else if (player_2.getTotal() == 21) {
        cout << "Player 2 win  " << endl;
    }
    else if (player_1.getTotal() > 21) {
        cout << "Player 2 win  " << endl;
    }
    else if (player_2.getTotal() > 21) {
        cout << "Player 1 win  " << endl;
    }
    else if (player_1.getTotal() > player_2.getTotal() && player_1.getTotal() < 21) {
        cout << "Player 1 win  " << endl;
    }
    else if (player_2.getTotal() > player_1.getTotal() && player_2.getTotal() < 21) {
        cout << "Player 2 win  " << endl;
    }
}

void exercize_2() {
    srand(time(0));
    Take player_1;
    Take player_2;

    player_1.addCard();
    player_1.addCard();

    player_2.addCard();
    player_2.addCard();

    cout << "Player 1 count: " << player_1.getTotal() << endl;
    cout << "Player 2 count: " << player_2.getTotal() << endl;
    char choise;
    while (true) {
        cout << "Does player 1 take card? 1 - yes 2 - no" << endl;
        cin >> choise;
        if (choise == '1') {
            player_1.addCard();
        }
        cout << "Player 1 count: " << player_1.getTotal() << endl;
        if (choise == '2') {
            break;
        }
    }
    while (true) {
        cout << "Does player 2 take card? 1 - yes 2 - no" << endl;
        cin >> choise;
        if (choise == '1') {
            player_2.addCard();
        }
        cout << "Player 2 count: " << player_2.getTotal() << endl;
        if (choise == '2') {
            break;
        }
    }
    win(player_1, player_2);
}


void Printf(int count, const char* str[]) {
    for (int i = 0; i < count; ++i) {
        cout << str[i] << " ";
    }
    cout << endl;
}

//int main() {
//    const char* args[] = { "Hi", "my", "name", "is", "jflkasjd", "fjdksfl", "fdafds", "HIIIIII" };
//    int count = sizeof(args) / sizeof(args[0]);
//    Printf(count, args);
//
//}








class Temp
{
    int TEMP;
public:
    //конструктор
    Temp() { TEMP = 25; }
    //функция показа на экран
    void TempFunction() {
        cout << "TEMP = " << TEMP << "\n\n";
    }
    //функция установки значения
    void TempSet(int T) {
        TEMP = T;
    }
};
// Класс, реализующий умный указатель
class SmartPointer
{
    //указатель
    Temp* ptr;
    //счётчик копий 
    int count_copy;

public:
    //конструктор
    SmartPointer(Temp* p = NULL) {
        //записываем 0 при создании копий нет
        count_copy = 0;
        ptr = p;
    }
    // конструктор копирования
    SmartPointer(const SmartPointer& obj) {
        //создается копия - увеличиваем счётчик
        ptr = obj.ptr;
        count_copy++;
    }
    //перегрузка оператора равно
    SmartPointer operator=(const SmartPointer& obj) {
        //создается копия - увеличиваем счётчик
        ptr = obj.ptr;
        ptr = obj.ptr;
        count_copy++;
        //возвращаем сам объект для ситуации a=b=c
        return *this;
    }
    // уничтожение объекта
    ~SmartPointer() {
        //если объект есть и копий нет
        if (ptr != NULL && count_copy == 0) {
            cout << "\n~Delete Object\n";
            //уничтожаем объект
            delete[]ptr;
        }
        //в противном случае(уничтожается копия)
        else {
            //уменьшаем счётчик
            count_copy--;
            cout << "\n~Delete Copy\n";
        }

    }
    //старая добрая перегрузка селектора
    Temp* operator->() {
        return ptr;
    }

};

//void main() {
//    //создаем объект
//    Temp* main_ptr = new Temp;
//    //инициализируем этим объектом умный указатель
//    SmartPointer PTR(main_ptr);
//    //проверяем работу умного указателя
//    PTR->TempSet(100);
//    PTR->TempFunction();
//    // создаем копию (работа конструктора копирования)
//    SmartPointer PTR2 = PTR;
//}



double sum(int count, ...) {
    va_list args;
    va_start(args, count);  // Инициализация списка аргументов

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int); // Получение следующего аргумента 
    }

    va_end(args);  // Очистка списка аргументов
    return total;
}

int main() {
    int a = sum(5, 1, 2, 3, 4, 5);
    cout << a << endl; // Вывод: Sum: 15
    return 0;
}