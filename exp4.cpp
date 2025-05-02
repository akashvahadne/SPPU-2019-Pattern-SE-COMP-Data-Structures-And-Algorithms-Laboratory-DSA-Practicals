// Beginning with an empty binary search tree,
// Construct binary search tree by inserting the
// values in the order given. After constructing a
// binary tree - i. Insert new node ii. Find number
// of nodes in longest path from root iii. Minimum
// data value found in the tree iv. Change a tree so
// that the roles of the left and right pointers are
// swapped at every node v. Search a value.


#include <iostream>
using namespace std;

// BST node structure
struct Bstnode {
    int data;
    Bstnode *left;
    Bstnode *right;
    Bstnode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// BST class
class Btree {
public:
    Bstnode* root;

    Btree() : root(nullptr) {}

    // Insert a new node with given data into BST
    Bstnode* insert(Bstnode* node, int val) {
        if (node == nullptr) {
            return new Bstnode(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    // Fixed: Search a value using full traversal (works after mirror too)
    bool searchNode(Bstnode* node, int val) {
        if (node == nullptr) return false;
        if (node->data == val) return true;
        return searchNode(node->left, val) || searchNode(node->right, val);
    }

    bool search(int val) {
        return searchNode(root, val);
    }

    // Find minimum value in the BST
    int findMin(Bstnode* node) {
        if (node == nullptr) {
            throw runtime_error("Tree is empty.");
        }
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    int findMin() {
        return findMin(root);
    }

    // Find height of the tree = number of nodes in longest path from root
    int height(Bstnode* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int height() {
        return height(root);
    }

    // Mirror the tree by swapping left and right pointers at every node
    void mirror(Bstnode* node) {
        if (node == nullptr) return;
        // swap left and right
        Bstnode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        // recurse for children
        mirror(node->left);
        mirror(node->right);
    }

    void mirror() {
        mirror(root);
    }

    // Inorder traversal to display tree data
    void inorder(Bstnode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    Btree tree;
    int n;
    cout << "Enter number of initial elements in BST: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    int choice;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert new node\n";
        cout << "2. Find number of nodes in longest path from root (height)\n";
        cout << "3. Find minimum data value in the BST\n";
        cout << "4. Mirror the BST (swap left and right pointers at every node)\n";
        cout << "5. Search a value\n";
        cout << "6. Display BST inorder\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter value to insert: ";
                int val; cin >> val;
                tree.insert(val);
                cout << "Value inserted.\n";
                break;
            }
            case 2: {
                int h = tree.height();
                cout << "Number of nodes in longest path from root (height): " << h << endl;
                break;
            }
            case 3: {
                try {
                    int minVal = tree.findMin();
                    cout << "Minimum data value in BST: " << minVal << endl;
                } catch (exception& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                tree.mirror();
                cout << "BST mirrored successfully.\n";
                break;
            }
            case 5: {
                cout << "Enter value to search: ";
                int val; cin >> val;
                bool found = tree.search(val);
                if (found)
                    cout << "Value " << val << " found in BST.\n";
                else
                    cout << "Value " << val << " not found in BST.\n";
                break;
            }
            case 6: {
                cout << "BST inorder traversal: ";
                tree.displayInorder();
                break;
            }
            case 7: {
                cout << "Exiting program.\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    return 0;
}