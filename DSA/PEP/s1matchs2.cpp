#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

// 
boolean match(vector<int>& tempW, vector<int>& freq){
    return true;
}
int find(string s1, string s2){
    // x y z a e b c a d e f
    // s2 = abc
    int n= s2.size();
    vector<int> freq(n+1, 0);
    for(int i=0;i<n; i++){
        freq[s2[i]-'a']++;
    }
    int minW=0;
    int s=0;
    vector<int> tempW(n+1,0);
    for(int i=0; i<s1.size(); i++){
        int curele = s1[i];
        if(freq[curele]>0){
            tempW[curele]++;
        }
        if(match(tempW,freq)){
            minW = min(minW, curWin);
        }
    }

}
int main(){


}