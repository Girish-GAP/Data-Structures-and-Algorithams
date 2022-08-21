////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Generic Doubly Circular Linked-List                                        //                                                     
//  Description :  This application performs all operations of Doubly circular linked list    //
//                                                                                            //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         19-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////

// Header file inclusion
#include <iostream>
using namespace std;

// Node strcture
template <typename T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

#define NODE node<T>
#define PNODE node<T>*


template <class T>
class DoublyCll
{
private:
    PNODE Head;
    PNODE Tail;
    int size;

public:
    // Functions declaraitons
    DoublyCll();
    void InsertAtFirst(int iNo);
    void InsertAtLast(int iNo);
    void InsertAtPos(int iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    int Count();
    void DisplayForward();
    void DisplayBackward();
};

// Constructor
template <class T>
DoublyCll<T> ::DoublyCll() : Head(NULL), Tail(NULL), size(0) {}

// Functions definations
template <class T>
void DoublyCll<T> ::InsertAtFirst(int iNo) // try
{
    // Memory allocation
    PNODE newN = new NODE();

    // Node Intilization
    newN->data = iNo;
    newN->next = NULL;
    newN->prev = NULL;

    // Insert Node
    if (Head == NULL)
    {
        Head = newN;
        Tail = newN;
        newN->next = Head;
        Head->prev = newN;
    }
    else
    {
        newN->next = Head;
        Head->prev = newN;
        Head = newN;
        Tail->next = Head;
    }
    size++;
}

template <class T>
void DoublyCll<T> ::InsertAtLast(int iNo)
{
    PNODE temp = Head;

    // Memory allocation
    PNODE newN = ((PNODE)malloc(sizeof(NODE)));

    // Initlize node
    newN->data = iNo;
    newN->next = NULL;
    newN->prev = NULL;

    // Insert node
    if (Head == NULL)
    {
        Head = newN;
        Tail = newN;
        newN->next = Head;
        Head->prev = newN;
    }
    else
    {
        newN->prev = Tail;
        Tail->next = newN;
        newN->next = Head;
        Tail = newN;
    }
    size++;
}

template <class T>
void DoublyCll<T> ::InsertAtPos(int iNo, int iPos)
{
    int icnt = 0;
    PNODE temp = Head;

    // Memory allocation
    PNODE newN = ((PNODE)malloc(sizeof(NODE)));

    // Intilize new node
    newN->data = iNo;
    newN->next = NULL;
    newN->prev = NULL;

    // Insert new node
    if (Head == NULL || iPos <= 0)
    {
        Head = newN;
        Tail = newN;
        newN->next = Head;
        Head->prev = newN;
        size++;
    }
    else if (iPos == 1)
    {
        InsertAtFirst(iNo);
    }
    else
    {
        do
        {
            icnt++;
            if (icnt == iPos - 1) // The privious node of desired position
            {
                newN->next = temp->next;
                temp->next->prev = newN;
                temp->next = newN;
                newN->prev = temp;
                size++;
                break;
            }
            temp = temp->next;

        } while (temp != Tail);

        if (temp == Tail) // If iPos >= no. of nodes in linked list
        {
            InsertAtLast(iNo);
        }
    }
}

template <class T>
void DoublyCll<T> ::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else if(Head->next == Head) // If only one element
    {
        Head = NULL;
        Tail = NULL;
        delete(Head);
        delete(Tail);
        size--;
    }
    else    // If more than one element
    {
        PNODE target = Head;
        Head = Head->next;
        Head->prev = Tail;
        Tail->next = Head;
        delete(target);
        size--;
    }
}

template <class T>
void DoublyCll<T> ::DeleteLast()
{
    PNODE temp = Head;

    if (Head == NULL)
    {
        return;
    }
    else
    {
        if (Head->next == Head) // If only one node
        {
            Head = NULL;
            Tail = NULL;
            delete(Head);
            delete(Tail);
            size--;
        }
        else
        {
            while (temp->next != Tail)  // More than one node
            {
                temp = temp->next;
            }
            PNODE target = Tail;
            temp->next = Head;
            Tail = NULL;
            Tail = temp;
            Head->prev = Tail;
            size--;
        }
    }
}

