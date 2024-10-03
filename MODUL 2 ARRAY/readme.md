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
![Tel-U](https://github.com/user-attachments/assets/168cc08d-afd1-4dd3-86ba-12e98bb81264)



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

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![Screenshot (24)](https://github.com/Rangga2181/Praktikum-Struktur-Data-Assignment/assets/162523255/0528111d-3e62-4915-b9c9-f6cfeaeac27e)

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
