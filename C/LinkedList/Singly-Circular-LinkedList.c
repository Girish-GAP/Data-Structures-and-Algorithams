// Singly Linked List

// Header file inclusion
#include <stdio.h>
#include <stdlib.h>



//////////////////////////////////////////////////////////////////////////
//
//  Strcture name :     node
//  Data :              intiger, struct node * (Self referential pointer)
//  Description :       Represent the node of linked list
//
//////////////////////////////////////////////////////////////////////////
typedef struct node
{
    int data;
    struct node *next;

} NODE, *PNODE, **PPNODE;


// to use user defined boolean
typedef int BOOL;
#define TRUE 1
#define FALSE 0


//////////////////////////////////////////////////////////////////////////
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

// Function prototype / Declarations
void InsertAtFirst(PPNODE Head,PPNODE Tail, int iNo);
void InsertAtLast(PPNODE Head,PPNODE Tail, int iNo);
BOOL InsertAtPos(PPNODE Head,PPNODE Tail, int iNo, int iPos);
void DeleteAtFirst(PPNODE Head, PPNODE Tail);
void DeleteAtLast(PPNODE Head, PPNODE Tail);
BOOL DeleteAtPos(PPNODE Head,PPNODE Tail, int iPos);
void Display(PNODE Head, PNODE Tail);
int Count(PNODE Head, PNODE Tail);
int Search(PNODE Head,PNODE Tail, int iNo);
void conquer(PNODE Head, int l,int r,int mid);   // merge sort function
void divide(PNODE Head, int l,int r);            // merge sort function                            


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     InsertAtFirst
//  Input :             struct node **,struct node **, Integer
//  Output :            void
//  Description :       Insert a new node @ first place
//  TimeComplexity :    O(1)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Create a Memory block and store address of it in struct node pointer.
        Intilize the data of memory block.
        If Head & Tail is NULL (empty linked list) simply insert newN in Head & Tail,
        Insert address of newN in next of newN.
        Else @next of newN -> insert address of first node from head,
        @Head insert address of newN,
        @Last node next insert address of newN (to maintain circular nature).
    STOP
