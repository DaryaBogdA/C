#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;

//struct Element {
//    // Данные
//    char data;
//    // Адрес следующего элемента списка
//    Element* Next;
//};
//
//// Односвязный список
//class List {
//    // Адрес головного элемента списка
//    Element* Head;
//    // Адрес головного элемента списка
//    Element* Tail;
//    // Количество элементов списка
//    int Count;
//
//public:
//    // Конструктор
//    List() {
//        // Изначально список пуст
//        Head = Tail = NULL;
//        Count = 0;
//    }
//
//    // Деструктор
//    ~List() {
//        // Вызов функции удаления
//        DelAll();
//    }
//
//    // Добавление элемента в список
//    // (Новый элемент становится последним)
//    void Add(char data) {
//        // Создание нового элемента
//        Element* temp = new Element;
//
//        // Заполнение данными
//        temp->data = data;
//        // Следующий элемент отсутствует
//        temp->Next = NULL;
//        // Новый элемент становится последним элементом списка
//        // если он не первый добавленный
//        if (Head != NULL) {
//            Tail->Next = temp;
//            Tail = temp;
//        }
//        // Новый элемент становится единственным
//        // если он первый добавленный
//        else {
//            Head = Tail = temp;
//        }
//    }
//
//    void Add_with_position(int pos, char data) {
//
//        Element* temp = new Element;
//        temp->data = data;
//
//        if (pos == 1) {
//            temp->Next = Head;
//            Head = temp;
//            if (Count == 0) {
//                Tail = temp;
//            }
//        }
//        else {
//            Element* current = Head;
//            for (int i = 1; i < pos - 1; i++) {
//                current = current->Next;
//            }
//            temp->Next = current->Next;
//            current->Next = temp;
//            if (temp->Next == NULL) {
//                Tail = temp;
//            }
//        }
//        Count++;
//    }
//
//    void Del_with_position(int pos) {
//
//        Element* temp;
//        if (pos == 1) {
//            temp = Head;
//            Head = Head->Next;
//            if (Count == 1) {
//                Tail = NULL;
//            }
//        }
//        else {
//            Element* current = Head;
//            for (int i = 1; i < pos - 1; i++) {
//                current = current->Next;
//            }
//            temp = current->Next;
//            current->Next = temp->Next;
//            if (temp->Next == NULL) {
//                Tail = current;
//            }
//        }
//        delete temp;
//        Count--;
//    }
//
//    int Search(char data) {
//        Element* temp = Head;
//        int pos = 1;
//        while (temp != NULL) {
//            if (temp->data == data) {
//                return pos;
//            }
//            temp = temp->Next;
//            pos++;
//        }
//        return -1; 
//    }
//
//    // Удаление элемента списка
//    // (Удаляется головной элемент)
//    void Del() {
//        // Запоминаем адрес головного элемента
//        Element* temp = Head;
//        // Перебрасываем голову на следующий элемент
//        Head = Head->Next;
//        // Удаляем бывший головной элемент
//        delete temp;
//    }
//
//    // Удаление всего списка
//    void DelAll() {
//        // Пока еще есть элементы
//        while (Head != 0)
//            // Удаляем элементы по одному
//            Del();
//    }
//
//    // Распечатка содержимого списка
//    // (Распечатка начинается с головного элемента)
//    void Print() {
//        // Запоминаем адрес головного элемента
//        Element* temp = Head;
//        // Пока еще есть элементы
//        while (temp != 0) {
//            // Выводим данные
//            cout << temp->data << " ";
//            // Переходим на следующий элемент
//            temp = temp->Next;
//        }
//
//        cout << "\n\n";
//    }
//
//    // Получение количества элементов, находящихся в списке
//    int GetCount() {
//        // Возвращаем количество элементов
//        return Count;
//    }
//};
//
//// Тестовый пример
//void main() {
//    // Создаем объект класса List
//    List lst;
//
//    // Тестовая строка
//    char s[] = "Hello, World !!!\n";
//    // Выводим строку
//    cout << s << "\n\n";
//    // Определяем длину строки
//    int len = strlen(s);
//    // Загоняем строку в список
//    for (int i = 0; i < len; i++)
//        lst.Add(s[i]);
//    // Распечатываем содержимое списка
//    lst.Print();
//
//    lst.Add_with_position(7, 'X');
//    lst.Print();
//    int pos = lst.Search('W');
//    if (pos != -1) {
//        cout << "'W': " << pos << endl;
//    }
//    else {
//        cout << "'W' no" << endl;
//    }
//    // Удаляем три элемента списка
//    lst.Del();
//    lst.Del();
//    lst.Del();
//    //Распечатываем содержимое списка
//    lst.Print();
//}


