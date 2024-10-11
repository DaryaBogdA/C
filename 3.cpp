#include <iostream>
#include <string>
using namespace std;

//int main() {
//    string line;
//    char symbol;
//    int kolichestvo;
//
//    cout << "Enter line (gor/vert): ";
//    cin >> line;
//
//    cout << "enter symbol ";
//    cin >> symbol;
//
//    cout << "enter kolichestvo symbol ";
//    cin >> kolichestvo;
//
//    if (line == "gor") {
//        for (int i = 0; i < kolichestvo; i++) {
//            cout << symbol;
//        }
//    }
//    else if (line == "vert") {
//        for (int i = 0; i < kolichestvo; i++) {
//            cout << symbol << endl;
//        }
//    }
//    else {
//        cout << "ti typoi?" << endl;
//    }
//
//    return 0;
//}


//int main() {
//    int start, finish;
//
//    cout << "Enter start of range : ";
//    cin >> start;
//
//    cout << "Enter finish of range : ";
//    cin >> finish;
//    int sum = 0;
//        for (int i = start; i <= finish; i++) {
//            if (i % 2 != 0) {
//                sum += i; 
//            }
//        }
//   
//        cout << "Sum of all odd numbers "<< sum << endl;
//    
//
//    return 0;
//}






int main()
{
	int num, res;
	cout << "Enter number: ";
	cin >> num;
	res = 1;
	for (int i = 1; i <= num; i++) {
		res *= i;
	}
	cout << "Factorial "<< num << " = " << res;

	return 0;
}