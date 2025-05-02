// Consider a scenario for Hospital to cater services to different kinds of patients as Serious (top priority), b) non-serious (medium priority), c) General Checkup (Least priority). Implement the priority queue to cater services to the patients.

#include<iostream>
#include<string>
using namespace std;

// Node for the priority queue
class Node {
public:
    Node* next;
    int priority;
    string data;
    Node(string d, int prior) {
        priority = prior;
        data = d;
        next = NULL;
    }
};

class PriorityQueue {
public:
    Node* front = NULL;

    // Insert patient with correct priority order
    void insert(string d, int prior) {
        Node* temp = new Node(d, prior);

        // Insert at front if higher priority or list is empty
        if (front == NULL || prior > front->priority) {
            temp->next = front;
            front = temp;
        } else {
            Node* curr = front;
            while (curr->next != NULL && curr->next->priority >= prior) {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    // Get name of first patient
    void peek() {
        if (front != NULL)
            cout << "First patient is:\t" << front->data << endl;
        else
            cout << "Queue is empty.\n";
    }

    // Remove first patient
    void pop() {
        if (front == NULL) {
            cout << "No patients to remove.\n";
            return;
        }
        cout << "Removed patient: " << front->data << endl;
        front = front->next;
    }

    // Display all patients with priority
    void dis() {
        if (front == NULL) {
            cout << "\nEmpty queue.\n";
            return;
        }

        Node* curr = front;
        cout << "\nCurrent patients:\n";
        while (curr != NULL) {
            string currPrior = "";
            if (curr->priority == 3)
                currPrior = "Serious patient";
            else if (curr->priority == 2)
                currPrior = "Not serious patient";
            else
                currPrior = "General checkup";

            cout << curr->data << " with priority:\t" << currPrior << endl;
            curr = curr->next;
        }
    }
};

int main() {
    string name;
    int priority, ch;

    PriorityQueue q;

    do {
        cout << "\n--- MAIN MENU ---";
        cout << "\n1 -> Add patient";
        cout << "\n2 -> Remove patient";
        cout << "\n3 -> Get all patients";
        cout << "\n0 -> Exit";
        cout << "\nChoose an option (0-3):\t";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Patient name is:\t";
            cin.ignore();
            getline(cin, name, '\n');
            cout << "Enter priority (3-High, 2-Medium, 1-General):\t";
            cin >> priority;
            q.insert(name, priority);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            q.dis();
            break;
        case 0:
            cout << "\n// END OF CODE\n\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (ch != 0);

    return 0;
}