#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    // Recursive insertion
    void insert(int value)
    {
        root = insertNode(root, value);
    }

    Node* insertNode(Node *temp, int value)
    {
        if (temp == NULL)
        {
            Node *newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        if (value < temp->data)
            temp->left = insertNode(temp->left, value);
        else
            temp->right = insertNode(temp->right, value);

        return temp;
    }

    // Level-wise traversal
    void levelOrder()
    {
        if (root == NULL)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        cout << endl;
    }

    // Find height
    int height()
    {
                return findHeight(root);
    }

    int findHeight(Node *temp)
    {
        if (temp == NULL)
            return -1;

        int leftHeight = findHeight(temp->left);
        int rightHeight = findHeight(temp->right);

        return (1 + max(leftHeight, rightHeight));
    }

    // Print leaf nodes
    void printLeafNodes()
    {
        printLeaves(root);
        cout << endl;
    }

    void printLeaves(Node *temp)
    {
        if (temp == NULL)
            return;

        if (temp->left == NULL && temp->right == NULL)
        {
            cout << temp->data << " ";
            return;
        }

        printLeaves(temp->left);
        printLeaves(temp->right);
    }
};

int main()
{
    BST original, newTree;
    int choice,value;
do
    {
        cout << "\n===== Binary Tree Menu =====";
        cout << "\n1.Insert Node in Binary Search  Tree";
        cout << "\n2. Original BST (Level-wise)";
        cout << "\n3. Height of Original BST:";
        cout << "\n4. Leaf Nodes of Original BST";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter value to be inserted:   ";
            cin>>value;
            original.insert(value);
            break;

        case 2:
            original.levelOrder();
                break;
        case 3:
    cout << "Height of Original BST: "
         << original.height() << endl;
         break;
  case 4:
    cout << "Leaf Nodes of Original BST: ";
    original.printLeafNodes();
    break;
     case 5:
            cout << "Program Exited.";
            break;
  default:
            cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}