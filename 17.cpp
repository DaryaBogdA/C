#include <iostream>
using namespace std;
//
//union Test {
//    int a;
//    char b;
//};
//
//int main() {
//    Test kkk;
//    kkk.a = 65;
//    cout << kkk.a << " "; // выводит число 65
//    cout << kkk.b << endl; // выводит символ 'A' (соответствующий числу 65)
//    return 0;
//}



//#include <iostream>
//using namespace std;
//void Binary(unsigned A) {
//    int i, N;
//    if (A > 255)
//        N = 15;
//    else
//        N = 7;
//    for (i = N; i >= 0; i--) {
//        cout << ((A >> i) & 1);
//        if (i == 8)
//            cout << " ";
//    }
//    cout << "\n\n";
//}
//
//
//void main() {
//    struct Bits {
//        unsigned bit1 : 3;
//        unsigned bit2 : 2;
//        unsigned bit3 : 3;
//    }Good;
//    Good.bit1 = 4;
//    Good.bit2 = 3;
//    Good.bit3 = 6;
//    cout << "Show: " << Good.bit1 << " ";
//    cout << Good.bit2 << " ";
//    cout << Good.bit3 << "\n\n";
//    cout << "Sum: ";
//    Binary(Good.bit1 + Good.bit2 + Good.bit3);
//
//}


















struct Student {
    string name;
    int group;
    unsigned int exams;
};


bool Result(unsigned A) {
    bool result;
    if (A == 1)
        result = true;
    else
        result = false;
    return result;
}

void Show(string name, int group) {
    cout << "Name " << name << endl;
    cout << "Group " << group << endl;
    cout << "-----------------" << endl;
}

void Sort_students(Student students[], int m) {
    for (int i = 0; i < m - 1; i++) { 
        for (int j = 0; j < m - i - 1; j++) {
            if (students[j].name > students[j + 1].name) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            
        }
        }
    }
}

void exercise1() {
    const int m = 5;
    Student students[m] = {
        {"Gorila", 141, 0b0000},
        {"Fedotor", 142, 0b0001},
        {"Siser", 143, 0b0001},
        {"Vawer", 142, 0b0000},
        {"Deblo", 141, 0b0001},
    };
    cout << "Passed all tests:" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < m; i++) {
        if (Result(students[i].exams)) {
            Show(students[i].name, students[i].group);
        }
    }
    cout << endl;

    cout << "Passed no all tests:" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < m; i++) {
        if (!(Result(students[i].exams))) {
            Show(students[i].name, students[i].group);
        }
    }
    cout << endl;

    cout << "All students in alphabetical order" << endl;

    Sort_students(students, m);
    for (int i = 0; i < m; i++) {
        Show(students[i].name, students[i].group);
    }
    cout << endl;
}





struct Time {
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    unsigned int milliseconds;
};

void Set_time(Time &time, unsigned int hours, unsigned int minutes, unsigned int seconds, unsigned int milliseconds) {
    time.hours = hours;
    time.minutes = minutes;
    time.seconds = seconds;
    time.milliseconds = milliseconds;
}

void Get_time(Time time, unsigned int &hours, unsigned int &minutes, unsigned int &seconds, unsigned int &milliseconds) {
    hours = time.hours;
    minutes = time.minutes;
    seconds = time.seconds;
    milliseconds = time.milliseconds;
}


void exercise2() {
    Time time;
    Set_time(time, 1, 36, 15, 50);
    unsigned int hours, minutes, seconds, milliseconds;
    Get_time(time, hours, minutes, seconds, milliseconds);
    cout << "Time: " << hours << ":" << minutes << ":" << seconds << "." << milliseconds << endl;
}
#include <iostream>
using namespace std;

struct Computer {
    unsigned frame : 1;   
    unsigned video : 1;  
    unsigned memory : 2;  
    unsigned CPU : 4;     
};

void displayConfig(const Computer config) {
    cout << "Frame: " << (config.frame ? "ATX" : "AT") << endl;
    cout << "Video: " << (config.video ? "Map" : "On board") << endl;
    cout << "Memory: ";
    switch (config.memory) {
    case 0: 
        cout << "256 MB"; 
        break;
    case 1: 
        cout << "512 MB"; 
        break;
    case 2: 
        cout << "1 GB"; 
        break;
    case 3: 
        cout << "2 GB"; 
        ;
    }
    cout << endl;
    cout << "CPU: ";
    switch (config.CPU) {
    case 0: 
        cout << "Celeron"; 
        break;
    case 1: 
        cout << "Pentium 4"; 
        break;
    case 2: 
        cout << "AMD"; 
        break;
    case 3: 
        cout << "intel"; 
        break;
    default:
        cout << "I don't know";
    }
    cout << endl;
}

void exercise3() {
    Computer config;
    config.frame = 1;      
    config.video = 1;     
    config.memory = 2;     
    config.CPU = 3;       

    displayConfig(config);
}



int main() {
    //exercise1(); //2
    //exercise2(); //3
    exercise3(); //1
}