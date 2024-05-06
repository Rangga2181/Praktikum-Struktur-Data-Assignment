# <h1 align="center">Laporan Praktikum Modul 5 - STACK</h1>
<p align="center">Rangga Pradarrell Fathi</p>
  <P align="center">2311102200</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### STACK

Stack adalah struktur data linear yang mengikuti prinsip Last In First Out (LIFO), yang berarti elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Dalam pemrograman C++, Stack dapat diimplementasikan dengan menggunakan array atau linked list.

### Berikut adalah penjelasan singkat tentang Stack:

1. Operasi Dasar:


-push(x): Menambahkan elemen x ke bagian atas Stack.

-pop(): Menghapus dan mengembalikan elemen dari bagian atas Stack.

-top(): Mengembalikan elemen yang berada di bagian atas Stack tanpa menghapusnya.

-isEmpty(): Memeriksa apakah Stack kosong atau tidak.


2. Implementasi dengan Array:
   

-Gunakan sebuah array untuk menyimpan elemen-elemen Stack.

-Gunakan variabel top untuk melacak indeks elemen teratas.

-Operasi push menambahkan elemen baru di indeks top dan menaikkan nilai top.

-Operasi pop mengembalikan elemen di indeks top dan menurunkan nilai top.


3. Implementasi dengan Linked List:


-Gunakan struktur Node yang berisi data dan pointer ke node berikutnya.

-Pointer top menunjuk ke node teratas pada Stack.

-Operasi push membuat node baru dan mengubah top untuk menunjuk ke node tersebut.

-Operasi pop mengembalikan data dari node yang ditunjuk top dan mengubah top untuk menunjuk ke node sebelumnya.


4. Aplikasi Stack:


-Pembalik string atau angka.

-Evaluasi ekspresi dengan notasi reverse polish.

-Penerapan rekursi dalam program.

-Penerapan algoritma traversal pada graph dan tree.

   
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
// Rangga Pradarrell Fathi
// 2311102200

#include <iostream>
#include <vector>

using namespace std;

// Ukuran Hash table
const int TABLE_SIZE = 100;

// Struktur data untuk Mahasiswa
struct Mahasiswa
{
    string nama;
    string nim;
    int nilai;
};

class HashTable
{
private:
    vector<Mahasiswa> *table;

