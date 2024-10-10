#include <iostream>
using namespace std;

class Stack{
    int top=-1;
    int len = 5;
    int arr[5];
    public: 
    void push(int data){
        if(top == len-1 ){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    void pop(){
       if(top == -1){
        cout<<"stack underflow"<<endl;
        return;
       }
        --top;
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }
};

int main(){
    Stack s1;

    s1.push(1);
    s1.push(2);
    s1.push(1);
    s1.push(2);
    s1.push(1);
    s1.push(2);
    s1.display();
    cout<<s1.isEmpty()<<endl;
}