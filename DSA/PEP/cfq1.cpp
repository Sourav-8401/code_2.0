#include<iostream>
#include<vector>

using namespace std;
vector<int> find(int n, int side, vector<pair<int, int>>& move){
    int fl=0, ft=0, fr=0, fb=0;
    int l=0, t=0, r=0, b=0;
    
    for(int i=0; i<n; i++){
        int cl=side,ct=side,cr=side,cb=side;
        int tochl = side-move[i].second;
        int tochb = side-move[i].first;
        ct = ct - tochb;
        fb = fb - tochb;
        l += l + side;
        b += side;
        t += ct;
        r += cr;
    }
}
int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        int n,m;
        cin >> n >> m;
        vector<pair<int, int>> moves(n);
        for(auto &p: moves){
            cin >> p.first >> p.second;
        }
        int ans = find(n,m,moves);
        cout << ans <<endl;
        
    }
}