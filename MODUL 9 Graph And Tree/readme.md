 # <h1 align="center">Laporan Praktikum Modul 9 - Graph And Tree</h1>
<p align="center">Rangga Pradarrell Fathi</p>
<P align="center">2311102200</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori


### Graph
Graph adalah struktur data non-linear yang terdiri dari kumpulan node (vertex/simpul) yang dihubungkan oleh edge (sisi/busur). Graph dapat direpresentasikan dengan beberapa cara:

-Adjacency Matrix (Menggunakan matriks dua dimensi untuk menyimpan informasi keberadaan edge antara setiap pasangan node.)

-Adjacency List (Menggunakan daftar berkait (linked list) untuk menyimpan daftar node tetangga dari setiap node.)

Setelah merepresentasikan graph, kita dapat melakukan berbagai operasi dan algoritma pada graph, seperti:

Traversal Graph

-Breadth-First Search (BFS)
-Depth-First Search (DFS)


Algoritma pada Graph

-Shortest Path (Dijkstra, Bellman-Ford, Floyd-Warshall)
-Minimum Spanning Tree (Prim, Kruskal)
-Topological Sort
-Strongly Connected Components

###  Tree
Sequential search atau pencarian linear adalah algoritma pencarian paling sederhana. Prinsip kerjanya adalah memeriksa setiap elemen dalam struktur data (seperti array atau linked list) satu per satu secara berurutan hingga elemen yang dicari ditemukan atau seluruh elemen sudah diperiksa.


Langkah-langkah sequential search:

-Mulai dari elemen pertama dalam struktur data.

-Bandingkan elemen saat ini dengan elemen yang dicari.

-Jika elemen saat ini sama dengan elemen yang dicari, kembalikan indeks atau posisi elemen tersebut.

-Jika elemen saat ini tidak sama dengan elemen yang dicari, pindah ke elemen berikutnya dalam struktur data.

-Ulangi langkah 2-4 hingga elemen yang dicari ditemukan atau seluruh elemen sudah diperiksa.

-Jika elemen tidak ditemukan, kembalikan nilai yang menunjukkan bahwa elemen tidak ada dalam struktur data.


Kompleksitas waktu sequential search dalam kasus terburuk adalah O(n), di mana n adalah jumlah elemen dalam struktur data. Ini berarti dalam kasus terburuk, algoritma harus memeriksa setiap elemen dalam struktur data.


### Binary Search (Pencarian Biner)
Binary search hanya dapat diterapkan pada struktur data yang sudah terurut (sorted), seperti array atau linked list yang terurut. Prinsip kerjanya adalah membagi struktur data menjadi dua bagian dan mencari elemen yang dicari di dalam salah satu bagian tersebut. Proses ini diulangi secara rekursif hingga elemen ditemukan atau seluruh elemen sudah diperiksa.


Langkah-langkah binary search:

-Tentukan batas bawah (low) dan batas atas (high) dari struktur data yang akan diperiksa.

-Hitung nilai tengah (mid) dari batas bawah dan batas atas.

-Bandingkan elemen pada posisi tengah dengan elemen yang dicari.

-Jika elemen pada posisi tengah sama dengan elemen yang dicari, kembalikan posisi tengah.

-Jika elemen pada posisi tengah lebih kecil dari elemen yang dicari, ubah batas bawah menjadi posisi tengah + 1.

-Jika elemen pada posisi tengah lebih besar dari elemen yang dicari, ubah batas atas menjadi posisi tengah - 1.

-Ulangi langkah 2-6 hingga elemen yang dicari ditemukan atau batas bawah melebihi batas atas (elemen tidak ditemukan).

-Jika elemen tidak ditemukan, kembalikan nilai yang menunjukkan bahwa elemen tidak ada dalam struktur data.


Kompleksitas waktu binary search dalam kasus rata-rata dan terbaik adalah O(log n), di mana n adalah jumlah elemen dalam struktur data terurut. Ini jauh lebih efisien dibandingkan sequential search, terutama untuk struktur data besar.



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


### 1) Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!



