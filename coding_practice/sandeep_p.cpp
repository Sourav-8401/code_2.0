// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n=5;
    int odd=0;
    int mid = (n/2)+1;
    int even = mid;
    for(int i=1; i<=n;i++){
        int tempo = odd;
        int tempe = even;
        int j = 1;
        
        //printing//////////////////////
        while(tempe){
            cout<<"*";
            tempe--;
            j++;
        }
        while(tempo){
           cout<<" ";
           tempo--;
           j++;
       }
       while(j<=n){
           cout<<"*";
           j++;
       }
       /////////////////////////////////
        if(i >= mid){
            even+=1;
            if(i == n-1) odd-=1;
            else odd-=2;
        }else{
            even -=1;
            if(i == 1) odd+=1;
            else odd +=2;
        }
        cout<<endl;
    }
}