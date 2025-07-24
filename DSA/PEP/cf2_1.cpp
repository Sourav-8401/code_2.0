
#include<iostream>
using namespace std;
int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        int l,r;
        cin>>l>>r;
        if(l==r && l != 1){
            cout<<0<<endl;
        }else if(l == r && l == 1){
            cout<<1<<endl;
        }else{
            cout<<r-l<<endl;
        }
    }
}