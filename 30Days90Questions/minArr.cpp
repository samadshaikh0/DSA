#include "bits/stdc++.h"
using namespace std;


int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int size = max(max(uniqueCnt1,uniqueCnt2), max(divisor1,divisor2) );
    vector<int> arr(size);

    for(int i=1;i<=size;i++){
        arr.push_back(i);
    }
    int i = 1;
    int un1 = uniqueCnt1;
    while(un1 > 0){
        if( ceil(arr[i] % divisor1) != 0){
            max1 = max(i,max1);
            un1--;
            arr[i] = -arr[i];
        }
        i++;
    }

    i=1;
    int un2 = uniqueCnt2;
    while(un2 > 0){
        if( arr[i] > 0 && ceil(arr[i] % divisor2) != 0 ){
            max2 = max(i,max2);
            un2--;
        }
        i++;
    }
return min(max1,max2);
}



int main(){
    
    return 0;
}