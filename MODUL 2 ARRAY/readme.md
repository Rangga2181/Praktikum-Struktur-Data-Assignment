# <h1 align="center">Laporan Praktikum Modul Array</h1>

<p align="center">Rangga Pradarrell Fathi</p>
<p align="center">2311102200 / IF-11-E</p>

## Dasar Teori
Array dalam bahasa C++ adalah sebuah struktur data yang digunakan untuk menyimpan sekumpulan data dengan tipe data yang sama. Setiap elemen array dapat diakses menggunakan indeks yang unik. Array sangat berguna dalam banyak kasus, seperti menyimpan daftar nilai, daftar nama, atau data lainnya.

Berikut adalah penjelasan singkat tentang array dalam C++:
 

#### 1. Deklarasi Array 
Deklarasi array  adalah proses mendefinisikan sebuah variabel sebagai array dan menentukan ukuran atau panjang array tersebut. 


#### 2. Inisialisasi Array
Inisialisasi array dalam C++ adalah proses memberikan nilai awal pada elemen-elemen array saat deklarasi atau setelah deklarasi.
 

#### 3. Mengakses Elemen Array
Mengakses elemen array berarti mengambil atau memodifikasi nilai dari elemen tertentu dalam array tersebut. Untuk mengakses elemen array, Anda perlu menggunakan indeks yang sesuai dengan posisi elemen dalam array. Indeks array dalam C++ dimulai dari 0.

#### 4. Ukuran Array
Ukuran array mengacu pada jumlah maksimum elemen yang dapat disimpan dalam array tersebut. Ukuran array harus ditentukan saat deklarasi dan tidak dapat diubah selama runtime (waktu program berjalan).

## Guided 

### 1. [Program Input Array Tiga Dimensi]
```C++
#include <iostream>
using namespace std;

// program input array 3 dimensi
int main()
{
    // deklarasi array
    int arr[2][3][3];
    // input elemen
    for (int x = 0; x < 2; x++)
    {

        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array [" << x << "][" << y << "][" << z << "]=";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "]=" << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

```
#### Output:
![Guided 1 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/40e0b9d5-09f4-41ac-80e2-3d5696fbe691)
![Guided 1 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/59e6b0b9-71a0-463d-b9ec-e8922a32a13d)

Kode di atas, pengguna dapat memasukkan 18 elemen (2x3x3) untuk array 3 dimensi tersebut. Kemudian, program akan mencetak seluruh elemen array dalam dua format yang berbeda: format yang mudah dibaca dengan indeks yang jelas, dan format yang lebih sederhana hanya dengan menampilkan nilai elemen saja. 

### 2. [Program Mencari Nilai Maksimal pada Array ]
```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << "angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
#### Output:
![Guided 2 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/3ac95a16-e44a-403f-a965-728b86f1781b)
![Guided 2 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/ce677a27-351e-4095-a3f0-f7e938ca1d81)

Program ini adalah sebuah program C++ yang berfungsi untuk mencari nilai maksimum dari sebuah array dan menampilkan nilai maksimum serta lokasinya di dalam array tersebut. 
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

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

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

Tipe data primitif adalah cara komputer dalam hal menyimpan data dasar seperti angka dan huruf. Tipe integer yang ditampung juga hanya tipe data tertentu yaitu tipe data integer untuk bilangan bulat, tipe data float untuk bilangan desimal, tipe data char untuk huruf, tipe data boolean untuk menentukan 2 hal yaitu true dan false. Jadi, tipe data primitif adalah tempat untuk menyimpan huruf dan angka di dalam komputer. 

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

Struct adalah struktur data yang memudahkan pengguna untuk menggabungkan beberapa jenis data yang berbeda. Mirip dengan fungsi class, struct bisa untuk menyimpan data, tetapi default anggotanya bersifat publik yang artinya semua anggotanya bisa diakses dari luar struct. Dengan menggunakan struct, program dengan mudah membuat dan memgelola kumpulan data tanpa adanya kompleksitas seperti pada fungsi class. Struct mempunyai kelebihan untuk menyimpan data simpel tanpa metode yang diutamakan dan memberikan fleksibilitas dalam membuat dan menyusun program.

Class berfungsi sebagai template untuk menciptakan objek. Class adalah struktur yang menggabungkan antara dara dan fungsi untuk memproses data dalam suatu pemrograman. Class dapat membuat objek yang memiliki sifat yang sama. Data dalam class menunjukan karakteristik objek, sedangkan fungsi berguna untuk berinteraksi dengan data tersebut. Dengan menggunakan fungsi class, program bisa jauh lebih dimengerti dan mudah diatur dan juga bisa untuk mengatasi kompleksitas program secara terstruktur.

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

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

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

Singkatnya, Array cocok untuk urutan data dengan indeks numerik dan map cocok untuk penugasan data dengan kunci yang dapat berupa tipe data apapun atau tipe data yang berbeda.

## Kesimpulan
Tipe data ini berisi beberapa data yang dapat diproses di komputer, seperti integer, float, char, dan lain-lain. Tipe data abstrak berisi pembahasan konsep yang lebih tinggi, fokus pada penyajian data, dan operasi  dapat dilakukan tanpa memperhatikan implementasi internal. Tipe data koleksi  ini menggunakan eksplorasi struktur data yang menyimpan banyak elemen, seperti array, vektor, dan map. Ini juga berguna untuk akses data yang lebih cepat.
 
Dari materi tipe data ini, pembelajaran yang didapat adalah paham tentang berbagai tipe data yang dapat digunakan dalam pemrograman, dan juga kegunaan dari tipe data abstrak maupun koleksi lebih efisien dalam penggunaannya. Menguasai beberapa tipe data bisa lebih mudah untuk membuat suatu program dan memperluas kemampuan dalam memprogram dan mendata secara cepat.

## Referensi
####  Pratama, M. A. (2020, March 29). STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++. 
####  "The C++ Programming Language" oleh Bjarne Stroustrup (pencipta C++).
####  Wahyuni, Z. (2023, February 27). Makalah Dasar-dasar pemograman Komputer.
