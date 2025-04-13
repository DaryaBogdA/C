#include <iostream>
#include <cmath>
using namespace std;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Базовый класс
class Base {
public:
    virtual void display() { // Виртуальная функция
        cout << "Start Base" << endl;
    }

    virtual ~Base() { // Виртуальный деструктор
        cout << "~ Base" << endl;
    }
};

// Производный класс
class Derived : public Base {
public:
    void display() override { // Переопределение виртуальной функции
        cout << "Start Derived" << endl;
    }

    ~Derived() {
        cout << "~ Derived" << endl;
    }
};

void virtual_function() {
    Base* obj = new Derived(); // Указатель на базовый класс, но объект производного класса
    obj->display(); // Вызов переопределённой функции из Derived
    delete obj; // Корректный вызов деструктора Derived и затем Base
}

//// Абстрактный класс
//class Shape {
//public:
//    virtual void draw() const = 0; // Чисто виртуальная функция
//    virtual ~Shape() {} // Виртуальный деструктор для корректного освобождения памяти
//};
//
//// Производный класс Circle
//class Circle : public Shape {
//public:
//    void draw() const override { // Переопределение виртуальной функции
//        cout << "Рисуем круг" << endl;
//    }
//};
//
//// Производный класс Square
//class Square : public Shape {
//public:
//    void draw() const override { // Переопределение виртуальной функции
//        cout << "Рисуем квадрат" << endl;
//    }
//};
//
//void abstraction_class() {
//    // Полиморфный вызов через указатели на базовый класс
//    Shape* shape1 = new Circle();
//    Shape* shape2 = new Square();
//
//    shape1->draw(); // Вызов функции draw() для Circle
//    shape2->draw(); // Вызов функции draw() для Square
//
//    delete shape1; // Освобождение памяти
//    delete shape2; // Освобождение памяти
//}












class Employer  {
public:
    virtual void Print() const = 0; 
    virtual ~Employer() {}
};

class President : public Employer {
private:
    string name;
public:
    President(string name) {
        this->name = name;
    }
    ~President() {}
    void Print() const override {
        cout << "President: " << name << endl;
    }
     
};
class Manager : public Employer {
private:
    string name;
public:
    Manager(string name) {
        this->name = name;
    }
    ~Manager() {}
    void Print() const override {
        cout << "Manager: " << name << endl;
    }

};
class Worker : public Employer {
private:
    string name;
public:
    Worker(string name) {
        this->name = name;
    }
    ~Worker() {}
    void Print() const override {
        cout << "Worker: " << name << endl;
    }

};

void exercise_1() {
    Employer* first = new President("Lukashenko");
    Employer* second = new Manager("Filipenko");
    Employer* third = new Worker("Duda");

    first->Print();
    second->Print();
    third->Print();
}





class List {
protected:
    int data[100]; 
    int count = 0;
public:
    virtual void add(int value) = 0; 
    virtual void remove() = 0;        
    virtual void print() {      
        for (int i = 0; i < count; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    virtual ~List() {}
};


class Stack : public List {
public:
    void add(int value) override {
        if (count < 100) {
            data[count++] = value; 
        }
        else {
            cout << "Stack max" << endl;
        }
    }

    void remove() override { 
        if (count > 0) {
            count--;
        }
        else {
            cout << "Stack empty" << endl;
        }
    }
};

class Queue : public List {
public:
    void add(int value) override {
        if (count < 100) {
            data[count++] = value; 
        }
        else {
            cout << "Queue max" << endl;
        }
    }

    void remove() override { 
        if (count > 0) {
            for (int i = 1; i < count; i++) {
                data[i - 1] = data[i];
            }
            count--; 
        }
        else {
            cout << "Queue empty" << endl;
        }
    }
};

void exercise_2() {
    List* stack = new Stack();
    List* queue = new Queue();

    cout << "Stack:" << endl;
    stack->add(5);
    stack->add(7);
    stack->add(8);
    stack->add(8);
    stack->add(4);
    stack->add(23);
    stack->print();
    stack->remove();
    stack->remove();
    stack->print();

    cout << "Queue:" << endl;
    queue->add(5);
    queue->add(7);
    queue->add(8);
    queue->add(8);
    queue->add(4);
    queue->add(23);
    queue->print();
    queue->remove();
    queue->remove();
    queue->print();


    delete stack;
    delete queue;
}



class Shape {
public:
    virtual double S() = 0; 
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double S() override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double S() override {
        return M_PI * radius * radius;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double S() override {
        return 0.5 * base * height;
    }
};

class Trapezoid : public Shape {
private:
    double a, b, height;
public:
    Trapezoid(double x, double y, double h) : a(x), b(y), height(h) {}
    double S() override {
        return (a + b) * height / 2;
    }
};

void exercise_3() {
    Shape* shapes[4];
    shapes[0] = new Rectangle(5, 10);   
    shapes[1] = new Circle(7);
    shapes[2] = new Triangle(6, 8);
    shapes[3] = new Trapezoid(4, 6, 5);

    for (int i = 0; i < 4; ++i) {
        cout << "S: " << shapes[i]->S() << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete shapes[i];
    }

}



class Equation {
public:
    virtual void find_x() = 0; 
    virtual ~Equation() {} 
};

class LineEquation : public Equation {
private:
    double a, b;
public:
    LineEquation(double A, double B) : a(A), b(B) {}

    void find_x() override {
        if (a == 0) {
            if (b == 0) {
                cout << "Line" << endl;
                cout << "Infinty x" << endl;
            }
            else {
                cout << "Line" << endl;
                cout << "Zero x" << endl;
            }
        }
        else {
            double x = -b / a;
            cout << "Line" << endl;
            cout << "x = " << x << endl;
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c;
public:
    QuadraticEquation(double A, double B, double C) : a(A), b(B), c(C) {}

    void find_x() override {
        if (a == 0) {
            cout << "This Line equation" << endl;
            LineEquation linear(b, c);
            linear.find_x();
            return;
        }

        double D = b * b - 4 * a * c;
        if (D > 0) {
            cout << "Quadratic" << endl;
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
        }
        else if (D == 0) {
            cout << "Quadratic" << endl;
            double x = -b / (2 * a);
            cout << "x = " << x << endl;
        }
        else {
            cout << "Quadratic" << endl;
            cout << "Zero x" << endl;
        }
    }
};

int exercise_4() {
    Equation* eq1 = new LineEquation(2, -4);
    eq1->find_x();
    delete eq1;

    Equation* eq2 = new QuadraticEquation(1, -3, 2); 
    eq2->find_x();
    delete eq2;

    Equation* eq3 = new QuadraticEquation(0, 4, -8); 
    eq3->find_x();
    delete eq3;

    Equation* eq4 = new QuadraticEquation(12, 3, -16);
    eq4->find_x();
    delete eq4;
}