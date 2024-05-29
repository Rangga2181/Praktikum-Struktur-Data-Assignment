 # <h1 align="center">Laporan Praktikum Modul 9 - Graph And Tree</h1>
<p align="center">Rangga Pradarrell Fathi</p>
<P align="center">2311102200</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori


### Graph
Graph adalah struktur data non-linear yang terdiri dari kumpulan node (vertex/simpul) yang dihubungkan oleh edge (sisi/busur).[1] Graph dapat direpresentasikan dengan beberapa cara:

-Adjacency Matrix (Menggunakan matriks dua dimensi untuk menyimpan informasi keberadaan edge antara setiap pasangan node.)

-Adjacency List (Menggunakan daftar berkait (linked list) untuk menyimpan daftar node tetangga dari setiap node.)


Setelah merepresentasikan graph, kita dapat melakukan berbagai operasi dan algoritma pada graph, seperti:

##### Traversal Graph

-Breadth-First Search (BFS)
-Depth-First Search (DFS)


##### Algoritma pada Graph

-Shortest Path (Dijkstra, Bellman-Ford, Floyd-Warshall)
-Minimum Spanning Tree (Prim, Kruskal)
-Topological Sort
-Strongly Connected Components

###  Tree
Tree adalah struktur data hierarkis yang merupakan jenis khusus dari graph yang tidak mengandung siklus (cycle). Setiap node dalam tree, kecuali root, memiliki tepat satu induk (parent).[1] Implementasi tree sering menggunakan pointer dan kelas/struct.


 jenis-jenis tree lain yang sering digunakan, seperti:

##### Binary Search Tree (BST)

Setiap node memiliki nilai yang lebih besar dari semua node di subtree kirinya, dan lebih kecil dari semua node di subtree kanannya.


##### AVL Tree dan Red-Black Tree

Jenis BST yang dioptimalkan untuk menjaga keseimbangan dan kinerja operasi pencarian, penyisipan, dan penghapusan.


##### Trie

Struktur data berbentuk seperti tree yang dioptimalkan untuk pencarian string.


Operasi umum pada tree meliputi traversal (preorder, inorder, postorder), pencarian, penyisipan, dan penghapusan node. Tree sering digunakan dalam implementasi struktur data seperti heap, BST, dan trie, serta dalam algoritma pemrosesan data dan pembuatan parse tree dalam kompilasi bahasa pemrograman.[2]



## Guided 

### Latihan 1

```C++
// Graph Code
/*
Rangga Pradarrell Fathi_2311102200
*/

#include <iostream>
#include <iomanip>

using namespace std;

const string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "Tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};

const int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setw(15) << left << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << setw(15) << left << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

#### Output :
![Screenshot (211)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/1162b408-7a7a-49fa-9f4e-9bd518456998)

Progam diatas akan menampilkan representasi graph yang terdiri dari 7 simpul (Ciamis, Bandung, Bekasi, Tasikmalaya, Cianjur, Purwokerto, Yogyakarta) dan sisi-sisi yang menghubungkan simpul tersebut beserta bobotnya. Sebagai contoh, output program akan menampilkan bahwa simpul Ciamis terhubung dengan simpul Bandung dengan bobot 7, dan terhubung dengan simpul Bekasi dengan bobot 8. Representasi graph menggunakan adjacency matrix seperti ini cocok digunakan untuk graph yang tidak terlalu besar, karena membutuhkan memori yang cukup besar untuk menyimpan matriks. Untuk graph yang lebih besar, biasanya digunakan representasi adjacency list yang lebih efisien dalam penggunaan memori.


### Latihan 2

```C++
// Tree Code
/*
Rangga Pradarrell Fathi - 2311102200
*/

#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main() {
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);

    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;

    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;

    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;

    characteristic();

    deleteSub(nodeE);

    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;

    characteristic();

    return 0;
}

