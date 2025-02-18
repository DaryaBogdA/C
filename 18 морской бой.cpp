#include <iostream>

using namespace std;

void show(char matrix[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

bool position_check(int line1, int column1, int line2, int column2) {
    return (line1 == line2) || (column1 == column2);
}

bool near_position_check(char matrix_you[10][10], int line1, int column1, int line2, int column2) {
    for (int i = min(line1, line2) - 1; i <= max(line1, line2) + 1; ++i) {
        for (int j = min(column1, column2) - 1; j <= max(column1, column2) + 1; ++j) {
            if (i >= 0 && i < 10 && j >= 0 && j < 10) {
                if (matrix_you[i][j] == '1') {
                    return true;
                }
            }
        }
    }
    return false;
}

void position(char matrix_you[10][10], int count_karables) {
    int line1, column1, line2, column2, k = 0;
    cout << "Enter the starting position (line and column):" << endl;
    cin >> line1 >> column1;
    cout << "Enter the ending position (line and column):" << endl;
    cin >> line2 >> column2;
    if (position_check(line1, column1, line2, column2) && !near_position_check(matrix_you, line1, column1, line2, column2)) {
        for (int i = min(line1, line2); i <= max(line1, line2); i++) {
            for (int j = min(column1, column2); j <= max(column1, column2); j++) {
                if (k != count_karables) {
                    matrix_you[i][j] = '1';
                    k++;
                }
            }
        }
    }
    else {
        cout << "Invalid position!" << endl;
        position(matrix_you, count_karables);
    }
}

void cycle(char matrix_you[10][10], int count, int count_karables) {
    for (int i = 0; i < count; i++) {
        position(matrix_you, count_karables);
        cout << "Yes" << endl;
    }
    show(matrix_you);
}

void positioning_the_ships_ourselves(char matrix_you[10][10]) {
    cout << "Put the ship on 4 squares" << endl;
    cycle(matrix_you, 1, 4);

    cout << "Put the ship on 3 squares(2)" << endl;
    cycle(matrix_you, 2, 3);

    cout << "Put the ship on 2 squares(2)" << endl;
    cycle(matrix_you, 3, 2);

    cout << "Put the ship on 1 squares(2)" << endl;
    cycle(matrix_you, 4, 1);
}

void auto_positioon_ship(char matrix_you[10][10], int count_karables){
    int line1, column1, line2, column2;
    bool proverka = false;
    while (!proverka) {
        if (rand() % 2 == 0) {
            line1 = line2 = rand() % 10;
            column1 = rand() % (10 - count_karables + 1);
            column2 = column1 + count_karables - 1;
        } else {
            column1 = column2 = rand() % 10;
            line1 = rand() % (10 - count_karables + 1);
            line2 = line1 + count_karables - 1;
        }
        if (!near_position_check(matrix_you, line1, column1, line2, column2)) {
            for (int i = min(line1, line2); i <= max(line1, line2); ++i) {
                for (int j = min(column1, column2); j <= max(column1, column2); ++j) {
                    matrix_you[i][j] = '1';
                }
            }
            proverka = true;
        }

    }
}

void auto_ship(char matrix_you[10][10]) {
    auto_positioon_ship(matrix_you, 4);
    auto_positioon_ship(matrix_you, 3);
    auto_positioon_ship(matrix_you, 3);
    auto_positioon_ship(matrix_you, 2);
    auto_positioon_ship(matrix_you, 2);
    auto_positioon_ship(matrix_you, 2);
    auto_positioon_ship(matrix_you, 1);
    auto_positioon_ship(matrix_you, 1);
    auto_positioon_ship(matrix_you, 1);
    auto_positioon_ship(matrix_you, 1);
    show(matrix_you);
}




int main()
{
    char choise_auto;
    char matrix_you[10][10] = { // первое строки line второе столбики
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}
    };
    char matrix_ataka[10][10] = { // первое строки второе столбики
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}
    };
    char matrix_comp[10][10] = { // первое строки второе столбики
        {'1', '0', '0', '0', '0', '1', '1', '0', '0', '0'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '1', '0'},
        {'1', '0', '1', '0', '0', '0', '0', '0', '0', '0'},
        {'1', '0', '1', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '1', '0', '0', '1', '1', '1', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '0', '1', '0', '1', '1', '0', '0', '0'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'1', '0', '0', '0', '0', '0', '0', '1', '0', '0'}
    };
    show(matrix_you);
    show(matrix_ataka);
    cout << "Arrange ships: 1 - yourself 2 - automatically" << endl;
    cin >> choise_auto;
    switch (choise_auto) {
    case '1':
        positioning_the_ships_ourselves(matrix_you);
        break;
    case '2':
        auto_ship(matrix_you);
        break;
    default:
        break;
    }
}
