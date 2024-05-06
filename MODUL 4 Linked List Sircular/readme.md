# <h1 align="center">Laporan Praktikum Modul 4 - Linked list Circular</h1>
<p align="center">Rangga Pradarrell Fathi</p>
  <P align="center">2311102200</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Linked List Circular

linked list circular adalah variasi dari linked list di mana penunjuk berikutnya dari node terakhir menunjuk kembali ke node head. Hal ini menciptakan struktur circular, di mana list tersebut tidak memiliki awal atau akhir yang pasti. Dalam linked list non-circular, penunjuk berikutnya dari node terakhir disetel ke nol, yang menunjukkan akhir list.[1]

*Single linked list sircular*: Dalam Single linked list sircular, node terakhir dari list berisi penunjuk ke node pertama dari list.[2] Melintasi Single linked list sircular hingga kita mencapai node yang sama tempat kami memulai. Single linked list sircular tidak memiliki awal atau akhir. Tidak ada nilai null di bagian selanjutnya dari node mana pun.

*Double linked list sircular*:Double linked list sircular memiliki properti Double linked list dan  linked list sircular di mana dua elemen berurutan dihubungkan atau dihubungkan oleh penunjuk sebelumnya dan berikutnya dan node terakhir menunjuk ke node pertama dengan penunjuk berikutnya dan juga node pertama menunjuk ke node terakhir dengan penunjuk sebelumnya.[2]

### Linked List Non Circular

Linked list non-circular adalah struktur data linear di mana setiap elemen terhubung ke elemen berikutnya, namun elemen terakhir tidak terhubung kembali ke elemen pertama atau ke elemen mana pun dalam linked list. Sebagai akibatnya, traversing dari awal ke akhir linked list akan berakhir ketika mencapai elemen terakhir yang menunjuk ke nilai NULL. Ini membuat manipulasi dan pengelolaan data menjadi lebih sederhana dan jelas, namun tidak memungkinkan traversing langsung kembali ke elemen pertama setelah mencapai elemen terakhir.[2]

   
## Guided 

### 1. Linked List Non Circular

```C++
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;
Node *tail;

// inialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// pengecekan
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// tambah depan
void insertDepan(int nilai)
{
    // buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
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

// tambah belakang
void insertBelakang(int nilai)
{
    // buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
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

// hitung jumlah list
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

// tambah tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan di tengah" << endl;
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

// hapus depan
void hapusDepan()
{
    Node *hapus;

    if (!isEmpty())
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
        cout << "List Kosong!" << endl;
    }
}

// hapus belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;

    if (!isEmpty())
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
        cout << "List Kosong!" << endl;
    }
}

// hapsu tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;

    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan di tengah" << endl;
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

// ubah depan
void ubahDepan(int data)
{
    if (!isEmpty())
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// ubah tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;

    if (!isEmpty())
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan di tengah" << endl;
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
        cout << "List masih kosong" << endl;
    }
}

// ubah belakang
void ubahBelakang(int data)
{
    if (!isEmpty())
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong" << endl;
    }
}

// hapus list
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

// tampilkan list
void tampil()
{
    Node *bantu;
    bantu = head;

    if (!isEmpty())
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

#### Output :
![318433553-d16f58bc-a710-4d26-bfa5-a421dfcbe01f](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/07631e6a-c6f3-4cbd-946f-cb49bdbba3b4)


Program ini adalah implementasi struktur data Linked List Linier (tidak circular) dalam bahasa pemrograman C++. Linked List adalah struktur data linear yang terdiri dari serangkaian node, di mana setiap node berisi data dan referensi (pointer) ke node berikutnya dalam urutan. Secara keseluruhan, program ini memberikan contoh implementasi dasar dari Linked List Linier dalam C++, termasuk berbagai operasi yang dapat dilakukan pada struktur data tersebut.


### 2. Linked List Circular

```C++
#include <iostream>

using namespace std;


// program single linked list circular

// deklarasi struct node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// pengecekan
bool isEmpty()
{
    if (head == NULL)
    {
        return 1; // true
    }
    else
    {
        return 0; // false
    }
}

// buat node baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// hitung list
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// tambah depan
void insertDepan(string data)
{
    // buat node baru
    buatNode(data);

    if (isEmpty())
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// tambah belakan
void insertBelakang(string data)
{
    // buat node baru
    buatNode(data);

    if (isEmpty())
    {
        head = baru;
        tail = head;
        tail->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
        tail = baru;
    }
}

// tambah tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty())
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// hapus depan
void hapusDepan()
{
    if (!isEmpty())
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus belakang
void hapusBelakang()
{
    if (!isEmpty())
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }

            while (tail->next != hapus)
            {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus tengah
void hapusTengah(int posisi)
{
    if (!isEmpty())
    {
        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus list
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

// tampilkan list
void tampil()
{
    if (!isEmpty())
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
```

#### Output :
![318434701-dc415993-d384-437b-b68b-052d38ee4c75](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/d5526383-24e0-4d0d-a85e-af6cae8d6a11)

Program ini adalah implementasi struktur data Linked List Circular (melingkar) dalam bahasa pemrograman C++. Linked List Circular mirip dengan Linked List Linier, namun elemen terakhir (tail) menunjuk kembali ke elemen pertama (head), sehingga membentuk struktur melingkar. Secara keseluruhan, program ini memberikan contoh implementasi dasar dari Linked List Circular dalam C++, termasuk berbagai operasi yang dapat dilakukan pada struktur data tersebut.


## Unguided 

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:

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
[1] Sahni, S. (2020). Data Structures, Algorithms, and Applications in C++ (2nd ed.). Universities Press.

[2] Duffy, J. (2019). Data Structures and Algorithms with Object-Oriented Design Patterns in C++ (1st ed.). Packt Publishing.

