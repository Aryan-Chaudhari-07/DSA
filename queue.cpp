#include <iostream>
using namespace std;



class Queue
{
private:
    int queue_1[5];
    int F, R,size_;

public:
    Queue()
    {
        F = -1;
        R = -1;
        size_ = 5;
    }

    // Enqueue Operation
    void enqueue(int value)
    {
        if (R == size_ - 1)
        {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        if (F == -1)
            F = 0;

        R++;
        queue_1[R] = value;
        cout << value << " inserted into the queue." << endl;
    }

    // Dequeue Operation
    void dequeue()
    {
        if (F == -1 || F > R)
        {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }

        cout << queue_1[F] << " deleted from the queue." << endl;
        F++;

        // Reset pointers when queue becomes empty
        if (F > R)
        {
            F = -1;
            R = -1;
        }
    }

    // Display Operation
    void display()
    {
        if (F == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = F; i <= R; i++)
        {
            cout << queue_1[i] << " ";
        }
        cout << endl;
    }
 void IsFull(){
        if (R == size_ - 1){
           cout << "Queue Is Full"<<endl;
               return;
        }
        cout << "Queue Is Not Full"<<endl;
        return;
            }
 void IsEmpty(){
        if (F == -1 || F > R){
           cout << "Queue Is Empty"<<endl;
               return;
        }
        cout << "Queue Is Not Empty"<<endl;
        return ;
            }
 void Peek(){
      if (F == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }
cout<< queue_1[F]<<endl;
     return;
            }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n----- Queue Menu -----";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Peek";
        cout << "\n5. IsEmpty";
        cout << "\n6. IsFull";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;
        case 4:
            q.Peek();
            break;
        case 5:
            q.IsEmpty();
            break;
        case 6:
            q.IsFull();
            break;

        case 7:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
