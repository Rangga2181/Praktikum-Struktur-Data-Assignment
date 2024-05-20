//Rangga Pradarrell Fathi
//2311102200
#include <iostream>
using namespace std;

int main()
{
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]); // Ukuran array
    int target = 4;                         // Nilai yang dicari
    int jumlah = 0;                         // Inisialisasi jumlah kemunculan target

    // Sequential Search
    for (int i = 0; i < n; i++)
    {
        if (data[i] == target)
        {
            jumlah++;
        }
    }

    cout << "Jumlah angka " << target << " yang muncul adalah " << jumlah << endl;

    return 0;
}