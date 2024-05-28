#include <iostream>
#include <string>
using namespace std;

// Struktur Node
struct Node
{
    char data;
    Node *left;
    Node *right;
};

// Fungsi untuk membuat Node baru
Node *newNode(char data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

// Fungsi untuk memasukkan data ke dalam tree
Node *insertNode(Node *root, char data)
{
    if (root == nullptr)
    {
        return newNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Fungsi untuk menampilkan child dari suatu node
void displayChildren(Node *root, char data)
{
    if (root == nullptr)
    {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    if (root->data == data)
    {
        cout << "Children dari node " << data << ":" << endl;
        if (root->left != nullptr)
        {
            cout << "Child Kiri: " << root->left->data << endl;
        }
        else
        {
            cout << "Child Kiri: Tidak ada" << endl;
        }
        if (root->right != nullptr)
        {
            cout << "Child Kanan: " << root->right->data << endl;
        }
        else
        {
            cout << "Child Kanan: Tidak ada" << endl;
        }
    }
    else
    {
        displayChildren(root->left, data);
        displayChildren(root->right, data);
    }
}

// Fungsi untuk menampilkan descendant dari suatu node
void displayDescendants(Node *root, char data)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->data == data)
    {
        cout << "Descendants dari node " << data << ":" << endl;
        if (root->left != nullptr)
        {
            cout << root->left->data << " ";
            displayDescendants(root->left, data);
        }
        if (root->right != nullptr)
        {
            cout << root->right->data << " ";
            displayDescendants(root->right, data);
        }
        cout << endl;
    }
    else
    {
        displayDescendants(root->left, data);
        displayDescendants(root->right, data);
    }
}

int main()
{
    Node *root = nullptr;
    int rangga_2311102200;
    char data;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Masukkan data ke dalam tree" << endl;
        cout << "2. Tampilkan children dari suatu node" << endl;
        cout << "3. Tampilkan descendants dari suatu node" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> rangga_2311102200;

        switch (rangga_2311102200)
        {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            root = insertNode(root, data);
            break;
        case 2:
            cout << "Masukkan node yang ingin ditampilkan childrennya: ";
            cin >> data;
            displayChildren(root, data);
            break;
        case 3:
            cout << "Masukkan node yang ingin ditampilkan descendantsnya: ";
            cin >> data;
            displayDescendants(root, data);
            break;
        case 4:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (rangga_2311102200 != 4);

    return 0;
}