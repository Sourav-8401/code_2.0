#include <iostream>
using namespace std;
int main(){
    string str = "SAURAV";
    int a =1, b =9;
    cout<<a+b<<endl; 
    for(int i = str.length()-1; i>=0; i--){
        cout<<str[i];
    }
}