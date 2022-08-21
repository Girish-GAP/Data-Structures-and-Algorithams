////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Stack implementation using linkedlist                                      //
//                                                                                            //
//  Description :  This application implement the stack by using linkedlist which accept      //
//                  any given datatype.                                                       //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         18-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////

// Header file inclusion
#include<iostream>
using namespace std;


// Structure node
typedef struct node
{
    int data;
    struct node * next;
}NODE, *PNODE;

// Stack class
class Stack     // Singly linked list
{
    private :
        int size;
        PNODE Top;

    public :
    Stack();
    void Push(int iNo);
    void Pop();
    int Count();
    void Display();
    bool isEmpty();
};

Stack :: Stack()
{
    size = 0;
    Top = NULL;
}

void Stack :: Push(int iNo)     // Insert at first
{
    // Memory allocation
    PNODE newN = new NODE();

    // Intilize new node
    newN->data = iNo;
    newN->next = NULL;

    // Insert node
    if(Top == NULL)
    {
        Top = newN;
    }
    else
    {
        newN->next = Top;
        Top = newN;
    }
    size++;
}

void Stack :: Pop()
{
    if(Top == NULL)
    {
        return;
    }
    else if(Top->next == NULL)
    {
        Top = NULL;
        delete(Top);
    }
    else
    {
        PNODE target = Top;
        Top = Top->next;
        target = NULL;
        delete(target);
    }
    size--;
}


void Stack :: Display()
{
    PNODE temp = Top;

    if(Top == NULL)
    {
        cout << "\nEmpty stack" << endl;
    }
    else
    {
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
}

bool Stack :: isEmpty()
{
    if(Top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Stack :: Count()
{
    return size;
}


// Entry point function
int main()
{
    // Local variables
    Stack sobj;
    int iChoice = 1, value = 0, iRet = 0;
    bool bAns = false;

    printf("\nStack\n");

    while (iChoice != 0)
    {
        printf("\n_________________________________________________\n");
        printf("Stack operations : \n\n");
        printf("1 : Push\n");
        printf("2 : Pop\n");
        printf("3 : isEmpty\n");
        printf("4 : Count\n");
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
            sobj.Push(value);
            printf("\nData pushed at top of stack\n");
            break;

        case 2:
            sobj.Pop();
            break;

        case 3:
            bAns = sobj.isEmpty();
            if (bAns == true)
            {
                printf("Stack is empty");
            }
            else
            {
                printf("Stack is not-empty");
            }
            break;

        case 4:
            iRet = sobj.Count();
            printf("Total elements in stack : %d", iRet);
            break;

        case 5:
            sobj.Display();
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
