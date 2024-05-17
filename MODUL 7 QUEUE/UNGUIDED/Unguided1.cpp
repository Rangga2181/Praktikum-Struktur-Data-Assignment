// Rangga Pradarrell Fathi
// 2311102200
#include <iostream>
using namespace std;

// Struktur Node untuk linked list
struct Node
{
    string data;
    Node *next;
};

Node *front = NULL; // Penanda antrian depan
Node *back = NULL;  // Penanda antrian belakang

bool isEmpty()
{
    return front == NULL;
}

void enqueueAntrian(string data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        string data = front->data;
        front = front->next;
        if (front == NULL)
        {
            back = NULL;
        }
        delete temp;
        cout << "Mengeluarkan data: " << data << endl;
    }
}

int countQueue()
{
    int count = 0;
    Node *temp = front;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue()
{
    Node *temp = front;
    while (temp != NULL)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
    front = back = NULL;
}

void viewQueue()
{
    cout << "Data antrian teller:" << endl;
    Node *temp = front;
    int i = 1;
    while (temp != NULL)
    {
        cout << i << ". " << temp->data << endl;
        temp = temp->next;
        i++;
    }
}

int main()
{
    enqueueAntrian("AJI");
    enqueueAntrian("MUNTUNG");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}