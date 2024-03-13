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
![Screenshot (23)]()
![Screenshot (22)]()

#### Output:
![Guided 3 Output](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/2aca387b-d93c-458a-a458-16edc99ef1ed)
![Guided 3 Full](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/066cfd2d-bd5c-404e-8c90-5fd220a53a14)

Kode diatas digunakan untuk medeklarasi array nilai dengan nilai elemen bertipe integer dan mencetak masing masing dari integer tersebut ke layar output dan menggunakan function cout untuk mengeksekusinya.

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>

using namespace std;

// Fungsi untuk memfaktorialkan suatu bilangan
int factorial(int Bilangan) {
    if (Bilangan == 0 || Bilangan == 1)
        return 1;
    else
        return Bilangan * factorial(Bilangan - 1);
}

int main() {
    int Bilangan;

    cout << "Masukkan suatu bilangan: ";
    cin >> Bilangan;

    // Untuk menghitung faktorial dari sebuah bilangan
    cout << "Bilangan Faktorial dari " << Bilangan << " adalah: " << factorial(Bilangan) << endl;

    return 0;
}

```
#### Output:
![Unguided 1 Output](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/7f4fb009-fc8d-43b2-b528-3fb82a579a1c)

#### Full code Screenshot:
![Unguided 1 Full](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/a70cacb9-d465-4d01-99e4-8d2cc33ad0df)

Kode diatas digunakan untuk mencetak hasil faktorial dari bilangan yang diinputkan oleh peng-input ke layar output dengan menggunakan function cout dan factorial untuk mengeksekusi program tersebut.

Tipe data primitif adalah cara komputer dalam hal menyimpan data dasar seperti angka dan huruf. Tipe integer yang ditampung juga hanya tipe data tertentu yaitu tipe data integer untuk bilangan bulat, tipe data float untuk bilangan desimal, tipe data char untuk huruf, tipe data boolean untuk menentukan 2 hal yaitu true dan false. Jadi, tipe data primitif adalah tempat untuk menyimpan huruf dan angka di dalam komputer. [3]

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!]

Struct adalah struktur data yang memudahkan pengguna untuk menggabungkan beberapa jenis data yang berbeda. Mirip dengan fungsi class, struct bisa untuk menyimpan data, tetapi default anggotanya bersifat publik yang artinya semua anggotanya bisa diakses dari luar struct. Dengan menggunakan struct, program dengan mudah membuat dan memgelola kumpulan data tanpa adanya kompleksitas seperti pada fungsi class. Struct mempunyai kelebihan untuk menyimpan data simpel tanpa metode yang diutamakan dan memberikan fleksibilitas dalam membuat dan menyusun program.

Class berfungsi sebagai template untuk menciptakan objek. Class adalah struktur yang menggabungkan antara dara dan fungsi untuk memproses data dalam suatu pemrograman. Class dapat membuat objek yang memiliki sifat yang sama. Data dalam class menunjukan karakteristik objek, sedangkan fungsi berguna untuk berinteraksi dengan data tersebut. Dengan menggunakan fungsi class, program bisa jauh lebih dimengerti dan mudah diatur dan juga bisa untuk mengatasi kompleksitas program secara terstruktur.[2]

Contoh Untuk Fungsi Dari Struct
```C++
#include <iostream>
#include <string>

using namespace std;

// struct Mahasiswa
struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

// memasukkan data mahasiswa
void inputMahasiswa(Mahasiswa& mhs) {
    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin, mhs.nama);

    cout << "Masukkan NIM Mahasiswa: ";
    cin >> mhs.nim;

    cout << "Masukkan IPK Mahasiswa: ";
    cin >> mhs.ipk;
}

// menampilkan data mahasiswa
void tampilkanMahasiswa(const Mahasiswa& mhs) {
    cout << "\nData Mahasiswa\n";
    cout << "Nama: " << mhs.nama << endl;
    cout << "NIM: " << mhs.nim << endl;
    cout << "IPK: " << mhs.ipk << endl;
}

int main() {
    // Mendefinisikan variabel bertipe struct Mahasiswa
    Mahasiswa mahasiswa1;

    // Memanggil fungsi inputMahasiswa untuk mengisi data mahasiswa1
    inputMahasiswa(mahasiswa1);

    // Memanggil fungsi tampilkanMahasiswa untuk menampilkan data mahasiswa1
    tampilkanMahasiswa(mahasiswa1);

    return 0;
}
```
#### Output:
![Unguided 2 (1) Output](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/5a1c7586-6515-43ce-ae54-92625a97fac3)

#### Full code Screenshot:
![Unguided 2 (1) Full](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/06b8ddc3-984e-4db4-be3f-305c49c9a24e)

Kode diatas digunakan untuk membuat struktur data mahasiswa dari nama, nim, dan ipk dengan  menggunakan struct  dan kemudian ditampilkan ke layar output dengan menggunakan function cout untuk mengelola programnya.

Contoh Untuk Fungsi Dari Class
```C++
#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
private:
    string nama;
    int nim;
    float ipk;

