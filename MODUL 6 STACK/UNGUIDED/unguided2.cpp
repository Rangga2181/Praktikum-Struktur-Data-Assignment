// Rangga Pradarrell Fathi
// 2311102200
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseString(string str)
{
    stack<char> charStack;
    string reversed = "";

    // Mendorong setiap huruf ke dalam stack
    for (char c : str)
    {
        charStack.push(c);
    }

    // Mengeluarkan huruf dari stack untuk membentuk string terbalik
    while (!charStack.empty())
    {
        reversed += charStack.top();
        charStack.pop();
    }

    return reversed;
}

int main()
{
    string input;
    cout << "Masukkan Kata: ";
    getline(cin, input);

    string reversed = reverseString(input);
    cout << "Data: " << reversed << endl;

    return 0;
}