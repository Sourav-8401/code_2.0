#include <iostream>
using namespace std;
int i =1;
void pLinerly(int n){
    if(n<i){
        return;
    }
    cout<<i;
    i++;
    pLinerly(n);
}
int main(){
    int n; cin>>n;
    pLinerly(n);
}