////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Generic Stack                                                              //
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
template <typename T>
struct node
{
    T data;
    struct node * next;
};

#define NODE node<T>
#define PNODE node<T>*

template <class T>
class Stack     // Singly linked list
{
    private :
        int size;
        PNODE Top;

    public :
    Stack();
    void Push(T iNo);
    void Pop();
    int Count();
    void Display();
    bool isEmpty();
};

template <class T>
Stack<T> :: Stack()
{
    size = 0;
    Top = NULL;
}

template <class T>
void Stack<T> :: Push(T iNo)     // Insert at first
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

template <class T>
void Stack<T> :: Pop()
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

template <class T>
void Stack<T> :: Display()
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

template <class T>
bool Stack<T> :: isEmpty()
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

template <class T>
int Stack<T> :: Count()
{
    return size;
}


// Entry point function
int main()
{
    // Local variables
    int iChoice = 1, iRet = 0;
    char value = '\0';
    bool bAns = false;

    Stack <char> sobj;

    printf("\nStack\n\n");

    sobj.Push('A');
    sobj.Push('B');
    sobj.Push('C');
    sobj.Push('D');
    sobj.Push('E');

    sobj.Display();

    sobj.Pop();

    cout << endl;
    sobj.Display();

    return 0; // Return success to OS
}