// Rangga Pradarrell Fathi
// 2311102200
#include <iostream>
using namespace std;

// Struktur Mahasiswa
struct Mahasiswa
{
    string nama;
    int nim;
};

// Struktur Node untuk linked list
struct Node
{
    Mahasiswa data;
    Node *next;
};

Node *front = NULL; // Tanda antrian depan
Node *back = NULL;  // Tanda antrian belakang

bool isEmpty()
{
    return front == NULL;
}

void enqueueAntrian(string nama, int nim)
{
    Node *newNode = new Node;
    newNode->data.nama = nama;
    newNode->data.nim = nim;
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
        Mahasiswa data = front->data;
        front = front->next;
        if (front == NULL)
        {
            back = NULL;
        }
        delete temp;
        cout << "Mengeluarkan data: " << data.nama << " (" << data.nim << ")" << endl;
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
    cout << "Data antrian mahasiswa:" << endl;
    Node *temp = front;
    int i = 1;
    while (temp != NULL)
    {
        cout << i << ". " << temp->data.nama << " (" << temp->data.nim << ")" << endl;
        temp = temp->next;
        i++;
    }
}

int main()
{
    enqueueAntrian("Rangga", 200);
    enqueueAntrian("Irsyad", 199);
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