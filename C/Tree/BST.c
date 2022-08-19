////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                            //
//  Program Name : Binary search tree                                                         //
//                                                                                            //
//  Description :  This application implement the queue by using linkedlist.                  //
//  Author :       Girish Ashok Pawar                                                         //
//  Date :         19-08-2022                                                                 //
//                                                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////

// Inclusion of header file
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
//
//  Strcture name :     node
//  Data :              intiger, struct node *, stuct node * (Self referential pointer)
//  Description :       Represent the node of queue
//
//////////////////////////////////////////////////////////////////////////
typedef struct node
{
    int data;
    struct node *lChild;
    struct node *rChild;
} NODE, *PNODE, **PPNODE;

#define BOOL int
#define TRUE 1
#define FALSE 0

// Function delcaraitons / prototype
int Insert(PPNODE root, int iNo);
BOOL search(PNODE root, int iNo);
int Count(PNODE root);
int CountParent(PNODE root);
void Inorder(PNODE root);
void Preorder(PNODE root);
void Postorder(PNODE root);


///////////////////////////////////////////////////////////////////////////
//
//  Function name :     Insert
//  Input :             struct node *, Integer
//  Output :            void
//  Description :       Insert a new node into the BST
//  TimeComplexity :    O(n)
//  Author :            Girish Ashok Pawar
//  Date :              19/08/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Create a Memory block and store address of it in struct node pointer.
        Intilize the data of memory block
        If root is NULL (empty tree) simply insert newN in root
        Else insert newn in next of rear
             Traverse in sorted fashion 
             if(no > root) go right
             if(no < root) go left
             @leat insert new node and break unconditional loop
    STOP
