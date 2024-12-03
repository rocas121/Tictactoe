#include <iostream>
#include <vector>

#include <map>
using namespace std;

vector<string>;
vector<int>;

//Initiating 
char board[3][3] = {{ ' ',' ',' ' },
                    { ' ',' ',' ' },
                    { ' ',' ',' ' }};
char player = 'X'; 
string winnertxt = "  ----winner----";

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
                return;
            }else if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                cout << "Winner\n";
                playing = false;
                return;
            }

        }

        //diagonals

        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            cout << "Winner\n";
            playing = false;

        }else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            cout << "Winner\n";
            playing = false;
        }
    
}

void play() {
    bool ingame = true;

    char choice1;
    int choice2;
    map<char, int> Choice;


       while (ingame == true){

            
            display();
            win(ingame, player);

            if (ingame == true) {
                cout << "\n-Your turn: ";
                cin >> choice1 >> choice2;
                Choice[choice1] = choice2;
            }
            write(Choice);
            

       }

    
}

int main(){

    play();

    return 0;
}