#include <limits>
#include <string>
#include <iostream>
using namespace std;

int exercise_1(string input) {
	try
	{
		long long num = stoll(input);
		if (num > numeric_limits<int>::max() || num < numeric_limits<int>::min()) {
			throw out_of_range("s");
		}
		return num;
	}
	catch (const out_of_range&)
	{
		cout << "This is very big digit" << endl;
		throw;
	}
	catch (const invalid_argument&)
	{
		cout << "This is not digit" << endl;
		throw;
	}
}


void try_catch()
{
    string input;
    cout << "Enter number: ";
    cin >> input;
	try
	{
		int result = exercise_1(input);
		cout << "Number" << result << endl;
	}
	catch (const exception&)
	{
		cout << "Error" << endl;
	}
}


class Steck {
private:
    int* arr;       
    int max_size;   
    int top;        

public:
    Steck(int size){
        this->max_size = size;
        this->top = -1;
        if (size <= 0) {
            throw invalid_argument("Size is not be zero");
        }
        arr = new int[max_size]; 
    }

    ~Steck() {
        delete[] arr;
    }

    void add(int value) {
        if (top >= max_size - 1) {
            throw overflow_error("Steck is max");
        }
        arr[++top] = value; 
    }

    int pop() {
        if (top < 0) {
            throw underflow_error("Steck is empty");
        }
        return arr[--top]; 
    }

    void show() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << endl;
        }
    }

};

int main() {
    try {
        Steck steck(5); 

        steck.add(10);
        steck.add(20);
        steck.add(30);
        steck.add(30);
        steck.show();
        steck.add(30);
        //steck.add(30);
        steck.show();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.pop();
        steck.show();

    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}