template <class T>
void DoublyCll<T> ::DeleteAtPos(int iPos)
{
    int icnt = 0;
    PNODE temp = Head;

    if (Head == NULL)
    {
        return;
    }
    else
    {
        if (iPos == 1)
        {
            DeleteFirst();
        }

        else
        {
            do
            {
                icnt++;

                if (icnt == iPos - 1) // The privious node of desired position
                {
                    PNODE target = temp->next;
                    temp->next = target->next;
                    target->next->prev = temp;
                    target = NULL;
                    delete(target);
                    size--;
                    break;
                }
                temp = temp->next;

            } while (temp != Tail);

            if (temp == Tail) // If iPos >= no. of nodes in linked list
            {
                DeleteLast();
            }
        }
    }
}

template <class T>
void DoublyCll<T> ::DisplayForward()
{
    PNODE temp = Head;

    if (temp == NULL)
    {
        printf("\nEmpty linkedlist");
        return;
    }

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != Tail->next);
}

template <class T>
void DoublyCll<T> :: DisplayBackward()
{
    PNODE temp = Tail;

    if (temp == NULL)
    {
        printf("\nEmpty linkedlist");
        return;
    }

    while(temp != Head)
    {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << temp->data << " -> ";
}

template <class T>
int DoublyCll<T> :: Count()
{
    return size;
}

// Entry point function
int main()
{
    // Local variables
    int iChoice = 1, iRet = 0, pos = 0;
    char  value = '\0';
    bool bAns = false;

    DoublyCll <char> lobj;

    while (iChoice != 0)
    {
        cout << ("\n_________________________________________________\n");
        cout << ("Linked list operations <char> : \n\n");
        cout << ("1 : Insert the node at first position\n");
        cout << ("2 : Insert the node at last position\n");
        cout << ("3 : Insert the node at  the desired position\n");
        cout << ("4 : Delete the first node\n");
        cout << ("5 : Delete the last node\n");
        cout << ("6 : Delete the node at desired position\n");
        cout << ("7 : Display the contents of linked list [Forward manner]\n");
        cout << ("8 : Display the contents of linked list [Backward manner]\n");
        cout << ("9 : Count the number of nodes from linked list\n");
        cout << ("0 : Terminate the application\n");
        cout << ("\nSelect Option -> ");
        cin >> iChoice;
        cout << ("\n_________________________________________________\n");

        switch (iChoice)
        {
        case 1:
            cout << ("Enter the data to insert\n");
            cin >> value;
            lobj.InsertAtFirst(value);
            cout << ("\nData inserted at first place..\n");
            break;

        case 2:
            cout << ("Enter the data to insert\n");
            cin >> value;
            lobj.InsertAtLast(value);
            cout << ("\nData inserted at last place..\n");
            break;

        case 3:
            cout << ("Enter the data to insert\n");
            cin >> value;
            cout << ("Enter the position\n");
            cin >> pos;
            lobj.InsertAtPos(pos, value);
            cout << ("\nData inserted..\n");
            break;

        case 4:
            lobj.DeleteFirst();
            cout << ("\nFirst element is deleted..\n");
            break;

        case 5:
            lobj.DeleteLast();
            cout << ("\nLast element is deleted..\n");
            break;

        case 6:
            cout << ("Enter the position\n");
            cin >> pos;
            lobj.DeleteAtPos(pos);
            cout << "\nData deleted...\n";
            break;

        case 7:
            cout << ("Elemenet of Linked list in forward manner : \n\n");
            lobj.DisplayForward();
            break;

        case 8:
            cout << ("Elemenet of Linked list in backward manner : \n\n");
            lobj.DisplayBackward();
            break;

        case 9:
            iRet = lobj.Count();
            cout << "No. of elements in linked list are : " << iRet;
            break;

        case 0:
            cout << ("\nThankyou for using Giri Linked List...\n\n");
            break;

        default:
            cout << ("\nPlease enter proper choice\n");
            break;
        }
    }

    return 0; // Return success to OS
}