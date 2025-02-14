#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void show(string text) {
    cout << text << endl;
}

void replace_english_letter(string text) {
    for (int i = 0, count = text.length(); i < count; i++) {
        if (isalpha(text[i])) {
            text[i] = ' ';
        }
    }
    show(text);
}

void replace_digit(string text) {
    for (int i = 0, count = text.length(); i < count; i++) {
        if (isdigit(text[i])) {
            text[i] = ' ';
        }
    }
    show(text);
}

void replace_punctuation(string text) {
    for (int i = 0, count = text.length(); i < count; i++) {
        if (ispunct(text[i])) {
            text[i] = ' ';
        }
    }
    show(text);
}

void replace_uppercase(string text) {
    for (int i = 0, count = text.length(); i < count; i++) {
        if (text[i] >= 65 && text[i] <= 90) {  
            text[i] = ' ';
        }
    }
    show(text);
}

void replace_capitals(string text) {
    for (int i = 0, count = text.length(); i < count; i++) {
        if (text[i] >= 97 && text[i] <= 122) {
            text[i] = ' ';
        }
    }
    show(text);
}

void show_menu() {
    cout << "-----------------------" << endl;
    cout << "Enter choise" << endl;
    cout << "1 replace punctuatinon" << endl;
    cout << "2 replace letters english" << endl;
    cout << "3 replace digit" << endl;
    cout << "4 replace uppercase letters" << endl;
    cout << "5 replace capitals letters" << endl;
    cout << "Other Exit" << endl;
    cout << "-----------------------" << endl;
}

int main()
{
    string text;
    cout << "Enter text:" << endl;
    getline(cin, text);
    while (true) {
        char choice;
        show_menu();
        cin >> choice;
        switch (choice) {
        case '1':
            replace_punctuation(text);
            show(text);
            break;
        case '2':
            replace_english_letter(text);
            show(text);
            break;
        case '3':
            replace_digit(text);
            show(text);
            break;
        case '4':
            replace_uppercase(text);
            show(text);
            break;
        case '5':
            replace_capitals(text);
            show(text);
            break;
        default:
            return 0;
        }
    }
}
