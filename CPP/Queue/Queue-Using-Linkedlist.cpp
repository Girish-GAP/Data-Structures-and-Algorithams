////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Queue                                                                      //
//                                                                                            //
//  Description :  This application implement the queue by using linkedlist.                  //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         18-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE;


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

Queue ::Queue()
{
    front = NULL;
    rear = NULL;
    size = 0;
}

void Queue ::Enqueue(int no) // InsertLast()
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

void Queue ::Dequeue() // Deletefront()
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

void Queue ::Display()
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

int Queue :: Count()
{
    return size;
}

// Entry point function
int main()
{
    // Local variables
    int iChoice = 1, value = 0, iRet = 0;

    Queue qobj;

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
            scanf("%d", &value);
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