////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Stack                                                                      //
//                                                                                            //
//  Description :  This application implement the stack by using linkedlist.                  //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         18-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////

// Toper file inclusion
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
//
//  Strcture name :     node
//  Data :              intiger, struct node * (Self referential pointer)
//  Description :       Represent the node of stack
//
//////////////////////////////////////////////////////////////////////////
typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE, **PPNODE;

// to use user defined boolean
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

// Function prototypes / Declarations
void push(PPNODE Top, int iNo);
int pop(PPNODE Top);
BOOL isEmpty(PNODE Top);
int peek(PNODE Top);
void Display(PNODE Top);

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     push
//  Input :             struct node **, Integer
//  Output :            void
//  Description :       Insert a new node @ top of stack
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
        If Top is NULL (empty stak) simply insert newN in Top
        else @next of newN -> insert address of Top & @Top insert newN
    STOP
*/
void push(PPNODE Top, int iNo)
{
    // Memoy allocation
    PNODE newN = ((PNODE)malloc(sizeof(NODE)));

    // Intilize node
    newN->data = iNo;
    newN->next = NULL;

    // Insert the node
    if (Top == NULL)
    {
        *Top = newN;
    }
    else
    {
        newN->next = *Top;
        *Top = newN;
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     pop
//  Input :             struct node **
//  Output :            void
//  Description :       Pop a node from top of stack
//  TimeComplexity :    O(1)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        If stack empty simply return with error code.
        Else edit top and add second node address
    STOP
*/
int pop(PPNODE Top)
{
    int no = 0;

    if (*Top == NULL)
    {
        return -1;
    }
    else
    {
        no = (*Top)->data;
        PNODE target = *Top;
        *Top = (*Top)->next;
        free(target);
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     isEmpty
//  Input :             struct node *
//  Output :            void
//  Description :       Check if stack is empty or not
//  TimeComplexity :    O(1)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        If Top is null return TRUE
        Else FALSE
    STOP
*/
BOOL isEmpty(PNODE Top)
{
    if (Top == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     peek
//  Input :             struct node *
//  Output :            void
//  Description :       Return the top of stack without removing it
//  TimeComplexity :    O(1)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        If Top is null return TRUE
        Else FALSE
    STOP
*/
int peek(PNODE Top)
{
    return (Top->data);
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     Display
//  Input :             struct node *
//  Output :            void
//  Description :       Display the stack elements
//  TimeComplexity :    O(1)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        If Top is null return
        Else Traverse from to bottom of stak
    STOP
*/
void Display(PNODE Top)
{
    if (Top == NULL)
    {
        printf("Emtpy stack");
        return;
    }

    while (Top != NULL)
    {
        printf("%d -> ", Top->data);
        Top = Top->next;
    }
}

// Entry point function
int main()
{
    // Local variables
    PNODE first = NULL, tail = NULL;
    int iChoice = 1, value = 0, iRet = 0, pos = 0;
    BOOL bAns = FALSE;

    printf("\nStack\n");

    while (iChoice != 0)
    {
        printf("\n_________________________________________________\n");
        printf("Stack operations : \n\n");
        printf("1 : Push\n");
        printf("2 : Pop\n");
        printf("3 : isEmpty\n");
        printf("4 : Peek\n");
        printf("5 : Display\n");
        printf("0 : Terminate the application\n");
        printf("\nSelect Option -> ");
        scanf("%d", &iChoice);
        printf("\n_________________________________________________\n");

        switch (iChoice)
        {
        case 1:
            printf("Enter the data to push into stack\n");
            scanf("%d", &value);
            push(&first, value);
            printf("\nData pushed at top of stack\n");
            break;

        case 2:
            iRet = pop(&first);
            if (iRet == -1)
            {
                printf("Stack is empty");
            }
            else
            {
                printf("Element is poped form top of stack");
            }
            break;

        case 3:
            bAns = isEmpty(first);
            if (bAns == TRUE)
            {
                printf("Stack is empty");
            }
            else
            {
                printf("Stack is not-empty");
            }
            break;

        case 4:
            iRet = peek(first);
            printf("The element at top is : %d", iRet);
            break;

        case 5:
            Display(first);
            break;

        case 0:
            printf("\nThankyou for using Giri Stack...\n\n");
            break;

        default:
            printf("\nPlease enter proper choice\n");
            break;
        }
    }

    return 0; // Return success to OS
}