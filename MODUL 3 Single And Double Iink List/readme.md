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
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
![Screenshot (48)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/63fe8797-1373-4826-bc3c-159946732ec8)



```C++
// RANGGA PRADARRELL FATHI
// 2311102200

#include <iostream>
#include <string>

using namespace std;

// Struktur Node
struct Node
{
    string nama;
    int usia;
    Node *next;
};

// Kelas Linked List
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Fungsi untuk menyisipkan data di akhir daftar
    void sisipkan(string nama, int usia)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Fungsi untuk menampilkan semua data dalam daftar
    void tampilkan()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void hapusNode(string nama)
    {
        if (head == nullptr)
        {
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

        // Jika node head sendiri menyimpan nama yang akan dihapus
        if (temp != nullptr && temp->nama == nama)
        {
            head = temp->next;
            delete temp;
            return;
        }

        // Mencari node yang akan dihapus
        while (temp != nullptr && temp->nama != nama)
        {
            prev = temp;
            temp = temp->next;
        }

        // Jika nama tidak ada dalam daftar
        if (temp == nullptr)
        {
            return;
        }

        // Memutuskan hubungan node dari linked list
        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk menyisipkan node setelah node tertentu
    void sisipkanSetelah(string namaSebelum, string nama, int usia)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;

        Node *temp = head;
        while (temp != nullptr && temp->nama != namaSebelum)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << namaSebelum << " tidak ditemukan dalam daftar." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Fungsi untuk menyisipkan node di awal daftar
    void sisipkanDiAwal(string nama, int usia)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;

        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk mengubah data berdasarkan nama
    void ubah(string nama, string namaBaru, int usiaBaru)
    {
        Node *temp = head;
        while (temp != nullptr && temp->nama != nama)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << nama << " tidak ditemukan dalam daftar." << endl;
            return;
        }

        temp->nama = namaBaru;
        temp->usia = usiaBaru;
    }
};

int main()
{
    LinkedList daftar;

    // Memasukkan data
    daftar.sisipkan("Rangga", 20);
    daftar.sisipkan("John", 19);
    daftar.sisipkan("Jane", 20);
    daftar.sisipkan("Michael", 18);
    daftar.sisipkan("Yusuke", 19);
    daftar.sisipkan("Akechi", 20);
    daftar.sisipkan("Hoshino", 18);
    daftar.sisipkan("Karin", 18);

    char pilihan;
    string nama, namaBaru;
    int usia, usiaBaru;

    do
    {
        cout << "Menu:" << endl;
        cout << "a. Tampilkan semua data" << endl;
        cout << "b. Hapus data Akechi" << endl;
        cout << "c. Tambahkan data di antara John dan Jane" << endl;
        cout << "d. Tambahkan data di awal" << endl;
        cout << "e. Ubah data Michael" << endl;
        cout << "f. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 'a':
            break;
        case 'b':
            daftar.hapusNode("Akechi");
            cout << "Data Akechi telah dihapus." << endl;
            break;
        case 'c':
            cout << "Masukkan nama dan usia yang ingin ditambahkan: ";
            cin >> nama >> usia;
            daftar.sisipkanSetelah("John", nama, usia);
            break;
        case 'd':
            cout << "Masukkan nama dan usia yang ingin ditambahkan di awal: ";
            cin >> nama >> usia;
            daftar.sisipkanDiAwal(nama, usia);
            break;
        case 'e':
            cout << "Masukkan nama dan usia baru untuk Michael: ";
            cin >> namaBaru >> usiaBaru;
            daftar.ubah("Michael", namaBaru, usiaBaru);
            break;
        case 'f':
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }

        // Menampilkan data setelah setiap operasi
        cout << "Data mahasiswa:" << endl;
        daftar.tampilkan();
        cout << endl;

    } while (pilihan != 'f');

    return 0;
}
```
#### Output:
![Screenshot (54)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/ff0a098a-070b-45e8-bdd4-1ecf7d335276)
![Screenshot (53)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/b2fe3c9a-5e84-4e34-8e9d-d385bda4ec2b)
![Screenshot (52)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/e1e54ab0-e6d6-49ae-bed4-f93353cff886)
![Screenshot (51)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/45d15794-cefa-4a33-9c6a-2b79fcb422f9)
![Screenshot (50)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/015b2f85-2ad0-4489-9064-b6bf663ed3c9)


#### Full code Screenshot:
![Unguided 1 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/02c60d4f-c84b-45c0-b3dc-b5c91e5c4310)

Program ini memberikan contoh implementasi dasar dari operasi-operasi pada Linked List, seperti menyisipkan node, menghapus node, mengubah data node, dan menampilkan data dalam daftar. Struktur data Linked List sangat berguna dalam berbagai aplikasi yang melibatkan pengolahan data dinamis dan fleksibel.


### 2.Soal mengenai Double Linked List
![Screenshot (47)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/fa9850d1-292b-4873-ba4c-b9c74906e000)

