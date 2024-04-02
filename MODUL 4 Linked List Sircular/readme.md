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
![Screenshot (2903)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/d16f58bc-a710-4d26-bfa5-a421dfcbe01f)

Program diatas memungkinkan penambahan, penghapusan, dan perubahan elemen di depan, di belakang, dan di tengah linked list. Pada awalnya, program mendefinisikan struktur Node yang berisi data dan pointer ke node selanjutnya. Kemudian, program menyediakan fungsi-fungsi untuk operasi dasar linked list, seperti penambahan, penghapusan, dan perubahan elemen. 
Di dalam main(), serangkaian operasi tersebut dijalankan untuk menguji fungsi-fungsi tersebut, seperti menambahkan dan menghapus elemen di berbagai posisi, serta mengubah nilai elemen. Hasilnya ditampilkan setiap kali ada perubahan pada linked list.


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
![Screenshot (2904)](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/dc415993-d384-437b-b68b-052d38ee4c75)

Program ini mendefinisikan struktur Node yang memiliki dua atribut: data dan pointer ke node berikutnya. Kemudian, program menyediakan fungsi-fungsi untuk operasi dasar pada linked list, seperti penambahan dan penghapusan elemen di depan, di belakang, dan di tengah linked list. 
Di dalam fungsi main(), serangkaian operasi tersebut dijalankan untuk menguji fungsi-fungsi tersebut. Misalnya, menambahkan elemen di depan dan di belakang, menghapus elemen di depan dan di belakang, serta menambahkan dan menghapus elemen di tengah. Setiap kali ada perubahan pada linked list, isi linked list ditampilkan.


## Unguided 

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:

```C++
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

#### Tampilan Awal
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/6d3b92b9-bb7b-4fde-8322-e17139096249)

#### Tampilan Operasi Tambah
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/dfe4b3ab-dd19-408e-afbc-b9a58bc0ac2c)
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/a4f479de-873a-4ab5-a542-d6c3cb70ee74)

#### Tampilan Operasi Hapus
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/5d40645e-e289-4775-b2ef-bf376bc4551d)
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/f0ab0956-3108-444e-926d-893633a7af85)


#### Tampilan Operasi Ubah
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/1d2b3cfe-58d2-488a-b9db-56f57bfdf89e)
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/6ef5c896-d475-4977-887c-02732c443ae2)

#### Tampilan Operasi Tampil Data
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/fa1d5a11-ab37-419c-8702-9264b42c07f8)


### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/f41344b7-715a-48ea-9fce-2154944b2f32)

### 3. Lakukan perintah berikut:

#### a) Tambah data Wati 2330004 diantara Farrel dan Denis
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/e1ba13bd-807c-48a2-8c67-2d04d2e89b60)

#### b) Hapus data Denis
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/fc7c07e9-672b-43b3-87d4-f0029cf80fc2)

#### c) Tambahkan data berikut di awal: Owi 2330000
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/9113b6b0-d9b6-4f86-b803-022039c2ba21)

#### d) Tambahkan data berikut di akhir: David 2330010
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/927de6a2-58d2-4256-9470-5d21aed00375)

#### e) Ubah data Udin menjadi data berikut: Idin 23300045
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/d69f6314-6ac1-4171-82c4-04ca1e22fc18)

#### f) Ubah data terkahir menjadi berikut: Lucy 23300101
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/4addcf01-8776-4d26-9cbb-703a5e45c8af)

#### g) Hapus data awal
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/0f96b024-2afc-4ea3-a1d7-05bc102ca49d)

#### h) Ubah data awal menjadi berikut: Bagas 2330002
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/d909d038-07ff-4685-8682-b2cd6bee1076)

#### i) Hapus data akhir
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/2f9bdb8c-b8c5-43c5-a42d-18a782bf4d16)

#### j) Tampilkan seluruh data
![image](https://github.com/andikaneviantoro/Struktur-Data-Assigment/assets/98001415/da02a681-fc94-4846-bdbf-ca2a3ca1fc3d)

Program di atas merupakan implementasi dari linked list circular. Kelas *LinkedListCircular* memiliki beberapa fungsi untuk operasi-operasi dasar pada linked list, seperti menambah, mengubah, dan menghapus data mahasiswa, serta menampilkan seluruh data mahasiswa. Setiap operasi tersebut dapat dilakukan di depan, di belakang, atau di tengah linked list.
Di dalam *main()*, program menyediakan menu untuk pengguna agar dapat memilih operasi yang ingin dilakukan, seperti menambah, mengubah, atau menghapus data mahasiswa, serta menampilkan seluruh data mahasiswa. Pengguna dapat memilih menu sesuai kebutuhan, dan program akan menjalankan operasi yang dipilih. Selama program berjalan, data mahasiswa disimpan dalam linked list circular, yang artinya elemen terakhir terhubung kembali ke elemen pertama, membentuk lingkaran. Hal ini memungkinkan untuk melakukan traversing dari awal ke akhir linked list secara terus menerus.

## Kesimpulan
Linked list circular merupakan varian dari struktur data linked list biasa. Perbedaannya adalah pada linked list circular, elemen terakhir terhubung kembali ke elemen pertama, sehingga membentuk lingkaran. Sementara pada linked list biasa, elemen terakhir menunjuk ke NULL.

Kelebihan utama linked list circular adalah kemampuannya untuk melakukan traversing secara terus-menerus tanpa harus kembali ke elemen pertama, sehingga memungkinkan pengolahan data yang lebih efisien dalam beberapa kasus penggunaan.

Linked list circular memiliki kemiripan dengan linked list ganda dalam hal sifat melingkar, namun hanya memiliki satu pointer next, sedangkan linked list ganda memiliki dua pointer (next dan prev).

Meskipun demikian, linked list circular juga memiliki kelemahan, seperti kompleksitas dalam penanganan kasus khusus, seperti menemukan elemen terakhir atau melakukan operasi pada elemen terakhir. Selain itu, kesalahan dalam implementasi operasi tambah dan hapus elemen dapat mengakibatkan terjadinya looping tak terbatas.

Oleh karena itu, penggunaan linked list circular harus dipertimbangkan dengan cermat sesuai dengan kebutuhan aplikasi dan karakteristik data yang diolah. Kelebihan dan kelemahan dari struktur data ini perlu dipahami dengan baik agar dapat memanfaatkannya secara efektif dalam pengembangan perangkat lunak.

## Referensi
[1] Malik, D. S. (2010). Struktur Data penggunaan C++. 

[2] Drozdek, A. (2005). Struktur data dan algoritma dalam C++.