public:
    void inputData() {
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, nama);

        cout << "Masukkan NIM Mahasiswa: ";
        cin >> nim;

        cout << "Masukkan IPK Mahasiswa: ";
        cin >> ipk;

        cin.ignore();
    }

    void MenampilkanData() {
        cout << "\nD Mahasiswa\n";
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << "IPK: " << ipk << endl;
    }
};

int main() {
    Mahasiswa mahasiswa1;

    // Memasukkan data mahasiswa
    mahasiswa1.inputData();

    // Menampilkan data mahasiswa
    mahasiswa1.MenampilkanData();

    return 0;
}
```
#### Output:
![Unguided 2 (2) Output](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/d7f69db0-a25a-4cb8-b0a3-f1e09450300d)

#### Full code Screenshot:
![Unguided 2 (2) Full](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/97581645-8191-4dd7-9cc2-6d77cc3cf14d)

Kode diatas digunakan untuk mendefinisikan sebuah class mahasiswa yang bersifat privat seperti nama, nim, dan ipk dan bersifat publik pada input data dan user diminta untuk menginputkan datanya dan di layar output sistem langsung menunjukan data yang diinput oleh user.

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!]

```C++
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Fungsi untuk menampilkan jenis motor berdasarkan plat nomor
void tampilkanJenisMotor(const map<string, string>& dataMotor, const string& platNomor) {
    auto it = dataMotor.find(platNomor);
    
    if (it != dataMotor.end()) {
        cout << "Jenis motor untuk plat nomor " << platNomor << ": " << it->second << endl;
    } else {
        cout << "Plat nomor " << platNomor << " tidak ditemukan." << endl;
    }
}

int main() {
    // Membuat map untuk menyimpan data plat nomor dan jenis motor
    map<string, string> dataMotor;

    // Mengisi data plat nomor dan jenis motor
    dataMotor["Honda"] = "R 7782 GA";
    dataMotor["Suzuki"] = "K 7574 TY";
    dataMotor["Yamaha"] = "H 6548 UW";

    // Meminta input plat nomor dari pengguna
    string MerkMotor;
    cout << "Masukkan jenis motor: ";
    cin >> MerkMotor;

    // Menampilkan jenis motor berdasarkan plat nomor
    tampilkanJenisMotor(dataMotor, MerkMotor);

    return 0;
}
```
#### Output:
![Unguided 3 Output](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/f7f7fb3e-95fc-40ff-8654-5884c5a9fb67)

#### Full code Screenshot:
![Unguided 3 Full](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/ddaab45c-79ac-40b8-b04f-51df02a7977d)

Kode diatas digunakan untuk mencari plat nomor dengan cara menginputkan merk motor yang dicari oleh user dan di layar output memunculkan hasil dari yang diinputkan oleh user berupa plat nomor.

Array dan map memiliki beberapa perbedaan , seperti :
1. Dari segi ukuran , ukuran array biasanya tetap dan jika ingin menyimpan banyak data ukuran array harus di ubah atau disesuaikan secara manual. Sedangkan map , ukuran map bersifat dinamis dan dapat diubah, ditambah, dan dihapus dan pada awal deklarasinya tidak perlu ditentukan untuk ukurannya.
2. Dari Tipe data nya, Array merupakan struktur data untuk menyimpan elemen data dengan tipe yang sama dalam satu linier. Sedangkan map adalah struktur data untuk menyimpan pasangan kunci dan nilai. Kunci dan nilaipyn bisa dari tipe data yang berbeda.
3. Dari Indeksnya, Array menggunakan indeks berbasis angka numerik mulai dari 0. Sedangkan map menggunakan data yang tidak terurut dan data diidentifikasi melalui kunci yang memiliki tipe data yang berbeda.

Singkatnya, Array cocok untuk urutan data dengan indeks numerik dan map cocok untuk penugasan data dengan kunci yang dapat berupa tipe data apapun atau tipe data yang berbeda.[2]

## Kesimpulan
Materi tipe data ini berisi beberapa data yang dapat di olah di dalam komputer seperti integer, float, char, dan lain lain. Tipe data abstrak berisi bahasan tentang konsep yang lebih tinggi, fokusnya adalah pada presentasi data dan operasi yang dapat dijalankan tanpa memperdulikan implementasi internal. Tipe data koleksi ini berisi tentang mengeksplorasi struktur data yang menyimpan beberapa elemen, seperti array, vector, dan map ini berguna juga untuk mengakses data dengan lebih cepat.

Dari materi tipe data ini, pembelajaran yang didapat adalah pemahaman tentang berbagai tipe data yang dilakukan dan dapat digunakan dalam pemrograman, dan juga kegunaan dari tipe data abstrak dan koleksi yang lebih efisien dalam penggunaannya. Menguasai beberapa tipe data bisa lebih mudah untuk membuat suatu program dan memperluas kemampuan dalam memprogram dan mendata secara cepat.

## Referensi
#### [1] Pratama, M. A. (2020, March 29). STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++. 
#### [2] Putra, M. T. D., Munawir, M., & Yuniarti, A. R. (2023). BELAJAR PEMROGRAMAN LANJUT DENGAN C++.
#### [3] Pratama, Yogga. "Jenis-jenis tipe data."
