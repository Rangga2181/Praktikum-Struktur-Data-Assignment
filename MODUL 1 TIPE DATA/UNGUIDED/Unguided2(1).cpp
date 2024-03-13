#include <iostream>
using namespace std;

class Kalkulator
{
private:
    double hasil;

public:
    Kalkulator()
    {
        hasil = 0.0;
    }

    void tambah(double bilangan1, double bilangan2)
    {
        hasil = bilangan1 + bilangan2;
    }

    void kurang(double bilangan1, double bilangan2)
    {
        hasil = bilangan1 - bilangan2;
    }

    void kali(double bilangan1, double bilangan2)
    {
        hasil = bilangan1 * bilangan2;
    }

    void bagi(double bilangan1, double bilangan2)
    {
        if (bilangan2 == 0)
        {
            cout << "Error: Pembagian dengan 0 tidak diizinkan." << endl;
            return;
        }

        hasil = bilangan1 / bilangan2;
    }

    void cetakHasil()
    {
        cout << "Hasil: " << hasil << endl;
    }
};

int main()
{
    Kalkulator kalkulator;

    // Contoh penggunaan operasi kalkulator
    kalkulator.tambah(5.0, 3.0);
    kalkulator.cetakHasil();

    kalkulator.kurang(10.0, 2.0);
    kalkulator.cetakHasil();

    kalkulator.kali(4.0, 5.0);
    kalkulator.cetakHasil();

    kalkulator.bagi(8.0, 2.0);
    kalkulator.cetakHasil();

    kalkulator.bagi(12.0, 0.0); // Menampilkan pesan error

    return 0;
}