*/
void InsertAtFirst(
                            PPNODE Head,    // Gives the address of first node of linkedList.
                            PPNODE Tail,    // Gives the address of last node of linkedList.
                            int iNo         // The data to be inserted
                        )
{
    // Allocate the memory
    PNODE newN = NULL;
    newN = ((PNODE)malloc(sizeof(NODE)));

    // Intilize the data
    newN->data = iNo;
    newN->next = NULL;

    // Insert the node
    if (*Head == NULL && *Tail == NULL)     // Empty linked list
    {
        *Head = newN;
        *Tail = newN;
        newN->next = newN;
    }
    else     // LL contains atlist one node
    {       
        newN->next = *Head;
        *Head = newN;
        (*Tail)->next = newN;
    }
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     InsertAtLast
//  Input :             struct node **, struct node **, Integer
//  Output :            void
//  Description :       Insert a new node @ last place
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
        If Head & Tail is NULL (empty linked list) simply insert at first.
        Else Insert the address of Head in newn->next.
        Insert the address of newN in last element->next.
        Insert the address of newN in tail.
    STOP
*/
void InsertAtLast(
                        PPNODE Head,     // Gives the address of first node of linkedList.
                        PPNODE Tail,     // Gives the address of last node of linkedList.
                        int iNo          // The data to be inserted
                    )
{
    PNODE temp = *Head; // temp for traverse

    // Allocate the memory
    PNODE newN = NULL;
    newN = ((PNODE)malloc(sizeof(NODE)));

    // Intilize the node
    newN->data = iNo;
    newN->next = NULL;

    // Insert the node
    if (*Head == NULL && *Tail == NULL)       // Empty linked list
    {
        *Head = newN;
        *Tail = newN;
        newN->next = newN;
    }
    else        // LL contains atlist one node
    {
        newN->next = ((*Tail)->next);
        (*Tail)->next = newN;
        *Tail = newN;
    }
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     InsertAtPos
//  Input :             struct node **, struct node **, Integer, Integer
//  Output :            void
//  Description :       Insert a new node @ given position
//  TimeComplexity :    O(n)   ( n = iPos )
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Create a Memory block and store address of it in struct node pointer.
        Intilize the data of memory block
        If Head & Tail is NULL (empty linked list) & pos is 1  simply insert at first.
        Else Traverse until reach to privious node of position number node.
        Copy the address of current element-> next in tempSwap pointer
        Insert newN address in Current element->next
        Insert tempSwap in newN -> next
    STOP
*/
BOOL InsertAtPos(PPNODE Head, PPNODE Tail, int iNo, int iPos)
{
    BOOL iFlag = FALSE;     // to indicate if ipos >= last node in linkedlist

    PNODE temp = *Head; // temp for traversal
    PNODE target = NULL;

    // Allocate the memory
    PNODE newN = NULL;
    newN = ((PNODE)malloc(sizeof(NODE)));

    // Intilize the node
    newN->data = iNo;
    newN->next = NULL;

    // Insert the node
    if (*Head == NULL || iPos == 1)
    {
        InsertAtFirst(Head, Tail, iNo);
        return FALSE;
    }

    // traverse until one node before iPos
    for (int i = 1; i < iPos - 1; i++)
    {
        if (temp->next == *Head)    // to handel if ipos > node in linkedlist
        {
            iFlag = TRUE;
            break;
        }
        temp = temp->next;
    }

    // Insert at last place
    if(temp->next == *Head)        
    {
        InsertAtLast(Head, Tail, iNo);
        return TRUE;
    }

    // Insert at pos
    target = temp->next;
    temp->next = newN;
    newN->next = target;

    return iFlag;   // to indicate if ipos >= last node in linkedlist
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     DeleteAtFirst
//  Input :             struct node **, struct node **
//  Output :            void
//  Description :       Delete a first node of linked list
//  TimeComplexity :    O(1)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        If Head & Tail is NULL (empty linked list) simply return.
        If only one node : intilize head & tail to NULL.
        Else more than one node : @head insert address of 2nd node,
        @last node next insert address of 2nd node.
    STOP
*/
void DeleteAtFirst(PPNODE Head, PPNODE Tail) 
{
    PNODE target = *Head; // to free the memory

    if (*Head == NULL && *Tail == NULL) // If LinkedList is empty
    {
        return;
    }

    if(*Head == target->next)  // contains only one node
    {
        *Head = NULL;
        *Tail = NULL;
        free(target);
    }
    else // LinkedList contains more than one node
    {
        *Head = target->next; 
        (*Tail)->next = *Head;
        free(target);
    }
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     DeleteAtLast
//  Input :             struct node **, struct node **
//  Output :            void
//  Description :       Delete the last node of linked list
//  TimeComplexity :    O(n)   ( n = number of nodes )
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        If Head is NULL (empty linked list) simply return
        Else Traverse until reach to second last element.
        Free Space of secondlast->next and intilize to head.
        @Tail insert the address of second last node
    STOP
*/
void DeleteAtLast(
                        PPNODE Head,    // Gives the address of first node of linkedList. 
                        PPNODE Tail     // Gives the address of last node of linkedList.
                    )
{
    PNODE target = *Head; // for traversal
    PNODE temp = NULL;  // to free memory

    if (*Head == NULL && *Tail == NULL) // If LinkedList is empty
    {
        return;
    }

    if ((*Head)->next == *Head) // If LinkedList Contains only one node
    {
        DeleteAtFirst(Head, Tail);
        return;
    }

    // If LinkedList Contains more than one node
    while (target->next->next != *Head) // traverse until one node before last node
    {
        target = target->next;
    }

    if (target->next == *Head) // If LinkedList Contains only one node
    {
        DeleteAtFirst(Head, Tail);
        return;
    }

    temp = target->next;
    target->next = *Head;
    *Tail = target;
    free(temp);
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     DeleteAtPos
//  Input :             struct node **, struct node **, intiger
//  Output :            void
//  Description :       Delete the node from a given position
//  TimeComplexity :    O(n)   ( n = iPos )
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        If Head & Tail is NULL (empty linked list) & pos is 1  simply delete at first.
        Else Traverse until reach to privious node of given position.
        If stop at last then delete at last.
        Insert the address of after pos node in privious pos next
    STOP
*/
BOOL DeleteAtPos(       
                        PPNODE Head,    // Gives the address of first node of linkedList.        
                        PPNODE Tail,    // Gives the address of last node of linkedList.
                        int iPos        // The position from which node will be deleted
                    )
{
    BOOL iFlag = FALSE; // to handel the condition if iPos > no. nodes in linked list
    PNODE temp = *Head;    // for traverse
    PNODE tempSwap = NULL; // for swapping address

    if (*Head == NULL && *Tail == NULL) // If LinkedList is empty
    {
        return TRUE;
    }

    if (iPos == 1) // If Position is 1
    {
        DeleteAtFirst(Head, Tail);
    }
    else
    {
        // Traverse one node before iPos
        for (int i = 1; i < iPos - 1; i++)
        {

            if (temp->next == *Head) // to handel the condition if iPos > no. nodes in linked list
            {
                iFlag = TRUE;       // @ iPos node not exists
                break;
            }
            temp = temp->next;
        }

        if (iFlag) return TRUE;     // iPos > nodes in linked list

        else if (temp->next->next == *Head)   // @ iPos node not exists
        {
            DeleteAtLast(Head, Tail);
            return iFlag;
        }
        else    // @ iPos node exists
        {
            tempSwap = temp->next;
            temp->next = temp->next->next;
            free(tempSwap);
            return iFlag;
        }

    }

    return iFlag;       //// @ iPos node exists or not
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Display
//  Input :             struct node *, struct node *
//  Output :            void
//  Description :       Display the data of linkedlist
//  TimeComplexity :    O(n)   ( n = number of nodes )
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Traverse until last node
        While traversing print the data of every node
    STOP
*/
void Display(
                    PNODE Head, // Gives the address of first node of linkedList.
                    PNODE Tail  // Gives the address of last node of linkedList.
                )
{
    if(Head == NULL && Tail == NULL)
    {
        printf("\nNULL\n");
        return;
    }
    do
    {
        printf("%d  -> ", Head->data);
        Head = Head->next;

    }while (Head != Tail->next);

}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Count
//  Input :             struct node *, struct node *
//  Output :            void
//  Description :       Return the count of nodes.
//  TimeComplexity :    O(n)   ( n = number of nodes )
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Traverse until last node
        Increse counter while traversing every node
        Return counter value
    STOP
*/
int Count(
    PNODE Head, // Gives the address of first node of linkedList.
    PNODE Tail  // Gives the address of last node of linkedList.
)
{
    int iCnt = 0;

    do
    {
        iCnt++;
        Head = Head->next;

    } while (Head != Tail->next);

    return iCnt;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Search
//  Input :             struct node *, struct node *
//  Output :            void
//  Description :       Linearly search given data in LinkedList.
//  TimeComplexity :    O(n)   ( n = number of nodes )
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Traverse until last node
        If node found return true else false.
    STOP
*/
BOOL Search(
    PNODE Head,     // Gives the address of first node of linkedList.
    PNODE Tail,  // Gives the address of last node of linkedList.
    int iNo        // The number to be search.
)
{
    BOOL iFlag = FALSE;

    do
    {
        if(Head->data == iNo)
        {
            iFlag = TRUE;
            break;
        }
        Head = Head->next;

    } while (Head != Tail->next);

    return iFlag;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     TakeElementAtPos
//  Input :             struct node *, Intiger
//  Output :            void
//  Description :       Take address in given position from given head.
//                      helper function for conquer function
//  TimeComplexity :    O(n)   ( n = iPos )
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Traverse Pointer until iPos
        return Pointer.
    STOP
*/
PNODE TakeElementAtPos(
    PNODE Head, // Gives the address of first node of linkedList.
    int iPos    // The position at which we will take our address
)
{
    for (int i = 0; i < iPos - 1; i++)
    {
        Head = (Head)->next;
    }

    return Head; // return the address of iPos node
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     conquer
//  Input :             struct node *, Intiger, intiger, intiger
//  Output :            void
//  Description :       MergeSort function :
//                      merge the divided solutions given by divide function
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Traverse Pointer until iPos
        return Pointer.
    STOP
*/
void conquer(
    PNODE Head, // Gives the address of first node of linkedList.
    int l,      // Left (Starting index)
    int r,      // Right (Ending index)
    int mid     // Middle Index
)
{

    PNODE idx1 = Head; //     int idx1 = l;
    PNODE idx2 = Head; //     int idx2 = mid+1;
    PNODE lside = Head;
    PNODE mergeList = NULL;
    PNODE mergeTail = NULL;

    int size = r - l + 1; // size of current linked list
    int x = 1;            // For traverse Duplicate LinkedList
    int lIndx = l;        // for traverse left part
    int rIndx = mid + 1;  // for traverse right part

    // idx1 = l
    idx1 = TakeElementAtPos(Head, l);

    // idx2 = mid+1
    idx2 = TakeElementAtPos(Head, mid + 1);

    // Compare and copy in new LinkedList
    while (lIndx <= mid && rIndx <= r)
    {
        if (idx1->data <= idx2->data)
        {
            InsertAtPos(&mergeList,&mergeTail, idx1->data, x);
            x++;
            idx1 = idx1->next;
            lIndx++;
        }
        else
        {
            InsertAtPos(&mergeList,&mergeTail, idx2->data, x);
            x++;
            idx2 = idx2->next;
            rIndx++;
        }
    }

    // If elements remain in left part
    while (lIndx <= mid)
    {
        InsertAtPos(&mergeList,&mergeTail, idx1->data, x);
        x++;
        idx1 = idx1->next;
        lIndx++;
    }

    // If elements remain in right part
    while (rIndx <= r)
    {
        InsertAtPos(&mergeList,&mergeTail, idx2->data, x);
        x++;
        idx2 = idx2->next;
        rIndx++;
    }

    // lside = l
    lside = TakeElementAtPos(Head, l);

    // Copy elements in duplicate elements
    for (int i = 0; i < size; i++)
    {
        lside->data = mergeList->data;
        lside = lside->next;
        mergeList = mergeList->next;
    }
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     divide
//  Input :             struct node *, Intiger, intiger
//  Output :            void
//  Description :       MergeSort function :
//                      Divide the linked list to smallest possible nodes
//                      to make problem small
//  TimeComplexity 
//  Mergesort :         O(n*log n)
//  Author :            Girish Ashok Pawar
//  Date :              08/06/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Find mid of current length of LinkedList
        Call divide for first half
        after base condition
        Call divide for last half
        after base condition
        Call Conquer for merge
        return Pointer.
    STOP
*/
void divide(PNODE Head, int l, int r)
{

    if (l >= r) // base condition
    {
        return;
    }

    int mid = 0;
    mid = l + (r - l) / 2;

    // divide for left part
    divide(Head, l, mid);

    // divide for right part
    divide(Head, mid + 1, r);

    // merge
    conquer(Head, l, r, mid);
}



// Entry point function
int main()
{
    // Local variables
    PNODE first = NULL, tail = NULL;
    int iChoice = 1, value = 0, iRet = 0, pos = 0;
    BOOL bAns = FALSE;

    printf("\nSingly Circular LinkedList\n");

    while (iChoice != 0)
    {
        printf("\n_________________________________________________\n");
        printf("Linked list operations : \n\n");
        printf("1 : Insert the node at first position\n");
        printf("2 : Insert the node at last position\n");
        printf("3 : Insert the node at  the desired position\n");
        printf("4 : Delete the first node\n");
        printf("5 : Delete the last node\n");
        printf("6 : Delete the node at desired position\n");
        printf("7 : Display the contents of linked list\n");
        printf("8 : Count the number of nodes from linked list\n");
        printf("9 : Search and check given element present or not \n");
         printf("10 : Sort LinkedList \n");
        printf("0 : Terminate the application\n");

        printf("\nSelect Option -> ");
        scanf("%d", &iChoice);

        printf("\n_________________________________________________\n");


        switch (iChoice)
        {
        case 1:
            printf("Enter the data to insert\n");
            scanf("%d", &value);
            InsertAtFirst(&first,&tail, value);
            printf("\nData inserted at first place..\n");
            break;

        case 2:
            printf("Enter the data to insert\n");
            scanf("%d", &value);
            InsertAtLast(&first,&tail, value);
            printf("\nData inserted at last place..\n");
            break;

        case 3:
            printf("Enter the data to insert\n");
            scanf("%d", &value);
            printf("Enter the position\n");
            scanf("%d", &pos);
            bAns = InsertAtPos(&first,&tail, value, pos);
            if(bAns == FALSE)
            {
               printf("\nData inserted at %d place..\n", pos);
            }
            else
            {   
                printf("\nData inserted at last place..! [ %d number of nodes are not present in linkedList ]\n", pos);   
            }
            break;

        case 4:
            DeleteAtFirst(&first, &tail);
            printf("\nFirst element is deleted..\n");
            break;

        case 5:
            DeleteAtLast(&first, &tail);
            printf("\nLast element is deleted..\n");
            break;

        case 6:
            printf("Enter the position\n");
            scanf("%d", &pos);
            bAns = DeleteAtPos(&first,&tail, pos);
            if(bAns == FALSE)
            {
                printf("\nData deleted from %d place..\n", pos);
            }
            else
            {
                printf("\nData can't be deleted ..! [ Data at pos %d not exists ]\n", pos);
            }
            
            break;

        case 7:
            printf("Elemenet of Linked list are\n\n");
            Display(first, tail);
            break;

        case 8:
            iRet = Count(first, tail);
            printf("\nNumber of elements are : %d\n", iRet);
            break;

        case 9:
            printf("Enter the data to search : \n");
            scanf("%d", &value);
            bAns = Search(first,tail, value);
            if(bAns == TRUE)
            {
                printf("Element is present in linked list.\n");
            }
            else
            {
                printf("Element is not present in linked list.\n");
            }
            break;

        case 10:
            iRet = Count(first, tail);
            divide(first, 1, iRet);
            printf("\nLinkedList Sorted !\n");
            break;

        case 0:
            printf("\nThankyou for using Giri Linked List...\n\n");
            break;

        default:
            printf("\nPlease enter proper choice\n");
            break;
        }
    }

    return 0;      // Return success to OS
}