```

#### Output :
![Screenshot (213)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/ad4b6fe3-15eb-4ecd-9ff8-5abf7085be3b)
![Screenshot (212)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/4b49dcae-88cf-4958-a2f5-f8d248d256cd)

program ini menunjukkan bagaimana mengimplementasikan struktur data Binary Tree dan berbagai operasi yang dapat dilakukan pada tree tersebut, seperti penciptaan, penyisipan, penghapusan, traversal, dan perhitungan karakteristik.



## Unguided 


### 1) Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.



```C++
//Rangga Pradarrell Fathi
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int maksimaldat = 10; // Maksimal banyak data yang dapat ditampung pada variabel maksimaldat untuk struct Graph

struct Graph
{
    string rangga_2311102200[maksimaldat];       // Banyaknya data string yang dapat disimpan dalam string sesuai dengan kapasitas maksimaldat
    int adjacencyMatrix[maksimaldat][maksimaldat]; // Menggunakan array 2 dimensi, dengan ukuran maksimal sesuai maksimaldat
    int no_kota;                               // Variabel yang digunakan untuk menyimpan jumlah kota dalam graph
};

void printMatrix(const Graph &graph)
{
    cout << setw(10) << " ";
    for (int i = 0; i < graph.no_kota; i++)
    {
        cout << setw(10) << graph.rangga_2311102200[i];
    }
    cout << endl;

    for (int i = 0; i < graph.no_kota; i++)
    {
        cout << setw(10) << graph.rangga_2311102200[i];
        for (int j = 0; j < graph.no_kota; j++)
        {
            cout << setw(10) << graph.adjacencyMatrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    Graph graph;
    cout << "\n---++ (Jarak Antar Kota) ++---" << endl;
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> graph.no_kota;
    cin.ignore(); // Mengabaikan karakter newline yang tersisa

    for (int i = 0; i < graph.no_kota; i++)
    {
        cout << "Simpul " << i + 1 << ": ";
        getline(cin, graph.rangga_2311102200[i]);
    }

    cout << "Silahkan masukan bobot antar simpul" << endl;
    for (int i = 0; i < graph.no_kota; i++)
    {
        for (int j = 0; j < graph.no_kota; j++)
        {
            cout << graph.rangga_2311102200[i] << " ---> " << graph.rangga_2311102200[j] << " = ";
            cin >> graph.adjacencyMatrix[i][j];
        }
    }

    cout << endl;
    printMatrix(graph);

    return 0;
}

```

#### Hasil Output
![Screenshot (214)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/95c0b0d7-a320-4abd-bc82-5158018e879f)
program diatas memungkinkan pengguna untuk mendefinisikan sebuah graph dengan memasukkan jumlah simpul, nama-nama simpul, dan bobot (jarak) antara setiap pasangan simpul. Kemudian, program akan mencetak representasi Adjacency Matrix dari graph tersebut dalam bentuk matriks.

### 2) Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
// Rangga Pradarrell Fathi
// 2311102200
#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nAlhamdulillah, Node " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nPliss! Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nUyy Node " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nMantapp!! Node " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nOyyy!! buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nUyy Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nAlhamdulillah!! Node " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nOyy!! buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nAlhamdulillah!! Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nOyy!! Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nOyy!! Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

void showChild(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nOyy!! Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nNode " << node->data << " Child: " << endl;
            if (node->left)
                cout << "Child Kiri : " << node->left->data << endl;
            else
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            if (node->right)
                cout << "Child Kanan : " << node->right->data << endl;
            else
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void showDescendants(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nOyy!! Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nDescendants of node " << node->data << " : ";
            preOrder(node);
            cout << endl;
        }
    }
}

// Penelusuran (Traversal)
// inOrder
void inOrder(Pohon *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
    }
}

// postOrder
void postOrder(Pohon *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (node != NULL)
    {
        if (node != root)
        {
            if (node->parent->left == node)
                node->parent->left = NULL;
            else if (node->parent->right == node)
                node->parent->right = NULL;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        if (node == root)
        {
            delete root;
            root = NULL;
        }
        else
        {
            delete node;
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nOyy!! Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nAlhamdulillah!! Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
    {
        cout << "\nOyy!! Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\nAlhamdulillah!! Pohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node)
{
    if (!node)
    {
        return 0;
    }
    else
    {
        return 1 + size(node->left) + size(node->right);
    }
}

// Cek Height Level Tree
int height(Pohon *node)
{
    if (!node)
    {
        return 0;
    }
    else
    {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        if (heightKiri >= heightKanan)
        {
            return heightKiri + 1;
        }
        else
        {
            return heightKanan + 1;
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main()
{
    int choice;
    char rangga_2311102200, parentData, direction;
    Pohon *parentNode, *tempNode;

    do
    {
        cout << "\n===---- Selamat Datang di Node Pohon ----===\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. Show Child\n";
        cout << "8. Show Descendants\n";
        cout << "9. PreOrder Traversal\n";
        cout << "10. InOrder Traversal\n";
        cout << "11. PostOrder Traversal\n";
        cout << "12. Show Characteristics\n";
        cout << "13. Clear Tree\n";
        cout << "14. Exit\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan data root: ";
            cin >> rangga_2311102200;
            buatNode(rangga_2311102200);
            break;
        case 2:
            cout << "Masukkan data parent: ";
            cin >> parentData;
            cout << "Masukkan data node kiri: ";
            cin >> rangga_2311102200;
            parentNode = root;
            while (parentNode && parentNode->data != parentData)
            {
                if (parentNode->left && parentNode->left->data == parentData)
                    parentNode = parentNode->left;
                else if (parentNode->right && parentNode->right->data == parentData)
                    parentNode = parentNode->right;
                else if (parentNode->left)
                    parentNode = parentNode->left;
                else if (parentNode->right)
                    parentNode = parentNode->right;
                else
                    parentNode = NULL;
            }
            if (parentNode)
            {
                insertLeft(rangga_2311102200, parentNode);
            }
            else
            {
                cout << "Parent tidak ditemukan!" << endl;
            }
            break;
        case 3:
            cout << "Masukkan data parent: ";
            cin >> parentData;
            cout << "Masukkan data node kanan: ";
            cin >> rangga_2311102200;
            parentNode = root;
            while (parentNode && parentNode->data != parentData)
            {
                if (parentNode->left && parentNode->left->data == parentData)
                    parentNode = parentNode->left;
                else if (parentNode->right && parentNode->right->data == parentData)
                    parentNode = parentNode->right;
                else if (parentNode->left)
                    parentNode = parentNode->left;
                else if (parentNode->right)
                    parentNode = parentNode->right;
                else
                    parentNode = NULL;
            }
            if (parentNode)
            {
                insertRight(rangga_2311102200, parentNode);
            }
            else
            {
                cout << "Parent tidak ditemukan!" << endl;
            }
            break;
        case 4:
            cout << "Masukkan data node yang ingin diupdate: ";
            cin >> parentData;
            cout << "Masukkan data baru: ";
            cin >> rangga_2311102200;
            tempNode = root;
            while (tempNode && tempNode->data != parentData)
            {
                if (tempNode->left && tempNode->left->data == parentData)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == parentData)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                update(rangga_2311102200, tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 5:
            cout << "Masukkan data node yang ingin diretrieve: ";
            cin >> rangga_2311102200;
            tempNode = root;
            while (tempNode && tempNode->data != rangga_2311102200)
            {
                if (tempNode->left && tempNode->left->data == rangga_2311102200)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == rangga_2311102200)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                retrieve(tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 6:
            cout << "Masukkan data node yang ingin dicari: ";
            cin >> rangga_2311102200;
            tempNode = root;
            while (tempNode && tempNode->data != rangga_2311102200)
            {
                if (tempNode->left && tempNode->left->data == rangga_2311102200)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == rangga_2311102200)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                find(tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 7:
            cout << "Masukkan data node yang ingin ditampilkan child-nya: ";
            cin >> rangga_2311102200;
            tempNode = root;
            while (tempNode && tempNode->data != rangga_2311102200)
            {
                if (tempNode->left && tempNode->left->data == rangga_2311102200)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == rangga_2311102200)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                showChild(tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 8:
            cout << "Masukkan data node yang ingin ditampilkan descendant-nya: ";
            cin >> rangga_2311102200;
            tempNode = root;
            while (tempNode && tempNode->data != rangga_2311102200)
            {
                if (tempNode->left && tempNode->left->data == rangga_2311102200)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == rangga_2311102200)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                showDescendants(tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 9:
            cout << "\nPreOrder :" << endl;
            preOrder(root);
            cout << "\n"
                 << endl;
            break;
        case 10:
            cout << "InOrder :" << endl;
            inOrder(root);
            cout << "\n"
                 << endl;
            break;
        case 11:
            cout << "PostOrder :" << endl;
            postOrder(root);
            cout << "\n"
                 << endl;
            break;
        case 12:
            characteristic();
            break;
        case 13:
            clear();
            break;
        case 14:
            cout << "Bye byee!!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 14);

    return 0;
}
```


#### Hasil Output
![Screenshot (228)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/f514f8aa-9889-4b82-9d73-88e0844ba4cb)
![Screenshot (227)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/9d03698a-60a2-4c99-a6a6-3e7e879ed1a5)
![Screenshot (226)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/b2f63e31-05f2-4191-aa03-ff9c5fdedaac)
![Screenshot (225)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/8c84e141-40b9-49c3-8d23-c0465644ba3f)
![Screenshot (224)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/435b676f-a7cb-459e-a50d-7637402463d0)
![Screenshot (223)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/14204c94-8ba3-4517-8be3-1e7a1458d20d)
![Screenshot (222)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/73a5673d-336d-4c2f-95cf-385720863f6f)
![Screenshot (221)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/37b80524-07e3-46b4-950f-ad84b9cce1a6)
![Screenshot (220)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/3dd5216a-e36b-4943-932f-8e709f24546e)
![Screenshot (219)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/d5edc5a5-9c53-41ff-b45c-439d1b88e919)
![Screenshot (218)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/5c0d5118-7093-4fbc-9eef-3886a69ad026)
![Screenshot (217)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/c913136f-0a8b-4dc3-8b22-c04964965252)
![Screenshot (216)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/c3e37971-049d-4171-8c89-08cbd669dd9b)
![Screenshot (215)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/52ffe6dc-2afd-41ad-aee9-7058cc1ccd60)

Program diatas menggunakan menu yang memungkinkan pengguna untuk melakukan berbagai operasi pada struktur data Binary Tree, seperti pembuatan node, penyisipan node baru, pengupdate-an node, pencarian node, traversal, penghapusan node atau subtree, dan menampilkan karakteristik tree. Program ini juga melakukan validasi input dan memberikan pesan error yang sesuai jika terjadi kesalahan atau kondisi tertentu tidak terpenuhi.


## Kesimpulan
Dari materi ini kita dapat mengetahui bahwa:
-Graph merupakan struktur data yang dapat merepresentasikan berbagai hubungan antar objek, seperti jaringan jalan raya yang dimodelkan dengan kota sebagai simpul dan jalan sebagai sisi yang memiliki bobot berupa panjang jalan.

-Tree adalah kumpulan node yang terhubung secara hierarkis, menyerupai struktur pohon. Tree merupakan cara merepresentasikan hubungan hirarkis (one-to-many) secara grafis.

Terdapat beberapa operasi yang dapat dilakukan pada tree, seperti pembuatan (create), pengambilan data (retrieve), dan traversal.
Graph memiliki beberapa jenis, seperti graph berarah (digraph), graph tak berarah (undigraph), dan graph berbobot. Graph dan tree merupakan struktur data fundamental yang memiliki kegunaan penting dalam berbagai aplikasi. Graph digunakan untuk merepresentasikan hubungan umum antar objek, sedangkan tree digunakan untuk merepresentasikan hierarki atau struktur berjenjang.

## Referensi
[1] Sindar, A, STRUKTUR DATA DAN ALGORITMADENGAN C++. Cetakan Pertama. Serang:CV.AA.RIZKY, 2019

[2] Bahit, M, ALGORITMA PEMROGRAMAN TERSTRUKTUR . Cetakan Pertama. Banjarmasin:Poliban Press,2024.
