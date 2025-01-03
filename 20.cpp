
#include <iostream>
using namespace std;
class counter {
    const int min = 0, max = 100;
public:
    int count = 0;
    void Min() {
        count = min;
    }
    void Max() {
        count = max;
    }
    void Counter() {
        if (count >= 100) {
            Min();
        }
        else {
            count++;
        }
    }
    void Show() {
        cout << count << endl;
    }
};
class group_students {

};
class students {
public:
    string name, last_name, surname;
    int group, date;
    void Data(string name_student, string last_name_student, string surname_student, int group_student, int date_student){
        name = name_student;
        last_name = last_name_student;
        surname = surname_student;
        group = group_student;
        date = date_student;
    }
    void Show() {
        cout << "Student " << endl;
        cout << "Name " << name << endl;
        cout << "Last name " << last_name << endl;
        cout << "Surname " << surname << endl;
        cout << "Group " << group << endl;
        cout << "Date " << date << endl;
        cout << "-----------------------" << endl;
    }
};
int main(){

    counter go;
    go.Show();
    go.Max();
    go.Counter();
    go.Show();
    go.Counter();
    go.Show();
    go.Min();
    go.Show();
    go.Counter();
    go.Show();
    go.Counter();
    go.Show();
    go.Counter();
    go.Show();

    students one;
    students two;
    students three;
    students four;
    students five;
    students six;
    students seven;
    students eight;
    students nine;
    students ten;
    one.Data("Alla", "Dudko", "Romanova", 144, 2004);
    one.Show();
    two.Data("Ivan", "Ivanov", "Absent", 145, 2005);
    two.Show();
    three.Data("Maria", "Sidorova", "Present", 146, 2006);
    three.Show();
    four.Data("Petr", "Kuznetsov", "Present", 147, 2007);
    four.Show();
    five.Data("Ekaterina", "Popova", "Present", 148, 2008);
    five.Show();
    six.Data("Alexander", "Egorov", "Absent", 149, 2009);
    six.Show();
    seven.Data("Anastasia", "Volkova", "Present", 150, 2010);
    seven.Show();
    eight.Data("Maxim", "Sokolov", "Present", 151, 2011);
    eight.Show();
    nine.Data("Victoria", "Konovalova", "Present", 152, 2012);
    nine.Show();
    ten.Data("Artem", "Novikov", "Present", 153, 2013);
    ten.Show();

}

