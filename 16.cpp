#include <iostream>
#include <cstring>
using namespace std;

struct video_store {
    char name_film1[120];
    char director[120];
    char genre[120];
    float rating;
    float price;
};

int main() {
    int choice;
    char name_movie[120];
    char director[120];
    char genre[120];
    const int m = 100;
    int movie_count = 10;
    float most_rating = 0.0;
    video_store store[m] = {
        {"Iron Man", "Jon Favreau", "Superhero, Action, Adventure", 7.9, 2.99},
        {"The Avengers", "Joss Whedon", "Superhero, Action, Adventure", 8.1, 3.99},
        {"Guardians of the Galaxy", "James Gunn", "Superhero, Action, Adventure", 8.0, 2.99},
        {"Avengers: Age of Ultron", "Joss Whedon", "Superhero, Action, Adventure", 7.3, 3.99},
        {"Captain America: Civil War", "Anthony and Joe Russo", "Superhero, Action, Adventure", 8.0, 3.99},
        {"Doctor Strange", "Scott Derrickson", "Superhero, Action, Fantasy", 7.5, 3.99},
        {"Avengers: Endgame", "Anthony and Joe Russo", "Superhero, Action, Adventure", 8.4, 3.99},
        {"Avengers: Infinity War", "Anthony and Joe Russo", "Superhero, Action, Adventure", 8.4, 3.99},
        {"Ant-Man and the Wasp", "Peyton Reed", "Superhero, Action, Comedy", 7.0, 2.99},
        {"Captain Marvel", "Anna Boden, Ryan Fleck", "Superhero, Action, Adventure", 7.0, 3.99}
    };
    while (true){
        cout << "1. Search by name" << endl;
        cout << "2. Search by genre" << endl;
        cout << "3. Search by director" << endl;
        cout << "4. Most popular film in the genre" << endl;
        cout << "5. Show all entries" << endl;
        cout << "6. Add entry" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "Enter movie title: ";
            cin.getline(name_movie, 120);
            bool found = false;
            for (int i = 0; i < m; i++) {
                if (strcmp(store[i].name_film1, name_movie) == 0) {
                    cout << "Name movie: " << store[i].name_film1 << endl;
                    cout << "Director: " << store[i].director << endl;
                    cout << "Genre: " << store[i].genre << endl;
                    cout << "Rating: " << store[i].rating << endl;
                    cout << "Price: $" << store[i].price << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Movie not found." << endl;
            }
        }
        else if (choice == 2) {
            cout << "Enter genre: ";
            cin.getline(genre, 120);
            bool found = false;
            for (int i = 0; i < m; i++) {
                if (strcmp(store[i].genre, genre) == 0) {
                    cout << "Name movie: " << store[i].name_film1 << endl;
                    cout << "Director: " << store[i].director << endl;
                    cout << "Genre: " << store[i].genre << endl;
                    cout << "Rating: " << store[i].rating << endl;
                    cout << "Price: $" << store[i].price << endl;
                    cout << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Movie not found." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Enter director: ";
            cin.getline(director, 120);
            bool found = false;
            for (int i = 0; i < m; i++) {
                if (strcmp(store[i].director, director) == 0) {
                    cout << "Name movie: " << store[i].name_film1 << endl;
                    cout << "Director: " << store[i].director << endl;
                    cout << "Genre: " << store[i].genre << endl;
                    cout << "Rating: " << store[i].rating << endl;
                    cout << "Price: $" << store[i].price << endl;
                    cout << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Movie not found." << endl;
            }
        }
        else if (choice == 4) {
            cout << "Enter genre: ";
            cin.getline(genre, 120);
            bool found = false;
            for (int i = 0; i < m; i++) {
                if (strcmp(store[i].genre, genre) == 0 && store[i].rating > most_rating) {
                    most_rating = store[i].rating;
                }
            }
            for (int i = 0; i < m; i++) {
                if (strcmp(store[i].genre, genre) == 0 && store[i].rating == most_rating) {
                    cout << "Name movie: " << store[i].name_film1 << endl;
                    cout << "Director: " << store[i].director << endl;
                    cout << "Genre: " << store[i].genre << endl;
                    cout << "Rating: " << store[i].rating << endl;
                    cout << "Price: $" << store[i].price << endl;
                    cout << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Movie not found." << endl;
            }
        }
        else if (choice == 5) {
            for (int i = 0; i < movie_count; i++) {
                cout << "Name movie: " << store[i].name_film1 << endl;
                cout << "Director: " << store[i].director << endl;
                cout << "Genre: " << store[i].genre << endl;
                cout << "Rating: " << store[i].rating << endl;
                cout << "Price: $" << store[i].price << endl;
                cout << endl;
            }
        }
        else if (choice == 6) {
            cout << "Name movie: " << endl;
            cin.getline(store[movie_count].name_film1, 120);
            cout << "Director: " << endl;
            cin.getline(store[movie_count].director, 120);
            cout << "Genre: " << endl;
            cin.getline(store[movie_count].genre, 120);
            cout << "Rating: " << endl;
            cin >> store[movie_count].rating;
            cout << "Price: $" << endl;
            cin >> store[movie_count].price;
            cout << endl;
            cin.ignore();
            movie_count++;
        }
        else if (choice == 0) {
            break;
        }
    }
    return 0;
}
