# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

<p align="center">Rangga Pradarrell Fathi</p>
<p align="center">2311102200 / IF-11-E</p>

## Dasar Teori
Tipe data merupakan suatu cara untuk membedakan data berdasarkan tipenya. Tipe data juga diperlukan agar compiler dapat memahami data apa yang akan digunakan.
 

#### 1. TIPE DATA PRMITIF
Tipe data primitif adalah cara komputer  menyimpan data dasar seperti angka dan huruf. Tipe data integer yang didukung hanya tipe data tertentu saja, yaitu tipe data integer untuk bilangan bulat, tipe data float untuk angka desimal, tipe data char untuk huruf, tipe data boolean untuk menentukan dua hal yang benar dan salah. Jadi, tipe data primitif memungkinkan untuk menyimpan huruf dan angka di  komputer.


#### 2. TIPE DATA ABSTRAK
Tipe Data Abstrak: Tipe data abstrak adalah tipe data yang tidak dapat dipakai secara langsung dan sering digunakan sebagai kelas dasar atau antarmuka. Tipe data abstrak memberikan definisi umum yang dapat diimplementasikan oleh kelas lain. Contoh  tipe data abstrak adalah kelas abstrak dan antarmuka. Dalam bahasa pemrograman Java, kelas abstrak memungkinkan Anda untuk mendefinisikan metode abstrak (metode yang tidak memerlukan implementasi) yang harus diimplementasikan oleh kelas turunannya.
 

#### 3. TIPE DATA KOLEKSI
Tipe data koleksi adalah tipe data untuk menyimpan beberapa nilai secara bersamaan. Tipe data koleksi juga bisa mengelola banyak data dengan terstruktur. Contoh dari tipe data koleksi yaitu :
- Array : Array merupakan suatu struktur data statis yang menyimpan elemen-elemen dengan jenis data yang seragam. Elemen-elemen tersebut diakses melalui indeks tertentu. Ukuran array bersifat tetap dan harus ditentukan pada saat pendeklarasian.

- Vector : Vector adalah Standard Template Library (STL), mirip dengan array dalam hal menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan otomatis dan bersebelahan. Vector memiliki kemampuan untuk menangani jumlah elemen yang dinamis. Vector menyediakan fleksibilitas dalam mengelola koleksi data dengan kemampuan dinamisnya, yang memungkinkan penambahan atau pengurangan elemen tanpa harus khawatir tentang alokasi memorinya secara manual.

- Map : Map, mirip dengan array, memungkinkan penggunaan indeks, disebut "key", yang tidak terbatas pada tipe data integer. Pada map, indeks diberi nama "key". Bukan hanya integer, sehingga map memberikan fleksibilitas yang lebih besar dibandingkan dengan array konvensional. Implementasi map menggunakan struktur data pohon merah-hitam yang secara otomatis seimbang, memberikan efisiensi dalam operasi pencarian dan penyisipan data.

## Guided 

### 1. [TIPE DATA PRIMITIF]
```C++
#include <iostream>

using namespace std;

// Main program
int main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cin >> op;
    // It allow user to enter the operands
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enter +
    case '+':
        cout << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << num1 / num2;
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
```

#### Output:
![Guided 1 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/a3ac0031-b13f-4d56-a27a-c6f6726ae7bd)
![Guided 1 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/e9685914-5ac0-4bf8-88c4-ac5ed45a3d8c)

Kode di atas digunakan untuk mencetak hasil dari penjumlahan, pengurangan, perkalian, dan pembagian atau bisa disebut juga kalkulator sederhana ke layar output dengan menggunakan function cout dan switch untuk menjalani atau mengeksekusi program tersebut.

### 2. [TIPE DATA ABSTRAK ]
```C++
#include <stdio.h>
// Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};
int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;
    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```

#### Output:
![Guided 2 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/14b77508-6be0-43ce-aa74-19d143280d32)
![Guided 2 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/5121a567-6e99-4858-9f11-4d3bfdaeeebd)

Kode diatas digunakan untuk menyimpan data mahasiswa yang terdiri dari nama, alamat, dan umur ke layar output dengan menggunakan function printf agar bisa mengeksekusi program tersebut.

### 3. [TIPE DATA KOLEKSI]
```C++
#include <iostream>
using namespace std;
int main()
{
    // deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    // mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}

```

#### Output:
![Guided 3 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/2aca387b-d93c-458a-a458-16edc99ef1ed)
![Guided 3 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/066cfd2d-bd5c-404e-8c90-5fd220a53a14)

Kode diatas digunakan untuk medeklarasi array nilai dengan nilai elemen bertipe integer dan mencetak masing masing dari integer tersebut ke layar output dan menggunakan function cout untuk mengeksekusinya.

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>

using namespace std;

// Fungsi untuk mendapatkan input dari pengguna
void getInput(double &alas, double &tinggi)
{
    cout << "Masukkan panjang alas segitiga: " << endl;
    cin >> alas;

    cout << "Masukkan tinggi segitiga: ";
    cin >> tinggi;
}