//struct Elem {
//    int data; // данные
//    Elem* next, * prev;
//};
//
//class List {
//    // Голова, хвост
//    Elem* Head, * Tail;
//    // Количество элементов
//    int Count;
//
//public:
//
//    // Конструктор
//    List() {
//        Head = Tail = NULL;
//        Count = 0;
//    }
//    
//    // Деструктор
//    ~List() {
//        // Удаляем все элементы
//        DelAll();
//    }
//
//    // Получить количество
//    int GetCount() {
//        return Count;
//    }
//
//    // Получить элемент списка
//    Elem* GetElem(int pos) {
//        Elem* temp = Head;
//
//        // Позиция от 1 до Count?
//        if (pos < 1 || pos > Count) {
//            // Неверная позиция
//            cout << "Incorrect position !!!\n";
//            return 0;
//        }
//
//        int i = 1;
//        // Ищем нужный нам элемент
//        while (i < pos && temp != 0) {
//            temp = temp->next;
//            i++;
//        }
//
//        if (temp == 0)
//            return 0;
//        else
//            return temp;
//    }
//
//    // Удалить весь список
//    void DelAll() {
//        // Пока остаются элементы, удаляем по одному с головы
//        while (Count != 0)
//            Del();
//    }
//
//    // Удаление элемента, если параметр не указывается,
//    // то функция его запрашивает
//    void Del() {
//       // Счетчик
//        int i = 1;
//        Elem* Del = Head;
//
//        // Доходим до элемента, 
//        // который предшествует удаляемому
//        Elem* PrevDel = Del->prev;
//        // Доходим до элемента, который следует за удаляемым
//        Elem* AfterDel = Del->next;
//
//
//
//        Head = AfterDel;
//
//
//        // Удаление элемента
//        delete Del;
//
//        Count--;
//    }
//
//    
//
//    // Добавление в конец списка
//    void Add(int n) {
//        // Создаем новый элемент
//        Elem* temp = new Elem;
//        // Следующего нет
//        temp->next = 0;
//        // Заполняем данные
//        temp->data = n;
//        // Предыдущий - бывший хвост
//        temp->prev = Tail;
//
//        // Если элементы есть?
//        if (Tail != 0)
//            Tail->next = temp;
//
//        // Если элемент первый, то он одновременно и голова и хвост
//        if (Count == 0)
//            Head = Tail = temp;
//        else
//            // иначе новый элемент - хвостовой
//            Tail = temp;
//
//        Count++;
//    }
//
//    
//
//    // Печать списка
//    void Print() {
//        // Если в списке присутствуют элементы, то пробегаем по нему
//        // и печатаем элементы, начиная с головного
//        if (Count != 0) {
//            Elem* temp = Head;
//            cout << "( ";
//            while (temp->next != 0) {
//                cout << temp->data << ", ";
//                temp = temp->next;
//            }
//
//            cout << temp->data << " )\n";
//        }
//    }
//
//   
//
//    
//    };
//
//    // Тестовый пример
//    int main() {
//        List L;
//
//        L.Add(3);
//        L.Add(5);
//        L.Add(12);
//        L.Add(65);
//        L.Add(87);
//        L.Add(1);
//        L.Print();
//        L.Del();
//        L.Print();
//        return 0;
//    }


////параметризованный класс
//template <class T> class TestClass {
//private:
//	//объявим поле tempo
//	//какого оно будет типа,
//	//это можно будет выяснить ТОЛЬКО во 
//	//время создания конкретного экземпляра класса
//	T tempo;
//public:
//	TestClass() { tempo = 0; }
//	//тестируемая функция
//	T testFunc();
//};
//
////функция-член класса TestClass
////Так как метод реализован вне класса, 
////используем явное упоминание template
//template <class T>
//T TestClass<T>::testFunc() {
//	//программа выводит на экран количество байт
//	//занимаемое переменной tempo, типа T
//	cout << "Type's size is: " << sizeof(tempo) << "\n\n";
//	return tempo;
//}
//
//
//void main()
//{
//	//создадим конкретные экземпляры класса TestClass
//	//char
//	TestClass<char> ClassChar;
//	ClassChar.testFunc();
//	//int
//	TestClass<int> ClassInt;
//	ClassInt.testFunc();
//	//double
//	TestClass<double> ClassDouble;
//	ClassDouble.testFunc();
//}

