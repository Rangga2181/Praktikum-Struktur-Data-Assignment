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
