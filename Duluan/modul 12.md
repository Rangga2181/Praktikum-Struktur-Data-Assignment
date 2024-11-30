<p align="center">
  <strong>LAPORAN PRAKTIKUM</strong>
  <br>
  <strong>ALGORITMA DAN PEMROGRAMAN 2</strong>
  <br>
</p>

<br>

<p align="center">
  <strong>MODUL XII & XIII</strong>
  <br>
  <strong>Pengurutan Data</strong>
  <br>
</p>

<br>

<p align="center">
  <img src="https://github.com/user-attachments/assets/296eb3c2-bd6b-401f-8256-3661150ec39e" alt="Logo" width="200"/>
</p>

<br>

<p align="center">
  <strong>Disusun Oleh :</strong>
  <br>
 Rangga Pradarrell Fathi
  <br>
  2311102200
  <br>
  IF-11-05
</p>

<br>

<p align="center">
  <strong>Dosen Pengampu :</strong><br>
  Arif Amrulloh, S.Kom., M.Kom.
</p>

<br>

<p align="center">
  <strong>PROGRAM STUDI S1 TEKNIK INFORMATIKA</strong>
  <br>
  <strong>FAKULTAS INFORMATIKA</strong>
  <br>
  <strong>TELKOM UNIVERSITY PURWOKERTO</strong>
  <br>
  <strong>2024</strong>
</p>


## <strong> Dasar Teori </strong>

<strong><h2>Definisi</h2></strong>
[1] Pengurutan data (sorting) adalah proses penyusunan elemen-elemen data dalam urutan tertentu, seperti urutan menaik (ascending) atau menurun (descending). Proses pengurutan ini digunakan dalam banyak algoritma komputer, baik itu untuk pencarian, perbandingan, maupun pengolahan data yang lebih efisien. Dalam pemrograman bahasa Go, pengurutan data dapat dilakukan menggunakan berbagai algoritma yang masing-masing memiliki karakteristik yang berbeda dalam hal kompleksitas waktu dan ruang.

### <strong> Prinsip algoritma Selection Sort
[2] Selection Sort adalah salah satu algoritma pengurutan sederhana yang bekerja dengan cara memilih elemen terkecil (atau terbesar, tergantung urutan yang diinginkan) dalam suatu array dan menempatkannya di posisi yang benar, kemudian mengulangi proses ini untuk elemen-elemen yang tersisa.

#### Prinsip Kerja Selection Sort
- Iterasi 1: Cari elemen terkecil dalam array dan tukar dengan elemen pertama.
- Iterasi 2: Cari elemen terkecil di bagian array yang tersisa dan tukar dengan elemen kedua.
- Iterasi 3: Cari elemen terkecil di bagian array yang tersisa dan tukar dengan elemen ketiga.
- Proses ini terus berulang hingga seluruh array terurut.

#### Langkah-Langkah Selection Sort
- Mulai dari elemen pertama dalam array, tentukan indeks elemen terkecil dalam array (dari indeks yang sedang diproses hingga akhir array).
- Tukar elemen terkecil tersebut dengan elemen di indeks yang sedang diproses.
- Pindah ke elemen berikutnya dan ulangi proses ini hingga array terurut.

### <strong> Prinsip algoritma Insertion Sort
[3] Insertion Sort adalah algoritma pengurutan yang lebih efisien dibandingkan Selection Sort untuk array kecil atau array yang sudah sebagian terurut. Prinsip dasar dari Insertion Sort adalah membangun array yang terurut satu elemen pada satu waktu dengan cara memasukkan elemen baru ke posisi yang benar dalam urutan yang sudah terurut sebelumnya.

#### Prinsip Kerja Insertion Sort
- Mulai dari elemen kedua (karena elemen pertama sudah dianggap terurut).
- Ambil elemen yang akan dimasukkan ke dalam urutan yang sudah terurut, dan bandingkan dengan elemen-elemen sebelumnya.
- Geser elemen-elemen yang lebih besar satu posisi ke kanan untuk memberi ruang bagi elemen yang baru.
- Tempatkan elemen tersebut pada posisi yang tepat.
- Ulangi proses ini untuk elemen-elemen berikutnya sampai array terurut.

#### Langkah-Langkah Insertion Sort
- Mulai dari elemen kedua (karena elemen pertama dianggap sudah terurut).
- Ambil elemen tersebut dan bandingkan dengan elemen-elemen yang lebih kecil di sebelah kirinya.
- Geser elemen-elemen yang lebih besar ke kanan.
- Tempatkan elemen tersebut pada posisi yang benar di array.
- Ulangi proses ini untuk setiap elemen dari kiri ke kanan hingga array terurut.


