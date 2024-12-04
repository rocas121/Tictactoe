#include <iostream>
#include <vector>

#include <chrono>
#include <thread>

#include <map>
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

vector<string>;
vector<int>;

//Initiating 
char board[3][3] = {{ ' ',' ',' ' },
                    { ' ',' ',' ' },
                    { ' ',' ',' ' }};


bool ingame = true;


char empty = ' ';
char player = 'X'; 
string winnertxt = "\n   ----winner----";

void display() {

    
    cout << "\n\n    " << " A  " << " B  " << " C \n\n";
    for (int i = 0 ; i < 3 ; i++)
    {
        cout << " " << i+1 << "   " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";

        if (i < 2) {
            cout << "    " << "---+---+---\n";
        }

    }

 
}

void write(map<char, int> Choice) {
    for (const auto& pair : Choice) {

        //A1
        if ((pair.first == 'a' && pair.second == 1) || (pair.first == 'A' && pair.second == 1)) {
            board[0][0] = player;
        }
        //A2
        else if ((pair.first == 'a' && pair.second == 2) || (pair.first == 'A' && pair.second == 2)) {
            board[0][1] = player;
        }
        //A3
        else if ((pair.first == 'a' && pair.second == 3) || (pair.first == 'A' && pair.second == 3)) {
            board[0][2] = player;
        }
        //B1
        if ((pair.first == 'b' && pair.second == 1) || (pair.first == 'B' && pair.second == 1)) {
            board[1][0] = player;
        }
        //B2
        else if ((pair.first == 'b' && pair.second == 2) || (pair.first == 'B' && pair.second == 2)) {
            board[1][1] = player;
        }
        //B3
        else if ((pair.first == 'b' && pair.second == 3) || (pair.first == 'B' && pair.second == 3)) {
            board[1][2] = player;
        }

        //C1
        if ((pair.first == 'c' && pair.second == 1) || (pair.first == 'C' && pair.second == 1)) {
            board[2][0] = player;
        }
        //C2
        else if ((pair.first == 'c' && pair.second == 2) || (pair.first == 'C' && pair.second == 2)) {
            board[2][1] = player;
        }
        //C3
        else if ((pair.first == 'c' && pair.second == 3) || (pair.first == 'C' && pair.second == 3)) {
            board[2][2] = player;
        }
    }
}

void win(bool& playing, char player) {

        //lines and collums
        for (int i = 0; i < 3; i++) {

            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                cout << winnertxt;
                playing = false;
                sleep_for(seconds(3));
                return;
            }else if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                cout << winnertxt;
                playing = false;
                sleep_for(seconds(3));
                return;
            }

        }

        //diagonals

        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            cout << winnertxt;
            playing = false;
            sleep_for(seconds(3));

        }else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            cout << winnertxt;
            playing = false;
            sleep_for(seconds(3));
        }
    
}

void redo(bool play) {
    char answer;
    cout << "\n-redo? Y/N : ";
    cin >> answer;

    play == true;
    cout << " DONE \n";
    if (answer == 'y' || answer == 'Y') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }


        }
        

    }

}
void play() {


    map<char, int> Choice;

       
       while (ingame == true){
            display();
            win(ingame, player);
            if (ingame == true) {

                char choice1;
                int choice2;

                cout << "\n-Your turn: ";
                cin >> choice1 >> choice2;
                Choice[choice1] = choice2;
                write(Choice);
            }


       }

    
}

int main(){

    play();
    return 0;
}