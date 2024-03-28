#include <iostream>
#include <string>
using namespace std;

// Node structure to store student data
struct Node
{
    string name;
    string nim;
    Node *next;
};

// Function prototypes
void menu();
void addFront(Node **head);
void addMiddle(Node *head);
void addEnd(Node **head);
void displayList(Node *head);
void deleteFront(Node **head);
void deleteMiddle(Node *head);
void deleteEnd(Node **head);

int main()
{
    Node *head = nullptr; // Initialize an empty list
    int choice;

    do
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addFront(&head);
            break;
        case 2:
            addEnd(&head);
            break;
        case 3:
            addMiddle(head);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            deleteFront(&head);
            break;
        case 6:
            deleteEnd(&head);
            break;
        case 7:
            deleteMiddle(head);
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 8);

    return 0;
}

// Display the menu
void menu()
{
    cout << "\nLINKED LIST NON-CIRCULAR\n";
    cout << "1. Add to Front\n";
    cout << "2. Add to End\n";
    cout << "3. Add to Middle\n";
    cout << "4. Display List\n";
    cout << "5. Delete from Front\n";
    cout << "6. Delete from End\n";
    cout << "7. Delete from Middle\n";
    cout << "8. Exit\n";
}

// Add a new node to the front of the list
void addFront(Node **head)
{
    Node *newNode = new Node;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newNode->name);
    cout << "Enter NIM: ";
    getline(cin, newNode->nim);
    newNode->next = *head;
    *head = newNode;
    cout << "Data added to the front." << endl;
}

// Add a new node to the end of the list
void addEnd(Node **head)
{
    Node *newNode = new Node;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newNode->name);
    cout << "Enter NIM: ";
    getline(cin, newNode->nim);
    newNode->next = nullptr;

    if (*head == nullptr)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data added to the end." << endl;
}

// Add a new node to the middle of the list
void addMiddle(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Adding to front." << endl;
        addFront(&head);
        return;
    }

    int pos;
    cout << "Enter the position to insert: ";
    cin >> pos;

    Node *newNode = new Node;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newNode->name);
    cout << "Enter NIM: ";
    getline(cin, newNode->nim);

    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        if (temp->next == nullptr)
        {
            cout << "Position out of range. Adding to the end." << endl;
            addEnd(&head);
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Data added to the middle." << endl;
}

// Display the linked list
void displayList(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    cout << "List: " << endl;
    while (temp != nullptr)
    {
        cout << "Name: " << temp->name << ", NIM: " << temp->nim << endl;
        temp = temp->next;
    }
}

// Delete the node at the front of the list
void deleteFront(Node **head)
{
    if (*head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    delete temp;
    cout << "Data deleted from the front." << endl;
}

// Delete the node at the end of the list
void deleteEnd(Node **head)
{
    if (*head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    if ((*head)->next == nullptr)
    {
        deleteFront(head);
        return;
    }

    Node *temp = *head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node *toDelete = temp->next;
    temp->next = nullptr;
    delete toDelete;
    cout << "Data deleted from the end." << endl;
}

// Delete a node from the middle of the list
void deleteMiddle(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;

    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        if (temp->next == nullptr)
        {
            cout << "Position out of range." << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        cout << "Position out of range." << endl;
        return;
    }

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    cout << "Data deleted from the middle." << endl;
}