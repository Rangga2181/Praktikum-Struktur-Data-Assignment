# <h1 align="center">Laporan Praktikum Modul 7 - QUEUE</h1>
<p align="center">Rangga Pradarrell Fathi</p>
  <P align="center">2311102200</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### QUEUE

Queue atau antrian adalah struktur data linier yang mengikuti prinsip First-In-First-Out (FIFO). Elemen baru ditambahkan di bagian belakang antrian (enqueue) dan elemen lama diambil dari bagian depan (dequeue). Queue sering digunakan dalam aplikasi seperti simulasi antrian, penjadwalan proses, dan manajemen buffer jaringan. Queue dapat diimplementasikan menggunakan array atau linked list. Contoh pada perpustakaan menyediakan kelas queue yang dapat digunakan secara langsung. 

### Operasi utama pada queue meliputi:

-Enqueue: Menambahkan elemen baru ke bagian belakang antrian. Operasi ini biasanya disebut juga "push" atau "insert".

-Dequeue: Menghapus elemen yang berada di bagian depan antrian. Operasi ini biasanya disebut juga "pop" atau "remove".

-Front: Mengakses atau melihat elemen yang berada di bagian depan antrian tanpa menghapusnya.

-Rear/Back: Mengakses atau melihat elemen yang berada di bagian belakang antrian.

-isEmpty: Memeriksa apakah queue dalam keadaan kosong atau tidak.

-isFull: Memeriksa apakah queue dalam keadaan penuh atau tidak (jika menggunakan implementasi array dengan ukuran tetap).

### Queue dapat diimplementasikan dengan beberapa cara, antara lain:

## Menggunakan Array:
 -Array statis: Queue diimplementasikan menggunakan array dengan ukuran tetap. Memiliki keterbatasan kapasitas dan dapat terjadi kondisi overflow jika antrian penuh.
 
 -Array dinamis (circular array): Untuk mengatasi keterbatasan array statis, digunakan circular array yang melakukan wrap-around saat mencapai ujung array.

## Menggunakan Linked List:
 Queue diimplementasikan dengan linked list, di mana setiap node menyimpan data dan pointer ke node berikutnya. Tidak memiliki batasan kapasitas seperti array statis dan dapat tumbuh secara dinamis.

## Beberapa operasi utama pada kelas Queue meliputi:
-push(const T& val): Menambahkan elemen baru ke bagian belakang antrian.

-pop(): Menghapus elemen dari bagian depan antrian.

-front(): Mengakses elemen di bagian depan antrian tanpa menghapusnya.

-back(): Mengakses elemen di bagian belakang antrian.

-empty(): Memeriksa apakah antrian kosong atau tidak.

-size(): Mendapatkan jumlah elemen dalam antrian.

### Implementasi Queue dengan prioritas dapat menggunakan struktur data seperti heap atau binary search tree. Queue memiliki berbagai aplikasi dalam pemrograman, seperti:

-Memodelkan antrian dalam sistem nyata (antrian di bank, kasir, printer, dll).

-Algoritma Breadth-First Search (BFS) pada graf.

-Manajemen buffer jaringan.

-Penjadwalan proses dalam sistem operasi.

-Pemrosesan batch dalam sistem komputer.

   
## Guided 

### Latihan

```C++
// Rangga Pradarrell Fathi
// 2311102200
#include <iostream>
using namespace std;
const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan
bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] <<

                endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
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
```

#### Output :
![Screenshot (180)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/cf7656b1-b60d-44ab-b3cd-779e9009c65b)

Program ini merupakan implementasi struktur data Queue (Antrian) menggunakan array statis. Program ini digunakan untuk mengelola antrian pada sebuah teller dengan kapasitas maksimal 5 orang.


## Unguided 


### 1) Ubahlah penerapan konsep queue pada bagian guided dari array menjadilinked list



```C++
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
```

#### Hasil Output
![Screenshot (166)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/66566ed4-7030-49d8-8cab-9948dff86d51)
![Screenshot (165)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/63302c04-5cbd-465c-9bdb-d11b784a82fc)

Dalam program ini menggunakan struktur data stack untuk memeriksa apakah sebuah kata atau kalimat merupakan palindrom atau bukan dengan cara membandingkan setengah huruf di awal dengan setengah huruf di akhir secara terbalik.


### ![Screenshot (163)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/935fe0f9-21b1-4a05-90ce-5d8f4003d053)


```C++
//Rangga Pradarrell Fathi
//2311102200
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseString(string str)
{
    stack<char> charStack;
    string reversed = "";

    // Mendorong setiap huruf ke dalam stack
    for (char c : str)
    {
        charStack.push(c);
    }

    // Mengeluarkan huruf dari stack untuk membentuk string terbalik
    while (!charStack.empty())
    {
        reversed += charStack.top();
        charStack.pop();
    }

    return reversed;
}

int main()
{
    string input;
    cout << "Masukkan Kata: ";
    getline(cin, input);

    string reversed = reverseString(input);
    cout << "Data: " << reversed << endl;

    return 0;
}
```

#### Hasil Output
![Screenshot (167)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/156ea1fb-2bf0-4edf-8fbc-d69dbaea59e9)

Program diatas ini menggunakan struktur data stack untuk membalik urutan karakter dalam sebuah string dengan cara mendorong setiap karakter kedalam stack, kemudian mengeluarkan karakter-karakter tersebut dari stack dalam urutan terbalik untuk membentuk string hasil pembalikan.


## Kesimpulan
Stack dapat diimplementasikan dalam C++ menggunakan array maupun linked list. Implementasi dengan array melibatkan penggunaan sebuah array untuk menyimpan elemen-elemen Stack dan variabel top untuk melacak indeks elemen teratas. Sementara implementasi dengan linked list melibatkan penggunaan struktur Node yang berisi data dan pointer ke node berikutnya, serta pointer top yang menunjuk ke node teratas.


Stack memiliki banyak aplikasi dalam pemrograman, seperti pembalik string atau angka, evaluasi ekspresi dengan notasi reverse polish, penerapan rekursi, dan algoritma traversal pada graph dan tree. Kompleksitas waktu rata-rata untuk operasi push dan pop pada Stack adalah O(1), yang membuatnya efisien untuk operasi penambahan dan penghapusan elemen.

## Referensi
[1] Reddy, P. K. (2019). Data Structures and Algorithms: Concepts, Techniques and Applications (1st ed.). Prentice Hall.

[2] Sahni, S. (2020). Data Structures, Algorithms, and Applications in C++ (2nd ed.). Universities Press.
