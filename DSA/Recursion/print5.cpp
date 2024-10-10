#include <iostream>
using namespace std;
int i =0;
void print(){
    if (i==5){
        return;
    }
    cout<<i<<"hello"<<endl;
    i++;
    print();
}
int main(){
    print();
}