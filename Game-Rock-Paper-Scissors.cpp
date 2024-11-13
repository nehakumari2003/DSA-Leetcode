#include <iostream>
using namespace std;

string findWinningMove(const string &playerA){
    if(playerA == "Rock"){
        return "Paper";
    }
    else if(playerA == "Paper"){
        return "Scissors";
    }
    else if(playerA == "Scissors"){
        return "Rock";
    }
    else{
        return "invalid ";
    }
}

int main() {
    string playerA;
    cout << "Enter Player A's move (Rock, Paper, Scissors): ";
    cin >> playerA;

    string playerB = findWinningMove(playerA);
    cout << "Player B's winning move is: " << playerB << endl;

    return 0;
}