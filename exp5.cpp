// Construct an expression tree from the given
// prefix expression eg. +--a*bc/def and traverse
// it using postorder traversal (non recursive) and
// then delete the entire tree

#include<iostream>
#include<string.h>
using namespace std;

struct node {
    char data;
    node *left;
    node *right;
};

class tree {
    char prefix[50];

public:
    node *top;

    tree() {
        top = nullptr;
    }

    void expression(char[]);
    void display(node*);
    void deletion(node*);
};

class stack1 {
public:
    node* data[30];
    int top;

    stack1() {
        top = -1;
    }

    int empty() {
        return top == -1;
    }

    void push(node* p) {
        data[++top] = p;
    }

    node* pop() {
        return data[top--];
    }
};

void tree::expression(char prefix[]) {
    stack1 s;
    node *t1, *t2;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        top = new node;
        top->left = nullptr;
        top->right = nullptr;

        if (isalpha(prefix[i])) {
            top->data = prefix[i];
            s.push(top);
        } else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
            t2 = s.pop();
            t1 = s.pop();
            top->data = prefix[i];
            top->left = t2;
            top->right = t1;
            s.push(top);
        }
    }
    top = s.pop();
}

void tree::display(node* top) {
    if (top == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    stack1 s1, s2;
    node* T = top;
    s1.push(T);

    while (!s1.empty()) {
        T = s1.pop();
        s2.push(T);
        if (T->left != nullptr) s1.push(T->left);
        if (T->right != nullptr) s1.push(T->right);
    }

    while (!s2.empty()) {
        top = s2.pop();
        cout << top->data;
    }
    cout << endl;
}

void tree::deletion(node* node) {
    if (node == nullptr) return;
    deletion(node->left);
    deletion(node->right);
    cout << "Deleting node: " << node->data << endl;
    delete node;
}

int main() {
    tree t;
    char exp1[20];
    int ch;

    do {
        cout << "1 -> Enter prefix expression" << endl;
        cout << "2 -> Display postfix Expression" << endl;
        cout << "3 -> Deletion" << endl;
        cout << "4 -> Exit" << endl;
        cout << "Choose an option (1-4):\t";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter the expression (eg.: +--a*bc/def):\t";
            cin >> exp1;
            t.expression(exp1);
            break;
        case 2:
            t.display(t.top);
            break;
        case 3:
            t.deletion(t.top);
            t.top = nullptr;  // Ensure pointer is cleared
            break;
        case 4:
            cout << "\n// END OF CODE\n" << endl;
            break;
        default:
            cout << "Choose a valid option (1-4)." << endl;
            break;
        }
    } while (ch != 4);

    return 0;
}