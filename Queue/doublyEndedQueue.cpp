#include "bits/stdc++.h"
using namespace std;

class deQueue {
public:
    int *arr;
    int size;
    int front;
    int rear;

    deQueue(int len){
        size = len;
        arr = new int[size];
        front = -1;
        rear = -1;
        for(int i = 0;i<size;i++){
            arr[i] = -1;
        }
    }
    bool isEmpty(){
        if(front == -1 && rear == -1)
            return true;
        else 
            return false;
    }

    bool isFull(){
        if(front == (rear+1)%size)
            return true;
        else 
            return false;
    }

    void push_front(int el){
        if(isFull()){
            cout << "Queue is Full!\n";
        }
        else if(isEmpty()){
            front = 0;
            rear = 0;
            arr[front] = el;
        }
        else if(front == 0){
            front = size-1;
            arr[front] = el;
        }
        else{
            front--;
            arr[front] = el;
        }
    }

    void push_back(int el){
        if(isFull())
            cout << "Queue is Full!\n";
        else if(isEmpty()){
            front= 0;
            rear = 0;
            arr[rear] = el;
        }
        else{
            rear = (rear+1)%size;
            arr[rear] = el;
        }
    }

    void pop_front(){
        if(isEmpty()){
            cout << "Queue is Empty!\n";
            return ;
        }
        int data = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
            cout << "Element " << data << " has been removed from queue!\n";
        }
        else{
            front = (front+1)%size;
            cout << "Element " << data << " has been removed from queue!\n";
        }
    }

    void pop_back(){
        if(isEmpty()){
            cout <<"Queue is Empty!\n";
            return ;
        }
        int data = arr[rear];
        if(front == rear){
            front = -1;
            rear = -1;
            cout << "Element " << data << " has been removed from queue!\n";
        }
        else if(rear == 0){
            rear = size-1;
            cout << "Element " << data << " has been removed from queue!\n";
        }
        else {
            rear = rear-1;
            cout << "Element " << data << " has been removed from queue!\n";
        }
    }

    void printDequeue(){
        if(isEmpty()){
            cout << "Queue is Empty!\n";
        }
        else{
            int copyF = front;
            int copyR = rear;

            if(copyR == copyF){
                cout << arr[copyF] << endl;
                return ;
            }
            int i = copyF;
            while(i!=copyR){
                cout << arr[i] <<endl;
                i = (i+1)%size;
                if(i == copyR) cout << arr[i] <<endl;
            }
            
        }
    }
};




int main(){
    deQueue q(8);
    q.push_front(9);
    q.push_front(65);
    q.push_front(71);
    q.push_front(52);
    q.push_back(23);
    q.push_back(81);
    q.push_back(87);
    q.push_back(73);
    
    q.push_back(9);
    q.push_front(62);

    
    q.printDequeue();
    cout << "Front : " <<q.front <<"   Rear : " <<q.rear << endl;
    
    return 0;
}