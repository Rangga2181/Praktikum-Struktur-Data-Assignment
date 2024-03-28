#include <iostream>
#include <conio.h>

using namespace std;

struct Node
{
    string nama;
    int nim;
    Node *next;
};

Node *head = NULL;

void tambahDepan()
{
    Node *baru = new Node;
    cout << "Masukkan nama: ";
    cin >> baru->nama;
    cout << "Masukkan NIM: ";
    cin >> baru->nim;
    baru->next = head;
    head = baru;
}

void tambahBelakang()
{
    Node *baru = new Node;
    cout << "Masukkan nama: ";
    cin >> baru->nama;
    cout << "Masukkan NIM: ";
    cin >> baru->nim;
    baru->next = NULL;
    if (head == NULL)
    {
        head = baru;
    }
    else
    {
        Node *bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void tambahTengah()
{
    Node *baru = new Node;
    cout << "Masukkan nama: ";
    cin >> baru->nama;
    cout << "Masukkan NIM: ";
    cin >> baru->nim;
    int pos;
    cout << "Masukkan posisi: ";
    cin >> pos;
    if (pos == 1)
    {
        tambahDepan();
    }
    else
    {
        Node *bantu = head;
        for (int i = 1; i < pos - 1; i++)
        {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void ubahDepan()
{
    if (head == NULL)
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        string namaBaru;
        int nimBaru;
        cout << "Masukkan nama baru: ";
        cin >> namaBaru;
        cout << "Masukkan NIM baru: ";
        cin >> nimBaru;
        head->nama = namaBaru;
        head->nim = nimBaru;
    }
}

void ubahBelakang()
{
    if (head == NULL)
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        Node *bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        string namaBaru;
        int nimBaru;
        cout << "Masukkan nama baru: ";
        cin >> namaBaru;
        cout << "Masukkan NIM baru: ";
        cin >> nimBaru;
        bantu->nama = namaBaru;
        bantu->nim = nimBaru;
    }
}

void ubahTengah()
{
    if (head == NULL)
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        int pos;
        cout << "Masukkan posisi: ";
        cin >> pos;
        if (pos == 1)
        {
            ubahDepan();
        }
        else
        {
            Node *bantu = head;
            for (int i = 1; i < pos; i++)
            {
                bantu = bantu->next;
            }
            string namaBaru;
            int nimBaru;
            cout << "Masukkan nama baru: ";
            cin >> namaBaru;
            cout << "Masukkan NIM baru: ";
            cin >> nimBaru;
            bantu->nama = namaBaru;
            bantu->nim = nimBaru;
        }
    }
}

void hapusDepan()
{
    if (head == NULL)
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        Node *hapus = head;
        head = head->next;
        delete hapus;
    }
}

void hapusBelakang()
{
    if (head == NULL)
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        Node *bantu = head;
        while (bantu->next->next != NULL)
        {
            bantu = bantu->next;
        }
        Node *hapus = bantu->next;
        bantu->next = NULL;
        delete hapus;
    }
}

void hapusTengah()
{
    if (head == NULL)
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        int pos;
        cout << "Masukkan posisi: ";
        cin >> pos;
        if (pos == 1)
        {
            hapusDepan();
        }
        else
        {
            Node *bantu = head;
            for (int i = 1; i < pos - 1; i++)
            {
                if (bantu->next == NULL)
                {
                    cout << "Posisi tidak ditemukan!" << endl;
                    return;
                }
                bantu = bantu->next;
            }
            Node *hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
        }
    }
}

int main()
{
    int pilihan;

    do
    {
        cout << "\nMenu Data Mahasiswa:" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            tambahTengah();
            break;
        case 4:
            ubahDepan();
            break;
        case 5:
            ubahBelakang();
            break;
        case 6:
            ubahTengah();
            break;
        case 7:
            hapusDepan();
            break;
        case 8:
            hapusBelakang();
            break;
        case 9:
            hapusTengah();
            break;
        case 10:
            tampilData();
            break;
        case 0:
            cout << "Terima kasih telah menggunakan program!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
