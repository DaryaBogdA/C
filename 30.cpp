#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class Directory {
    string name_firm;
    string name_person;
    string phone_number;
    string adres;
    string hobby;
public:
    Directory(string name_firm = "", string name_person = "", string phone_number = "", string adres = "", string hobby = "") {
        this->name_firm = name_firm;
        this->name_person = name_person;
        this->phone_number = phone_number;
        this->adres = adres;
        this->hobby = hobby;
    }
    void add() {
        cout << "Enter firm name: ";
        getline(cin, name_firm);
        cout << "Enter owner's name: ";
        getline(cin, name_person);
        cout << "Enter phone number: ";
        getline(cin, phone_number);
        cout << "Enter address: ";
        getline(cin, adres);
        cout << "Enter activity: ";
        getline(cin, hobby);

        ofstream file("directory.txt", ios::app);
        if (file.is_open()) {
            file << name_firm << ";" << name_person << ";" << phone_number << ";" << adres << ";" << hobby << endl;
            file.close();
            cout << "Yes" << endl;
        }
    }

    void show() {
        cout << "-------------------" << endl;
        cout << "Firm: " << name_firm << endl;
        cout << "Person: " << name_person << endl;
        cout << "Phone: " << phone_number << endl;
        cout << "Adres: " << adres << endl;
        cout << "Hobby: " << hobby << endl;
        cout << "-------------------" << endl;
    }

    void search(string n, string value){
        ifstream file("directory.txt");

        string line;
        bool found = false;
        while (getline(file, line)) {
            int pos = 0;
            string data[5];
            for (int i = 0; i < 5; i++) {
                pos = line.find(';');
                data[i] = line.substr(0, pos);
                line.erase(0, pos + 1);
            }

            if ((n == "firm" && data[0] == value) ||
                (n == "owner" && data[1] == value) ||
                (n == "phone" && data[2] == value) ||
                (n == "hobby" && data[4] == value)) {
                cout << "Found " << n << endl << endl;
                Directory(data[0], data[1], data[2], data[3], data[4]).show();
                found = true;
            }
        }

        if (!found) {
            cout << "No find" << endl;
        }

        file.close();
    }

    void show_all() {
        ifstream file("directory.txt");
        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            string data[5];
            for (int i = 0; i < 5; ++i) {
                pos = line.find(';');
                data[i] = line.substr(0, pos);
                line.erase(0, pos + 1);
            }
            Directory(data[0], data[1], data[2], data[3], data[4]).show();
        }

        file.close();
    }

};



int main() {
    Directory directory;
    int choice;
    do {
        cout << "Directory Menu:" << endl;
        cout << "1. Add new entry" << endl;
        cout << "2. Search firm name" << endl;
        cout << "3. Search owner" << endl;
        cout << "4. Search phone number" << endl;
        cout << "5. Search hobby" << endl;
        cout << "6. Show all" << endl;
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1: {
            directory.add();
            break;
        }
        case 2: {
            string value;
            cout << "Enter firm name: ";
            getline(cin, value);
            directory.search("firm", value);
            break;
        }
        case 3: {
            string value;
            cout << "Enter owner name: ";
            getline(cin, value);
            directory.search("owner", value);
            break;
        }
        case 4: {
            string value;
            cout << "Enter phone number: ";
            getline(cin, value);
            directory.search("phone", value);
            break;
        }
        case 5: {
            string value;
            cout << "Enter hobby: ";
            getline(cin, value);
            directory.search("hobby", value);
            break;
        }
        case 6:
            directory.show_all();
            break;
        case 7:
            break;
        default:
            break;
        }
    } while (choice != 7);
    return 0;
}

//ifstrem: для чтения с файла
//
//ofstream : для записи в файл
//
//fstream : совмещает запись и чтение
//
//open(путь, режим)
//
//
//ios::in : файл открывается для ввода(чтения).Может быть установлен только для объекта ifstream или fstream
//
//ios::out : файл открывается для вывода(записи).При этом старые данные удаляются.Может быть установлен только для объекта ofstream или fstream
//
//ios::app : файл открывается для дозаписи.Старые данные не удаляются.
//
//ios::ate : после открытия файла перемещает указатель в конец файла
//
//ios::trunc : файл усекается при открытии.Может быть установлен, если также установлен режим out
//
//ios::binary : файл открывается в бинарном режиме
//
//
//std::ofstream out;          // поток для записи
//out.open("hello1.txt"); // окрываем файл для записи
//
//std::ofstream out2;
//out2.open("hello2.txt", std::ios::app); // окрываем файл для дозаписи
//
//std::ofstream out3;
//out2.open("hello3.txt", std::ios::out | std::ios::trunc); // установка нескольких режимов
//
//std::ifstream in;       // поток для чтения
//in.open("hello4.txt"); // окрываем файл для чтения
//
//std::fstream fs;        // поток для чтения-записи
//fs.open("hello5.txt"); // окрываем файл для чтения-записи
//
//
//std::ofstream out("hello.txt");
//std::ifstream in("hello.txt");
//std::fstream fs("hello.txt", std::ios::app);
//
//
//if (file.is_open()) // вызов метода is_open()
//cout << "Все ОК! Файл открыт!\n\n" << endl;
//else
//{
//    cout << "Файл не открыт!\n\n" << endl;
//    return -1;
//}
//file.close()
//
////перезаписывает
//std::ofstream out;          // поток для записи
//out.open("hello.txt");      // открываем файл для записи
//if (out.is_open())
//{
//    out << "Hello World!" << std::endl;
//}
//out.close();
//std::cout << "File has been written" << std::endl;
//
//
//
////дозапись
//std::ofstream out("hello.txt", std::ios::app);
//if (out.is_open())
//{
//    out << "Welcome to C++" << std::endl;
//}
//out.close();
//
//
////читать
//
//std::string line;
//
//std::ifstream in("hello.txt"); // окрываем файл для чтения
//if (in.is_open())
//{
//    while (std::getline(in, line))
//    {
//        std::cout << line << std::endl;
//    }
//}
//in.close();     // закрываем файл



//String^ line;