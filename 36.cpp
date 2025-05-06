#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual string get_name() = 0;
    virtual ~Shape() {};
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.1415 * radius * radius;
    }
    string get_name() override {
        return "circle";
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() override {
        return width * height;
    }
    string get_name() override {
        return "rectangle";
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() override {
        return 0.5 * base * height;
    }
    string get_name() override {
        return "triangle";
    }
};

void exercise_1() {
    vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Triangle(3.0, 7.0));

    double all_area = 0.0;
    for (int i = 0; i < shapes.size(); i++) {
        cout << "Area " << shapes[i]->get_name() << ": " << shapes[i]->area() << endl;
        all_area += shapes[i]->area();
    }
    cout << "All area: " << all_area << endl;
}


struct Person {
    string name;
    string surname;
};

vector<Person> read_file(string& file_name) {
    vector<Person> people;
    ifstream file(file_name);
    string line, name, surname;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> name >> surname;
        people.push_back({ name, surname });
    }
    file.close();
    return people;
}

void write_file(string file_name, vector<Person>& people) {
    ofstream file(file_name);
    for (int i = 0; i < people.size(); i++) {
        file << people[i].name << " " << people[i].surname << endl;
    }
    file.close();
}

void sort_name(vector<Person>& people) {
    for (int i = 0; i < people.size(); i++) {
        for (int j = 0; j < people.size() - 1; j++) {
            if (people[j].name > people[j + 1].name) {
                swap(people[j], people[j + 1]);
            }
        }
    }
    cout << "done" << endl;
}

void sort_surname(vector<Person>& people) {
    for (int i = 0; i < people.size(); i++) {
        for (int j = 0; j < people.size() - 1; j++) {
            if (people[j].surname > people[j + 1].surname) {
                swap(people[j], people[j + 1]);
            }
        }
    }
}

void show(vector<Person>& people) {
    cout << "All people" << endl;
    for (int i = 0; i < people.size(); i++) {
        cout << people[i].name << " " << people[i].surname << endl;
    }
}

void add(vector<Person>& people) {
    string name, surname;
    cout << "Enter name and surname: ";
    cin >> name >> surname;
    people.push_back({ name, surname });
}

void remove(vector<Person>& people) {
    string name, surname;
    bool find = true;
    cout << "Enter name and surname: ";
    cin >> name >> surname;

    for (int i = 0; i < people.size(); i++) {
        if (people[i].name == name && people[i].surname == surname) {
            people.erase(people.begin() + i);
            i--; 
            find = false;
        }
    }
    if (find) {
        cout << "People not find" << endl;
    }
}

void exercise_2() {
    string filename = "people.txt";
    vector<Person> people = read_file(filename);

    int choice;
    do {
        cout << "1 - Show all" << endl;
        cout << "2 - Add people" << endl;
        cout << "3 - Remove people" << endl;
        cout << "4 - Sort by name and save" << endl;
        cout << "5 - Sort by surname and save" << endl;
        cout << "0 - Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            show(people);

            break;
        case 2:
            add(people);
            break;
        case 3:
            remove(people);
            break;
        case 4:
            sort_name(people);
            write_file("sort_name.txt", people);
            break;
        case 5:
            sort_surname(people);
            write_file("sort_surname.txt", people);
            break;
        case 0:
            break;
        default:
            cout << "Go again";
        }
    } while (choice != 0);

}


struct Ditail {
    string name;
    int count;
};

map<string, int> summa_details(vector<vector<Ditail>>& products) {
    map<string, int> all;

    for (int i = 0; i < products.size(); i++) {
        for (int j = 0; j < products[i].size(); j++) {
            all[products[i][j].name] += products[i][j].count;
        }
    }

    return all;
}

void show_ditails(map<string, int>& all) {
    cout << "Summa ditails" << endl;
    for (map<string, int>::iterator iter = all.begin(); iter != all.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }
}

void exercise_3() {
    vector<vector<Ditail>> products = {
        {{"Gold", 10}, {"Copper", 5}, {"Wheel", 2}},
        {{"Iron", 7}, {"Wheel", 3}, {"Wool", 1}},
        {{"Copper", 4}, {"Gold", 2}, {"Iron", 8}}
    };

    map<string, int> totalParts = summa_details(products);
    show_ditails(totalParts);
}
