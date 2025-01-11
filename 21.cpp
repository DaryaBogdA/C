#include <string>
#include <iostream>
using namespace std;

class Person {
    string name, gender, telephone_number;
    int age;
public:
    void Print();
    Person() {
        name = "";
        age = 0;
        gender = "";
        telephone_number = "";
    }


    Person(string name, int age, string gender, string telephone_number) {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->telephone_number = telephone_number;
    }
    void Set_name(string name) {
        this->name = name;
    }

    void Set_age(int age) {
        this->age = age;
    }

    void Set_gender(char gender) {
        this->gender = gender;
    }

    void Set_telephone_number(string telephone_number) {
        this->telephone_number = telephone_number;
    }

};

void Person::Print() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Phone number: " << telephone_number << endl;
    cout << "-------------------" << endl;
}


class String {
    string str;
public:

    String() {
        str = "adsfadfdsfdsfadasdffffffffff";
        str.resize(80);
    }

    String(int length) {
        str.resize(length);
    }

    String(string str) {
        this->str = str;
    }

    void Input() {
        cin >> str;
    }

    void Show() {
        cout << str << endl;
    }

};
void exercise1(){
    Person person("Ben", 30, "Man", "+14315346");
    Person person2("Katy", 30, "Woman", "+5475745");
    person2.Set_telephone_number("+976575");
    person.Print();
    person2.Print();
    person.Set_age(35);
    person.Print();
}
void exercise2() {
    String str;
    str.Show();
    str.Input();
    str.Show();
    String str2("zfgbzfvcvcxzvzcxvvvvvvvvvvvvvv");
    str2.Show();


}
int main() {
    exercise1();
    //exercise2();
}