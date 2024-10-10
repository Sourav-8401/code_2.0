#include <iostream>
using namespace std;
// int i=1;
void pLinerly(int n){
    if(n==0){
        return;
    }
    cout<<n;
    pLinerly(--n);
}
int main(){
    int n; cin>>n;
    pLinerly(n);
}