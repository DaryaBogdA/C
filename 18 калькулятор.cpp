#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

bool check_letters(string str) {
    for (char i : str){
        if (isalpha(i)){
            return true;
        }
    }
    return false;
}

bool check_bracket(string str) {
    int count_open_bracket = 0;
    int count_close_bracket = 0;
    for (char i : str) {
        if (i == '(') count_open_bracket++;
        if (i == ')') count_close_bracket++;
    }
    if (count_close_bracket == count_open_bracket) return false;
    return true;
}

bool check_mathematical_operations(string str) {
    string result = "";
    for (char j : str) {
        if (j != ' ') {
            result += j;
        }
    }
    for (int i = 0; i < result.length() - 1; i++) {
        if ((result[i] == '+' || result[i] == '-' || result[i] == '*' || result[i] == '/' || result[i] == '^') &&
            (result[i + 1] == '+' || result[i + 1] == '-' || result[i + 1] == '*' || result[i + 1] == '/' || result[i + 1] == '^')) {
            return true;
        }
        
    }

    return false;
}

bool check_equals(string str) {
    int count = 0;
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == '=') {
            count++;
        }
    }
    if (count) return true;
    return false;
}

void Pow(string sample[], int& size) {
    for (int i = 1; i < size; i++) {
        if (sample[i] == "^") {
            int num_1 = stoi(sample[i - 1]);
            int num_2 = stoi(sample[i + 1]);
            sample[i - 1] = to_string(static_cast<int>(pow(num_1, num_2)));
            for (int j = i; j < size - 2; j++) {
                sample[j] = sample[j + 2];
            }
            size -= 2;
            i--;
        }
    }
}

void division_and_multiplication(int num1, int num2, string sample[], int& size) {
    
    if (num1 == -1) {
        num2 = size;
    }


    for (int i = num1 + 1; i <= num2; i++) {
        if (sample[i] == "*") {
            int num_1 = stoi(sample[i - 1]);
            int num_2 = stoi(sample[i + 1]);
            string a = to_string(num_1 * num_2);
            sample[i - 1] = to_string(num_1 * num_2);
            for (int j = i; j < size - 2; j++) {
                sample[j] = sample[j + 2];
            }
            size -= 2;
        }
        else if (sample[i] == "/") {
            int num_1 = stoi(sample[i - 1]);
            int num_2 = stoi(sample[i + 1]);
            sample[i - 1] = to_string(num_1 / num_2);
            for (int j = i; j < size - 2; j++) {
                sample[j] = sample[j + 2];
            }
            size -= 2;
        }
    }
   
}

void sum_and_subtraction(int num1, int num2, string sample[], int& size) {
    if (num1 == -1) {
        num2 = size;
    }

    for (int i = num1 + 1; i < num2; i++) {
        if (sample[i] == "+") {
            int num_1 = stoi(sample[i - 1]);
            int num_2 = stoi(sample[i + 1]);
            sample[i - 1] = to_string(num_1 + num_2);
            for (int j = i; j < size - 2; j++) {
                sample[j] = sample[j + 2];
            }
            size -= 2;
        }
        else if (sample[i] == "-") {
            int num_1 = stoi(sample[i - 1]);
            int num_2 = stoi(sample[i + 1]);
            sample[i - 1] = to_string(num_1 - num_2);
            for (int j = i; j < size - 2; j++) {
                sample[j] = sample[j + 2];
            }
            size -= 2;
        }
    }
    for (int i = num1; i < size; i++) {
        if (sample[i] == "(") {
            for (int j = i; j < size - 1; j++) {
                sample[j] = sample[j + 1];
            }
            size--;
            i--;
        }
        if (sample[i] == ")") {
            for (int j = i; j < size - 1; j++) {
                sample[j] = sample[j + 1];
            }
            size--;
            i--;
            break;
        }
    }
}

struct Result {
    int value1;
    int value2;
};

Result brasket_index(string simple[], int size) {
    int index_bracket_open = -1;
    int bracket_open = 0;
    int index_bracket_close = -1;
    for (int i = 0; i < size; i++) {
        if (simple[i] == "(") {
            index_bracket_open = i;
            bracket_open++;
        }
        if (simple[i] == ")") {
            index_bracket_close = i;
            break;
        }
    }
    Result res;
    if (bracket_open) {
        res.value1 = index_bracket_open;
        res.value2 = index_bracket_close;
    }
    else {
        res.value1 = -1;
        res.value2 = 1000;
    }
    
    return res;
}

int count_brasket(string sample) {
    int count = 0;
    for (int i = 0; i < sample.length(); i++) {
        if (sample[i] == '(') count++;
    }
    return count;
}

bool error(string sample){
    while (true) {
        if (check_letters(sample)) {
            cout << "!!!!!ERROR (letter)!!!!!" << endl;
            return true;
        }
        if (check_bracket(sample)) {
            cout << "!!!!!ERROR (bracket)!!!!!" << endl;
            return true;
        }
        if (check_mathematical_operations(sample)) {
            cout << "!!!!!ERROR (mathematical operations)!!!!!" << endl;
            return true;
        }
        if (check_equals(sample)) {
            cout << "!!!!!ERROR (equals)!!!!!" << endl;
            return true;
        }
        return false;
    }
}

void parseString(const string& sample, string result[], int& size) {
    size = 0;
    string num = "";

    for (char c : sample) {
        if (isdigit(c)) {
            num += c;  
        }
        else {
            if (!num.empty()) {
                result[size++] = num; 
                num = "";
            }
            string sym(1, c);  
            result[size++] = sym; 
        }
    }
    if (!num.empty()) {
        result[size++] = num;
    }
}

int main() {
    string sample;
    cout << "Enter sample" << endl;
    getline(cin, sample);
    if (error(sample)) {
        return 0;
    }

    int count = count_brasket(sample);

    const int size_array = 1000;
    string result[size_array];
    int size = 0;
    parseString(sample, result, size);
    Pow(result, size);

    for(int i = 0; i <= count + 1; i++){
        Result res = brasket_index(result, size);
        division_and_multiplication(res.value1, res.value2, result, size);
        res = brasket_index(result, size);
        sum_and_subtraction(res.value1, res.value2, result, size);

        for (int i = 0; i < size; ++i) {
            cout << result[i];
        }
        cout << endl;
    }
}

/*
17*2^8+(3*14+5^3*(18*3^3+5^4/4+2))
6+(8*9)
*/