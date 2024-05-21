 # <h1 align="center">Laporan Praktikum Modul 8 - SEARCHING</h1>
<p align="center">Rangga Pradarrell Fathi</p>
  <P align="center">2311102200</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### SEARCHING
Searching atau pencarian data adalah salah satu operasi fundamental dalam pemrograman yang melibatkan pencarian elemen atau nilai tertentu di dalam struktur data seperti array, vektor, atau daftar tertaut (linked list). 

 


Binary search hanya dapat diterapkan pada struktur data yang sudah terurut (sorted), seperti array atau linked list yang terurut. Prinsip kerjanya adalah membagi struktur data menjadi dua bagian dan mencari elemen yang dicari di dalam salah satu bagian tersebut. Proses ini diulangi secara rekursif hingga elemen ditemukan atau seluruh elemen sudah diperiksa.
Langkah-langkah binary search:

Tentukan batas bawah (low) dan batas atas (high) dari struktur data yang akan diperiksa.
Hitung nilai tengah (mid) dari batas bawah dan batas atas.
Bandingkan elemen pada posisi tengah dengan elemen yang dicari.
Jika elemen pada posisi tengah sama dengan elemen yang dicari, kembalikan posisi tengah.
Jika elemen pada posisi tengah lebih kecil dari elemen yang dicari, ubah batas bawah menjadi posisi tengah + 1.
Jika elemen pada posisi tengah lebih besar dari elemen yang dicari, ubah batas atas menjadi posisi tengah - 1.
Ulangi langkah 2-6 hingga elemen yang dicari ditemukan atau batas bawah melebihi batas atas (elemen tidak ditemukan).
Jika elemen tidak ditemukan, kembalikan nilai yang menunjukkan bahwa elemen tidak ada dalam struktur data.

Kompleksitas waktu binary search dalam kasus rata-rata dan terbaik adalah O(log n), di mana n adalah jumlah elemen dalam struktur data terurut. Ini jauh lebih efisien dibandingkan sequential search, terutama untuk struktur data besar.

###  Sequential Search (Pencarian Sekuensial)
Sequential search atau pencarian linear adalah algoritma pencarian paling sederhana. Prinsip kerjanya adalah memeriksa setiap elemen dalam struktur data (seperti array atau linked list) satu per satu secara berurutan hingga elemen yang dicari ditemukan atau seluruh elemen sudah diperiksa.


Langkah-langkah sequential search:

-Mulai dari elemen pertama dalam struktur data.

-Bandingkan elemen saat ini dengan elemen yang dicari.

-Jika elemen saat ini sama dengan elemen yang dicari, kembalikan indeks atau posisi elemen tersebut.

-Jika elemen saat ini tidak sama dengan elemen yang dicari, pindah ke elemen berikutnya dalam struktur data.

-Ulangi langkah 2-4 hingga elemen yang dicari ditemukan atau seluruh elemen sudah diperiksa.

-Jika elemen tidak ditemukan, kembalikan nilai yang menunjukkan bahwa elemen tidak ada dalam struktur data.


Kompleksitas waktu sequential search dalam kasus terburuk adalah O(n), di mana n adalah jumlah elemen dalam struktur data. Ini berarti dalam kasus terburuk, algoritma harus memeriksa setiap elemen dalam struktur data.


### Binary Search (Pencarian Biner)
Binary search hanya dapat diterapkan pada struktur data yang sudah terurut (sorted), seperti array atau linked list yang terurut. Prinsip kerjanya adalah membagi struktur data menjadi dua bagian dan mencari elemen yang dicari di dalam salah satu bagian tersebut. Proses ini diulangi secara rekursif hingga elemen ditemukan atau seluruh elemen sudah diperiksa.

Langkah-langkah binary search:

-Tentukan batas bawah (low) dan batas atas (high) dari struktur data yang akan diperiksa.

-Hitung nilai tengah (mid) dari batas bawah dan batas atas.

-Bandingkan elemen pada posisi tengah dengan elemen yang dicari.

-Jika elemen pada posisi tengah sama dengan elemen yang dicari, kembalikan posisi tengah.

