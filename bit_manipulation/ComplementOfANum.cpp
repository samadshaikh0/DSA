#include "bits/stdc++.h"
using namespace std;

// 2's Complement of 5:
//Approach : 
// find the mask using right shift of 5 that is total number of 1 at end of mask = until number is not 0
// rest of the bits of mask are zero 
// perform & operation of mask and not of (~) number
// return the answer





int main(){
    int n = 5;
    int mask = 0;
    if( n == 0){
        cout << 1 <<endl;
    }

    while(n != 0){
        mask = (mask << 1) | 1;
        n = n >> 1;
    }

    int ans = mask & (~n);
    cout << ans;

}