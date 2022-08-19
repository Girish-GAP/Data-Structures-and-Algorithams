////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Singly Circular Linked-List                                                //                                                     
//  Description :  This application performs all operations of singly linked list             //
//                                                                                            //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         19-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////

// Header file inclusion
#include <iostream>
using namespace std;

// Node strcture
typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE;

// Class of Circular linked list
class SinglyCll
{
private:
    PNODE Head;
    PNODE Tail;
    int size;

public:
    // Functions declaraitons
    SinglyCll();
    void InsertAtFirst(int iNo);
    void InsertAtLast(int iNo);
    void InsertAtPos(int iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    int Count();
    void Display();
};

// Constructor
SinglyCll ::SinglyCll() : Head(NULL), Tail(NULL), size(0) {}

// Functions definations
void SinglyCll ::InsertAtFirst(int iNo)
{
    // Memory allocation
    PNODE newN = new NODE();

    // Node Intilization
    newN->data = iNo;
    newN->next = NULL;

    // Insert Node
    if (Head == NULL)
    {
        Head = newN;
        Tail = newN;
        newN->next = Head;
    }
    else
    {
        newN->next = Head;
        Head = newN;
        Tail->next = Head;
    }
    size++;
}

void SinglyCll ::InsertAtLast(int iNo)
{
    PNODE temp = Head;

    // Memory allocation
    PNODE newN = ((PNODE)malloc(sizeof(NODE)));

    // Initlize node
    newN->data = iNo;
    newN->next = NULL;

    // Insert node
    if (Head == NULL)
    {
        Head = newN;
        newN->next = Head;
        Tail = newN;
    }
    else
    {
        Tail->next = newN;
        Tail = newN;
    }
    size++;
}



void SinglyCll ::InsertAtPos(int iNo, int iPos)
{
    int icnt = 0;
    PNODE temp = Head;

    // Memory allocation
    PNODE newN = ((PNODE)malloc(sizeof(NODE)));

    // Intilize new node
    newN->data = iNo;
    newN->next = NULL;

    // Insert new node
    if (Head == NULL || iPos <= 0)
    {
        Head = newN;
        newN->next = Head;
        Tail = newN;
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
                temp->next = newN;
                size++;
                break;
            }
            temp = temp->next;

        } while (temp != Tail);

        if (temp == Tail) // If iPos >= no. of nodes in linked list
        {
            newN->next = Head;
            Tail->next = newN;
            Tail = newN;
            size++;
        }
    }
}

void SinglyCll ::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else if(Head->next == Head)
    {
        Head = NULL;
        Tail = NULL;
        delete(Head);
        delete(Tail);
        size--;
    }
    else
    {
        PNODE target = Head;
        Head = Head->next;
        Tail->next = Head;
        delete(target);
        size--;
    }
}

void SinglyCll ::DeleteLast()
{
    PNODE temp = Head;

    if (Head == NULL)
    {
        return;
    }
    else
    {
        if (Head->next == Tail)
        {
            Head = NULL;
            Tail = NULL;
            delete(Head);
            delete(Tail);
            size--;
        }
        else
        {
            while (temp->next != Tail)
            {
                temp = temp->next;
            }

            temp->next = Head;
            Tail = NULL;
            Tail = temp;
            size--;
        }
    }
}

void SinglyCll ::DeleteAtPos(int iPos)
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

void SinglyCll ::Display()
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

int SinglyCll :: Count()
{
    return size;
}

// Entry point function
int main()
{
    // Local variables
    int iChoice = 1, value = 0, iRet = 0, pos = 0;
    bool bAns = false;

    SinglyCll lobj;

    cout << ("\n_________________________________________________\n");
    cout << ("Singly Circular Linked list operations : \n\n");
    cout << ("1 : Insert the node at first position\n");
    cout << ("2 : Insert the node at last position\n");
    cout << ("3 : Insert the node at  the desired position\n");
    cout << ("4 : Delete the first node\n");
    cout << ("5 : Delete the last node\n");
    cout << ("6 : Delete the node at desired position\n");
    cout << ("7 : Display the contents of linked list\n");
    cout << ("8 : Count no. of nodes\n");
    cout << ("0 : Terminate the application\n");

    while (iChoice != 0)
    {
        cout << ("\n\nSelect Option -> ");
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
            lobj.InsertAtPos(value, pos);
            cout << "Data inserted\n";
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
            cout << ("\nData deleted");
            break;

        case 7:
            cout << ("Elemenet of Linked list are\n\n");
            lobj.Display();
            break;

        case 8:
            cout << ("Count no. of nodes\n\n");
            iRet = lobj.Count();
            cout << "No. of nodes are : " << iRet << endl;
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
