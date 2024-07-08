#include "bits/stdc++.h"
using namespace std;




void print(vector<int> arr){
    for(auto x:arr) cout << x << "  ";
    cout << endl;
}

vector<int> solve(vector<int> &a,vector<int> &b,int n1,int n2){
    int i = 0;
    int j = 0;
    vector<int> intersection;
    
    while(i < n1 && j < n2){
        if( a[i] == b[j] ){
            intersection.push_back(a[i]);
            j++;
            i++;
        }

        else if(a[i] > b[j]){
            j++;
        }
        else    
            i++;
    }
    return intersection;
}


int main(){
    vector<int> a = {1,2,3,4,5,6};
    vector<int> b = {1,2,2,3,6,6,7};
    int n1 = a.size();
    int n2 = b.size();
    print(a);
    print(b);
    cout << "Intersection array :   ";
    print(solve(a,b,n1,n2));
    return 0;

}