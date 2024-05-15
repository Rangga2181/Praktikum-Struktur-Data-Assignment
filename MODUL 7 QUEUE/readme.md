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
# -Array statis: Queue diimplementasikan menggunakan array dengan ukuran tetap. Memiliki keterbatasan kapasitas dan dapat terjadi kondisi overflow jika antrian penuh.
# -Array dinamis (circular array): Untuk mengatasi keterbatasan array statis, digunakan circular array yang melakukan wrap-around saat mencapai ujung array.

## Menggunakan Linked List:
# Queue diimplementasikan dengan linked list, di mana setiap node menyimpan data dan pointer ke node berikutnya. Tidak memiliki batasan kapasitas seperti array statis dan dapat tumbuh secara dinamis.

### Beberapa operasi utama pada kelas Queue meliputi:
-push(const T& val): Menambahkan elemen baru ke bagian belakang antrian.

-pop(): Menghapus elemen dari bagian depan antrian.

-front(): Mengakses elemen di bagian depan antrian tanpa menghapusnya.

-back(): Mengakses elemen di bagian belakang antrian.

-empty(): Memeriksa apakah antrian kosong atau tidak.

-size(): Mendapatkan jumlah elemen dalam antrian.
   
#### Guided 

### 1.

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull()
{
    return (top == maksimal);
}

bool isEmpety()
{
    return (top == 0);
}

void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku()
{
    if (isEmpety())
    {
        cout << " Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi)
{
    if (isEmpety())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack()
{
    return top;
}

void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku()
{
    if (isEmpety())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpety() << endl;

    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
```

#### Output :
![Screenshot (162)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/7f5bba49-c8fa-41a1-a346-098b8df777e6)
![Screenshot (161)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/7fcb98ae-62ee-4903-80a5-15af659229a0)

Progam diatas menjalankan implementasi struktur data stack menggunakan array, dengan menyediakan operasi-operasi dasar seperti push, pop, peek, dan lainnya.


## Unguided 


### ![Screenshot (164)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/ea84ff25-9ac8-4b6d-8771-d9294fd6a632)



```C++
//Rangga Pradarrell Fathi
//2311102200
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100; // Ukuran maksimal stack

class Stack
{
private:
    char arr[MAX_SIZE]; // Array untuk menyimpan elemen stack
    int top;            // Indeks elemen atas
    int count;          // Jumlah elemen dalam stack

public:
    Stack()
    {
        top = -1; // Mengecek stack kosong
        count = 0;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == MAX_SIZE;
    }

    void push(char x)
    {
        if (isFull())
        {
            cout << "Error: Stack penuh" << endl;
            return;
        }
        arr[++top] = x;
        count++;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Error: Stack kosong" << endl;
            return '\0';
        }
        count--;
        return arr[top--];
    }
};

bool isPalindrome(string str)
{
    Stack s;
    int len = str.length();

    // Mendorong huruf ke dalam stack
    for (int i = 0; i < len / 2; i++)
    {
        s.push(str[i]);
    }

    // Memeriksa panjang ganjil dan lewati huruf tengah
    int start = len % 2 == 0 ? len / 2 : (len / 2) + 1;

    // Keluarkan huruf dari stack dan bandingkan dengan sisa huruf
    for (int i = start; i < len; i++)
    {
        if (s.pop() != str[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string input;
    cout << "Masukkan sebuah kata: ";
    getline(cin, input);

    if (isPalindrome(input))
    {
        cout << "Kata yang dimasukkan adalah palindrom." << endl;
    }
    else
    {
        cout << "Kata yang dimasukkan bukan palindrom." << endl;
    }

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
