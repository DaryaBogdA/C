#include <iostream>
#include <cmath>

using namespace std;

/*
        INLINE
int sum(int a, int b) {
  return a + b;
}
int main() {
  int result = sum(1, 2);
  return 0;
}


inline int sum(int a, int b) {
  return a + b;
}
int main() {
  int result = sum(1, 2);
  return 0;
}


int main() {
  int result = 1 + 2;
  return 0;
}



        РАСКРЫТИЕ МАКРОСА
#define имя_макроса(параметры) (выражение)

#define SQR(X) ((X) * (X)) 
#define CUBE(X) (SQR(X)*(X)) 

using namespace std; 
void main() { 
у = SQR(t + 8) - CUBE(t - 8) ; 
cout <<sqrt(y); 
}


        ПЕРЕГРУЗКА ФУНКЦИЙ
long max_element(int n, int array[])
{
    int value = array[0];
    for (int i = 1; i < n; i++)
        value = value > array[i] ? value : array[i];
    cout << "\nFor (int) : ";
    return long(value);
}

long max_element(int n, long array[])
{
    long value = array[0];
    for (int i = 1; i < n; i++)
        value = value > array[i] ? value : array[i];
    cout << "\nFor (long) : ";
    return value;
}

double max_element(int n, float array[])
{
    float value = array[0];
    for (int i = 1; i < n; i++)
        value = value > array[i] ? value : array[i];
    cout << "\nFor (float) : ";
    return double(value);
}

double max_element(int n, double array[])
{
    double value = array[0];
    for (int i = 1; i < n; i++)
        value = value > array[i] ? value : array[i];
    cout << "\nFor (double) : ";
    return value;
}

void main()
{
    int x[] = {10, 20, 30, 40, 50, 60};
    long f[] = {12L, 44L, 5L, 22L, 37L, 30L};
    float y[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
    double z[] = {0.01, 0.02, 0.03, 0.04, 0.05, 0.06};
    cout << "max_elem(6, x) = " << max_element(6, x);
    cout << "max_elem(6, f) = " << max_element(6, f);
    cout << "max_elem(6, y) = " << max_element(6, y);
    cout << "max elem(6, z) = " << max_element(6, z);
}


        ШАБЛОНЫ ФУНКЦИЙ
template <typename T> T Max(T a, T b) {
   return a > b ? a : b;
    }
    cout << Max(10, 5); //10
    cout << Max(10, 5.5555); //ошибка
}

template <typename T1, typename T2> T2 Max(T1 a, T2 b) {
   return a > b ? a : b;
    }
    cout << Max(10, 5); //10
    cout << Max(10, 5.5555); //10
}
*/





//1
template <typename T> T exercize1(T array[], int size) {
    T result = 0;
    for (int i = 0; i < size; i++) {
        result += array[i];
    }
    result /= size;
    return result;
}



template <typename T1, typename T2, typename T3> 
T3 discriminant(T1 a, T2 b, T3 c) {
    T3 result = sqrt(b*b - 4 * a * c);
    return result;
}

//template <typename T1, typename T2, typename T3> T3 exercize2(T1 a, T2 b, T3 c) {
//    T3 result = (-b + discriminant(a, b, c)) / (2 * a);
//    return result;
//}

//2

template <typename T1, typename T2>
T2 x1(T1 a, T2 b) {
    return -b / a;
}

template <typename T1, typename T2, typename T3>
T3 x1(T1 a, T2 b, T3 c) {
    T3 result = (-b + discriminant(a, b, c)) / (2 * a);
    return result;
}
template <typename T1, typename T2, typename T3>
T3 x2(T1 a, T2 b, T3 c) {
    T3 result2 = (-b - discriminant(a, b, c)) / (2 * a);

    return result2;
}

void rounding(float number, int comma) {
    cout << (number * pow(10, comma)) / pow(10, comma) << endl;
}



int main() {
    //1
    const int size = 5;
    double array[size] = { 1.2, 2.5, 3.6, 4.6, 5.6 };
    //cout << exercize1(array, size);

    //2
    int a = 1;
    double b = 2;
    int c = -3;
    //cout << x1(a, b);

    //cout << x1(a, b, c) << endl;
    //cout << x2(a, b, c);
   

    rounding(2.2257777545647457, 5);
    return 0;
}


