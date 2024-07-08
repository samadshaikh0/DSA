#include "bits/stdc++.h"
using namespace std;


int MCM_req(int *arr, int i, int j){

    if(i >= j)
        return 0;
    
    int mini = INT_MAX;
    for(int k=i; k<j; k++){
        int temp_ans = MCM_req(arr, i, k) + MCM_req(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
        mini = min(temp_ans ,mini);
    }
    return mini;
}


static int t[1001][1001];

int MCM_bottom_up(int *arr, int i, int j){

    if(i >= j)
        return 0;

    if(t[i][j] != -1)
        return t[i][j];
    
    int mini = INT_MAX;
    for(int k=i; k<j; k++){
        int temp_ans = MCM_req(arr, i, k) + MCM_req(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
        mini = min(temp_ans ,mini);
    }
    return t[i][j] = mini;
}





int main(){
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(int);
    memset(t,-1,sizeof(t));
    cout << "MCM : " << MCM_bottom_up(arr,1, n-1);

    return 0;
}