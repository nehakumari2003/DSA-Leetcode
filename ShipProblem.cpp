#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int ShipCapacity , NoOfPeople;
    cin>> ShipCapacity >> NoOfPeople;
    
    int rounds = NoOfPeople/ShipCapacity;
    int rem = NoOfPeople % ShipCapacity;
    if(rem != 0){
        rounds = rounds + 1;
    }
    cout<<rounds;
}

