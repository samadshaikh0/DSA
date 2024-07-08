#include "bits/stdc++.h"
using namespace std;

string firstNonRepeatingChar(string str){

    unordered_map<char,int> m;
    queue<char> q;
    string ans="";

    for(int i = 0;i<str.length();i++){
        m[str[i]]++;
        q.push(str[i]);

        while(!q.empty()){
            if(m[q.front()] > 1){
                q.pop();
            }

            else {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
            ans.push_back('#');
    }
    return ans;

}



int main(){
    string str = "aabcd";
    cout<< firstNonRepeatingChar(str);
    return 0;
}