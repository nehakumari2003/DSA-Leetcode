#include <bits/stdc++.h> 
using namespace std;

int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N) {
    int deficit = 0;    
    int balance = 0;     
    int start = 0;       

    
    for (int i = 0; i < N; i++) {
        balance += petrol[i] - distance[i];

        // If balance goes negative, current start point is not feasible
        if (balance < 0) {
            deficit += balance;   
            start = i + 1;        
            balance = 0;          
        }
    }

    
    if (balance + deficit >= 0) {
        return start;
    } else {
        return -1;  
    }
}

int main() {
    vector<int> petrol = {4, 6, 7, 4};  
    vector<int> distance = {6, 5, 3, 5};  
    int N = petrol.size();  

    int startPoint = firstCircularTour(petrol, distance, N);
    if (startPoint != -1) {
        cout << "The first circular tour can start at petrol pump " << startPoint << endl;
    } else {
        cout << "No circular tour is possible" << endl;
    }
    
    return 0;
}
