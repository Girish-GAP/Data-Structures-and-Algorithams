////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Generic Queue                                                              //
//                                                                                            //
//  Description :  This application implement the generic queue by using linkedlist           //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         18-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    struct node *next;
};

#define NODE node<T>
#define PNODE node<T>*

template <class T>
class Queue // Singly Linear Linked List
{
private:
    PNODE front;
    PNODE rear;
    int size;

public:
    Queue();
    void Enqueue(int no); // InsertLast()
    void Dequeue();
    void Display();
    int Count();
};

template <class T>
Queue<T> ::Queue()
{
    front = NULL;
    rear = NULL;
    size = 0;
}

template <class T>
void Queue<T> ::Enqueue(int no) // InsertLast()
{
    // Memory allocation
    PNODE newN = new NODE();

    // Intilize node
    newN->data = no;
    newN->next = NULL;

    // Insert node
    if (front == NULL) 
    {
        front = newN;
        rear = newN;
    }
    else
    {
        rear->next = newN;
        rear = newN;
    }
    size++;
}

template <class T>
void Queue<T> ::Dequeue() // Deletefront()
{
    if (front == NULL)
    {
        return;
    }

    if (front == rear)
    {
        delete front;
        delete rear;
        front = NULL;
        rear = NULL;
    }
    else
    {
        PNODE target = front;
        front = front->next;
        delete target;
    }

    size--;
}

template <class T>
void Queue<T> ::Display()
{
    PNODE temp = front;

    if(front == NULL)
    {
        cout << "Empty queue" << endl;
        return;
    }

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

template <class T>
int Queue<T> :: Count()
{
    return size;
}

// Entry point function
int main()
{
    // Local variables
    int iChoice = 1, iRet = 0;
    char value = '\0';

    Queue <char> qobj;

    printf("\nQueue\n");

    while (iChoice != 0)
    {
        printf("\n_________________________________________________\n");
        printf("Queue operations : \n\n");
        printf("1 : Enqueue\n");
        printf("2 : Dequeue\n");
        printf("3 : Display\n");
        printf("0 : Terminate the application\n");
        printf("\nSelect Option -> ");
        scanf("%d", &iChoice);
        printf("\n_________________________________________________\n");

        switch (iChoice)
        {
        case 1:
            printf("Enter the data to Enqueue into the Queue\n");
            cin >> value;
            qobj.Enqueue(value);
            printf("\nData Enqueueed at the end of Queue\n");
            break;
        case 2:
            qobj.Dequeue();
            printf("\nData Dequeueed front of Queue\n");
            break;
        case 3:
            qobj.Display();
            break;

        case 0:
            printf("\nThankyou for using Giri Queue...\n\n");
            break;

        default:
            printf("\nPlease enter proper choice\n");
            break;
        }
    }

    return 0; // Return success to OS
}