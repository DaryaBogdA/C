#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <time.h>

using namespace std;

class One_armed_bandit
{
    int count;
    char step_1, step_2, step_3;
    char symbols[6] = { '$', '*', '#', '@', '+', '='};

    void spin() {
        step_1 = symbols[rand() % 6];
        step_2 = symbols[rand() % 6];
        step_3 = symbols[rand() % 6];
    }

    bool win() {
        return (step_1 == step_2 && step_2 == step_3);
    }
public:

    One_armed_bandit(){
        srand(time(0));
        count = rand() % 8 + 3;
    }

    void show(char step_1, char step_2, char step_3) {
        cout << "-----------------------------------" << endl;
        cout << step_1 << " " << step_2 << " " << step_3 << endl;
        cout << "-----------------------------------" << endl;
    }
    
    void game()
    {
        while (count) {
            cout << "Enter 'Enter'" << endl;
            cin.ignore();
            cout << "You have " << count << " step" << endl;
            spin();
            show(step_1, step_2, step_3);
            if (win()) {
                cout << "you win" << endl;
                return;
            }
            count--;
        }
        cout << "You lose!" << endl;
    }
};

class Bus_stop {
private:
    double passenger_time;
    double minibuses_time;
    bool terminal;
    int max_people;
    double wait_people;
    double interval_time_minibus;
public:
    Bus_stop(double passenger_time_enter, double minibuses_time_enter, bool terminal_enter, int max_people_enter){
        passenger_time = passenger_time_enter;
        minibuses_time = minibuses_time_enter;
        terminal = terminal_enter;
        max_people = max_people_enter;
    }

    double waiting_for_a_passenger() {
        wait_people = 1 / passenger_time * minibuses_time;
        return wait_people;
    }

    double interval_time() {
        interval_time_minibus = max_people / (1 / passenger_time);
        return interval_time_minibus;
    }

    
};






using namespace std;

class Printer {
    string* Wait;
    int* Pri;
    int MaxQueueLength;
    int QueueLength;
public:
    // Конструктор
    Printer(int m) {

        MaxQueueLength = m;

        Wait = new string[MaxQueueLength];
        Pri = new int[MaxQueueLength];

        QueueLength = 0;
    }


    ~Printer() {

        delete[] Wait;
        delete[] Pri;
    }

    int Add(string c, int p) {
        if (!IsFull()) {
            Wait[QueueLength] = c;
            Pri[QueueLength] = p;
            QueueLength++;
        }
        else {
            cout << "FULL!!!!!!!" << endl;
            return 0;
        }
    }


    string Extract() {  

        int max_pri = Pri[0];
            
        int pos_max_pri = 0;

           
        for (int i = 1; i < QueueLength; i++)
            if (max_pri < Pri[i]) {
                max_pri = Pri[i];
                pos_max_pri = i;
            }

        string temp1 = Wait[pos_max_pri];
        int temp2 = Pri[pos_max_pri];

        for (int i = pos_max_pri; i < QueueLength - 1; i++) {
            Wait[i] = Wait[i + 1];
            Pri[i] = Pri[i + 1];
        }
        QueueLength--;
        return temp1;

        

    }
    bool IsFull() {
        return QueueLength == MaxQueueLength;
    }
    void Show() {
        cout << "\n-------------------------------------\n";
        int* indexes = new int[QueueLength];
        for (int i = 0; i < QueueLength; i++) {
            indexes[i] = i;
        }
        sort(indexes, indexes + QueueLength, [this](int a, int b) {
            return Pri[a] < Pri[b];
            });

        for (int i = 0; i < QueueLength; i++) {
            cout << Wait[indexes[i]] << " - " << Pri[indexes[i]] << "\n\n";
        }
        cout << "\n-------------------------------------\n";
        delete[] indexes;
    }
};

int main() {
    One_armed_bandit player;
    player.game();


    double passenger_time, minibuses_time, waiting_for_a_passenger, interval_time;
    bool terminal;
    int max_people;

    cout << "Enter the average time between passengers appearing at a stop (in minutes): ";
    cin >> passenger_time;
    cout << "Enter the average time between minibuses appearing at a stop (in minutes): ";
    cin >> minibuses_time;
    cout << "1 - ultimate 0 - no ultimate: ";
    cin >> terminal;
    cout << "Maximum people on a stop:";
    cin >> max_people;

    Bus_stop minibus_stop(passenger_time, minibuses_time, terminal, max_people);

    waiting_for_a_passenger = minibus_stop.waiting_for_a_passenger();
    interval_time = minibus_stop.interval_time();

    cout << "interval time " << interval_time << " minute" << endl;
    cout << "waiting for a passenger " << waiting_for_a_passenger << " minute" << endl;



    Printer pechat(25);

    pechat.Add("Lessons", 1);
    pechat.Show();
    pechat.Add("Mother", 5);
    pechat.Show();
    pechat.Add("Ferma", 4);
    pechat.Show();
    pechat.Add("Math", 2);
    pechat.Show();
    pechat.Add("son", 3);
    pechat.Show();
    pechat.Extract();
    pechat.Show();

    return 0;
}
