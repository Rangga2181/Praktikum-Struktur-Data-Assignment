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