// Fungsi untuk menghitung luas segitiga
double calculateTriangleArea(double panjangAlas, double tinggi)
{
    return 0.5 * panjangAlas * tinggi;
}

int main()
{
    // Mendeklarasikan variabel
    double panjangAlas, tinggi, luas;

    // Memanggil fungsi untuk mendapatkan input
    getInput(panjangAlas, tinggi);

    // Memanggil fungsi untuk menghitung luas segitiga
    luas = calculateTriangleArea(panjangAlas, tinggi);

    // Menampilkan hasil
    cout << "Luas segitiga: " << luas << endl;

    return 0;
}

```

#### Output:
![Unguided 1 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/2531bdad-e05f-40f4-8a02-6e4e942640bb)

#### Full code Screenshot:
![Unguided 1 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/47b0813f-fd66-4067-8529-00a68f5f220e)

Program ini adalah sebuah program C++ dengan tipe data primitif yang menghitung luas segitiga berdasarkan panjang alas dan tingginya yang dimasukkan oleh pengguna.

Tipe data primitif adalah cara komputer dalam hal menyimpan data dasar seperti angka dan huruf. Tipe integer yang ditampung juga hanya tipe data tertentu yaitu tipe data integer untuk bilangan bulat, tipe data float untuk bilangan desimal, tipe data char untuk huruf, tipe data boolean untuk menentukan 2 hal yaitu true dan false. Jadi, tipe data primitif adalah tempat untuk menyimpan huruf dan angka di dalam komputer. [3]

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!]

Struct adalah struktur data yang memudahkan pengguna untuk menggabungkan beberapa jenis data yang berbeda. Mirip dengan fungsi class, struct bisa untuk menyimpan data, tetapi default anggotanya bersifat publik yang artinya semua anggotanya bisa diakses dari luar struct. Dengan menggunakan struct, program dengan mudah membuat dan memgelola kumpulan data tanpa adanya kompleksitas seperti pada fungsi class. Struct mempunyai kelebihan untuk menyimpan data simpel tanpa metode yang diutamakan dan memberikan fleksibilitas dalam membuat dan menyusun program.

Class berfungsi sebagai template untuk menciptakan objek. Class adalah struktur yang menggabungkan antara dara dan fungsi untuk memproses data dalam suatu pemrograman. Class dapat membuat objek yang memiliki sifat yang sama. Data dalam class menunjukan karakteristik objek, sedangkan fungsi berguna untuk berinteraksi dengan data tersebut. Dengan menggunakan fungsi class, program bisa jauh lebih dimengerti dan mudah diatur dan juga bisa untuk mengatasi kompleksitas program secara terstruktur.[2]

Contoh Untuk Fungsi Dari Class
```C++
#include <iostream>
#include <string>
using namespace std;

class Mahasiswa
{
private:
    string nama;
    int nim;
    string jurusan;

public:
    // Constructor
    Mahasiswa(string _nama, int _nim, string _jurusan)
    {
        nama = _nama;
        nim = _nim;
        jurusan = _jurusan;
    }

    // Destructor
    ~Mahasiswa()
    {
        cout << "Objek Mahasiswa " << nama << " Aktif" << endl;
    }

    // Method untuk menampilkan informasi mahasiswa
    void tampilkanInfo()
    {
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << "Jurusan: " << jurusan << endl;
    }
};

int main()
{
    // Membuat objek mahasiswa
    Mahasiswa mhs1("Rangga Pradarrell", 200, "Teknik Informatika");
    Mahasiswa mhs2("Wahyu Hidayat", 180, "Teknik Informatika");

    // Memanggil method untuk menampilkan informasi mahasiswa
    cout << "Informasi Mahasiswa 1:" << endl;
    mhs1.tampilkanInfo();

    cout << endl;

    cout << "Informasi Mahasiswa 2:" << endl;
    mhs2.tampilkanInfo();

    return 0;
}

```

#### Output:
![Unguided 2 (1) Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/50d797b5-d632-4790-93ee-1bb97740f695)

#### Full code Screenshot:
![Unguided 2 (1) Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/68ff192e-8ec5-4db3-9a06-9d999bd75f6a)

Program tersebut adalah sebuah program C++ yang mendefinisikan sebuah class Mahasiswa. Setiap objek Mahasiswa memiliki atribut nama, NIM, dan jurusan. Program ini memiliki constructor untuk menginisialisasi objek Mahasiswa dengan nilai-nilai tersebut. Program juga memiliki destructor yang mencetak pesan saat objek Mahasiswa dihapus.

Contoh Untuk Fungsi Dari Struct
```C++
#include <iostream>
using namespace std;
struct Buku
{
    string judul;
    string penulis;
    int tahunTerbit;
    int halaman;

    void cetakInfo()
    {
        cout << "Judul: " << judul << endl;
        cout << "Penulis: " << penulis << endl;
        cout << "Tahun Terbit: " << tahunTerbit << endl;
        cout << "Halaman: " << halaman << endl;
    }
};