//template <typename T>
//struct Elem
//{
//    // Любые данные
//    T data;
//    Elem* next, * prev;
//};
//
//template <typename T>
//class List
//{
//    // Голова хвост
//    Elem<T>* Head, * Tail;
//    int Count;
//
//public:
//
//    List();
//    List(const List&);
//    ~List();
//
//    int GetCount();
//    Elem<T>* GetElem(int);
//
//    void DelAll();
//    void Del(int);
//    void Del();
//
//    void AddTail();
//    void AddTail(T);
//
//    void AddHead(T);
//    void AddHead();
//
//    void Print();
//    void Print(int pos);
//
//    List& operator = (const List&);
//    List operator + (const List&);
//
//    bool operator == (const List&);
//    bool operator != (const List&);
//    bool operator <= (const List&);
//    bool operator >= (const List&);
//    bool operator < (const List&);
//    bool operator > (const List&);
//
//    List operator - ();
//};
//
//template <typename T>
//List<T>::List()
//{
//    Head = Tail = 0;
//    Count = 0;
//}
//
//template <typename T>
//List<T>::List(const List& L)
//{
//    Head = Tail = 0;
//    Count = 0;
//
//    Elem<T>* temp = L.Head;
//    while (temp != 0)
//    {
//        AddTail(temp->data);
//        temp = temp->next;
//    }
//}
//
//template <typename T>
//List<T>::~List()
//{
//    DelAll();
//}
//
//template <typename T>
//Elem<T>* List<T>::GetElem(int pos)
//{
//    Elem<T>* temp = Head;
//
//    // Позиция от 1 до Count?
//    if (pos < 1 || pos > Count)
//    {
//        // Неверная позиция
//        cout << "Incorrect position !!!\n";
//        return;
//    }
//
//    int i = 1;
//    while (i < pos && temp != 0)
//    {
//        temp = temp->next;
//        i++;
//    }
//
//    if (temp == 0)
//        return 0;
//    else
//        return temp;
//}
//
//template <typename T>
//void List<T>::AddHead()
//{
//    Elem<T>* temp = new Elem<T>;
//
//    temp->prev = 0;
//
//    int n;
//    cout << "Input new number: ";
//    cin >> n;
//
//    temp->data = n;
//
//    temp->next = Head;
//
//    if (Head != 0)
//        Head->prev = temp;
//
//    if (Count == 0)
//        Head = Tail = temp;
//    else
//        Head = temp;
//
//    Count++;
//}
//
//template <typename T>
//void List<T>::AddHead(T n)
//{
//    Elem<T>* temp = new Elem<T>;
//
//    temp->prev = 0;
//    temp->data = n;
//    temp->next = Head;
//
//    if (Head != 0)
//        Head->prev = temp;
//
//    if (Count == 0)
//        Head = Tail = temp;
//    else
//        Head = temp;
//
//    Count++;
//}
//
//template <typename T>
//void List<T>::AddTail()
//{
//    Elem<T>* temp = new Elem<T>;
//
//    temp->next = 0;
//    int n;
//    cout << "Input new number: ";
//    cin >> n;
//
//    temp->data = n;
//    temp->prev = Tail;
//
//    if (Tail != 0)
//        Tail->next = temp;
//
//    if (Count == 0)
//        Head = Tail = temp;
//    else
//        Tail = temp;
//
//    Count++;
//}
//
//template <typename T>
//void List<T>::AddTail(T n)
//{
//    Elem<T>* temp = new Elem<T>;
//
//    temp->next = 0;
//    temp->data = n;
//    temp->prev = Tail;
//
//    if (Tail != 0)
//        Tail->next = temp;
//
//    if (Count == 0)
//        Head = Tail = temp;
//    else
//        Tail = temp;
//
//    Count++;
//}
//
//template <typename T>
//void List<T>::Del()
//{
//    int n;
//    cout << "Input position: ";
//    cin >> n;
//
//    if (n < 1 || n > Count)
//    {
//        cout << "Incorrect position !!!\n";
//        return;
//    }
//
//    int i = 1;
//    Elem<T>* Del = Head;
//
//    while (i <= n)
//    {
//        // Доходим до элемента, который удаляется
//        Del = Del->next;
//        i++;
//    }
//
//    // Доходим до элемента, который предшествует удаляемому
//    Elem<T>* PrevDel = Del->prev;
//    // Доходим до элемента, который следует за удаляемым
//    Elem<T>* AfterDel = Del->next;
//
//    if (PrevDel != 0 && Count != 1)
//        PrevDel->next = AfterDel;
//
//    if (AfterDel != 0 && Count != 1)
//        AfterDel->prev = PrevDel;
//
//    if (n == 1)
//        Head = AfterDel;
//    if (n == Count)
//        Tail = PrevDel;
//
//    delete Del;
//
//    Count--;
//}
//
//template <typename T>
//void List<T>::Del(int n)
//{
//    if (n < 1 || n > Count)
//    {
//        cout << "Incorrect position !!!\n";
//        return;
//    }
//
//    int i = 1;
//    Elem<T>* Del = Head;
//
//    while (i < n)
//    {
//        // Доходим до элемента, который удаляется
//        Del = Del->next;
//        i++;
//    }
//
//    // Доходим до элемента, который предшествует удаляемому
//    Elem<T>* PrevDel = Del->prev;
//    // Доходим до элемента, который следует за удаляемым
//    Elem<T>* AfterDel = Del->next;
//
//    if (PrevDel != 0 && Count != 1)
//        PrevDel->next = AfterDel;
//
//    if (AfterDel != 0 && Count != 1)
//        AfterDel->prev = PrevDel;
//
//    if (n == 1)
//        Head = AfterDel;
//    if (n == Count)
//        Tail = PrevDel;
//
//    delete Del;
//
//    Count--;
//}
//
//template <typename T>
//void List<T>::Print(int pos)
//{
//    // Позиция от 1 до Count?
//    if (pos < 1 || pos > Count)
//    {
//        // Неверная позиция
//        cout << "Incorrect position !!!\n";
//        return;
//    }
//
//    Elem<T>* temp;
//
//    // Определяем с какой стороны 
//    // быстрее двигаться
//    if (pos <= Count / 2)
//    {
//        // Отсчет с головы
//        temp = Head;
//        int i = 1;
//
//        while (i < pos)
//        {
//            // Двигаемся до нужного элемента
//            temp = temp->next;
//            i++;
//        }
//    }
//    else
//    {
//        // Отсчет с хвоста
//        temp = Tail;
//        int i = 1;
//
//        while (i <= Count - pos)
//        {
//            // Двигаемся до нужного элемента
//            temp = temp->prev;
//            i++;
//        }
//    }
//    // Вывод элемента
//    cout << pos << " element: ";
//    cout << temp->data << "\n";
//}
//
//template <typename T>
//void List<T>::Print()
//{
//    if (Count != 0)
//    {
//        Elem<T>* temp = Head;
//        while (temp != 0)
//        {
//            cout << temp->data << "\n";
//            temp = temp->next;
//        }
//    }
//}
//
//template <typename T>
//void List<T>::DelAll()
//{
//    while (Count != 0)
//        Del(1);
//}
//
//template <typename T>
//int List<T>::GetCount()
//{
//    return Count;
//}
//
//template <typename T>
//List<T>& List<T>::operator = (const List<T>& L)
//{
//    if (this == &L)
//        return *this;
//
//    this->~List();
//
//    Elem<T>* temp = L.Head;
//
//    while (temp != 0)
//    {
//        AddTail(temp->data);
//        temp = temp->next;
//    }
//
//    return *this;
//}
//
//template <typename T>
//List<T> List<T>::operator + (const List<T>& L)
//{
//    List Result(*this);
//
//    Elem<T>* temp = L.Head;
//
//    while (temp != 0)
//    {
//        Result.AddTail(temp->data);
//        temp = temp->next;
//    }
//
//    return Result;
//}
//
//template <typename T>
//bool List<T>::operator == (const List<T>& L)
//{
//    if (Count != L.Count)
//        return false;
//
//    Elem<T>* t1, * t2;
//
//    t1 = Head;
//    t2 = L.Head;
//
//    while (t1 != 0)
//    {
//        if (t1->data != t2->data)
//            return false;
//
//        t1 = t1->next;
//        t2 = t2->next;
//    }
//
//    return true;
//}
//
//template <typename T>
//bool List<T>::operator != (const List& L)
//{
//    if (Count != L.Count)
//        return true;
//
//    Elem<T>* t1, * t2;
//
//    t1 = Head;
//    t2 = L.Head;
//
//    while (t1 != 0)
//    {
//        if (t1->data != t2->data)
//            return true;
//
//        t1 = t1->next;
//        t2 = t2->next;
//    }
//
//    return false;
//}
//
//template <typename T>
//bool List<T>::operator >= (const List& L)
//{
//    if (Count > L.Count)
//        return true;
//
//    if (*this == L)
//        return true;
//
//    return false;
//}
//
//template <typename T>
//bool List<T>::operator <= (const List& L)
//{
//    if (Count < L.Count)
//        return true;
//
//    if (*this == L)
//        return true;
//
//    return false;
//}
//
//template <typename T>
//bool List<T>::operator > (const List& L)
//{
//    if (Count > L.Count)
//        return true;
//
//    return false;
//}
//
//template <typename T>
//bool List<T>::operator < (const List& L)
//{
//    if (Count < L.Count)
//        return true;
//
//    return false;
//}
//
//template <typename T>
//List<T> List<T>::operator - ()
//{
//    List Result;
//    Elem<T>* temp = Head;
//
//    while (temp != 0)
//    {
//        Result.AddHead(temp->data);
//        temp = temp->next;
//    }
//
//    return Result;
//}
//
//// Тестовый пример
//void main()
//{
//    List <int> L;
//
//    const int n = 10;
//    int a[n] = { 0,1,2,3,4,5,6,7,8,9 };
//
//    // Добавляем элементы, стоящие на четных индексах, в голову,
//    // на нечетных - в хвост
//    for (int i = 0; i < n; i++)
//        if (i % 2 == 0)
//            L.AddHead(a[i]);
//        else
//            L.AddTail(a[i]);
//
//    // Распечатка списка
//    cout << "List L:\n";
//    L.Print();
//
//    cout << "\n\n";
//
//    // Распечатка списка
//    cout << "List L:\n";
//    L.Print();
//
//    // Распечатка 2-го и 8-го элементов списка
//    L.Print(2);
//    L.Print(8);
//
//    List <int> T;
//
//    // Копируем список
//    T = L;
//    // Распечатка копии
//    cout << "List T:\n";
//    T.Print();
//
//    // Складываем два списка (первый в перевернутом состоянии)
//    cout << "List Sum:\n";
//    List <int> Sum = -L + T;
//    // Распечатка списка
//    Sum.Print();
//}




