#include <iostream>
using namespace std;

int main() {
    int v, w;
    cin >> v >> w;

    if(w < 2 || w < 2*v || w > 4*v || w%2 != 0){
        cout << "INVALID INPUT" << endl;
        return 0;
    }
    int FW = (w - 2 * v) / 2;
    int TW = v - FW;

    cout << "TW=" << TW << " FW=" << FW << endl;

    return 0;
}