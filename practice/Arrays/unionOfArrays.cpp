#include "bits/stdc++.h"
using namespace std;




void print(vector<int> arr){
    for(auto x:arr) cout << x << "  ";
    cout << endl;
}

vector<int> solve(vector<int> &a,vector<int> &b,int n1,int n2){
    int i = 0;
    int j = 0;
    vector<int> union_array;
    
    while(i < n1 && j < n2){

        if(a[i] >= b[j]){
            if(union_array.size() == 0 || union_array.back() != b[j]){
                union_array.push_back(b[j]);
            }
            j++;
        }
        else{
            if(union_array.size() == 0 || union_array.back() != a[i]){
                union_array.push_back(a[i]);
            }
            i++;
        }
        
    }

    while(i < n1){
        if(union_array.size() == 0 || union_array.back() != a[i]){
                union_array.push_back(a[i]);
        }
        i++;
    }


    while(j < n2){
        if(union_array.size() == 0 || union_array.back() != b[j]){
                union_array.push_back(b[j]);
        }
        j++;
    }
    return union_array;
}


int main(){
    vector<int> a = {1,2,3,4,5,6,7};
    vector<int> b = {1,2,2,3,6,6,7,8,9,10,14};
    int n1 = a.size();
    int n2 = b.size();
    print(a);
    print(b);
    cout << "Union array :   ";
    print(solve(a,b,n1,n2));
    return 0;

}