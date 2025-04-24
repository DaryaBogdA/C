#include <sstream>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Errors {
    string str;
public:
    Errors(string err) {
        str = err;
    }
    bool check_letters() {
        for (char c : str) {
            if (isalpha(c)) return true;
        }
        return false;
    }

    bool check_mathematical_operations() {
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

    bool check_equals() {
        int count = 0;
        for (int i = 0; i < str.length() - 1; i++) {
            if (str[i] == '=') {
                count++;
            }
        }
        if (count) return true;
        return false;
    }


    bool check_all() {
        if (check_letters()) {
            throw runtime_error("ERROR (letter)");
        }
        if (check_mathematical_operations()) {
            throw runtime_error("ERROR (mathematical operations)");
        }
        if (check_equals()) {
            throw runtime_error("ERROR (equals)");
        }
        return false;
    }
};

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

class Steck {
private:
    int* arr;
    int max_size;
    int top;

public:
    Steck(int size) {
        this->max_size = size;
        this->top = 0;
        arr = new int[max_size];
    }

    ~Steck() {
        delete[] arr;
    }

    void add(int value) {
        arr[++top] = value;
    }

    int is_empty() {
        return top;
    }

    int pop() {
        if (!is_empty()) {
            throw runtime_error("Bracket is false first");
        }
        return arr[top--];
    }

    void show() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << endl;
        }
    }

};


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
    try
    {
        string sample;
        cout << "Enter sample" << endl;
        getline(cin, sample);
        Errors errors(sample);
        errors.check_all();

        int count = count_brasket(sample);

        const int size_array = 1000;
        string result[size_array];
        int size = 0;
        parseString(sample, result, size);
        Steck steck(size);
        for (int i = 0; i < size; i++) {
            if (result[i] == "(") {
                steck.add(1);
            }
            if (result[i] == ")") {
                steck.pop();
            }
        }
        if (steck.is_empty()) {
            throw runtime_error("Bracket is false");
        }

        Pow(result, size);

        for (int i = 0; i <= count + 1; i++) {
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
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    
}

//((8 + 5) * 2) +3