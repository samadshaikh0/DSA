#include "bits/stdc++.h"
using namespace std;


string encode(string src)
{     
    int cnt = 1;
    string ans = "";
    
    for(int i = 0; i < src.length();i++){
        char ch = src[i];
        
        if(ch == src[i+1]){
            cnt++;
        }
        
        else{
            string num = to_string(cnt);
            ans += src[i];
            ans += num;
            cnt = 1;
        }
    }
    return ans;
    
}     


int main(){
    cout << encode("aaawwerrryuhjkiioooolll");
    return 0;
}