-Jika elemen pada posisi tengah lebih kecil dari elemen yang dicari, ubah batas bawah menjadi posisi tengah + 1.

-Jika elemen pada posisi tengah lebih besar dari elemen yang dicari, ubah batas atas menjadi posisi tengah - 1.

-Ulangi langkah 2-6 hingga elemen yang dicari ditemukan atau batas bawah melebihi batas atas (elemen tidak ditemukan).

-Jika elemen tidak ditemukan, kembalikan nilai yang menunjukkan bahwa elemen tidak ada dalam struktur data.


Kompleksitas waktu binary search dalam kasus rata-rata dan terbaik adalah O(log n), di mana n adalah jumlah elemen dalam struktur data terurut. Ini jauh lebih efisien dibandingkan sequential search, terutama untuk struktur data besar.



## Guided 

### Latihan 1

```C++
#include <iostream>
using namespace std;

int arr[]={1,2,3,4,5,6,7,8,9,10,15,14};
int cari = 15;
bool ketemu = false;
int panjangArray = sizeof(arr)/sizeof(arr[0]);
int i;

int main()
{
    for (i = 0; i < panjangArray; i++){
        if(arr[i] == cari) {
            ketemu = true;
            break;
        } else {
            i++;
        }
    }

    cout << "Panjang Array : " << panjangArray <<endl;
    cout << cari << " Terdapat pada index ke- " << i;
}
```

#### Output :


### Latihan 2

```C++
#include <iostream>
#include <iomanip>
using namespace std;
// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort(int arr[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void binary_search(int arr[], int n, int target)
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target)
        {
            b_flag = 1;
            break;
        }
        else if (arr[tengah] < target)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag == 1)
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}
int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
}
```

#### Output :




## Unguided 


### 1) Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!



```C++
// Rangga Pradarrell Fathi
// 2311102200
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int binarySearch(string kalimat, char huruf)
{
    sort(kalimat.begin(), kalimat.end()); // Mengurutkan kalimat terlebih dahulu

    int left = 0;
    int right = kalimat.length() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (kalimat[mid] == huruf)
        {
            return mid; // Jika huruf ditemukan, kembalikan indeksnya
        }
        else if (kalimat[mid] < huruf)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Jika huruf tidak ditemukan, kembalikan -1
}

int main()
{
    string kalimat;
    char huruf;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    int indeks = binarySearch(kalimat, huruf);

    if (indeks == -1)
    {
        cout << "Huruf " << huruf << " tidak ditemukan dalam kalimat." << endl;
    }
    else
    {
        cout << "Huruf " << huruf << " ditemukan pada indeks " << indeks << " dalam kalimat." << endl;
    }

    return 0;
}
```

#### Hasil Output


### 2) Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
//Rangga Pradarrell Fathi
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int jumlahVokal = 0;
    char vokal[] = {'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};
    int ukuranVokal = sizeof(vokal) / sizeof(vokal[0]);

    // Menggunakan Sequential Search
    for (char huruf : kalimat)
    {
        for (int i = 0; i < ukuranVokal; i++)
        {
            if (huruf == vokal[i])
            {
                jumlahVokal++;
                break;
            }
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat: " << jumlahVokal << endl;

    return 0;
}
```

#### Hasil Output




### 3) Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!
```C++
//Rangga Pradarrell Fathi
//2311102200
#include <iostream>
using namespace std;

int main()
{
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]); // Ukuran array
    int target = 4;                         // Nilai yang dicari
    int jumlah = 0;                         // Inisialisasi jumlah kemunculan target

    // Sequential Search
    for (int i = 0; i < n; i++)
    {
        if (data[i] == target)
        {
            jumlah++;
        }
    }

    cout << "Jumlah angka " << target << " yang muncul adalah " << jumlah << endl;

    return 0;
}
```

#### Hasil Output





## Kesimpulan


## Referensi
[1] Putra, Muhammad Taufik Dwi, Munawir Munawir, and Ana Rahma Yuniarti. "BELAJAR PEMROGRAMAN LANJUT DENGAN C++." (2023).

[2] Riyanto, Joko, et al. "ALGORITMA DAN PEMROGRAMAN 2." (2022).
