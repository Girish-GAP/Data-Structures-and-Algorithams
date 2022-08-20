// Binary search tree

// Header file inclusion
#include <iostream>
using namespace std;

// structur node
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE, *PNODE;

class BST
{
private:
    PNODE root;
    int size;

public:
    BST();
    void Insert(int iNo);
    void InorderX(PNODE root);
    void Inorder();
    void PreorderX(PNODE root);
    void Preorder();
    void PostorderX(PNODE root);
    void Postorder();
    bool Search(int iNo);
    int Count();
    int CountParent();
    int CountLeaf();
};

BST ::BST()
{
    root = NULL;
    size = 0;
}

void BST ::Insert(int iNo)
{
    PNODE temp = root;

    // Memory allocation
    PNODE newN = new NODE();

    // Intilze node
    newN->data = iNo;
    newN->left = NULL;
    newN->right = NULL;

    // Insert node
    if (root == NULL)
    {
        root = newN;
        root->data = iNo;
    }
    else
    {
        while (1)
        {
            if (temp->data == iNo)
            {
                break;
            }

            if (iNo < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newN;
                    break;
                }
                temp = temp->left;
            }

            if (iNo > temp->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = newN;
                    break;
                }
                temp = temp->right;
            }
        }
    }
    size++;
}

bool BST ::Search(int iNo)
{
    bool bAns = false;

    if (root == NULL)
    {
        return false;
    }
    else
    {
        PNODE temp = root;

        while (temp != NULL)
        {
            if (temp->data == iNo)
            {
                bAns = true;
                break;
            }
            if (iNo < temp->data)
            {
                temp = temp->left;
            }
            else if(iNo > temp->data)
            {
                temp = temp->right;
            }
        }
    }
    return bAns;
}

void BST ::InorderX(PNODE Root)
{
    if (Root != NULL)
    {
        InorderX(Root->left);
        cout << Root->data << "  ";
        InorderX(Root->right);
    }
}

void BST ::Inorder() // to keep root private
{
    InorderX(root);
}

void BST ::PreorderX(PNODE Root)
{
    if (Root != NULL)
    {
        cout << Root->data << "  ";
        PreorderX(Root->left);
        PreorderX(Root->right);
    }
}

void BST ::Preorder() // to keep root private
{
    PreorderX(root);
}

void BST ::PostorderX(PNODE Root)
{
    if (Root != NULL)
    {
        PostorderX(Root->left);
        PostorderX(Root->right);
        cout << Root->data << "  ";
    }
}

void BST ::Postorder() // to keep root private
{
    PostorderX(root);
}

int BST :: Count()
{
    return size;
}


// Entry point function
int main()
{
    // Local variables
    int iChoice = 1, value = 0, iRet = 0;
    bool bRet = false;
    BST bobj;

    printf("\nBinary Search Tree\n");

    while (iChoice != 0)
    {
        printf("\n_________________________________________________\n");
        printf("BST operations : \n\n");
        printf("1 : Insert data\n");
        printf("2 : Search data\n");
        printf("3 : Count nodes\n");
        printf("4 : Inorder Display\n");
        printf("5 : Preorder Display\n");
        printf("6 : postoder Display\n");
        printf("0 : Terminate the application\n");
        printf("\nSelect Option -> ");
        scanf("%d", &iChoice);
        printf("\n_________________________________________________\n");

        switch (iChoice)
        {
        case 1:
            printf("Enter data : \n");
            scanf("%d", &value);
            bobj.Insert(value);
            printf("\nData Inserted into the tree\n");
            break;

        case 2:
            printf("Enter the data to search : \n");
            scanf("%d", &value);
            bRet = bobj.Search(value);
            if (bRet == true)
            {
                printf("Data is present in tree");
            }
            else
            {
                printf("Data is not present in tree");
            }
            break;
        case 3:
            iRet = bobj.Count();
            printf("Number of nodes are : %d", iRet);
            break;

        case 4:
            printf("Inorder : \n");
            bobj.Inorder();
            break;
        
        case 5:
            printf("Preorder : \n");
            bobj.Preorder();
            break;

        case 6:
            printf("Postorder : \n");
            bobj.Postorder();
            break;

        case 0:
            printf("\nThank you...\n\n");
            break;

        default:
            printf("\nPlease enter proper choice\n");
            break;
        }
    }

    return 0; // Return success to OS
}
