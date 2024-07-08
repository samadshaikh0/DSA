#include "bits/stdc++.h"
using namespace std;

class Queue{
    public:
        int size;
        int* arr;
        int front;
        int rear;
    
        Queue(int len){
            size = len;
            front = -1;
            rear = -1;
            arr = new int[size];
        }

        bool isFull(){
            if(rear == size-1)
                return true;
            else 
                return false;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1)
                return true;
            else  
                return false;
        }

        void enqueue(int el){
            if(isFull()){
                cout << "Queue is full "<<endl;
                return ;
            }
            if(front == -1 && rear == -1){
                front = 0;
                rear = 0;
                arr[rear] = el;
                return ;
            } 
            else {
                rear = (rear+1);
                arr[rear] = el;
            }
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty!" <<endl;
                return ;
            }
            int data = arr[front];

            if(front == rear){
                front = -1;
                rear = -1;
                cout << "The element " << data << " has been removed from the queue!\n";
            }
            else {
                arr[front] = -1;
                front = (front+1);
                cout << "The element " << data << " has been removed from the queue!\n";
            }
        }

        void printQueue(){
            if(isEmpty()){
                cout << "Queue is empty\n";
            }
            if(front == rear){cout << arr[front] <<endl; return;}
            int copyF = front;
            int copyR = rear;
            int i = copyF;
            while(copyF!=copyR){
                cout << arr[copyF] <<endl;
                copyF = (copyF+1)%size;
                if(copyF == copyR) cout << arr[copyR] <<endl;
            }
        }
};

int main(){
    Queue q1(5);
    q1.enqueue(34);
    q1.enqueue(90);
    q1.enqueue(23);
    q1.enqueue(53);
    q1.enqueue(91);
    q1.printQueue();

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    // cout << "\n\n\n";
    
    cout << "Front : " <<q1.front <<"   Rear : " <<q1.rear << endl;
    q1.enqueue(23);
    q1.printQueue();
    cout << "Front : " <<q1.front <<"   Rear : " <<q1.rear << endl;
    
    

    return 0;
}