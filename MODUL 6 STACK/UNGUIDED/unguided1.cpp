// Rangga Pradarrell Fathi
// 2311102200
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100; // Ukuran maksimal stack

class Stack
{
private:
    char arr[MAX_SIZE]; // Array untuk menyimpan elemen stack
    int top;            // Indeks elemen atas
    int count;          // Jumlah elemen dalam stack

public:
    Stack()
    {
        top = -1; // Mengecek stack kosong
        count = 0;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == MAX_SIZE;
    }

    void push(char x)
    {
        if (isFull())
        {
            cout << "Error: Stack penuh" << endl;
            return;
        }
        arr[++top] = x;
        count++;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Error: Stack kosong" << endl;
            return '\0';
        }
        count--;
        return arr[top--];
    }
};

bool isPalindrome(string str)
{
    Stack s;
    int len = str.length();

    // Mendorong huruf ke dalam stack
    for (int i = 0; i < len / 2; i++)
    {
        s.push(str[i]);
    }

    // Memeriksa panjang ganjil dan lewati huruf tengah
    int start = len % 2 == 0 ? len / 2 : (len / 2) + 1;

    // Keluarkan huruf dari stack dan bandingkan dengan sisa huruf
    for (int i = start; i < len; i++)
    {
        if (s.pop() != str[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string input;
    cout << "Masukkan sebuah kata: ";
    getline(cin, input);

    if (isPalindrome(input))
    {
        cout << "Kata yang dimasukkan adalah palindrom." << endl;
    }
    else
    {
        cout << "Kata yang dimasukkan bukan palindrom." << endl;
    }

    return 0;
}