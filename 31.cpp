#include <iostream>
#include <string>

using namespace std;

class Outer { // Внешний класс
public:
    class Inner { // Вложенный класс
    public:
        void display() {
            std::cout << "Это вложенный класс!" << std::endl;
        }
    };

    void outerDisplay() {
        std::cout << "Это внешний класс!" << std::endl;
    }
};

void vlozhenni_class() {
    Outer outerObj; // Объект внешнего класса
    Outer::Inner innerObj; // Объект вложенного класса

    outerObj.outerDisplay(); // Вызываем метод внешнего класса
    innerObj.display(); // Вызываем метод вложенного класса
}



class Faculty {
public:
    Faculty(const std::string& name) : name(name) {}

    void show() const {
        std::cout << "Факультет: " << name << std::endl;
    }

private:
    std::string name; // Имя факультета
};

class University {
public:
    University(const std::string& universityName) : name(universityName) {}

    void setFaculty1(Faculty* f1) {
        faculty1 = f1; // Привязываем факультет к университету
    }

    void setFaculty2(Faculty* f2) {
        faculty2 = f2; // Привязываем факультет к университету
    }

    void showFaculties() const {
        std::cout << "Университет: " << name << std::endl;
        if (faculty1) faculty1->show(); // Если факультет 1 существует
        if (faculty2) faculty2->show(); // Если факультет 2 существует
    }

private:
    std::string name; // Имя университета
    Faculty* faculty1 = nullptr; // Указатель на первый факультет
    Faculty* faculty2 = nullptr; // Указатель на второй факультет
};

void agregatia() {
    // Создаём факультеты
    Faculty f1("Математика");
    Faculty f2("Физика");

    // Создаём университет
    University uni("Государственный университет");

    // Привязываем факультеты к университету
    uni.setFaculty1(&f1);
    uni.setFaculty2(&f2);

    // Выводим информацию
    uni.showFaculties();

}






class Engine {
public:
    Engine(const std::string& type) : type(type) {}
    void show() const {
        std::cout << "Type engine: " << type << std::endl;
    }
private:
    std::string type;
};

class Car {
public:
    Car(const std::string& type) : engine(type) {} // Инициализация двигателя в конструкторе
    void showEngine() const {
        engine.show();
    }
private:
    Engine engine; // Композиция: двигатель является частью машины
};

void kompozicia() {
    Car car("Benzinovsi");
    car.showEngine(); // Показываем тип двигателя
}




class Student {
private:
    string name;
    string lastname;
    string surname;
    string group;
    int age;
public:
    Student(string name, string lastname, string surname, string group, int age) {
        this->name = name;
        this->lastname = lastname;
        this->surname = surname;
        this->group = group;
        this->age = age;
    }
    void show() {
        cout << "----------------------------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Lastname: " << lastname << endl;
        cout << "Surname: " << surname << endl;
        cout << "Group: " << group << endl;
        cout << "Age: " << age << endl;
    }
};

class Aspirant : public Student {
private:
    string name_work;
public:
    Aspirant(string name_work, string name, string lastname, string surname, string group, int age) : Student(name, lastname, surname, group, age) {
        this->name_work = name_work;
    }
    void show_more() {
        Student::show();
        std::cout << "Topic of the PhD thesis: " << name_work << endl;
        cout << "----------------------------------------------------" << endl;
    }
};

void exercize_1() {
    Student student("Bogdan", "Dedov", "Felipovich", "123a", 19);
    student.show();

    Aspirant aspirant_1("Save animal", "Nikita", "Asik", "Aleksandrovich", "124a", 20);
    aspirant_1.show_more();
    
    Aspirant aspirant_2("Save plants", "Lesha", "Grag", "Nisterovich", "123b", 19);
    aspirant_2.show();
}



class Passport {
private:
    string name;
    string lastname;
    string surname;
    string date_of_birth;
    string passport_No;
public:
    Passport(string name, string lastname, string surname, string date_of_birth, string passport_No) {
        this->name = name;
        this->lastname = lastname;
        this->surname = surname;
        this->date_of_birth = date_of_birth;
        this->passport_No = passport_No;
    }
    void show() {
        cout << "----------------------------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Lastname: " << lastname << endl;
        cout << "Surname: " << surname << endl;
        cout << "Date of birth: " << date_of_birth << endl;
        cout << "Passport No: " << passport_No << endl;
    }

};

class ForeignPassport : public Passport{
private:
    string visas[10];
    int visa_count = 0;
    string number_foreign_passport;
public:
    ForeignPassport(string name, string lastname, string surname, string date_of_birth, string passport_No, string number_foreign_passport)
        : Passport(name, lastname, surname, date_of_birth, passport_No) {
        this->number_foreign_passport = number_foreign_passport;
    }