```C++
// RANGGA PRADARRELL FATHI
// 2311102200

#include <iostream>
using namespace std;

struct Node
{
    string namaProduk;
    double harga;
    Node *prev;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void tambahData(string nama, double harga)
    {
        Node *newNode = new Node;
        newNode->namaProduk = nama;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void hapusData(string nama)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->namaProduk == nama)
            {
                if (current == head && current == tail)
                {
                    head = tail = NULL;
                }
                else if (current == head)
                {
                    head = head->next;
                    head->prev = NULL;
                }
                else if (current == tail)
                {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void updateData(string nama, string newName, double newHarga)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->namaProduk == nama)
            {
                current->namaProduk = newName;
                current->harga = newHarga;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void tambahDataUrutanTertentu(string nama, double harga, string setelah)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->namaProduk == setelah)
            {
                Node *newNode = new Node;
                newNode->namaProduk = nama;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != NULL)
                {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Produk setelahnya tidak ditemukan!" << endl;
    }

    void hapusDataUrutanTertentu(string nama)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->namaProduk == nama)
            {
                if (current == head)
                {
                    head = head->next;
                    head->prev = NULL;
                }
                else if (current == tail)
                {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void hapusSeluruhData()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = NULL;
    }

    void tampilkanData()
    {
        Node *current = head;
        cout << "----------------------" << endl;
        cout << "Nama Produk  ||\t Harga " << endl;
        cout << "----------------------" << endl;
        while (current != NULL)
        {
            cout << current->namaProduk << " \t" << current->harga << endl;
            current = current->next;
        }
    }
};

int main()
{
    LinkedList daftarProduk;
    daftarProduk.tambahData("Originote", 60000);
    daftarProduk.tambahData("Somethinc", 150000);
    daftarProduk.tambahData("Skintific", 100000);
    daftarProduk.tambahData("Wardah   ", 50000);
    daftarProduk.tambahData("Hanasui  ", 30000);

    int pilihan;
    string nama, newName, setelah;
    double harga, newHarga;

    do
    {
        cout << "--------------------------------" << endl;
        cout << " || Toko Skincare Purwokerto || " << endl;
        cout << "--------------------------------" << endl;

        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Nama Produk: ";
            cin >> nama;
            cout << "Harga: ";
            cin >> harga;
            daftarProduk.tambahData(nama, harga);
            daftarProduk.tampilkanData();
            break;
        case 2:
            cout << "Nama Produk yang akan dihapus: ";
            cin >> nama;
            daftarProduk.hapusData(nama);
            daftarProduk.tampilkanData();
            break;
        case 3:
            cout << "Nama Produk yang akan diupdate: ";
            cin >> nama;
            cout << "Nama Baru: ";
            cin >> newName;
            cout << "Harga Baru: ";
            cin >> newHarga;
            daftarProduk.updateData(nama, newName, newHarga);
            daftarProduk.tampilkanData();
            break;
        case 4:
            cout << "Nama Produk: ";
            cin >> nama;
            cout << "Harga: ";
            cin >> harga;
            cout << "Setelah Produk: ";
            cin >> setelah;
            daftarProduk.tambahDataUrutanTertentu(nama, harga, setelah);
            daftarProduk.tampilkanData();
            break;
        case 5:
            cout << "Nama Produk yang akan dihapus: ";
            cin >> nama;
            daftarProduk.hapusDataUrutanTertentu(nama);
            daftarProduk.tampilkanData();
            break;
        case 6:
            daftarProduk.hapusSeluruhData();
            cout << "Seluruh data telah dihapus." << endl;
            break;
        case 7:
            daftarProduk.tampilkanData();
            break;
        case 8:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);

    return 0;
}
```

#### Output:

![Screenshot (58)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/d281171d-1883-4fbf-ac74-303e71bc52d9)
![Screenshot (57)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/051e9fdd-3488-44d5-b7c4-428008553bb2)
![Screenshot (56)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/0806f857-bfa5-461f-a072-24546533b062)

#### Full code Screenshot:
![Screenshot (55)1](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/85329a40-f4b9-405e-aa18-b949324faa30)

Program ini memberikan contoh implementasi struktur data Double Linked List dalam C++ untuk mengelola daftar produk pada sebuah toko skincare. Double Linked List memungkinkan operasi-operasi seperti menambah, menghapus, dan mengupdate data dilakukan dengan efisien karena setiap node memiliki pointer ke node sebelumnya dan node berikutnya.

## Kesimpulan
Dalam pemrograman C++, linked List adalah salah satu struktur data fundamental dalam pemrograman C++. Pemahaman konsep dan implementasi Linked List sangat penting untuk membangun dan mengoptimalkan berbagai jenis aplikasi yang melibatkan pengolahan data dinamis. [3]

Dari materi linked list, linked list sangat berguna dalam berbagai aplikasi seperti Penyisipan dan penghapusan node lebih efisien dibandingkan Array dan tidak perlu menyediakan ruang memori yang berlebihan seperti pada Array.

## Referensi
####  [2]Charles E. Leiserson, Ronald L. Rivest, dan Clifford Stein, MIT Press, 2009.
####  [1]	"Introduction to Algorithms, Third Edition" oleh Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, dan Clifford Stein, MIT Press, 2009.
####  [3]Wahyuni, Z. (2023, February 27). Makalah Dasar-dasar pemograman Komputer.
