# <h1 align="center">Laporan Praktikum Modul 5 - HASH TABLE</h1>
<p align="center">Rangga Pradarrell Fathi</p>
  <P align="center">2311102200</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### HASH TABLE

Hash Table adalah struktur data yang menggunakan fungsi hash untuk memetakan nilai kunci ke dalam indeks di dalam array. Ini memungkinkan pencarian, penyisipan, dan penghapusan elemen dalam waktu yang konstan rata-rata.

Hash table memiliki kelebihan yaitu "mampu menyediakan operasi pencarian, penyisipan, dan penghapusan dalam waktu yang konstan rata-rata, asalkan fungsi hash yang digunakan menyebar masukan secara merata".[1]

Selanjutnya, Hash table adalah struktur data yang efisien untuk menyimpan dan mengambil data dalam waktu yang konstan rata-rata, dan membuatnya menjadi pilihan yang sangat baik untuk banyak aplikasi praktis".[2]


### Implementasi Hash Table

-Dapat menggunakan library bawaan unordered_map dari C++.
-unordered_map menyediakan operasi-operasi hash table seperti penyisipan, pencarian, dan penghapusan elemen.

   
## Guided 

### 1.

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value),
                               next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value

                     << endl;

                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```

#### Output :
![Screenshot (110)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/11dd922a-65d8-4f10-bbf0-3305f7e180c9)



Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan modulus untuk memetakan setiap input kunci ke nilai indeks array.


### 2.

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
                                               phone_number));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it !=
                                                table[hash_val].end();
             it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```

#### Output :
![Screenshot (111)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/63ccedc5-ab4c-4154-87f4-90859333824a)

Dalam program di atas, kelas HashNode mewakili setiap node dalam tabel hash , termasuk nama karyawan dan nomor telepon. Kelas HashMap digunakan untuk mengimplementasikan struktur tabel hash  menggunakan vektor yang berisi pointer ke HashNodes. Fungsi hash digunakan untuk menghitung nilai hash dari nama karyawan yang diberikan dan fungsi penyisipan  digunakan untuk menambahkan data baru ke tabel hash. Fungsi remove digunakan untuk menghapus data dari tabel hash, dan fungsi searchByName digunakan untuk menemukan nomor telepon  karyawan bernama .




## Unguided 

### ![Screenshot (109)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/9278f928-d5ff-406d-b867-0db05741bbca)


