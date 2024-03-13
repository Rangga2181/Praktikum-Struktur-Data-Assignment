#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Membuat map untuk menyimpan nama dan umur
    map<string, int> umur;

    // Menambahkan data ke dalam map
    umur["John"] = 25;
    umur["Jane"] = 30;
    umur["Doe"] = 20;

    // Mengakses nilai dalam map
    cout << "Umur John: " << umur["John"] << " tahun" << endl;
    cout << "Umur Jane: " << umur["Jane"] << " tahun" << endl;
    cout << "Umur Doe: " << umur["Doe"] << " tahun" << endl;

    // Menggunakan iterator untuk menampilkan semua pasangan kunci-nilai dalam map
    cout << "\nDaftar Nama dan Umur:\n";
    for (auto it = umur.begin(); it != umur.end(); ++it)
    {
        cout << it->first << ": " << it->second << " tahun\n";
    }

    return 0;
}