```C++
// Rangga Pradarrell Fathi
// 2311102200
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int binarySearch(string kalimat, char huruf)
{
    sort(kalimat.begin(), kalimat.end()); // Mengurutkan kalimat terlebih dahulu

    int left = 0;
    int right = kalimat.length() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (kalimat[mid] == huruf)
        {
            return mid; // Jika huruf ditemukan, kembalikan indeksnya
        }
        else if (kalimat[mid] < huruf)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Jika huruf tidak ditemukan, kembalikan -1
}

int main()
{
    string kalimat;
    char huruf;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    int indeks = binarySearch(kalimat, huruf);

    if (indeks == -1)
    {
        cout << "Huruf " << huruf << " tidak ditemukan dalam kalimat." << endl;
    }
    else
    {
        cout << "Huruf " << huruf << " ditemukan pada indeks " << indeks << " dalam kalimat." << endl;
    }

    return 0;
}
```

#### Hasil Output
![Screenshot (190)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/9f362840-65f3-4edd-bd08-fa982dd1db20)

Dalam program ini, algoritma binary search digunakan karena kalimat diurutkan terlebih dahulu sebelum dilakukan pencarian. Ini membuat binary search menjadi pilihan yang efisien untuk mencari posisi sebuah karakter dalam kalimat.


### 2) Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
//Rangga Pradarrell Fathi
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int jumlahVokal = 0;
    char vokal[] = {'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};
    int ukuranVokal = sizeof(vokal) / sizeof(vokal[0]);

    // Menggunakan Sequential Search
    for (char huruf : kalimat)
    {
        for (int i = 0; i < ukuranVokal; i++)
        {
            if (huruf == vokal[i])
            {
                jumlahVokal++;
                break;
            }
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat: " << jumlahVokal << endl;

    return 0;
}
```


#### Hasil Output
![Screenshot (191)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/be064c13-f48f-4976-8ab7-8e9e82813198)

Dalam program ini, algoritma sequential search digunakan karena array vokal relatif kecil dan tidak terurut. Sequential search dapat diimplementasikan dengan mudah dan cukup efisien untuk kasus seperti ini. Namun, jika jumlah huruf vokal yang dicari lebih banyak atau pada kasus yang lebih kompleks, algoritma binary search atau struktur data lain seperti hash table mungkin lebih efisien.



### 3) Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!
```C++
//Rangga Pradarrell Fathi
//2311102200
#include <iostream>
using namespace std;

int main()
{
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]); // Ukuran array
    int target = 4;                         // Nilai yang dicari
    int jumlah = 0;                         // Inisialisasi jumlah kemunculan target

    // Sequential Search
    for (int i = 0; i < n; i++)
    {
        if (data[i] == target)
        {
            jumlah++;
        }
    }

    cout << "Jumlah angka " << target << " yang muncul adalah " << jumlah << endl;

    return 0;
}
```

#### Hasil Output





## Kesimpulan
Dari materi ini kita dapat mengetahui bahwa:
-Graph merupakan struktur data yang dapat merepresentasikan berbagai hubungan antar objek, seperti jaringan jalan raya yang dimodelkan dengan kota sebagai simpul dan jalan sebagai sisi yang memiliki bobot berupa panjang jalan.

-Tree adalah kumpulan node yang terhubung secara hierarkis, menyerupai struktur pohon. Tree merupakan cara merepresentasikan hubungan hirarkis (one-to-many) secara grafis.

Terdapat beberapa operasi yang dapat dilakukan pada tree, seperti pembuatan (create), pengambilan data (retrieve), dan traversal.
Graph memiliki beberapa jenis, seperti graph berarah (digraph), graph tak berarah (undigraph), dan graph berbobot. Graph dan tree merupakan struktur data fundamental yang memiliki kegunaan penting dalam berbagai aplikasi. Graph digunakan untuk merepresentasikan hubungan umum antar objek, sedangkan tree digunakan untuk merepresentasikan hierarki atau struktur berjenjang.

## Referensi
[1] Sindar, A, STRUKTUR DATA DAN ALGORITMADENGAN C++. Cetakan Pertama. Serang:CV.AA.RIZKY, 2018

[2] Bahit, M, ALGORITMA PEMROGRAMAN TERSTRUKTUR . Cetakan Pertama. Banjarmasin:Poliban Press,2024.
