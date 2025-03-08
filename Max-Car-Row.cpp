#include<iostream>
using namespace std;

int main (){
    int M,N;
    cout<<"Enter the NO. of rows : " <<endl;
    cin>>M;
    cout<<"Enter the NO. of col : " <<endl;
    cin>>N;

    int parkingLot[M][N];

    for(int i = 0; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>parkingLot[i][j];
        }
    }

    int maxRow = 0 , maxCars = 0 ;
    for(int i = 0; i< M ; i++){
        int carCount = 0 ;
        for(int j = 0 ; j < N ; j++){
            if(parkingLot[i][j] == 1){
                carCount++;
            }
        }
        if(carCount > maxCars){
            maxCars = carCount;
            maxRow= i+1;
        }
    }
    cout << "Maximum at  " << maxRow << " row" <<endl;
    return 0;

}