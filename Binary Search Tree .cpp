#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};
struct node *newNode(int item) {
  struct node *temp =new node;
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " -> ";
    inorder(root->right);
  }
}
void preorder(struct node *root) {
  if (root != NULL) {
    cout << root->key << " -> ";
    preorder(root->left);

    preorder(root->right);
  }
}
void postorder(struct node *root) {
  if (root != NULL) {
    postorder(root->left);

    postorder(root->right);

    cout << root->key << " -> ";

  }
}

struct node *insert(struct node *node, int key) {

  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      delete(root);
      return temp;
    }

    struct node *temp = minValueNode(root->right);

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

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
