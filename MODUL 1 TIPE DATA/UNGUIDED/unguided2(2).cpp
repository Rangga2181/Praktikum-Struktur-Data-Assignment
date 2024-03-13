#include <iostream>
using namespace std;
struct Buku
{
    string judul;
    string penulis;
    int tahunTerbit;
    int halaman;

    void cetakInfo()
    {
        cout << "Judul: " << judul << endl;
        cout << "Penulis: " << penulis << endl;
        cout << "Tahun Terbit: " << tahunTerbit << endl;
        cout << "Halaman: " << halaman << endl;
    }
};

int main()
{
    // Menginisialisasi variabel bertipe Buku
    Buku buku1;
    buku1.judul = "Laskar Pendekar";
    buku1.penulis = "Andreas Wibowo";
    buku1.tahunTerbit = 2008;
    buku1.halaman = 329;

    // Menampilkan informasi buku
    buku1.cetakInfo();

    // Menginisialisasi variabel bertipe Buku dengan konstruktor
    Buku buku2{"Sang Pemimpi", "Andreas Wibowo", 2009, 264};

    // Menampilkan informasi buku
    buku2.cetakInfo();

    return 0;
}
