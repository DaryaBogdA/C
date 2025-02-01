#include <iostream>
#include <cstring>
using namespace std;

//class MyClass {
//private:
//	int data;
//public:
//	MyClass(int d)  {
//		data = d;
//	}
//
//	// Константный метод - не изменяет data
//	int getData() const { return data; }
//
//	// Неконстантный метод - изменяет data
//	void setData(int d) { data = d; }
//};
//
//int main() {
//	const MyClass constObj(10); // Константный объект
//
//	int value = constObj.getData(); // Допустимо - вызов константного метода
//
//	// constObj.setData(20); // Ошибка компиляции - попытка вызвать неконстантный метод для константного объекта
//	return 0;
//}



//class string_ {
//private:
//    char* S;
//    int len;
//public:
//    string_();
//    string_(const char* s);
//    string_(const string_& s);
//    ~string_() {
//        delete[] S;
//    }
//    void Sort(string_ s[], int n);
//    const char* GetStr() const {
//        return S;
//    }
//    void SetStr() {
//        if (S != nullptr) {
//            delete[] S;
//        }
//        char a[256];
//        cin.getline(a, 256);
//        len = strlen(a) + 1;
//        S = new char[len];
//        strcpy_s(S, len, a);
//    }
//    void SetStr2(const char* str) {
//        if (S != nullptr) {
//            delete[] S;
//        }
//        len = strlen(str) + 1;
//        S = new char[len];
//        strcpy_s(S, len, str);
//    }
//
//    string_ operator*(const string_& other) const {
//        string result = "";
//        string str1(this->S);
//        string str2(other.S);
//
//        for (char c : str1) {
//            if (str2.find(c) && result.find(c) == string::npos) {
//                result += c;
//            }
//        }
//        return string_(result.c_str());
//    }
//};
//
//string_::string_() {
//    S = nullptr;
//    len = 0;
//}
//
//string_::string_(const char* s) {
//    len = strlen(s) + 1;
//    S = new char[len];
//    strcpy_s(S, len, s);
//}
//
//string_::string_(const string_& s) {
//    len = s.len;
//    S = new char[len];
//    strcpy_s(S, len, s.S);
//}
//
//void string_::Sort(string_ s[], int n) {
//    string_ temp;
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = n - 1; j > i; j--) {
//            if (strcmp(s[j].S, s[j - 1].S) < 0) {
//                temp.SetStr2(s[j].S);
//                s[j].SetStr2(s[j - 1].S);
//                s[j - 1].SetStr2(temp.S);
//            }
//        }
//    }
//}
//
//int main() {
//    int n;
//    cout << "Input the number of strings:\t";
//    cin >> n;
//    if (n <= 0) {
//        cout << "Error number:\t" << n << endl;
//        return 1;
//    }
//    cin.ignore(); 
//    string_* s = new string_[n];
//    for (int i = 0; i < n; i++) {
//        s[i].SetStr();
//    }
//    s[0].Sort(s, n); 
//    for (int i = 0; i < n; i++) {
//        cout << "\n" << s[i].GetStr() << "\n";
//    }
//    delete[] s;
//   
//    string_ str1("sdqcg");
//    string_ str2("rgfas34");
//    string_ result = str1 * str2;
//    cout << result.GetStr() << endl;
//
//
//}



//class Complex {
//private:
//    double real;
//    double imag;
//public:
//    Complex(double r, double i) : real(r), imag(i) {}
//
//    Complex operator+(const Complex& other) const {
//        return Complex(real + other.real, imag + other.imag);
//    }
//
//    void print() const {
//        std::cout << real << " + " << imag << "i" << std::endl;
//    }
//};
//
//int main() {
//    Complex c1(2.0, 3.0);
//    Complex c2(1.0, -1.0);
//    Complex c3 = c1 + c2; // Используем перегруженный оператор +
//    c3.print(); // Вывод: 3 + 2i
//    return 0;
//}



//class Date {
//private:
//    int day;
//    int month;
//    int year;
//public:
//    
//    Date(int d, int m, int y) {
//        day = d;
//        month = m;
//        year = y;
//    }
//
//    bool leap_year(int year) const {
//        return (year % 4 == 0);
//    }
//
//    int days_month_year(int m, int y) const {
//        if (month == 2) return leap_year(year) ? 29 : 28;
//        if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
//        return 31;
//    }
//
//    int operator-(const Date& other) const {
//        int result_day = 0;
//        int result_month = 0;
//        int result_year = 0;
//        int y1 = year, m1 = month, d1 = day;
//        int y2 = other.year, m2 = other.month, d2 = other.day;
//
//        result_day = day - other.day;
//        result_month = month - other.month;
//        result_year = year - other.year;
//        if (result_day < 0) {
//            result_month--;
//        }
//        if (result_month < 0) {
//            result_year--;
//        }
//
//    }
//
//
//    Date& operator+=(int days) {
//        int days_in_month = days_month_year(month, year);
//        if (day + days <= days_in_month) {
//            day += days;
//            days = 0;
//        }
//        else {
//            days -= (days_in_month - day + 1);
//            day = 1;
//            if (month == 12) {
//                month = 1;
//                ++year;
//            }
//            else {
//                ++month;
//            }
//        }
//        return *this;
//    }
// 
// 
//    void print() const {
//        cout << day << " " << month << " " << year << endl << endl;
//    }
//};
//
//int main() {
//    Date d1(15, 10, 2023);
//    Date d2(25, 12, 2023);
//    Date d3(1, 1, 2024);
//
//    cout << d2 - d1 << endl;
//
//
//    d1 += 10;
//    std::cout << "d1 + 10;" << endl;
//    d1.print();
//
//    d2 += 366;
//    std::cout << "d2 + 366; " << endl;
//    d2.print();
//
//
//}