# <h1 align="center">Laporan Praktikum Modul Linked List</h1>

<p align="center">Rangga Pradarrell Fathi</p>
<p align="center">2311102200 / IF-11-E</p>

## Dasar Teori
Linked list adalah struktur data dinamis yang terdiri dari serangkaian node, masing-masing berisi bidang data dan referensi (atau tautan) ke node berikutnya dalam urutan tersebut.[1]

Berikut adalah penjelasan singkat tentang Linked list dalam C++:
####  Single Linked List
"Single Linked List adalah daftar tertaut yang setiap simpulnya berisi satu bidang tautan yang menunjuk ke simpul berikutnya dalam daftar tertaut." [2] Dalam single linked list, setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya dalam daftar. Dengan kata lain, setiap node hanya menyimpan data dan alamat dari node berikutnya.

#### Double linked List
"Double linked list adalah daftar tertaut di mana setiap node berisi dua bidang tautan, satu menunjuk ke node berikutnya dan satu lagi menunjuk ke node sebelumnya." [2] Dalam double linked list, setiap node memiliki dua pointer: satu pointer menunjuk ke node berikutnya, dan satu pointer lagi menunjuk ke node sebelumnya. Dengan demikian, setiap node menyimpan data, alamat node berikutnya, dan alamat node sebelumnya. 
 

## Guided 

### 1. [Latihan Single Linked List]
```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}

```
#### Output:
![Guided 1 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/9105e70c-bb2c-4f06-b29a-3fa50a6afd4c)
![Guided 1 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/6ab18de8-fe46-42ee-82b7-265326923514)

Kode di atas,merupakan program yang memberikan contoh implementasi dasar dari operasi-operasi utama pada Single Linked List Non-Circular, seperti menambahkan node, menghapus node, mengubah data node, dan menampilkan data dalam Linked List.



### 2. [Program Double Linked List ]
```C++
#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Output:
![Guided 2 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/8da875ac-b920-40a4-b51c-dda2b68f8783)
![Guided 2 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/2fb212f9-ec98-46ad-ba5e-b50f1b0df01d)

Secara keseluruhan, program ini merupakan implementasi sederhana dari struktur data Double Linked List dalam C++ dengan berbagai operasi dasar seperti menambah, menghapus, mengubah, dan menampilkan data. Program ini juga menyediakan antarmuka teks sederhana untuk berinteraksi dengan Double Linked List.

## Unguided 

### 1. Soal mengenai Single Linked List

```C++
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    vector<int> data(n);
    vector<int> genap, ganjil;

    cout << "Masukkan elemennya: ";
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (data[i] % 2 == 0)
        {
            genap.push_back(data[i]);
        }
        else
        {
            ganjil.push_back(data[i]);
        }
    }

    cout << "Data Array      : ";
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Nomor Genap     : ";
    for (int i = 0; i < genap.size(); i++)
    {
        cout << genap[i] << " ";
    }
    cout << endl;

    cout << "Nomor Ganjil    : ";
    for (int i = 0; i < ganjil.size(); i++)
    {
        cout << ganjil[i] << " ";
    }
    cout << endl;

    return 0;
}
```
#### Output:
![Unguided 1 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/79c750ab-cad2-4889-9dbd-96f7fd5728a3)

#### Full code Screenshot:
![Unguided 1 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/f529373f-222a-498e-9882-c953c3008716)

Program ini adalah fungsi untuk memisahkan elemen-elemen dari sebuah array menjadi dua array terpisah, yaitu array untuk elemen-elemen genap dan array untuk elemen-elemen ganjil. 

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>

using namespace std;

int main()
{
    int x, y, z;

    // Meminta pengguna memasukkan ukuran array tiga dimensi
    cout << "Masukkan ukuran array tiga dimensi (x y z): ";
    cin >> x >> y >> z;

    // Menginisialisasi array tiga dimensi dengan ukuran yang dimasukkan oleh pengguna
    int arr[x][y][z];

    // Meminta pengguna memasukkan nilai-nilai elemen array
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            for (int k = 0; k < z; ++k)
            {
                cout << "arr[" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    // Menampilkan array tiga dimensi yang telah dimasukkan oleh pengguna
    cout << "Array tiga dimensi yang dimasukkan:\n";
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            for (int k = 0; k < z; ++k)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl; // Setiap baris baru untuk setiap dimensi y
        }
        cout << endl; // Setiap lapisan baru untuk setiap dimensi x
    }

    return 0;
}

```

#### Output:
![Unguided 2 (1) Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/13df568d-4ae6-4fcb-bd87-6fd67caca36a)

#### Full code Screenshot:
![Unguided 2 (1) Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/6ed3a8ad-7b53-48ff-95ee-30e5e3f22ef3)


### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> n;

    // Menginisialisasi array dengan ukuran n
    int arr[n];

    // Meminta pengguna memasukkan elemen array
    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Menghitung nilai maksimum, minimum, dan rata-rata
    int max = arr[0];
    int min = arr[0];
    int sum = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
        sum += arr[i];
    }

    double average = static_cast<double>(sum) / n;

    // Menampilkan hasil
    cout << "Nilai maksimum: " << max << endl;
    cout << "Nilai minimum: " << min << endl;
    cout << "Nilai rata-rata: " << average << endl;

    return 0;
}


```

#### Output:
![Unguided 3 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/4698b5a4-7168-4367-8744-cfbf2abed996)

#### Full code Screenshot:
![Unguided 3 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/af6c21b3-16f6-4168-9ea2-93cda489b728)

Program ini adalah sebuah program C++ yang berfungsi untuk menghitung nilai maksimum, nilai minimum, dan rata-rata dari elemen-elemen dalam sebuah array. 

## Kesimpulan
Dalam pemrograman C++, array merupakan struktur data yang sangat penting dan sering digunakan untuk menyimpan sekumpulan data dengan tipe data yang sama.
Dari materi array ini, Array sangat berguna dalam berbagai aplikasi seperti penyimpanan data, pengolahan data, dan algoritma. Pemahaman yang baik tentang array akan membantu Anda dalam menulis program yang lebih efisien dan mudah dikelola.

## Referensi
####  Pratama, M. A. (2020, March 29). STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++. 
####  "The C++ Programming Language" oleh Bjarne Stroustrup (pencipta C++).
####  Wahyuni, Z. (2023, February 27). Makalah Dasar-dasar pemograman Komputer.
