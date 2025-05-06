#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>

using namespace std;
void exercise_1() {
	vector<int> squares;
	for (int i = 1; i < 11; i++) {
		squares.push_back(i * i);
	}
	for (int num : squares) {
		cout << num << endl;
	}
}
void exercise_2() {
    int size = 10; 
    vector<vector<int>> table(size, vector<int>(size)); 

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            table[i-1][j-1] = i * j;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << table[i][j] << "\t"; 
        }
        cout << endl;
    }
}


class Student {
private:
    string name;
    string surname;
    int cours;
public:
    Student(string name, string surname, int cours) {
        this->name = name;
        this->surname = surname;
        this->cours = cours;
    }
    void show() {
        cout << name << " " << surname << ' ' << cours << endl;
    }
    string get_name() {
        return name;
    }
    string get_surname() {
        return surname;
    }
    int get_cours() {
        return cours;
    }
};

void fill(vector<Student>& students) {
    students.push_back(Student("Bob", "Drover", 2));
    students.push_back(Student("Annn", "Surikova", 3));
    students.push_back(Student("Pete", "Vrebod", 1));
    students.push_back(Student("Maria", "Himor", 4));
    students.push_back(Student("Andry", "Smirtel", 2));
    students.push_back(Student("Dener", "Wertyl", 1));
    students.push_back(Student("Dimer", "Derka", 3));
}

void show(vector<Student>& students) {
    for (Student& s : students) {
        s.show();
    }
}

void sort_name(vector<Student>& students) {
    for (int i = 0; i < students.size(); i++) {
        for (int j = 0; j < students.size() - 1; j++) {
            if (students[j].get_name() > students[j + 1].get_name()) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void sort_surname(vector<Student>& students) {
    for (int i = 0; i < students.size(); i++) {
        for (int j = 0; j < students.size() - 1; j++) {
            if (students[j].get_surname() > students[j + 1].get_surname()) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void last_sort(vector<Student>& students) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < students.size(); j++) {
            if (students[j].get_cours() < students[i].get_cours()) {
                swap(students[i], students[j]);
            }
        }
    }
}

int main()
{
    //exercise_1();
    //exercise_2();
    vector<Student> students;
    cout << "-----------------------" << endl;
    fill(students);
    show(students);

    sort_name(students);
    cout << "-----------------------" << endl;
    cout << "------Sort name" << endl;
    for (Student& s : students) s.show();

    sort_surname(students);
    cout << "-----------------------" << endl;
    cout << "------Sort surname" << endl;
    for (Student& s : students) s.show();

    last_sort(students);
    cout << "-----------------------" << endl;
    cout << "------Last sort" << endl;
    for (Student& s : students) s.show();
}



// vector
 

//push_back(x)	Добавляет элемент x в конец
//pop_back()	Удаляет последний элемент
//insert(pos, x)	Вставляет x в позицию pos
//erase(pos)	Удаляет элемент в позиции pos
//clear()	Очищает все элементы вектора
//
//
//size()	Возвращает количество элементов
//capacity()	Возвращает выделенный объём памяти
//resize(n)	Изменяет размер вектора до n
//reserve(n)	Выделяет память под n элементов(ускоряет push_back)
//
//
//operator[]	Доступ по индексу(без проверок)
//at(i)	Доступ по индексу с проверкой
//front()	Первый элемент
//back()	Последний элемент
//
//
//begin()	Указатель на первый элемент
//end()	Указатель после последнего элемента
//rbegin()	Обратный итератор(с конца)
//rend()	Обратный итератор(до начала)



//list



//push_back(x)	Добавляет элемент x в конец
//push_front(x)	Добавляет x в начало
//pop_back()	Удаляет последний элемент
//pop_front()	Удаляет первый элемент
//insert(pos, x)	Вставляет x перед pos(итератор)
//erase(pos)	Удаляет элемент по pos(итератор)
//clear()	Удаляет все элементы

//size()	Возвращает количество элементов
//empty()	Проверяет, пуст ли список
//resize(n)	Изменяет размер(добавляет или удаляет элементы)

//front()	Возвращает первый элемент
//back()	Возвращает последний элемент

//begin()	Указатель на первый элемент
//end()	Указатель после последнего элемента
//rbegin()	Обратный итератор(с конца)
//rend()	Обратный итератор(до начала)
void List() {
    list<int> numbers = { 1, 2, 3, 4, 5 };

    numbers.push_front(0); 
    numbers.push_back(6);   

    cout << "Элементы списка: ";
    for (int num : numbers) {
        cout << num << " ";
    }
}


//map


//insert({ key, value })	Добавляет пару ключ - значение(если ключа нет)
//erase(key)	Удаляет элемент по ключу
//clear()	Удаляет все элементы
//emplace(key, value)	Добавляет без лишнего копирования(лучше insert)

//operator[]	Возвращает значение по ключу(если ключа нет, создаёт новый)
//at(key)	Возвращает значение(если ключа нет → std::out_of_range!)

//size()	Количество элементов
//empty()	Проверяет, пуст ли map

//find(key)	Возвращает итератор на найденный элемент или end()
//count(key)	Возвращает 1 (если ключ есть) или 0 (если нет)


void Map() {
    map<int, string> students;

    students.insert({ 1, "Alice" });
    students[2] = "Bob";   // Альтернативное добавление
    students.emplace(3, "Charlie");

    cout << "Студент с ключом 2: " << students.at(2) << endl;

    cout << "\nВсе студенты:\n";
    map<int, string>::iterator it = students.begin();
    while (it != students.end()) {
        cout << it->first << ": " << it->second << endl;
        it++;
    }
}


//multimap


//insert({ key, value })	Добавляет пару ключ - значение(даже если такой ключ уже есть)
//erase(key)	Удаляет все элементы с этим ключом
//clear()	Удаляет все элементы
//emplace(key, value)	Добавляет без лишнего копирования(лучше insert)

//find(key)	Возвращает итератор на первый найденный элемент с key или end()
//count(key)	Возвращает количество элементов с данным key
//equal_range(key)	Возвращает диапазон всех элементов с key
//lower_bound(key)	Первый элемент >= key
//upper_bound(key)	Первый элемент > key

void Multimap() {
    multimap<int, string> students;

    students.insert({ 1, "Alice" });
    students.insert({ 2, "Bob" });
    students.insert({ 2, "Charlie" });  // Дубликат ключа 2
    students.insert({ 3, "David" });

    cout << "Все студенты:\n";
    for (pair<const int, string>& pair : students) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\nСтуденты с ключом 2:\n";
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> range = students.equal_range(2);
    for (multimap<int, string>::iterator it = range.first; it != range.second; ++it) {
        cout << it->second << endl;
    }
}