    // Fungsi hash sederhana untuk menghasilkan indeks dari NIM
    int hashFunction(const string &nim)
    {
        int sum = 0;
        for (char c : nim)
        {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

public:
    // Konstruktor
    HashTable()
    {
        table = new vector<Mahasiswa>[TABLE_SIZE];
    }

    // Destruktor
    ~HashTable()
    {
        delete[] table;
    }

    // Fungsi untuk menambahkan data mahasiswa baru
    void tambahMahasiswa(string nama, string nim, int nilai)
    {
        Mahasiswa mhs;
        mhs.nama = nama;
        mhs.nim = nim;
        mhs.nilai = nilai;

        int index = hashFunction(nim);
        table[index].push_back(mhs);
    }

    // Fungsi untuk menampilkan seluruh data mahasiswa
    void tampilkanSeluruhData()
    {
        cout << ">>>> DATA MAHASISWA <<<<" << endl;
        cout << "No\tNAMA\t\tNIM\t\tNILAI" << endl;
        int nomor = 1;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            for (const Mahasiswa &mhs : table[i])
            {
                cout << nomor++ << "\t" << mhs.nama << "\t" << mhs.nim << "\t" << mhs.nilai << endl;
            }
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    Mahasiswa *cariMahasiswaNIM(const string &nim)
    {
        int index = hashFunction(nim);
        for (int i = 0; i < table[index].size(); ++i)
        {
            if (table[index][i].nim == nim)
            {
                return &table[index][i];
            }
        }
        return nullptr;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
    vector<Mahasiswa *> cariMahasiswaNilai()
    {
        vector<Mahasiswa *> hasil;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            for (int j = 0; j < table[i].size(); ++j)
            {
                if (table[i][j].nilai >= 80 && table[i][j].nilai <= 90)
                {
                    hasil.push_back(&table[i][j]);
                }
            }
        }
        return hasil;
    }

    void tampilkanMahasiswaNilai()
    {
        vector<Mahasiswa *> mahasiswas = cariMahasiswaNilai();
        cout << ">>>>> DATA MAHASISWA DENGAN NILAI 80-90 <<<<<" << endl;
        cout << "No\tNAMA\t\tNIM\t\tNilai" << endl;
        int nomor = 1;
        for (Mahasiswa *mhs : mahasiswas)
        {
            cout << nomor++ << "\t" << mhs->nama << "\t" << mhs->nim << "\t" << mhs->nilai << endl;
        }
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void hapusMahasiswa(const string &nim)
    {
        int index = hashFunction(nim);
        for (int i = 0; i < table[index].size(); ++i)
        {
            if (table[index][i].nim == nim)
            {
                table[index].erase(table[index].begin() + i);
                return;
            }
        }
    }
};

// Fungsi untuk menampilkan menu dan meminta input dari pengguna
void tampilkanMenu()
{
    cout << "===== ||M E N U|| =====" << endl;
    cout << "|1| Tambah Data Mahasiswa" << endl;
    cout << "|2| Tampilkan Seluruh Data Mahasiswa" << endl;
    cout << "|3| Cari Data Mahasiswa berdasarkan NIM" << endl;
    cout << "|4| Cari Data Mahasiswa berdasarkan Rentang Nilai (80 - 90)" << endl;
    cout << "|5| Hapus Data Mahasiswa" << endl;
    cout << "|6| Keluar" << endl;
    cout << "Pilih opsi: ";
}

int main()
{
    HashTable hashTable;

    int opsi;
    do
    {
        tampilkanMenu();
        cin >> opsi;

        switch (opsi)
        {
        case 1:
        {
            string nama, nim;
            int nilai;
            cout << "Masukkan nama mahasiswa: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim;
            cout << "Masukkan nilai mahasiswa: ";
            cin >> nilai;
            hashTable.tambahMahasiswa(nama, nim, nilai);
            cout << "Mahasiswa berhasil ditambahkan." << endl;
            break;
        }
        case 2:
        {
            hashTable.tampilkanSeluruhData();
            break;
        }
        case 3:
        {
            string nim;
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> nim;
            Mahasiswa *mhs = hashTable.cariMahasiswaNIM(nim);
            if (mhs != nullptr)
            {
                cout << "Data Mahasiswa ditemukan dengan \nNama: " << mhs->nama << "\nNIM: " << mhs->nim << "\nNilai: " << mhs->nilai << endl;
            }
            else
            {
                cout << "Data Mahasiswa tidak ditemukan." << endl;
            }
            break;
        }
        case 4:
        {
            hashTable.tampilkanMahasiswaNilai();
            break;
        }
        case 5:
        {
            string nim;
            cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
            cin >> nim;
            hashTable.hapusMahasiswa(nim);
            cout << "Data Mahasiswa berhasil dihapus." << endl;
            break;
        }
        case 6:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Opsi tidak valid. Silakan pilih lagi." << endl;
        }

        cout << endl;
    } while (opsi != 6);

    return 0;
}
```

#### Output:

#### Tampilan Menu
![Screenshot (113)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/a44f83d0-28c7-49d8-8598-232e71354f4d)



#### Tampilan Operasi Tambah
![Screenshot (114)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/e81034f0-e99d-4ce5-8937-a39113926358)



#### Tampilan Operasi Hapus
![Screenshot (118)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/dd48578e-4e29-4da0-ad0b-b9826cbe6422)



####  Cari Data Mahasiswa berdasarkan NIM
![Screenshot (116)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/8c4b0ac1-ec79-4537-a464-d191644a0878)



####  Cari Data Mahasiswa berdasarkan Rentang Nilai (80 - 90)
![Screenshot (117)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/4e5e298f-7f36-4c72-851b-35a57ec74fe0)



#### Tampilan Operasi Tampil Data
![Screenshot (115)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/b12973b2-0dcd-40ee-9961-6a9fbcebc763)

Dalam program diatas, Hash Table digunakan untuk menyimpan data mahasiswa secara efisien. Operasi-operasi seperti pencarian, penyisipan, dan penghapusan dapat dilakukan dalam waktu yang konstan rata-rata, karena sifat dasar dari struktur data Hash Table. Program diatas juga menyediakan fitur-fitur seperti pencarian data mahasiswa berdasarkan NIM atau rentang nilai, serta penghapusan data mahasiswa berdasarkan NIM. Semua operasi tersebut dapat dilakukan dengan mudah menggunakan Hash Table.


## Kesimpulan
Hash Table adalah struktur data yang digunakan untuk menyimpan dan mengakses data dengan cepat menggunakan fungsi hash. Dalam hash table, data disimpan dalam array berindeks dengan menggunakan fungsi hash untuk mengonversi kunci menjadi indeks array. Ini memungkinkan akses langsung ke data dengan kompleksitas waktu rata rata O(1). Ketika dua kunci menghasilkan indeks yang sama (kolisi), teknik seperti cha ining atau linear probing digunakan untuk menangani kolisi tersebut. 

Operasi utama pada hash table meliputi penambahan data, penghapusan data, dan pencarian data berdasarkan kunci. Hash table memiliki berbagai aplikasi, seperti pengindeksan, pencarian cepa t, penyimpanan data, dan implementasi struktur data seperti set dan kamus. Penting untuk merancang atau memilih fungsi hash yang baik agar meminimalkan kolisi dan memastikan distribusi yang merata. Memahami prinsip dan implementasi hash table akan membantu Anda dalam pengelolaan data dan pencarian efisien dalam pemrograman.

## Referensi
[1] Cormen et al. (2009) dalam buku "Introduction to Algorithms".

[2] Goodrich dan Tamassia (2015) dalam buku "Data Structures and Algorithms in C++".
