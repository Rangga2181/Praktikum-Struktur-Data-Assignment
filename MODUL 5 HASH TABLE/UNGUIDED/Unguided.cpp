#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int main()
{
    // Buat hash table untuk menyimpan data mahasiswa
    unordered_map<string, double> student_records;

    // a. Setiap mahasiswa memiliki NIM dan nilai
    string nim;
    double score;

    // b. Program memiliki tampilan pilihan menu berisi poin C
    char choice;
    do
    {
        cout << "Menu:\n";
        cout << "a. Tambah data mahasiswa\n";
        cout << "b. Tampilkan data mahasiswa\n";
        cout << "c. Ubah data mahasiswa\n";
        cout << "d. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
            // c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
            // mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan nilai: ";
            cin >> score;
            student_records[nim] = score;
            cout << "Data mahasiswa berhasil ditambahkan.\n";
            break;
        case 'b':
            // Tampilkan semua data mahasiswa
            if (student_records.empty())
            {
                cout << "Belum ada data mahasiswa.\n";
            }
            else
            {
                cout << "Data mahasiswa:\n";
                for (const auto &[nim, score] : student_records)
                {
                    cout << "NIM: " << nim << ", Nilai: " << score << "\n";
                }
            }
            break;

        case 'c':
            // Ubah data mahasiswa berdasarkan NIM
            cout << "Masukkan NIM: ";
            cin >> nim;
            if (student_records.count(nim) > 0)
            {
                cout << "Masukkan nilai baru: ";
                cin >> score;
                student_records[nim] = score;
                cout << "Data mahasiswa berhasil diubah.\n";
            }
            else
            {
                cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
            }
            break;
        case 'd':
            cout << "Terima kasih, program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
            break;
        }
    } while (choice != 'd');

    return 0;
}