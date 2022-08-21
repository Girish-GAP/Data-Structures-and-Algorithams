////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Generic Doubly Linear Linked list                                          //
//                                                                                            //
//  Description :  This application performs all operations of Doubly linear linked list      //
//                 for any given datatype.                                                    //
//                                                                                            //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         19-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////   

// Header file inclusion
#include <iostream>
using namespace std;

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
class DoublyLL
{
private:
    int size;
    PNODE Head;

public:
    DoublyLL();
    void InsertAtFirst(int iNo);
    void InsertAtLast(int iNo);
    void InsertAtPos(int iPos, int iNo);
    void DeleteAtFirst();
    void DeleteAtLast();
    void DeleteAtPos(int iPos);
    int Count();
    void DisplayForward();
    void DisplayBackward();
};

template <class T>
DoublyLL<T> ::DoublyLL()
{
    size = 0;
    Head = NULL;
}

template <class T>
void DoublyLL<T> ::InsertAtFirst(int iNo)
{
    // Memory allocation
    PNODE newN = new NODE();

    // Node intilization
    newN->data = iNo;
    newN->next = NULL;
    newN->prev = NULL;

    // Insert node
    if (Head == NULL)
    {
        Head = newN;
    }
    else
    {
        newN->next = Head;
        Head->prev = newN;
        Head = newN;
    }
    size++;
}

template <class T>
void DoublyLL<T> ::InsertAtLast(int iNo)
{
    PNODE temp = Head;

    // Memory allocation
    PNODE newN = new NODE();

    // data intilization
    newN->data = iNo;
    newN->next = NULL;
    newN->prev = NULL;

    if (Head == NULL)
    {
        Head = newN;
    }
    else if(Head->next == NULL)  // If contains only one node
    {
        Head->next = newN;
        newN->prev = Head;
    }
    else
    {
        while (temp->next != NULL) // If more than one node
        {
            temp = temp->next;
        }
        
        newN->prev = temp;
        temp->next = newN;
    }
    size++;
}

template <class T>
void DoublyLL<T> ::InsertAtPos(int iPos, int iNo)
{
    PNODE temp = Head;
    bool bAns = true;

    // Memory allocation
    PNODE newN = new NODE();

    // Intilization data
    newN->data = iNo;
    newN->next = NULL;
    newN->prev = NULL;

    // Insert node
    if ((Head == NULL) || (iPos == 1))
    {
        InsertAtFirst(iNo);
    }
    else if (iPos > size)
    {
        InsertAtLast(iNo);
        bAns = false;
    }
    else
    {
        for (int i = 1; i < iPos - 1; i++)  // one node before desired position
        {
            temp = temp->next;
        }
        
        newN->next = temp->next;
        newN->prev = temp;
        temp->next = newN;
    }
    size++;
}

template <class T>
void DoublyLL<T> ::DeleteAtFirst()
{
    if(Head->next == NULL)
    {
        Head = NULL;
        return;
        size--;
    }

    if (Head != NULL)
    {
        PNODE target = Head;
        Head = Head->next;
        Head->prev = NULL;
        target = NULL;
        delete (target);
        size--;
    }
}

template <class T>
void DoublyLL<T> ::DeleteAtLast()
{
    PNODE temp = Head;

    if (Head == NULL)
    {
        return;
    }

    if (Head->next == NULL)
    {
        Head = NULL;
        delete (Head);
        size--;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
        size--;
    }
}

template <class T>
void DoublyLL<T> ::DeleteAtPos(int iPos)
{
    PNODE temp = Head;
    bool bAns = true;

    if (Head == NULL)
    {
        return;
    }

    if (iPos == 1)
    {
        DeleteAtFirst();
    }
    if (iPos >= size)
    {
        DeleteAtLast();
        bAns = false;
    }
    else
    {
        for (int i = 1; i < iPos - 1; i++)  // Access privious node of desired position
        {
            temp = temp->next;
        }

        PNODE target = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        target = NULL;
        delete (target);
        size--;
    }
}

template <class T>
void DoublyLL<T> ::DisplayForward()
{
    PNODE temp = Head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

template <class T>
void DoublyLL<T> :: DisplayBackward()
{
    PNODE temp = Head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    while(temp != Head)
    {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << temp->data << " -> ";
}

template <class T>
int DoublyLL<T> :: Count()
{
    return size;
}

// Entry point function
int main()
{
    // Local variables
    int iChoice = 1, iRet = 0, pos = 0;
    char value = '\0';
    bool bAns = false;

    DoublyLL <char> lobj;

    cout << ("\n_________________________________________________\n");
    cout << ("Linked list operations <char> \n\n");
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

    while (iChoice != 0)
    {
        cout << ("\n___________________\n");
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
            lobj.DeleteAtFirst();
            cout << ("\nFirst element is deleted..\n");
            break;

        case 5:
            lobj.DeleteAtLast();
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