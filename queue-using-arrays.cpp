#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Queue {
    private:
        int A[MAX_SIZE];
        int front, rear;

    public:

        Queue() {          
            front = -1;
            rear = -1 ;
        }
      bool IsFull()  {
          if (rear == (MAX_SIZE -1)) return true;
          else return false;
      }

      bool IsEmpty() {
          if (front == -1 && rear == -1) return true;
          else false;
      }

      void Enqueue(int x) {
          if (IsFull()) return;
          if (IsEmpty()){
              front = rear = 0;
          } else {
              rear = rear + 1;
          }
          A[rear] = x;
      }

      void Dequeue(){
          if (IsEmpty()) return;
          else if (front == rear) {
              front = rear = -1;
          }
          else {
              front = front + 1;
          }
      }
      void Print(){
          for (int i = front; i <= rear; i++){
              cout << A[i] << " ";
          }
      }
};
int main(){
    Queue Q;
    Q.Enqueue(2);
    Q.Enqueue(4);
    Q.Enqueue(5);
    Q.Dequeue();
    Q.Print();

}