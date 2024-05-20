//Rangga Pradarrell Fathi
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int jumlahVokal = 0;
    char vokal[] = {'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};
    int ukuranVokal = sizeof(vokal) / sizeof(vokal[0]);

    // Menggunakan Sequential Search
    for (char huruf : kalimat)
    {
        for (int i = 0; i < ukuranVokal; i++)
        {
            if (huruf == vokal[i])
            {
                jumlahVokal++;
                break;
            }
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat: " << jumlahVokal << endl;

    return 0;
}