#include <iostream>
#include <map>
#include <string>
using namespace std;
struct Mahasiswa
{
    string nama;
    string jurusan;

    Mahasiswa(string nama, string jurusan)
    {
        this->nama = nama;
        this->jurusan = jurusan;
    }
};

int main()
{
    // Membuat map yang menyimpan data mahasiswa dengan key berupa integer (NIM)
    map<int, Mahasiswa> daftarMahasiswa;

    // Menambahkan data mahasiswa ke dalam map
    daftarMahasiswa[12345] = Mahasiswa("Andi", "Teknik Informatika");
    daftarMahasiswa[67890] = Mahasiswa("Budi", "Sistem Informasi");
    daftarMahasiswa[90123] = Mahasiswa("Caca", "Elektroteknik");

    // Mengakses data mahasiswa berdasarkan NIM
    int nim = 12345;
    if (daftarMahasiswa.count(nim))
    {
        Mahasiswa mahasiswa = daftarMahasiswa[nim];
        cout << "Nama: " << mahasiswa.nama << endl;
        cout << "Jurusan: " << mahasiswa.jurusan << endl;
    }
    else
    {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    // Menampilkan semua data mahasiswa
    for (const auto &[nim, mahasiswa] : daftarMahasiswa)
    {
        cout << "NIM: " << nim << endl;
        cout << "Nama: " << mahasiswa.nama << endl;
        cout << "Jurusan: " << mahasiswa.jurusan << endl;
        cout << endl;
    }

    return 0;
}
