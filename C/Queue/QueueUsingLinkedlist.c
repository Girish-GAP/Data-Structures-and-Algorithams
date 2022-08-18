////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Queue                                                                      //
//                                                                                            //
//  Description :  This application implement the queue by using linkedlist.                  //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         18-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////

// Header file inclusion
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
//
//  Strcture name :     node
//  Data :              intiger, struct node * (Self referential pointer)
//  Description :       Represent the node of queue
//
//////////////////////////////////////////////////////////////////////////
typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE, **PPNODE;

#define BOOL int
#define TRUE 1
#define FALSE 0

/////////////////////////////////////////////////////////////////////////
//
//  Typedef:
//      NODE :          struct node
//      PNODE :         struct node *
//      PPNODE :        struct node **
//      int :           BOOL
//
//  define:
//      TRUE : 1
//      FALSE : 0
//
//////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     Enqueue
//  Input :             struct node **, struct node **, Integer
//  Output :            void
//  Description :       Insert a new node rear of queue
//  TimeComplexity :    O(1)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Create a Memory block and store address of it in struct node pointer.
        Intilize the data of memory block
        If front is NULL (empty queue) simply insert newN in front
           insert newN in rear
        Else insert newn in next of rear
             intilize rear with newn
    STOP
*/
void Enqueue(PPNODE front, PPNODE rear, int iNo)
{
    PNODE temp = *front;
    // memory allocation
    PNODE newN = ((PNODE)malloc(sizeof(NODE)));

    // Node intilization
    newN->data = iNo;
    newN->next = NULL;

    // Insert the data
    if (*front == NULL)
    {
        *front = newN;
        *rear = newN;
    }
    else
    {
        (*rear)->next = newN;
        *rear = newN;
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     Dnqueue
//  Input :             struct node **
//  Output :            void
//  Description :       Dequeue node from front of queue
//  TimeComplexity :    O(1)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Create a Memory block and store address of it in struct node pointer.
        Intilize the data of memory block
        If front is NULL (empty queue) simply return with error code -1
        Else Intilize front with fornt next
    STOP
*/
int Dequeue(PPNODE front)
{
    if (*front == NULL)
    {
        return -1;
    }
    else
    {
        PNODE target = *front;
        *front = (*front)->next;
        free(target);
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     Display
//  Input :             struct node *
//  Output :            void
//  Description :       Display the Data of queue
//  TimeComplexity :    O(1)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        If front is NULL (empty queue) simply return
        Else traverse linkedlist from front to rear and display data
    STOP
*/
void Display(PNODE front)
{
    if (front == NULL)
    {
        printf("Empty queue");
        return;
    }
    while (front != NULL)
    {
        printf("%d -> ", front->data);
        front = front->next;
    }
}

// Entry point function
int main()
{
    // Local variables
    PNODE first = NULL, last = NULL;
    int iChoice = 1, value = 0, iRet = 0;
    BOOL bAns = FALSE;

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
            Enqueue(&first, &last, value);
            printf("\nData Enqueueed at the end of Queue\n");
            break;

        case 2:
            iRet = Dequeue(&first);
            if (iRet == -1)
            {
                printf("Queue is empty");
            }
            else
            {
                printf("Element is Dequeueed form front of Queue");
            }
            break;
        case 3:
            Display(first);
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