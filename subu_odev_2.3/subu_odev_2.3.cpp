#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int ROWS = 21;
const int COLS = 50;

void printMaze(const vector<string>& maze) {
    for (const auto& row : maze) {
        cout << row << endl;
    }
}

bool isValidMove(const vector<string>& maze, int x, int y) {
    return x >= 0 && x < ROWS&& y >= 0 && y < COLS&& maze[x][y] != '#';
}

int main() {


    cout << "kuzey = 8" << endl;
    cout << "guney = 2" << endl;
    cout << "dogu = 6" << endl;
    cout << "bati = 4" << endl;
    cout << "( yonleri NUM LOCK dan kolayca yapabilirsiniz )" << endl << endl << endl;


    vector<string> maze(ROWS);
    ifstream file("harita.txt");

    if (!file) {
        cerr << "harita.txt dosyasi acilamadi." << endl;
        return 1;
    }

    for (int i = 0; i < ROWS; ++i) {
        getline(file, maze[i]);
    }
    file.close();




    int startX = 1, startY = 1;
    int endX = 19, endY = 48;
    int x = startX, y = startY;

    printMaze(maze);

    while (true) {
        string direction;
        cout << endl << endl << "Yon girin (8, 2, 6, 4): ";
        cin >> direction;

        int newX = x, newY = y;

        if (direction == "8") {
            newX--;
        }
        else if (direction == "2") {
            newX++;
        }
        else if (direction == "6") {
            newY++;
        }
        else if (direction == "4") {
            newY--;
        }
        else {
            cout << "Gecersiz yon!!!!!!!!" << endl;
            continue;
        }

        if (isValidMove(maze, newX, newY)) {
            swap(maze[x][y], maze[newX][newY]);
            x = newX;
            y = newY;
            printMaze(maze);

            if (x == endX && y == endY) {
                cout << "Tebrikler! Cikisi buldunuz!" << endl;
                break;
            }
        }
        else {
            cout << "Gecersiz hareket!" << endl;
        }
    }

    return 0;
}
