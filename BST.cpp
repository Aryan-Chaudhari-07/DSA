// Binary Search Tree operations in C++

#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}
void preorder(struct node *root) {
  if (root != NULL) {
            // Traverse root
    cout << root->key << " -> ";
    // Traverse left
    preorder(root->left);

    // Traverse right
    preorder(root->right);
  }
}
void postorder(struct node *root) {
  if (root != NULL) {
    // Traverse lefta
    postorder(root->left);


    // Traverse right
    postorder(root->right);
     // Traverse root
    cout << root->key << " -> ";

  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;
  int choice,value;

    do
    {
        cout << "\n===== Binary Tree Menu =====";
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Postorder Traversal";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value (-1 for NULL): ";
            cin >> value;
             root = insert(root, value);
            break;

        case 2:
            cout << "Enter value (-1 for NULL): ";
            cin >> value;
            root = deleteNode(root, value);
              break;
        case 3:
             cout << "Inorder traversal: ";
             inorder(root);
              break;
        case 4:
             cout << "preorder traversal: ";
             preorder(root);
              break;
         case 5:
             cout << "postorder traversal: ";
             postorder(root);
              break;
        case 6:
            cout << "Program Exited.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 6);
    return 0;
}