int main()
{
    // Menginisialisasi variabel bertipe Buku
    Buku buku1;
    buku1.judul = "Laskar Pendekar";
    buku1.penulis = "Andreas Wibowo";
    buku1.tahunTerbit = 2008;
    buku1.halaman = 329;

    // Menampilkan informasi buku
    buku1.cetakInfo();

    // Menginisialisasi variabel bertipe Buku dengan konstruktor
    Buku buku2{"Sang Pemimpi", "Andreas Wibowo", 2009, 264};

    // Menampilkan informasi buku
    buku2.cetakInfo();

    return 0;
}

```

#### Output:
![Unguided 2 (2) Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/484e371b-058e-4c4e-83be-56aea89e3eb8)

#### Full code Screenshot:
![Unguided 2 (2) Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/c20fc2e0-986e-4d32-b0f6-0817a7940606)

Program tersebut adalah sebuahfungsi yang mendefinisikan sebuah struktur (struct) bernama Buku. Struktur Buku memiliki empat atribut: judul, penulis, tahunTerbit, dan halaman. Program ini juga memiliki sebuah method cetakInfo() yang digunakan untuk mencetak informasi buku ke layar.

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!]

```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Membuat map untuk menyimpan nama dan umur
    map<string, int> umur;

    // Menambahkan data ke dalam map
    umur["Jawier"] = 25;
    umur["Jandul"] = 30;
    umur["Doel"] = 20;

    // Mengakses nilai dalam map
    cout << "Umur Jawir: " << umur["Jawier"] << " tahun" << endl;
    cout << "Umur Jandul: " << umur["Jandul"] << " tahun" << endl;
    cout << "Umur Doel: " << umur["Doel"] << " tahun" << endl;

    // Menggunakan iterator untuk menampilkan semua pasangan kunci-nilai dalam map
    cout << "\nDaftar Nama dan Umur:\n";
    for (auto it = umur.begin(); it != umur.end(); ++it)
    {
        cout << it->first << ": " << it->second << " tahun\n";
    }

    return 0;
}

```
#### Output:
![Unguided 3 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/0a515ff2-6f5e-4b74-ba37-170fbd0d672e)

#### Full code Screenshot:
![Unguided 3 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/22dbcde0-9ff3-44cd-8d9c-0a88c122f08a)

Program tersebut adalah sebuah program C++ yang menggunakan fungsi map untuk menyimpan pasangan kunci-nilai, di mana kunci adalah nama dan nilai adalah umur.

Array dan map memiliki beberapa perbedaan , seperti :
1. Dari segi ukuran , ukuran array biasanya tetap dan jika ingin menyimpan banyak data ukuran array harus di ubah atau disesuaikan secara manual. Sedangkan map , ukuran map bersifat dinamis dan dapat diubah, ditambah, dan dihapus dan pada awal deklarasinya tidak perlu ditentukan untuk ukurannya.
2. Dari Tipe data nya, Array merupakan struktur data untuk menyimpan elemen data dengan tipe yang sama dalam satu linier. Sedangkan map adalah struktur data untuk menyimpan pasangan kunci dan nilai. Kunci dan nilaipyn bisa dari tipe data yang berbeda.
3. Dari Indeksnya, Array menggunakan indeks berbasis angka numerik mulai dari 0. Sedangkan map menggunakan data yang tidak terurut dan data diidentifikasi melalui kunci yang memiliki tipe data yang berbeda.

Singkatnya, Array cocok untuk urutan data dengan indeks numerik dan map cocok untuk penugasan data dengan kunci yang dapat berupa tipe data apapun atau tipe data yang berbeda.[2]

## Kesimpulan
Tipe data ini berisi beberapa data yang dapat diproses di komputer, seperti integer, float, char, dan lain-lain. Tipe data abstrak berisi pembahasan konsep yang lebih tinggi, fokus pada penyajian data, dan operasi  dapat dilakukan tanpa memperhatikan implementasi internal. Tipe data koleksi  ini menggunakan eksplorasi struktur data yang menyimpan banyak elemen, seperti array, vektor, dan map. Ini juga berguna untuk akses data yang lebih cepat.
 
Dari materi tipe data ini, pembelajaran yang didapat adalah paham tentang berbagai tipe data yang dapat digunakan dalam pemrograman, dan juga kegunaan dari tipe data abstrak maupun koleksi lebih efisien dalam penggunaannya. Menguasai beberapa tipe data bisa lebih mudah untuk membuat suatu program dan memperluas kemampuan dalam memprogram dan mendata secara cepat.

## Referensi
####  Pratama, M. A. (2020, March 29). STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++. 
####  Putra, M. T. D., Munawir, M., & Yuniarti, A. R. (2023). BELAJAR PEMROGRAMAN LANJUT DENGAN C++.
####  Wahyuni, Z. (2023, February 27). Makalah Dasar-dasar pemograman Komputer.
