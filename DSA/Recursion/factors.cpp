#include <iostream>

using namespace std;
int main(){
    int n = 30;
    int count = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            if(i == n/i){
                count++;
            }else{
                count +=2;
            }
        }
    }
    cout<<"Number of factors: "<<count<<endl;
}