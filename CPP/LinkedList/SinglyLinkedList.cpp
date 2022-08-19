////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Singly-Linked-List                                                         //
//                                                                                            //
//  Description :  This application performs all operations of singly linked list             //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         19-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////   


// Inclusion of header file
#include <iostream>
using namespace std;

// Represent the node
typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE;

// Linked list class
class SinglyLL
{
private:
    PNODE Head;
    int size = 0;

public:

    // Function declarations / prototype
    SinglyLL();
    void InsertAtFirst(int iNo);
    void InsertAtLast(int iNo);
    bool InsertAtPos(int iPos, int iNo);
    void DeleteAtFirst();
    void DeleteAtLast();
    bool DeleteAtPos(int iPos);
    int Count();
    bool Search(int iNo);
    void Display();
};

// Constructor
SinglyLL :: SinglyLL()
{
    Head = NULL;
    size = 0;
}

// Function defination
void SinglyLL ::InsertAtFirst(int iNo)
{
    // Memory allocation
    PNODE newN = NULL;
    newN = new NODE();

    // Intilization of node
    newN->data = iNo;
    newN->next = NULL;

    // Insert node
    if (Head == NULL)
    {
        Head = newN;
    }
    else
    {
        newN->next = Head;
        Head = newN;
    }
    size++;
}

void SinglyLL ::InsertAtLast(int iNo)
{
    PNODE temp = Head;

    // Memory allocation
    PNODE newN = new NODE();

    // data intilization
    newN->data = iNo;
    newN->next = NULL;

    if (Head == NULL)
    {
        Head = newN;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newN;
    }
    size++;
}

bool SinglyLL ::InsertAtPos(int iPos, int iNo)
{
    PNODE temp = Head;
    bool bAns = true;

    // Memory allocation
    PNODE newN = new NODE();

    // Intilization data
    newN->data = iNo;
    newN->next = NULL;

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
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newN->next = temp->next;
        temp->next = newN;
    }
    size++;
    return bAns;
}

void SinglyLL ::DeleteAtFirst()
{
    if (Head != NULL)
    {
        PNODE temp = Head;
        Head = Head->next;
        delete (temp);
        size--;
    }
}

void SinglyLL ::DeleteAtLast()
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

bool SinglyLL ::DeleteAtPos(int iPos)
{
    PNODE temp = Head;
    bool bAns = true;

    if (Head == NULL)
    {
        return -1;
    }

    if (iPos == 1)
    {
        DeleteAtFirst();
    }
    if (iPos > size)
    {
        DeleteAtLast();
        bAns = false;
    }
    else
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        PNODE target = temp->next;
        temp->next = temp->next->next;
        delete (target);
        size--;
    }
    return bAns;
}

int SinglyLL ::Count()
{
    return size;
}

bool SinglyLL ::Search(int iNo)
{
    PNODE temp = Head;
    bool bAns = false;

    while (temp->next != NULL)
    {
        if (temp->data == iNo)
        {
            bAns = true;
            break;
        }
        temp = temp->next;
    }

    return bAns;
}

void SinglyLL ::Display()
{
    PNODE temp = Head;

    if(Head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

// Entry point function
int main()
{
    // Local variables
    int iChoice = 1, value = 0, iRet = 0, pos = 0;
    bool bAns = false;

    SinglyLL lobj;

    cout << ("\n_________________________________________________\n");
    cout << ("Linked list operations : \n\n");
    cout << ("1 : Insert the node at first position\n");
    cout << ("2 : Insert the node at last position\n");
    cout << ("3 : Insert the node at  the desired position\n");
    cout << ("4 : Delete the first node\n");
    cout << ("5 : Delete the last node\n");
    cout << ("6 : Delete the node at desired position\n");
    cout << ("7 : Display the contents of linked list\n");
    cout << ("8 : Count the number of nodes from linked list\n");
    cout << ("9 : Search and check given element present or not \n");
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
            bAns = lobj.InsertAtPos(pos, value);
            if (bAns == false)
            {
                cout << ("\nData inserted..\n", pos);
            }
            else
            {
                cout << "\nData inserted at last place..! [ " << pos << " number of nodes are not present in SinglyLL ]\n";
            }
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
            bAns = lobj.DeleteAtPos(pos);
            if (bAns == false)
            {
                cout << "\nData deleted from " << pos <<" place..\n";
            }
            else
            {
                cout << "\nData deleted from " << pos <<" place..\n";
            }

            break;

        case 7:
            cout << ("Elemenet of Linked list are\n\n");
            lobj.Display();
            break;

        case 8:
            iRet = lobj.Count();
            cout << "\nNumber of elements are : "<< iRet << endl;
            break;

        case 9:
            cout << ("Enter the data to search : \n");
            cin >> value;
            bAns = lobj.Search(value);
            if (bAns == true)
            {
                cout << ("Element is present in linked list.\n");
            }
            else
            {
                cout << ("Element is not present in linked list.\n");
            }
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