```C++
//RANGGA PRADARRELL FATHI
//2311102200
#include <iostream>
#include <cstring>
using namespace std;

// Struktur untuk node linked list
struct Node
{
    string nama, nim;
    Node *next;
};

Node *head = NULL; // Pointer untuk head linked list

// Fungsi untuk menambahkan node baru di awal linked list
void tambahDepan()
{
    cout << "\n ||Tambah Depan||" << endl;
    cout << "" << endl;
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = head;
    head = newNode;
    cout << "" << endl;
    cout << "Data telah ditambahkan" << endl;
}

// Fungsi untuk menambahkan node baru di akhir linked list
void tambahBelakang()
{
    cout << "\n ||Tambah Belakang||" << endl;
    cout << "" << endl;
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "" << endl;
    cout << "Data telah ditambahkan" << endl;
}

// Fungsi untuk menambahkan node baru di tengah linked list
void tambahTengah()
{
    cout << "\n ||Tambah Tengah||" << endl;
    cout << "" << endl;
    string nama, nim;
    int posisi;
    cout << "Masukkan Nama: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    cout << "Masukkan Posisi: ";
    cin >> posisi;

    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->nim = nim;

    if (posisi == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout << "" << endl;
    cout << "Data telah ditambahkan" << endl;
}

// Fungsi untuk mengubah data node di awal linked list
void ubahDepan()
{
    cout << "\n ||Ubah Depan||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    string nama, nim;
    cout << "Masukkan nama baru: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM baru: ";
    getline(cin, nim);

    head->nama = nama;
    head->nim = nim;

    cout << "" << endl;
    cout << "Data " << nama << " telah diubah" << endl;
}

// Fungsi untuk mengubah data node di akhir linked list
void ubahBelakang()
{
    cout << "" << endl;
    cout << "\n ||Ubah Belakang||" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    string nama, nim;
    cout << "Masukkan nama baru: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM baru: ";
    getline(cin, nim);

    temp->nama = nama;
    temp->nim = nim;

    cout << "" << endl;
    cout << "Data " << nama << " telah diubah" << endl;
}

// Fungsi untuk mengubah data node di tengah linked list
void ubahTengah()
{
    cout << "\n ||Ubah Tengah||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    int posisi;
    cout << "Masukkan posisi: ";
    cin >> posisi;

    Node *temp = head;
    for (int i = 1; i < posisi; i++)
    {
        if (temp == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    string nama, nim;
    cout << "Masukkan nama baru: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM baru: ";
    getline(cin, nim);

    temp->nama = nama;
    temp->nim = nim;

    cout << "" << endl;
    cout << "Data " << nama << " telah diubah" << endl;
}

// Fungsi untuk menghapus node di awal linked list
void hapusDepan()
{
    cout << "\n ||Hapus Depan||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;

    cout << "" << endl;
    cout << "Data depan telah dihapus" << endl;
}

// Fungsi untuk menghapus node di akhir linked list
void hapusBelakang()
{
    cout << "\n ||Hapus Belakang||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        cout << "Data telah dihapus" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = NULL;
    delete deleteNode;

    cout << "" << endl;
    cout << "Data akhir telah dihapus" << endl;
}

// Fungsi untuk menghapus node di tengah linked list
void hapusTengah()
{
    cout << "\n ||Hapus Tengah||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    int posisi;
    cout << "Masukkan posisi: ";
    cin >> posisi;

    if (posisi == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Data telah dihapus" << endl;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < posisi - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;

    cout << "" << endl;
    cout << "Data ke-" << posisi << " telah dihapus" << endl;
}

// Fungsi untuk menghapus seluruh data dalam linked list
void hapusSeluruhData()
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *deleteNode = temp;
        temp = temp->next;
        delete deleteNode;
    }
    head = NULL;
    cout << "Seluruh data telah dihapus" << endl;
}

// Fungsi untuk menampilkan seluruh data dalam linked list
void tampilkanData()
{
    Node *temp = head;
    cout << "DATA MAHASISWA" << endl;
    cout << "|| NAMA "
         << "  |  "
         << "NIM"
         << "\t ||"
         << "\n"
         << endl;
    while (temp != NULL)
    {
        cout << temp->nama << "\t  |" << temp->nim << endl;
        temp = temp->next;
    }
}

int main()
{
    int pilihan;
    do
    {
        cout << "\n||PROGAM SINGLE LINKED LIST NON-CIRCULAR||"
             << "\n"
             << endl;
        cout << "Tampilan Menu:" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            tambahTengah();
            break;
        case 4:
            ubahDepan();
            break;
        case 5:
            ubahBelakang();
            break;
        case 6:
            ubahTengah();
            break;
        case 7:
            hapusDepan();
            break;
        case 8:
            hapusBelakang();
            break;
        case 9:
            hapusTengah();
            break;
        case 10:
            hapusSeluruhData();
            break;
        case 11:
            tampilkanData();
            break;
        case 0:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```

#### Output:

#### Tampilan Menu
 ![Screenshot (77)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/5b95d1d5-3c5d-414f-998f-011a9dab0059)


#### Tampilan Operasi Tambah
![Screenshot (78)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/04032ba3-abbc-4890-83b2-7e552ad63c54)
![Screenshot (80)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/10bb7b26-dba2-4591-b9f9-e752dc8636b5)
![Screenshot (83)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/ac048583-030e-4668-9488-7b81af533d3c)



#### Tampilan Operasi Hapus
![Screenshot (81)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/a90640d3-5616-4644-b3ac-68f4c51e3c19)
![Screenshot (86)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/6efd6bac-1252-4cae-9176-fba9f4f05aa0)
![Screenshot (88)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/ebb76ee7-3d7f-481f-b1d9-113ad47c0d65)



#### Tampilan Operasi Ubah
![Screenshot (84)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/2baa9c4f-34c5-45bd-900d-917d8ad6938d)
![Screenshot (85)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/10e1b9ff-416b-49ce-95f8-82cac55193bf)
![Screenshot (87)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/b4dc2225-4b25-46fe-a65b-04774744ccf0)


#### Tampilan Operasi Tampil Data
![Screenshot (79)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/dbb93b3f-ee73-4b20-8533-835dd627a7e0)



### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![Screenshot (79)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/6f0ebcec-aeab-45fd-9095-a3fbaad04a95)


### 3. Lakukan perintah berikut:

#### a) Tambah data Wati 2330004 diantara Farrel dan Denis
![Screenshot (80)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/ce540b93-012c-45ff-85f2-ccdd7e1e51b6)


#### b) Hapus data Denis

![Screenshot (81)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/78f49242-1bae-4546-b1fe-d530f23b495b)

#### c) Tambahkan data berikut di awal: Owi 2330000
![Screenshot (82)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/ef65e080-c526-4b3d-af5e-db0f9aa3d71e)

#### d) Tambahkan data berikut di akhir: David 2330010
![Screenshot (83)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/f6252f5e-d895-496a-92dd-8a9d4802574a)


#### e) Ubah data Udin menjadi data berikut: Idin 23300045
![Screenshot (84)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/3ea8d958-4c45-4828-bf8b-b04bf1db09e0)


#### f) Ubah data terkahir menjadi berikut: Lucy 23300101
![Screenshot (85)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/989eb147-3290-4e1e-b36f-cdfaffb2664a)


#### g) Hapus data awal
![Screenshot (86)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/531dfde6-5bdf-4c02-839a-72039f4da21c)


#### h) Ubah data awal menjadi berikut: Bagas 2330002
![Screenshot (87)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/f2ba1392-b682-4206-87f8-31793500ea4c)


#### i) Hapus data akhir
![Screenshot (88)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/609913b9-087a-4ed5-8ffa-3652bace6f2c)


#### j) Tampilkan seluruh data
![Screenshot (89)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/4c112cad-8f39-4768-bd21-3c6e8d688e9c)


Program ini adalah implementasi struktur data Linked List Non-Circular (tidak melingkar) dalam bahasa pemrograman C++. Linked List ini digunakan untuk menyimpan data mahasiswa yang terdiri dari nama dan NIM (Nomor Induk Mahasiswa). Program menyediakan berbagai fungsi untuk melakukan operasi pada Linked List, seperti menambah data di depan, belakang, atau tengah, mengubah data di depan, belakang, atau tengah, menghapus data di depan, belakang, atau tengah, serta menghapus seluruh data dalam Linked List. Secara keseluruhan, program ini memberikan contoh implementasi dasar dari Linked List Non-Circular dalam C++ untuk mengelola data mahasiswa (nama dan NIM). Pengguna dapat melakukan berbagai operasi seperti menambah, mengubah, menghapus, dan menampilkan data dalam Linked List melalui menu yang disediakan.

## Kesimpulan
Linked list circular merupakan varian dari struktur data linked list biasa. Perbedaannya adalah pada linked list circular, elemen terakhir terhubung kembali ke elemen pertama, sehingga membentuk lingkaran. Sementara pada linked list biasa, elemen terakhir menunjuk ke NULL.

Kelebihan utama linked list circular adalah kemampuannya untuk melakukan traversing secara terus-menerus tanpa harus kembali ke elemen pertama, sehingga memungkinkan pengolahan data yang lebih efisien dalam beberapa kasus penggunaan.

Linked list circular memiliki kemiripan dengan linked list ganda dalam hal sifat melingkar, namun hanya memiliki satu pointer next, sedangkan linked list ganda memiliki dua pointer (next dan prev).

Meskipun demikian, linked list circular juga memiliki kelemahan, seperti kompleksitas dalam penanganan kasus khusus, seperti menemukan elemen terakhir atau melakukan operasi pada elemen terakhir. Selain itu, kesalahan dalam implementasi operasi tambah dan hapus elemen dapat mengakibatkan terjadinya looping tak terbatas.

Oleh karena itu, penggunaan linked list circular harus dipertimbangkan dengan cermat sesuai dengan kebutuhan aplikasi dan karakteristik data yang diolah. Kelebihan dan kelemahan dari struktur data ini perlu dipahami dengan baik agar dapat memanfaatkannya secara efektif dalam pengembangan perangkat lunak.

## Referensi
[1] Cormen et al. (2009) dalam buku "Introduction to Algorithms".

[2] Goodrich dan Tamassia (2015) dalam buku "Data Structures and Algorithms in C++".
