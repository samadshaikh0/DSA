#include "bits/stdc++.h"
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};




int tour(petrolPump p[], int n){
    int balance = 0;
    int dificit = 0;
    int start = 0;

    for(int i = 0;i<n;i++){
        balance+= (p[i].petrol-p[i].distance);
        if(balance < 0){
            dificit+=balance;
            start = i+1;
        }
    }

    if(balance+dificit>=0){
        return start;
    }
    else{
        return -1;
    }
}


int main(void){
    petrolPump p1,p2,p3,p4;
    p1.petrol = 4;
    p1.distance = 6;

    p2.petrol = 6;
    p2.distance = 5;

    p3.petrol = 7;
    p3.distance = 3;

    p4.petrol = 4;
    p4.distance = 5;
    petrolPump p_array[] = {p1,p2,p3,p4};
    int n = 4;
    cout << tour << endl;

    return 0;
}