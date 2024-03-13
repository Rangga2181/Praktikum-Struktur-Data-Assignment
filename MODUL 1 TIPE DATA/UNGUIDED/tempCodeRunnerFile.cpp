#include <iostream>
#include <string>
using namespace std;

class Mahasiswa
{
private:
    string nama;
    int nim;
    string jurusan;

public:
    // Constructor
    Mahasiswa(string _nama, int _nim, string _jurusan)
    {
        nama = _nama;
        nim = _nim;
        jurusan = _jurusan;
    }

    // Destructor
    ~Mahasiswa()
    {
        cout << "Objek Mahasiswa " << nama << " Aktif" << endl;
    }

    // Method untuk menampilkan informasi mahasiswa
    void tampilkanInfo()
    {
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << "Jurusan: " << jurusan << endl;
    }
};

int main()
{
    // Membuat objek mahasiswa
    Mahasiswa mhs1("Rangga Pradarrell", 200, "Teknik Informatika");
    Mahasiswa mhs2("Wahyu Hidayat", 180, "Teknik Informatika");

    // Memanggil method untuk menampilkan informasi mahasiswa
    cout << "Informasi Mahasiswa 1:" << endl;
    mhs1.tampilkanInfo();

    cout << endl;

    cout << "Informasi Mahasiswa 2:" << endl;
    mhs2.tampilkanInfo();

    return 0;
}
