#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int a)
    {
        data = a;
        next = nullptr;
    }
};

class linkedlist {
public:
    Node* head;
    linkedlist()
    {
        head = nullptr;
    }
    int count_Nodes()
    {
        if (head == nullptr)
            return 0;
        else if (head->next == head)
            return 1;
        else
        {
            int count = 0;

            Node* current = head;
            while (current->next != head)
            {
                count++;
                current = current->next;
            }
            return count + 1;
        }
    }
    Node* create_Node(int a)
    {
        Node* newNode = new Node(a);
        if (newNode == nullptr)
        {
            cout << "Node not created" << endl;
            return nullptr;
        }
        else
        {
            return newNode;
        }
    }

    void add_Node_start()
    {
        int a;
        cout << "Enter the value you want to store" << endl;
        cin >> a;
        Node* newNode = create_Node(a);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            newNode->next = head;
            head = newNode;
            current->next = head;
        }
    }

    void add_Node_end()
    {
        int a;
        cout << "Enter the value you want to store" << endl;
        cin >> a;
        Node* newNode = create_Node(a);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            newNode->next = head;
            last->next = newNode;
        }
    }

    void delete_Node_end()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        else if (head->next == nullptr)
        {
            delete head;
        }
        else
        {
            Node* last = head;
            Node* secondlast = head;
            while (last->next != head)
            {
                secondlast = last;
                last = last->next;
            }
            secondlast->next = head;
            delete last;
        }
    }

    void delete_Node_start()
    {

    }

    void add_Node_Random()
    {
        int data, position;
        cout << "Enter the position at which you want to enter the data" << endl;
        cin >> position;
        cout << "Enter the data you want to enter" << endl;
        cin >> data;
        Node* newNode = create_Node(data);
        int numNodes = count_Nodes();

        if (position < 1 || position >(numNodes + 1))
        {
            cout << "Invalid Position" << endl;
        }
        else if (position == 1)
        {
            add_Node_start();
        }
        else if (position == (numNodes + 1))
        {
            add_Node_end();
        }
        else
        {
            Node* previousposition = head;
            Node* nextposition = head;
            for (int i = 1; i < position; i++)
            {
                previousposition = nextposition;
                nextposition = nextposition->next;
            }

            previousposition->next = newNode;
            newNode->next = nextposition;
        }
    }

    void delete_Node_Random()
    {
        int position;
        cout << "Enter the position of the node you want to delete" << endl;
        cin >> position;
        int numNodes = count_Nodes();

        if (position < 1 || position > numNodes)
        {
            cout << "Invalid Position" << endl;
        }
        else if (position == 1)
        {
            delete_Node_start();
        }
        else if (position == numNodes)
        {
            delete_Node_end();
        }
        else
        {
            Node* previousposition = head;
            Node* nodeToDelete = head;

            for (int i = 1; i < position; i++)
            {
                previousposition = nodeToDelete;
                nodeToDelete = nodeToDelete->next;
            }

            previousposition->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }


    void displayList() {
        Node* current = head;
        while (current->next != head) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << current->data << " -> ";
        cout << "nullptr" << endl;
    }
};


int main()
{
    linkedlist myList;


    int choice = -1; // Initialize choice to a non-zero value

    while (choice != 0) {
        cout << "Linked List Menu:" << endl;
        cout << "1. Count Nodes" << endl;
        cout << "2. Add Node at start" << endl;
        cout << "3. Add Node at End" << endl;
        cout << "4. Add Node at Random Position" << endl;
        cout << "5. Delete Node at start" << endl;
        cout << "6. Delete Node at End" << endl;
        cout << "7. Delete Node at Random Position" << endl;
        cout << "8. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            cout << "Total Nodes: " << myList.count_Nodes() << endl;
        else if (choice == 2)
            myList.add_Node_start();
        else if (choice == 3)
            myList.add_Node_end();
        else if (choice == 4)
            myList.add_Node_Random();
        /*else if (choice == 5)
            myList.delete_Node_start();*/
        else if (choice == 6)
            myList.delete_Node_end();
        else if (choice == 7) 
            myList.delete_Node_Random();
        else if (choice == 8)
            myList.displayList();
        else if (choice == 0)
            cout << "Exiting..." << endl;
        else
            cout << "Invalid choice! Please try again." << endl;

    }

    // Free memory for all nodes before exiting
//    while (start != nullptr) {
//        Node* temp = start;
//        start = start->next;
//        delete temp;
//    }
    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "X The Code is Ended X" << endl;
    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
    return 0;
}