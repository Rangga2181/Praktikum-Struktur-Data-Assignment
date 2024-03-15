#include <iostream>

using namespace std;

int main()
{
    int x, y, z;

    // Meminta pengguna memasukkan ukuran array tiga dimensi
    cout << "Masukkan ukuran array tiga dimensi (x y z): ";
    cin >> x >> y >> z;

    // Menginisialisasi array tiga dimensi dengan ukuran yang dimasukkan oleh pengguna
    int arr[x][y][z];

    // Meminta pengguna memasukkan nilai-nilai elemen array
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            for (int k = 0; k < z; ++k)
            {
                cout << "arr[" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    // Menampilkan array tiga dimensi yang telah dimasukkan oleh pengguna
    cout << "Array tiga dimensi yang dimasukkan:\n";
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            for (int k = 0; k < z; ++k)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl; // Setiap baris baru untuk setiap dimensi y
        }
        cout << endl; // Setiap lapisan baru untuk setiap dimensi x
    }

    return 0;
}
