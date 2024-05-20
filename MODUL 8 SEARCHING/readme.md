 # <h1 align="center">Laporan Praktikum Modul 8 - SEARCHING</h1>
<p align="center">Rangga Pradarrell Fathi</p>
  <P align="center">2311102200</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### SEARCHING



### Operasi utama pada queue meliputi:



### Queue dapat diimplementasikan dengan beberapa cara, antara lain:

## Menggunakan Array:


## Menggunakan Linked List:


## Beberapa operasi utama pada kelas Queue meliputi:


### Implementasi Queue dengan prioritas dapat menggunakan struktur data seperti heap atau binary search tree. Queue memiliki berbagai aplikasi dalam pemrograman, seperti:


   
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
