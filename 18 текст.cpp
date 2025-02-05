#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void show(string text) {
    cout << text << endl;
}

void replacing_english_letter(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            text[i] = ' ';
        }
    }
    show(text);
}

void replacing_digit(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (isdigit(text[i])) {
            text[i] = ' ';
        }
    }
    show(text);
}

void replacing_punctuation(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (ispunct(text[i])) {
            text[i] = ' ';
        }
    }
    show(text);
}

int main()
{
    string text, text_2;
    cout << "Enter text" << endl;
    getline(cin, text);
    text_2 = text;
    show(text);
    while (true) {
        char choice;
        cout << "-----------------------" << endl;
        cout << "Enter choise" << endl;
        cout << "1 replace punctuatinon" << endl;
        cout << "2 replace letters english" << endl;
        cout << "3 replace digit" << endl;
        cout << "Other Exit" << endl;
        cout << "-----------------------" << endl;
        cin >> choice;
        switch (choice) {
        case '1':
            replacing_punctuation(text);
            show(text);
            break;
        case '2':
            replacing_english_letter(text);
            show(text);
            break;
        case '3':
            replacing_digit(text);
            show(text);
            break;
        default:
            return 0;
        }
    }
}