*/
int Insert(PPNODE root, int iNo)
{
    PNODE temp = *root;
    int errorcode = 0;

    // Memory intilization
    PNODE newN = ((PNODE)malloc(sizeof(NODE)));

    // Node intilization
    newN->data = iNo;
    newN->lChild = NULL;
    newN->rChild = NULL;

    // Node insertion
    if (*root == NULL)
    {
        (*root) = newN;
    }
    else
    {
        while (1) // Unconditional loop
        {
            if (temp->data == iNo)
            {
                errorcode = -1;
                break;
            }

            if (temp->data > iNo)
            {

                if (temp->lChild == NULL)
                {
                    temp->lChild = newN;
                    break;
                }
                temp = temp->lChild;
            }

            else if (temp->data < iNo)
            {

                if (temp->rChild == NULL)
                {
                    temp->rChild = newN;
                    break;
                }
                temp = temp->rChild;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     search
//  Input :             struct node *, Integer
//  Output :            void
//  Description :       Search node in bst
//  TimeComplexity :    O(n)
//  Author :            Girish Ashok Pawar
//  Date :              19/08/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        If root is NULL (empty tree) simply return false
        Else travere tree until leaf nodes
             if root data == serach data return true
             if(no > root) search in right
             if(no < root) search in left
    STOP
*/
BOOL search(PNODE root, int iNo)
{
    BOOL bAns = FALSE;

    if (root == NULL)
    {
        return bAns;
    }
    else
    {
        while (root != NULL)
        {
            if (iNo == root->data)
            {
                bAns = TRUE;
                break;
            }

            if (iNo < root->data)
            {
                root = root->lChild;
            }
            else if (iNo > root->data)
            {
                root = root->rChild;
            }
        }
    }
    return bAns;
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     Count
//  Input :             struct node *
//  Output :            void
//  Description :       Count total nodes of tree
//  TimeComplexity :    O(n)
//  Author :            Girish Ashok Pawar
//  Date :              19/08/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Intilially intilize static counter with 0
        explore all left and right childs by using recursion & increse the counter
        recursion will continue until base condition root become NULL
    STOP
*/
int Count(PNODE root)
{
    static int iCnt = 0;
    if (root != NULL)
    {
        iCnt++;
        Count(root->lChild);
        Count(root->rChild);
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     CountParent
//  Input :             struct node *
//  Output :            void
//  Description :       Count total noded of tree
//  TimeComplexity :    O(n)
//  Author :            Girish Ashok Pawar
//  Date :              19/08/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Intilially intilize static counter with 0
        explore all left and right childs by using recursion
        if the node found which left and right child are not null then increase the counter
        recursion will continue until base condition root become NULL
    STOP
*/
int CountParent(PNODE root)
{
    static int iCnt = 0;

    if (root != NULL)
    {
        if ((root->lChild != NULL) || (root->rChild != NULL))
        {
            iCnt++;
        }
        CountParent(root->lChild);
        CountParent(root->rChild);
    }

    return iCnt;
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     CountLeaf
//  Input :             struct node *
//  Output :            void
//  Description :       Count total leaf nodes
//  TimeComplexity :    O(n)
//  Author :            Girish Ashok Pawar
//  Date :              19/08/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Intilially intilize static counter with 0
        explore all left and right childs by using recursion
        if the node found which left and right child are null then increase the counter
        recursion will continue until base condition root become NULL
    STOP
*/
int CountLeaf(PNODE root)
{
    static int iCnt = 0;

    if (root != NULL)
    {
        if ((root->lChild == NULL) && (root->rChild == NULL))
        {
            iCnt++;
        }
        CountLeaf(root->lChild);
        CountLeaf(root->rChild);
    }

    return iCnt;
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     Inorder
//  Input :             struct node *
//  Output :            void
//  Description :       print tree data in inorder format
//  TimeComplexity :    O(n)
//  Author :            Girish Ashok Pawar
//  Date :              19/08/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Traverse the left subtree, i.e., call inorder (left-subtree)
        visit the root
        Traverse the right subtree, i.e. call inorder (right-subtree)
    STOP
*/
void Inorder(PNODE root)
{
    if (root != NULL)
    {
        Inorder(root->lChild);
        printf("%d\t", root->data);
        Inorder(root->rChild);
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     Preorder
//  Input :             struct node *
//  Output :            void
//  Description :       print tree data in Preorder format
//  TimeComplexity :    O(n)
//  Author :            Girish Ashok Pawar
//  Date :              19/08/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        visit the root
        Traverse the left subtree, i.e., call inorder (left-subtree)
        Traverse the right subtree, i.e. call inorder (right-subtree)
    STOP
*/
void Preorder(PNODE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        Preorder(root->lChild);
        Preorder(root->rChild);
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Function name :     Postorder
//  Input :             struct node *
//  Output :            void
//  Description :       print tree data in Postorder format
//  TimeComplexity :    O(n)
//  Author :            Girish Ashok Pawar
//  Date :              19/08/2022
//
//////////////////////////////////////////////////////////////////////////
/*
    Algorithm
    START
        Traverse the left subtree, i.e., call inorder (left-subtree)
        Traverse the right subtree, i.e. call inorder (right-subtree)
        visit the root
    STOP
*/
void Postorder(PNODE root)
{
    if (root != NULL)
    {
        Postorder(root->lChild);
        Postorder(root->rChild);
        printf("%d\t", root->data);
    }
}


// Entry point function
int main()
{
    // Local variables
    PNODE first = NULL;
    int iChoice = 1, value = 0, iRet = 0;
    BOOL bRet = FALSE;

    printf("\nBinary Search Tree\n");

    while (iChoice != 0)
    {
        printf("\n_________________________________________________\n");
        printf("BST operations : \n\n");
        printf("1 : Insert data\n");
        printf("2 : Search data\n");
        printf("3 : Count nodes\n");
        printf("4 : Count leaf\n");
        printf("5 : Count parents\n");
        printf("6 : Inorder Display\n");
        printf("7 : Preorder Display\n");
        printf("8 : postoder Display\n");
        printf("0 : Terminate the application\n");
        printf("\nSelect Option -> ");
        scanf("%d", &iChoice);
        printf("\n_________________________________________________\n");

        switch (iChoice)
        {
        case 1:
            printf("Enter the data to Enqueue into the Queue\n");
            scanf("%d", &value);
            Insert(&first, value);
            printf("\nData Inserted into the tree\n");
            break;

        case 2:
            printf("Enter the data to search : \n");
            scanf("%d", &value);
            bRet = search(first, value);
            if (iRet == TRUE)
            {
                printf("Data is present in tree");
            }
            else
            {
                printf("Data is not present in tree");
            }
            break;
        case 3:
            iRet = Count(first);
            printf("Number of nodes are : %d", iRet);
            break;

        case 4:
            iRet = CountParent(first);
            printf("Number of parents in tree are : %d", iRet);
            break;

        case 5:
            iRet = CountLeaf(first);
            printf("Number of leafs in tree are : %d", iRet);
            break;

        case 6:
            printf("Inorder : \n");
            Inorder(first);
            break;
        
        case 7:
            printf("Preorder : \n");
            Preorder(first);
            break;

        case 8:
            printf("Postorder : \n");
            Postorder(first);
            break;

        case 0:
            printf("\nThankyou...\n\n");
            break;

        default:
            printf("\nPlease enter proper choice\n");
            break;
        }
    }

    return 0; // Return success to OS
}