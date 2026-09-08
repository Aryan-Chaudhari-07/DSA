#include <iostream>
using namespace std;

// Node of the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinaryTree
{
private:
    Node *root;

public:

    // Constructor
    BinaryTree()
    {
        root = NULL;
    }

    // Create the binary tree recursively
    Node* createTree()
    {
        int value;

        cout << "\nEnter node value (-1 for No Node): ";
        cin >> value;

        // -1 means there is no node
        if(value == -1)
            return NULL;

        Node *newNode = new Node;
        newNode->data = value;

        cout << "Enter Left Child of " << value;
        newNode->left = createTree();

        cout << "Enter Right Child of " << value;
        newNode->right = createTree();

        return newNode;
    }

    void buildTree()
    {
        cout << "\nCreate Binary Tree\n";
        root = createTree();
    }

    // Inorder: Left -> Root -> Right
    void inorder(Node *temp)
    {
        if(temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    // Preorder: Root -> Left -> Right
    void preorder(Node *temp)
    {
        if(temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Postorder: Left -> Right -> Root
    void postorder(Node *temp)
    {
        if(temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    // Added feature: count leaf nodes
    int countLeafNodes(Node *temp)
    {
        if(temp == NULL)
            return 0;

        // Leaf node has no children
        if(temp->left == NULL && temp->right == NULL)
            return 1;

        return countLeafNodes(temp->left) +
               countLeafNodes(temp->right);
    }

    void displayInorder()
    {
        cout << "\nInorder Traversal : ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder()
    {
        cout << "\nPreorder Traversal : ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder()
    {
        cout << "\nPostorder Traversal : ";
        postorder(root);
        cout << endl;
    }

    void displayLeafNodes()
    {
        cout << "\nNumber of Leaf Nodes : ";
        cout << countLeafNodes(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;
    int choice;

    do
    {
        cout << "\n================================";
        cout << "\n     BINARY TREE MENU";
        cout << "\n================================";
        cout << "\n1. Create Binary Tree";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Count Leaf Nodes";
        cout << "\n6. Exit";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                tree.buildTree();
                break;

            case 2:
                tree.displayInorder();
                break;

            case 3:
                tree.displayPreorder();
                break;

            case 4:
                tree.displayPostorder();
                break;

            case 5:
                tree.displayLeafNodes();
                break;

            case 6:
                cout << "\nProgram Ended Successfully.";
                break;

            default:
                cout << "\nInvalid Choice.";
        }

    } while(choice != 6);

    return 0;
}