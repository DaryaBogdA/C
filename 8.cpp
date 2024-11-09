#include<iostream> 
#include<stdlib.h> 
// в этом файле содержатся rand и srand 
#include<time.h> 
using namespace std;
void exersize1(int num, int SS) {
    string result = "";
    const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int origNum = num;
    if (num == 0) {
        result = "0";
    }
    else {
        while (num > 0) {  
            int i = num % SS;
            result = digits[i] + result;
            num /= SS;
        }
    }

    cout << "Number " << origNum << " in " << SS << "SS: " << result << std::endl;

}







void kubik(int& result) {
    result = rand() % 6 + 1; 
    for (int i = 0; i < 5; i++) {
                cout << "*";
            }
            cout << endl;
        
            cout << "*";
            for (int i = 0; i < 3; i++) {
                cout << " ";
            }
            cout << "*" << endl;
        
        
            cout << "*";
            for (int i = 0; i < 1; i++) {
                cout << " ";
            }
            cout << result;
            for (int i = 0; i < 1; i++) {
                cout << " ";
            }
            cout << "*" << endl;
        
        
            cout << "*";
            for (int i = 0; i < 3; i++) {
                cout << " ";
            }
            cout << "*" << endl;
        
        
            for (int i = 0; i < 5; i++) {
                cout << "*";
            }
            cout << endl;
}

int exersize2() {
    srand(time(0)); 

    int player = 0;
    int computer = 0;
    int playercount = 0, computercount= 0;
    int start;

    cout << "who will walk, press 1 if ves or press 0 if no: ";
    cin >> start;


    if (start == 1) {
        cout << "you\n";
        for (int i = 0; i < 5; i++) {
            kubik(playercount);
            player += playercount;
            cout << "summa count you: " << player << endl;
            cout << "noYou";
            kubik(computercount);
            computer += computercount;
            cout << "summa count noyou: " << computer << endl;
            cout << endl;
        }
    }
    else {
        cout << "noYou\n";
        for (int i = 0; i < 5; i++) {
            kubik(computercount);
            computer += computercount;
            cout << "summa count noyou: " << computer << endl;
            cout << "you\n";
            kubik(playercount);
            player += playercount;
            cout << "summa count you: " << player << endl;
            cout << endl;
        }
    }


    cout << "summa count you: " << player << endl;
    cout << "summa count noyou: " << computer << endl;

    if (player > computer) {
        cout << "you win" << endl;
    }
    else if (computer > player) {
        cout << "you no win" << endl;
    }
    else {
        cout << "you and noyou win" << endl;
    }

    cout << "Average amount you: " << (double)player / 5 << endl;
    cout << "Average amount noyou: " << (double)computer / 5 << endl;

    return 0;
}





int main() {
	//exersize1(16, 3);
    //exersize2();
}