template <typename T>
class Array {
    T* data;
    int size;
    int count;
    int grow;

public:

    Array(int enterSize = 0, int growBy = 1){
        size = enterSize;
        count = 0;
        grow = growBy;
        data = new T[size];
    }

    ~Array() {
        delete[] data;
    }

    int GetSize() {
        return size;
    }

    void SetSize(int newSize, int growBy = 1) {
        T* newData = new T[newSize];
        int elementsToCopy = (newSize < count) ? newSize : count;
        for (int i = 0; i < elementsToCopy; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
        grow = growBy;
        if (newSize < count) {
            count = newSize;
        }
    }

    int GetUpperBound() {
        return count - 1;
    }

    bool IsEmpty() {
        return count == 0;
    }

    void FreeExtra() {
        SetSize(count);
    }

    void RemoveAll() {
        delete[] data;
        data = new T[size];
        count = 0;
    }

    T GetAt(int index) {
        if (index < 0 || index >= count) {
            return T();
        }
        return data[index];
    }

    void SetAt(int index, const T& value) {
        if (index < 0 || index >= count) {
            return;
        }
        data[index] = value;
    }

    T& operator[](int index) {
        if (index < 0 || index >= count) {
            return data[0];
        }
        return data[index];
    }

    void Add(const T& value) {
        if (count == size) {
            SetSize(size + grow);
        }
        data[count++] = value;
    }

    Array<T> Append(const Array<T>& other) const {
        Array<T> result(count + other.count, grow);
        for (int i = 0; i < count; ++i) {
            result.Add(data[i]);
        }
        for (int i = 0; i < other.count; ++i) {
            result.Add(other.data[i]);
        }
        return result;
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size = other.size;
        count = other.count;
        grow = other.grow;
        data = new T[size];
        for (int i = 0; i < count; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    T* GetData() {
        return data;
    }


    void InsertAt(int index, const T& value) {
        if (index < 0 || index > count) {
            return;
        }
        if (count == size) {
            SetSize(size + grow);
        }
        for (int i = count; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        count++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= count) {
            return;
        }
        for (int i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        count--;
    }

    void Print() {
        for (int i = 0; i < count; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Array<int> arr(5, 2);

    arr.Add(41);
    arr.Add(34);
    arr.Add(8);
    arr.Add(12);
    arr.Add(87);
    arr.Add(45);
    arr.Print();

    arr.InsertAt(1, 99);
    arr.Print();

    arr.RemoveAt(2);
    arr.Print();

    cout << arr.GetAt(4) << endl;
    cout << arr.GetUpperBound() << endl;

    return 0;
}