# <strong> Guided </strong>
## Guided - 1
### Study Case
**1. Hercules, preman terkenal seantero ibukota, memiliki kerabat di banyak daerah. Tentunya Hercules sangat suka mengunjungi semua kerabatnya itu.
Diberikan masukan nomor rumah dari semua kerabatnya di suatu daerah, buatlah program rumahkerabat yang akan menyusun nomor-nomor rumah kerabatnya secara terurut membesar menggunakan algoritma selection sort.
Masukan dimulai dengan sebuah integer 𝒏 (0 < n < 1000), banyaknya daerah kerabat Hercules tinggal. Isi 𝒏 baris berikutnya selalu dimulai dengan sebuah integer 𝒎 (0 < m < 1000000) yang menyatakan banyaknya rumah kerabat di daerah tersebut, diikuti dengan rangkaian bilangan bulat positif, nomor rumah para kerabat.
Keluaran terdiri dari n baris, yaitu rangkaian rumah kerabatnya terurut membesar di masing- masing daerah.**
![image](https://github.com/user-attachments/assets/ffb2fb28-b16b-46b5-9c9f-641d4c6eaa83)


### Source Code
```go
// Rangga Pradarrell Fathi
// 2311102200
// IF-11-05
package main

import (
	"fmt"
)

// Fungsi untuk mengurutkan array menggunakan selection sort
func selectionSort(arr []int, n int) {
	for i := 0; i < n-1; i++ {
		idxMin := i
		for j := i + 1; j < n; j++ {
			if arr[j] < arr[idxMin] {
				idxMin = j
			}
		}
		arr[i], arr[idxMin] = arr[idxMin], arr[i]
	}
}

func main() {
	var n int
	fmt.Print("Masukkan jumlah daerah kerabat (n) : ")
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var m int
		fmt.Printf("\nMasukkan jumlah nomor rumah kerabat untuk daerah %d : ", i+1)
		fmt.Scan(&m)

		arr := make([]int, m)
		fmt.Printf("Masukkan %d nomor rumah kerabat : ", m)
		for j := 0; j < m; j++ {
			fmt.Scan(&arr[j])
		}
		selectionSort(arr, m)

		// Tampilkan nomor rumah terurut
		fmt.Printf("Nomor rumah terurut untuk daerah %d : ", i+1)
		for _, num := range arr {
			fmt.Printf("%d ", num)
		}
		fmt.Println()
	}
}
```

### Screenshot Output
![image](https://github.com/user-attachments/assets/7a87061f-3c3c-424c-bc72-648997fcf1d2)

### Deskripsi Program
Program di atas adalah sebuah aplikasi yang mengurutkan nomor rumah kerabat di beberapa daerah menggunakan algoritma selection sort.
**Algoritma Program**
1. Input jumlah daerah kerabat (n):
- Minta pengguna untuk memasukkan jumlah daerah kerabat yang akan diproses (jumlah daerah yang memiliki nomor rumah kerabat).
2. Untuk setiap daerah:
- Lakukan iterasi untuk setiap daerah kerabat (mulai dari 1 hingga n).
- Minta pengguna untuk memasukkan jumlah nomor rumah kerabat untuk setiap daerah.
3. Input nomor rumah untuk setiap daerah:
- Untuk setiap daerah, buat array dengan panjang sesuai jumlah nomor rumah (m).
- Minta pengguna untuk memasukkan nomor rumah untuk daerah tersebut satu per satu dan simpan dalam array.
4. Urutkan nomor rumah menggunakan selection sort:
- Panggil fungsi selectionSort() untuk mengurutkan nomor rumah dalam array sesuai dengan algoritma selection sort.
5. Tampilkan hasil urutan nomor rumah:
- Setelah array terurut, tampilkan nomor rumah yang telah diurutkan untuk setiap daerah, masing-masing dipisahkan sesuai dengan daerah yang dimasukkan.

**Alur Program**
1. Program meminta input jumlah daerah:
- Program meminta pengguna untuk memasukkan jumlah daerah kerabat yang akan diproses (n).
2. Program meminta input jumlah nomor rumah per daerah:
- Untuk setiap daerah (dari 1 hingga n), program meminta pengguna untuk memasukkan jumlah nomor rumah untuk daerah tersebut (m).
3. Program meminta input nomor rumah:
- Program membuat array untuk menyimpan nomor rumah dan meminta pengguna untuk memasukkan nomor rumah kerabat untuk daerah tersebut.
4. Program mengurutkan nomor rumah:
- Program memanggil fungsi selectionSort() untuk mengurutkan nomor rumah dalam array berdasarkan algoritma selection sort.
5. Program menampilkan nomor rumah yang terurut:
- Setelah array diurutkan, program menampilkan nomor rumah yang sudah terurut untuk setiap daerah secara terpisah.

## Guided - 2
### Study Case
**2.Buatlah sebuah program yang digunakan untuk membaca data integer seperti contoh yang diberikan di bawah ini, kemudian diurutkan (menggunakan metoda insertion sort), dan memeriksa apakah data yang terurut berjarak sama terhadap data sebelumnya.
Masukan terdiri dari sekumpulan bilangan bulat yang diakhiri oleh bilangan negatif. Hanya bilangan non negatif saja yang disimpan ke dalam array.
Keluaran terdiri dari dua baris. Baris pertama adalah isi dari array setelah dilakukan pengurutan, sedangkan baris kedua adalah status jarak setiap bilangan yang ada di dalam array. "Data berjarak x" atau "data berjarak tidak tetap".**
![image](https://github.com/user-attachments/assets/867a101d-fb1e-4dc3-8403-39dc6e59084e)

### Source Code
```go
// Rangga Pradarrell Fathi
// 2311102200
// IF-11-05
package main

import (
	"fmt"
)

// Fungsi untuk mengurutkan array menggunakan Insertion Sort
func insertionSort(arr []int, n int) {
	for i := 1; i < n; i++ {
		key := arr[i]
		j := i - 1

		// Geser elemen yang lebih besar dari key ke kanan
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}
}

// Fungsi untuk memeriksa apakah selisih elemen array tetap
func isConstantDifference(arr []int, n int) (bool, int) {
	if n < 2 {
		return true, 0
	}

	difference := arr[1] - arr[0]
	for i := 1; i < n-1; i++ {
		if arr[i+1]-arr[i] != difference {
			return false, 0
		}
	}
	return true, difference
}

func main() {
	var arr []int
	var num int

	// Input data hingga bilangan negatif ditemukan
	fmt.Print("Masukkan data integer (Akhiri dengan bilangan negatif) : ")
	for {
		fmt.Scan(&num)
		if num < 0 {
			break
		}
		arr = append(arr, num)
	}

	n := len(arr)

	// Urutkan array menggunakan Insertion Sort
	insertionSort(arr, n)

	// Periksa apakah selisih elemen tetap
	isConstant, difference := isConstantDifference(arr, n)

	// Tampilkan hasil pengurutan
	fmt.Print("Array setelah diurutkan : ")
	for _, val := range arr {
		fmt.Printf("%d ", val)
	}
	fmt.Println()

	// Tampilkan status jarak
	fmt.Print("Data berjarak")
	if isConstant {
		fmt.Printf(" %d", difference)
	}
	fmt.Println()
}
```

### Screenshot Output
![image](https://github.com/user-attachments/assets/8770ce34-851f-469a-afb3-810a331c50a5)

### Deskripsi Program
Program ini menerima input sejumlah angka integer dari pengguna, mengurutkan angka-angka tersebut menggunakan algoritma insertion sort, kemudian memeriksa apakah angka-angka yang diurutkan memiliki selisih tetap antar elemen (apakah membentuk deret aritmatika). 
**Algoritma Program**
1. Input data:
- Program meminta pengguna untuk memasukkan serangkaian angka integer. Input diakhiri dengan memasukkan bilangan negatif. Angka-angka yang dimasukkan akan disimpan dalam array.
2. Pengurutan array menggunakan Insertion Sort:
- Program menggunakan algoritma insertion sort untuk mengurutkan array. Algoritma ini bekerja dengan cara memeriksa elemen-elemen array satu per satu, dan memindahkan elemen yang lebih - 
- besar dari elemen kunci ke posisi yang lebih tinggi, hingga seluruh array terurut.
3. Memeriksa apakah selisih antar elemen tetap:
- Setelah array diurutkan, program memeriksa apakah selisih antara elemen-elemen berturut-turut dalam array tetap (membentuk deret aritmatika). Jika ya, program menyimpan nilai selisih tersebut.
4. Menampilkan array yang telah diurutkan:
- Program menampilkan array setelah diurutkan menggunakan algoritma insertion sort.
5. Menampilkan status jarak:
- Program memeriksa apakah selisih antar elemen array tetap (konstan). Jika ya, program menampilkan nilai selisih tersebut; jika tidak, program hanya menampilkan informasi bahwa data tidak berjarak konstan.

**Alur Program**
1. Input data integer:
- Program meminta pengguna untuk memasukkan serangkaian angka integer dan menyimpannya dalam array arr. Input berakhir jika pengguna memasukkan angka negatif.
2. Panggil fungsi insertionSort:
- Fungsi insertionSort dipanggil untuk mengurutkan array yang telah diisi dengan data integer.
3. Panggil fungsi isConstantDifference:
- Setelah array terurut, fungsi isConstantDifference dipanggil untuk memeriksa apakah selisih antar elemen array tetap atau tidak. Fungsi ini juga mengembalikan nilai selisih jika data berjarak tetap.
4. Tampilkan array terurut:
- Program menampilkan array yang telah diurutkan setelah pemrosesan insertion sort selesai.
5. Tampilkan status jarak:
- Program memeriksa dan menampilkan apakah selisih antar elemen tetap konstan atau tidak. Jika tetap konstan, nilai selisih akan ditampilkan.




# <strong> Unguided </strong>
## Unguided - 1
### Study Case
**1. Belakangan diketahui ternyata Hercules itu tidak berani menyeberang jalan, maka selalu diusahakan agar hanya menyeberang jalan sesedikit mungkin, hanya diujung jalan. Karena nomor rumah sisi kiri jalan selalu ganjil dan sisi kanan jalan selalu genap, maka buatlah program kerabat dekat yang akan menampilkan nomor rumah mulai dari normor yang ganjil lebih dulu terurut membesar dan kemudian menampilkan nomor rumah dengan nomor genap terurut mengecil.**

_Masukan masih persis sama seperti sebelumnya._

_Keluaran terdiri dari n baris, yaitu rangkaian rumah kerabatnya terurut membesar untuk nomor ganjil, diikuti dengan terurut mengecil untuk nomor genap, di masing masing daerah,_

#### Source Code
```go
//Rangga Pradarrell Fathi
//2311102200
//IF-11-05
package main

import "fmt"

// Fungsi untuk mengurutkan array menggunakan selection sort dengan parameter urutan naik atau turun
func urutkanDenganSelection(arr []int, urutNaik bool) {
    panjang := len(arr)
    for i := 0; i < panjang-1; i++ {
        indeksTerpilih := i
        for j := i + 1; j < panjang; j++ {
            if (urutNaik && arr[j] < arr[indeksTerpilih]) || (!urutNaik && arr[j] > arr[indeksTerpilih]) {
                indeksTerpilih = j
            }
        }
        arr[i], arr[indeksTerpilih] = arr[indeksTerpilih], arr[i]
    }
}

func main() {
    var totalDaerah int
    // Meminta input jumlah daerah kerabat
    fmt.Print("Masukkan jumlah daerah kerabat: ")
    fmt.Scan(&totalDaerah)

    // Proses input dan pengurutan untuk setiap daerah
    for i := 0; i < totalDaerah; i++ {
        var totalRumah int
        // Input jumlah rumah untuk daerah tertentu
        fmt.Printf("\nMasukkan jumlah rumah di daerah %d: ", i+1)
        fmt.Scan(&totalRumah)

        nomorRumah := make([]int, totalRumah)
        // Input nomor rumah untuk daerah tersebut
        fmt.Printf("Masukkan %d nomor rumah: ", totalRumah)
        for j := 0; j < totalRumah; j++ {
            fmt.Scan(&nomorRumah[j])
        }

        // Pisahkan nomor rumah ganjil dan genap
        var rumahGanjil, rumahGenap []int
        for _, nomor := range nomorRumah {
            if nomor%2 == 0 {
                rumahGenap = append(rumahGenap, nomor)
            } else {
                rumahGanjil = append(rumahGanjil, nomor)
            }
        }

        // Urutkan rumah ganjil secara menaik
        urutkanDenganSelection(rumahGanjil, true)

        // Urutkan rumah genap secara menurun
        urutkanDenganSelection(rumahGenap, false)

        // Tampilkan hasil nomor rumah yang terurut
        fmt.Printf("\nNomor rumah terurut untuk daerah %d:\n", i+1)

        // Tampilkan nomor rumah ganjil yang sudah terurut
        for _, nomor := range rumahGanjil {
            fmt.Printf("%d ", nomor)
        }

        // Tampilkan nomor rumah genap yang sudah terurut
        for _, nomor := range rumahGenap {
            fmt.Printf("%d ", nomor)
        }

        fmt.Println()
    }
}

```
#### Screenshoot Output
![image](https://github.com/user-attachments/assets/5c82ab36-3db5-4a2f-bd6a-18d7fcbf90f6)


#### Deskripsi Program
Program ini digunakan untuk mengurutkan nomor rumah di beberapa daerah berdasarkan dua kategori: rumah dengan nomor ganjil dan rumah dengan nomor genap. Program ini menerima input berupa jumlah daerah dan jumlah rumah di setiap daerah. Setiap daerah akan memiliki sejumlah nomor rumah yang akan dipisahkan menjadi dua kategori: nomor rumah ganjil dan nomor rumah genap. Kemudian, program akan mengurutkan nomor rumah ganjil secara menaik dan nomor rumah genap secara menurun, menggunakan algoritma Selection Sort. Hasil akhirnya adalah daftar nomor rumah yang sudah terurut untuk setiap daerah.

##### Algoritma:

- Input jumlah daerah: Program meminta input jumlah daerah yang ingin diproses.
- Input jumlah rumah untuk setiap daerah: Untuk setiap daerah, program akan meminta input jumlah rumah dan kemudian meminta nomor rumah untuk setiap rumah tersebut.
- Pisahkan nomor rumah ganjil dan genap: Setelah menerima daftar nomor rumah, program memisahkan nomor rumah menjadi dua kategori: rumah ganjil dan rumah genap.
- Pengurutan dengan Selection Sort: Program mengurutkan nomor rumah ganjil secara menaik (ascending) menggunakan algoritma Selection Sort, Program juga mengurutkan nomor rumah genap secara menurun (descending) menggunakan algoritma yang sama.
- Menampilkan hasil urutan: Setelah mengurutkan nomor rumah, program akan menampilkan nomor rumah yang sudah terurut dalam urutan yang diinginkan untuk setiap daerah.

##### Alur Program:
- Input jumlah daerah: Pengguna diminta untuk memasukkan jumlah daerah yang ingin diproses. Program akan menyimpan nilai ini dalam variabel totalDaerah.
- Loop untuk setiap daerah: Program masuk ke dalam sebuah loop yang iterasi sebanyak totalDaerah. Setiap iterasi akan memproses satu daerah.
- Input jumlah rumah dan nomor rumah: Untuk setiap daerah, program meminta input jumlah rumah (totalRumah) dan kemudian meminta input nomor rumah satu per satu dan menyimpannya dalam array nomorRumah.
- Pisahkan nomor rumah ganjil dan genap: Program memisahkan nomor rumah yang ganjil dan genap ke dalam dua array terpisah: rumahGanjil dan rumahGenap.
- Pengurutan menggunakan Selection Sort: Array rumahGanjil diurutkan secara menaik (ascending) dan array rumahGenap diurutkan secara menurun (descending) dengan menggunakan fungsi urutkanDenganSelection.
- Tampilkan hasil urutan: Setelah pengurutan, program menampilkan nomor rumah yang sudah terurut, dimulai dengan nomor rumah ganjil yang diurutkan secara menaik, diikuti dengan nomor rumah genap yang diurutkan secara menurun.
- Ulangi untuk daerah selanjutnya: Program mengulang langkah-langkah di atas untuk setiap daerah sampai selesai.

## Unguided - 2
### Study Case
**2. Kompetisi pemrograman yang baru saja berlalu diikuti oleh 17 tim dari berbagai perguruan tinggi ternama. Dalam kompetisi tersebut, setiap tim berlomba untuk menyelesaikan sebanyak mungkin problem yang diberikan, Dari 13 problem yang diberikan, ada satu problem yang menarik, Problem tersebut mudah dipahami, hampir semua tim mencoba untuk menyelesaikannya, tetapi hanya 3 tim yang berhasil. Apa sih problemnya?**

_"Median adalah nilai tengah dari suatu koleksi data yang sudah terurut. Jika jumlah data genap,  maka nilai median adalah rerata dari kedua nilai tengahnya. Pada problem ini, semua data merupakan bilangan bulat positif, dan karenanya rerata nilai tengah dibulatkan ke bawah." Buatlah program median yang mencetak nilai median terhadap seluruh data yang sudah terbaca, jika data yang dibaca saat itu adalah 0._

_Masukan berbentuk rangkaian bilangan bulat. Masukan tidak akan berisi lebih dari 1000000 data, tidak termasuk bilangan 0. Data O merupakan tanda bahwa median harus dicetak, tidak termasuk data yang dicari mediannya. Data masukan diakhiri dengan bilangan bulat -5313._

_Keluaran adalah median yang diminta, satu data per baris._

#### Source Code
```go
package main

import "fmt"

// Fungsi untuk mengurutkan angka dalam array menggunakan metode selection sort
func urutkanArray(arr []int) {
    panjang := len(arr)
    for i := 0; i < panjang-1; i++ {
        // Menentukan elemen terkecil di subarray yang belum terurut
        indeksTerkecil := i
        for j := i + 1; j < panjang; j++ {
            if arr[j] < arr[indeksTerkecil] {
                indeksTerkecil = j
            }
        }
        // Tukar posisi elemen terkecil dengan elemen pertama yang belum terurut
        arr[i], arr[indeksTerkecil] = arr[indeksTerkecil], arr[i]
    }
}

// Fungsi untuk menghitung dan mengembalikan nilai median dari array yang sudah terurut
func hitungMedian(arr []int) int {
    totalElemen := len(arr)
    if totalElemen%2 == 1 {
        // Jika jumlah elemen ganjil, ambil elemen tengah
        return arr[totalElemen/2]
    }
    // Jika jumlah elemen genap, rata-rata dua elemen tengah
    return (arr[(totalElemen/2)-1] + arr[totalElemen/2]) / 2
}

func main() {
    var angkaList []int
    fmt.Print("Masukkan angka-angka (akhir dengan -5313): ")

    // Loop untuk menerima input angka
    for {
        var angka int
        _, err := fmt.Scan(&angka)

        // Cek jika angka yang dimasukkan adalah -5313 untuk keluar
        if angka == -5313 {
            break
        }

        // Jika terjadi error dalam input, keluar dari loop
        if err != nil {
            fmt.Println("Terjadi kesalahan input.")
            break
        }

        // Jika angka adalah 0, urutkan dan tampilkan median
        if angka == 0 {
            urutkanArray(angkaList)
            fmt.Printf("Median: %d\n", hitungMedian(angkaList))
        } else {
            // Menambahkan angka ke list
            angkaList = append(angkaList, angka)
        }
    }
}
```
#### Screenshoot Output
![image](https://github.com/user-attachments/assets/d3e2716f-cbbb-4675-87da-7a4f8d54891d)

#### Deskripsi Program
Program ini dirancang untuk menerima input angka-angka dari pengguna, menyimpannya dalam sebuah list, dan menghitung median setelah angka-angka tersebut diurutkan. Pengguna dapat memasukkan angka satu per satu. Program akan terus menerima input angka hingga pengguna memasukkan angka khusus -5313, yang menandakan berakhirnya input. Setiap kali pengguna memasukkan angka 0, program akan mengurutkan angka-angka yang telah dimasukkan sebelumnya menggunakan algoritma Selection Sort dan menampilkan nilai median dari angka-angka yang sudah terurut tersebut.

##### Algoritma
- Input Angka:Program menerima input angka satu per satu dari pengguna menggunakan fmt.Scan. Proses ini berlangsung terus-menerus hingga pengguna memasukkan angka -5313, yang menandakan akhir dari input.
- Penanganan Angka 0: Ketika pengguna memasukkan angka 0, program akan mengurutkan angka-angka yang telah dimasukkan sebelumnya menggunakan metode Selection Sort.
- Pengurutan dengan Selection Sort: Program akan mengurutkan angka-angka dalam array menggunakan metode Selection Sort. Algoritma ini bekerja dengan memilih elemen terkecil di subarray yang belum terurut dan menukarnya dengan elemen pertama yang belum terurut.
- Perhitungan Median: Setelah array diurutkan, program menghitung nilai median berdasarkan jumlah elemen dalam array yang sudah terurut. Jika jumlah elemen ganjil, median adalah elemen tengah. Jika jumlah elemen genap, median adalah rata-rata dari dua elemen tengah.
- Tampilan Hasil: Program menampilkan nilai median yang dihitung setelah pengurutan selesai dilakukan, dan menunggu input berikutnya hingga pengguna memasukkan angka -5313.

##### Alur Program:
- Inisialisasi: Program dimulai dengan mendeklarasikan sebuah list kosong angkaList untuk menampung angka-angka yang dimasukkan oleh pengguna.
- Loop Input: Program meminta pengguna untuk memasukkan angka dengan pesan "Masukkan angka-angka (akhir dengan -5313): ".
Program akan terus menerima input selama angka yang dimasukkan bukan -5313.
- Penanganan Angka 0: Jika pengguna memasukkan angka 0, program akan mengurutkan angka-angka yang telah dimasukkan (selain angka 0) menggunakan Selection Sort.
Setelah pengurutan, program akan menghitung nilai median dari angka yang sudah terurut dan menampilkannya.
- Penambahan Angka ke List: Jika angka yang dimasukkan bukan 0 atau -5313, program akan menambahkan angka tersebut ke dalam list angkaList.
- Akhir Input: Program berhenti menerima input jika pengguna memasukkan angka -5313, dan program selesai berjalan.

## Unguided - 3
### Study Case
**3. Sebuah program perpustakaan digunakan untuk mengelola data buku di dalam suatu perpustakaan. Misalnya terdefinisi struct dan array seperti berikut ini:**
```go
const nMax : integer = 7919
type Buku = <
  id, judul, penulis, penerbit : string
  eksemplar, tahun, rating : integer

type DaftarBuku = array [1..nMax) of Buku
Pustaka : Daftar Buku
nPustaka : integer
```

_Masukan terdiri dari beberapa baris. Baris pertama adalah bilangan bulat N yang menyatakan banyaknya data buku yang ada di dalam perpustakaan. N baris berikutnya, masing-masingnya adalah data buku sesuai dengan atribut atau field pada struct. Baris terakhir adalah bilangan bulat yang menyatakan rating buku yang akan dicari._

_Keluaran terdiri dari beberapa baris. Baris pertama adalah data buku terfavorit, baris kedua adalah lima judul buku dengan rating tertinggi, selanjutnya baris terakhir adalah data buku. yang dicari sesual rating yang diberikan pada masukan baris terakhir._

#### Source Code
```go
// Rangga Pradarrell Fathi
// 2311102200
// IF-11-05
package main

import "fmt"

const maxBooks = 7919

// Struktur Buku untuk menyimpan data buku
type Buku struct {
	kode, judul, penulis, penerbit string
	eksemplar, tahun, rating       int
}

// Array DaftarBuku untuk menyimpan buku-buku
type KoleksiBuku [maxBooks]Buku

// Fungsi untuk mendaftarkan buku ke koleksi
func tambahBuku(koleksi *KoleksiBuku, jumlah *int) {
	fmt.Print("Masukkan jumlah buku yang ingin didaftarkan: ")
	fmt.Scan(jumlah)

	for i := 0; i < *jumlah; i++ {
		fmt.Printf("\nMasukkan data buku ke-%d (kode, judul, penulis, penerbit, eksemplar, tahun, rating):\n", i+1)
		fmt.Scan(&koleksi[i].kode, &koleksi[i].judul, &koleksi[i].penulis, &koleksi[i].penerbit,
			&koleksi[i].eksemplar, &koleksi[i].tahun, &koleksi[i].rating)
	}
}

// Fungsi untuk mencetak buku dengan rating tertinggi
func bukuFavorit(koleksi KoleksiBuku, jumlah int) {
	if jumlah == 0 {
		fmt.Println("Tidak ada buku yang terdaftar.")
		return
	}

	favorit := koleksi[0]
	for i := 1; i < jumlah; i++ {
		if koleksi[i].rating > favorit.rating {
			favorit = koleksi[i]
		}
	}

	fmt.Println("\nBuku Favorit:")
	fmt.Printf("Judul: %s, Penulis: %s, Penerbit: %s, Tahun: %d, Rating: %d\n",
		favorit.judul, favorit.penulis, favorit.penerbit, favorit.tahun, favorit.rating)
}

// Fungsi untuk mengurutkan buku berdasarkan rating secara menurun
func urutkanBuku(koleksi *KoleksiBuku, jumlah int) {
	for i := 1; i < jumlah; i++ {
		buku := koleksi[i]
		j := i - 1

		for j >= 0 && koleksi[j].rating < buku.rating {
			koleksi[j+1] = koleksi[j]
			j--
		}
		koleksi[j+1] = buku
	}
}

// Fungsi untuk menampilkan 5 buku dengan rating tertinggi
func tampilkanTop5(koleksi KoleksiBuku, jumlah int) {
	fmt.Println("\n5 Buku Dengan Rating Tertinggi:")
	batas := 5
	if jumlah < 5 {
		batas = jumlah
	}

	for i := 0; i < batas; i++ {
		fmt.Printf("%d. %s (Rating: %d)\n", i+1, koleksi[i].judul, koleksi[i].rating)
	}
}

// Fungsi untuk mencari buku berdasarkan rating
func cariBukuByRating(koleksi KoleksiBuku, jumlah, rating int) {
	ditemukan := false
	fmt.Printf("\nMencari Buku dengan Rating %d:\n", rating)

	for i := 0; i < jumlah; i++ {
		if koleksi[i].rating == rating {
			ditemukan = true
			fmt.Printf("Judul: %s, Penulis: %s, Penerbit: %s, Tahun: %d, Eksemplar: %d, Rating: %d\n",
				koleksi[i].judul, koleksi[i].penulis, koleksi[i].penerbit,
				koleksi[i].tahun, koleksi[i].eksemplar, koleksi[i].rating)
		}
	}

	if !ditemukan {
		fmt.Println("Tidak ada buku dengan rating tersebut.")
	}
}

func main() {
	var koleksi KoleksiBuku
	var jumlahBuku, ratingPencarian int

	// Menambahkan buku ke dalam koleksi
	tambahBuku(&koleksi, &jumlahBuku)

	// Menampilkan buku dengan rating tertinggi
	bukuFavorit(koleksi, jumlahBuku)

	// Mengurutkan buku berdasarkan rating dan menampilkan hasilnya
	urutkanBuku(&koleksi, jumlahBuku)

	// Menampilkan 5 buku dengan rating tertinggi
	tampilkanTop5(koleksi, jumlahBuku)

	// Mencari buku berdasarkan rating
	fmt.Print("\nMasukkan rating yang ingin dicari: ")
	fmt.Scan(&ratingPencarian)
	cariBukuByRating(koleksi, jumlahBuku, ratingPencarian)
}
```
#### Screenshoot Output
![Screenshot 2024-11-30 103450](https://github.com/user-attachments/assets/42ecd742-7d3c-4a8f-9ac0-e1b1ce794023)


#### Deskripsi Program
Program ini digunakan untuk mengelola koleksi buku di sebuah perpustakaan atau tempat penyimpanan buku. Pengguna dapat menambahkan buku baru, mengurutkan buku berdasarkan rating secara menurun, menampilkan buku dengan rating tertinggi, serta mencari buku berdasarkan rating tertentu. Buku yang didaftarkan menyertakan data seperti kode, judul, penulis, penerbit, jumlah eksemplar, tahun terbit, dan rating. Program ini akan memberikan tampilan berupa daftar buku yang sudah diurutkan dan buku-buku dengan rating tertinggi sesuai permintaan pengguna.

##### Algoritma:
1. Menambah Buku:
- Pengguna memasukkan data buku yang ingin didaftarkan (kode, judul, penulis, penerbit, eksemplar, tahun, rating).
- Data buku disimpan dalam array KoleksiBuku yang memiliki kapasitas maksimal sebanyak 7919 buku.
2. Mencari Buku dengan Rating Tertinggi:
- Program memeriksa setiap buku di koleksi dan membandingkan ratingnya.
- Buku dengan rating tertinggi akan dicetak ke layar.
3. Mengurutkan Buku Berdasarkan Rating:
- Menggunakan algoritma Insertion Sort untuk mengurutkan koleksi buku berdasarkan rating secara menurun (rating terbesar di depan).
- Proses pengurutan dilakukan dengan membandingkan rating setiap buku dan menempatkan buku dengan rating lebih tinggi di urutan lebih depan.
4. Menampilkan 5 Buku dengan Rating Tertinggi:
- Setelah koleksi buku diurutkan, program menampilkan 5 buku pertama dengan rating tertinggi.
- Jika jumlah buku kurang dari 5, maka akan ditampilkan sebanyak jumlah buku yang ada.
5. Mencari Buku Berdasarkan Rating:
- Pengguna memasukkan rating yang ingin dicari.
- Program mencari buku yang memiliki rating tersebut dan menampilkan informasi buku yang ditemukan.

#####  Alur Program:
1. Inisialisasi Koleksi Buku:
- Program dimulai dengan mendeklarasikan variabel koleksi bertipe KoleksiBuku yang akan menyimpan data buku, serta variabel jumlahBuku untuk menyimpan jumlah buku yang telah didaftarkan.
2. Input Data Buku:
- Pengguna diminta untuk memasukkan jumlah buku yang akan didaftarkan.
- Setelah itu, program meminta input untuk setiap buku (kode, judul, penulis, penerbit, eksemplar, tahun, rating), yang kemudian disimpan dalam array koleksi.
3. Mencetak Buku dengan Rating Tertinggi:
- Setelah semua buku didaftarkan, program mencari buku dengan rating tertinggi dan menampilkannya ke layar.
4. Mengurutkan Buku Berdasarkan Rating:
- Program kemudian mengurutkan buku-buku berdasarkan rating secara menurun menggunakan Insertion Sort.
- Buku dengan rating tertinggi akan ditempatkan di bagian depan array.
5. Menampilkan 5 Buku dengan Rating Tertinggi:
- Setelah pengurutan selesai, program menampilkan 5 buku pertama dengan rating tertinggi.
- Program juga memberikan opsi untuk mencari buku berdasarkan rating tertentu yang dimasukkan oleh pengguna, dan menampilkan buku yang sesuai.

# <strong> Refrensi </strong>
[1] Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. (2009). "Introduction to Algorithms" (3rd Edition). MIT Press.
[2] Donald E. Knuth. (1998). "The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition). Addison-Wesley Professional.
[3] Jurnal: "A Comparative Study of Sorting Algorithms" - International Journal of Computer Applications
