<p align="center">
  <strong>LAPORAN PRAKTIKUM</strong>
  <br>
  <strong>ALGORITMA DAN PEMROGRAMAN 2</strong>
  <br>
</p>

<br>

<p align="center">
  <strong>MODUL XII</strong>
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
Pencarian nilai ekstrim adalah algoritma untuk menelusuri dan membandingkan setiap elemen dalam sebuah himpunan data guna menentukan elemen dengan nilai tertinggi (maksimum) atau nilai terendah (minimum).

### <strong> Prinsip algoritma pencarian nilai ekstrim adalah:
- Memulai dengan menetapkan elemen pertama sebagai nilai awal (sementara) untuk nilai maksimum atau minimum.
- Membandingkan setiap elemen berikutnya dengan nilai sementara.
- Memperbarui nilai maksimum atau minimum jika ditemukan elemen dengan nilai lebih tinggi (untuk maksimum) atau lebih rendah (untuk minimum).
  
### <strong> Implementasi:
Dalam pemrograman, pencarian nilai ekstrim sering kali menjadi dasar untuk membangun algoritma yang lebih kompleks, seperti sorting, optimasi, atau analisis data. Algoritma ini diimplementasikan menggunakan perulangan (loop) untuk memindai elemen-elemen dalam struktur data.


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