    void add_visa(string visa) {
        if (visa_count < 10) { 
            visas[visa_count] = visa;
            visa_count++;
        }
        else {
            cout << "Max count visa" << endl;
        }
    }

    void show_info() {
        Passport::show();
        cout << "Number foreign passport: " << number_foreign_passport << endl;
        cout << "Visas:";
        for (int i = 0; i < visa_count; i++) {
            cout << " " << visas[i] << " ";
        }
        cout << endl;
        cout << "----------------------------------------------------" << endl;
    }
};



void exercise_2() {
    ForeignPassport foreign_passport("Bogdan", "Dedov", "Felipovich", "16.10.2004", "MP3478P549", "MP4854OE8493");
    foreign_passport.add_visa("Japan");
    foreign_passport.add_visa("Kanada");

    foreign_passport.show_info();
} 

class Circle {
private:
    double radius;
public:
    Circle(double radius) {
        this->radius = radius;
    }

    double area() {
        return 3.14 * radius * radius;
    }
    void show_circle() {
        cout << "-------------------------------------" << endl;
        cout << "Circle: " << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "-------------------------------------" << endl;
    }
};

class Square {
private:
    double side;
public:
    Square(double side) {
        this->side = side;
    }

    double area() {
        return side * side;
    }
    void show_square() {
        cout << "-------------------------------------" << endl;
        cout << "Square: " << endl;
        cout << "Side: " << side << endl;
        cout << "Area: " << area() << endl;
        cout << "-------------------------------------" << endl;
    }
};


class Circle_in_Square : public Circle, public Square {
public:
    Circle_in_Square(double side) : Circle(side/2), Square(side){}

    void show_all() {
        Circle::show_circle();
        Square::show_square();
    }
};

void exercise_3() {
    Circle_in_Square result(6.0);
    result.show_all();
}








// класс "точка"
class Point {

    // кооординаты
    int X;
    int Y;
public:

    //конструктор
    Point() {
        X = Y = 0;
    }

    //установка координат
    void SetPoint(int iX, int iY) {
        X = iX;
        Y = iY;
    }

    //демонстрация координат
    void Show() {
        cout << "----------------------------\n\n";
        cout << X << "\t" << Y << "\n\n";
        cout << "----------------------------\n\n";
    }
};
//класс фигура
class Figura {

    // агрегация точки
    // (координаты углов)
    Point* obj;

    // количество углов
    int count;
    // цвет фигуры
    int color;

public:

    //конструктор
    Figura() {
        count = color = 0;
        obj = NULL;
    }

    // создание фигуры
    void CreateFigura(int cr, int ct) {
        // если углов меньше трех - это не фигура
        if (ct < 3) exit(0);
        //инициализация цвета и количества углов
        count = ct;
        color = cr;
        // выдделение памяти под массив точек
        obj = new Point[count];
        if (!obj) exit(0);

        //установка координат точек
        int tempX, tempY;
        for (int i = 0; i < count; i++) {
            cout << "Set X\n";
            cin >> tempX;
            cout << "Set Y\n";
            cin >> tempY;
            obj[i].SetPoint(tempX, tempY);
        }
    }

    //показ фигуры
    void ShowFigura() {
        cout << "----------------------------\n\n";
        cout << "Color" << color << "\n\nPoints - " << count << "\n\n";
        for (int i = 0; i < count; i++) {
            obj[i].Show();
        }
    }

    //если фигура была очистить память
    ~Figura() {
        if (obj != NULL) delete[]obj;
    }


};

class CompositeFigure {
    Figura* figures; // Композиция: массив фигур
    int figureCount; // Количество фигур

public:
    CompositeFigure(int count) {
        figureCount = count;
        figures = new Figura[figureCount]; // Выделение памяти для массива фигур
    }

    void CreateCompositeFigure() {
        for (int i = 0; i < figureCount; i++) {
            int color, sides;
            cout << "\nCreate figure " << i + 1 << ":\n";
            cout << "Enter color: ";
            cin >> color;
            cout << "Enter count sides: ";
            cin >> sides;

            figures[i].CreateFigura(color, sides);
        }
    }

    void ShowCompositeFigure() {
        cout << "\n=== Composition figure ===\n";
        for (int i = 0; i < figureCount; i++) {
            cout << "\nFigure " << i + 1 << ":\n";
            figures[i].ShowFigura();
        }
    }

    ~CompositeFigure() {
        if (figures != nullptr) delete[] figures; // Удаление массива фигур
    }
};

void main() {

    int numFigures;
    cout << "Enter count figure in composition: ";
    cin >> numFigures;

    CompositeFigure composite(numFigures);

    // Создание композитной фигуры
    composite.CreateCompositeFigure();

    // Вывод всех фигур
    composite.ShowCompositeFigure();

}
