#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> n;

    // Menginisialisasi array dengan ukuran n
    int arr[n];

    // Meminta pengguna memasukkan elemen array
    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Menghitung nilai maksimum, minimum, dan rata-rata
    int max = arr[0];
    int min = arr[0];
    int sum = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
        sum += arr[i];
    }

    double average = static_cast<double>(sum) / n;

    // Menampilkan hasil
    cout << "Nilai maksimum: " << max << endl;
    cout << "Nilai minimum: " << min << endl;
    cout << "Nilai rata-rata: " << average << endl;

    return 0;
}
