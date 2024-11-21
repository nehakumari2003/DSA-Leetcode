#include <iostream>
#include <vector>

using namespace std;

int minSwitchPressesToTurnOnAllBulbs(const vector <int> & bulbs){
    int swtichPress = 0;
    int exceptedState = 0;
    for(int i = 0 ; i < bulbs.size() ; i++){
        if(bulbs[i] != exceptedState){
            swtichPress++;
            exceptedState = 1 - exceptedState;
        }
    }
    return exceptedState;
}
int main (){
    int N;
    cout << "Enter the number of bulbs: ";
    cin >> N;

    vector<int> bulbs(N);
    cout << "Enter the initial state of bulbs (0 for OFF, 1 for ON): ";
    for (int i = 0; i < N; ++i) {
        cin >> bulbs[i];
    }

    int result = minSwitchPressesToTurnOnAllBulbs(bulbs);
    cout << "Minimum number of switch presses to turn on all bulbs: " << result << endl;

    return 0;      
}