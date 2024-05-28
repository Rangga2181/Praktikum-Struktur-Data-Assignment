#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int rangga_2311102200;
    cout << "Masukkan jumlah kota: ";
    cin >> rangga_2311102200;

    // Inisialisasi matriks jarak dengan nilai maksimum
    const int MAX_VAL = numeric_limits<int>::max();
    int jarak[rangga_2311102200][rangga_2311102200];
    for (int i = 0; i < rangga_2311102200; i++)
    {
        for (int j = 0; j < rangga_2311102200; j++)
        {
            jarak[i][j] = MAX_VAL;
        }
    }

    // Masukkan jarak antara setiap pasangan kota
    for (int i = 0; i < rangga_2311102200; i++)
    {
        for (int j = i + 1; j < rangga_2311102200; j++)
        {
            int dist;
            cout << "Masukkan jarak antara kota " << i + 1 << " dan " << j + 1 << ": ";
            cin >> dist;
            jarak[i][j] = jarak[j][i] = dist;
        }
    }

    // Hitung jarak terpendek antara dua kota
    int kotaAwal, kotaTujuan;
    cout << "Masukkan nomor kota awal: ";
    cin >> kotaAwal;
    cout << "Masukkan nomor kota tujuan: ";
    cin >> kotaTujuan;

    int jarak_terpendek = jarak[kotaAwal - 1][kotaTujuan - 1];
    if (jarak_terpendek == MAX_VAL)
    {
        cout << "Tidak ada jalur langsung antara kota " << kotaAwal << " dan " << kotaTujuan << "." << endl;
    }
    else
    {
        cout << "Jarak terpendek antara kota " << kotaAwal << " dan " << kotaTujuan << " adalah " << jarak_terpendek << "." << endl;
    }

    return 0;
}