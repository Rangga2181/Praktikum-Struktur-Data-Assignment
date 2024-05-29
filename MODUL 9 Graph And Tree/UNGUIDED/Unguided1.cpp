//Rangga Pradarrell Fathi
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int maksimaldat = 10; // Maksimal banyak data yang dapat ditampung pada variabel maksimaldat untuk struct Graph

struct Graph
{
    string rangga_2311102200[maksimaldat];       // Banyaknya data string yang dapat disimpan dalam string sesuai dengan kapasitas maksimaldat
    int adjacencyMatrix[maksimaldat][maksimaldat]; // Menggunakan array 2 dimensi, dengan ukuran maksimal sesuai maksimaldat
    int no_kota;                               // Variabel yang digunakan untuk menyimpan jumlah kota dalam graph
};

void printMatrix(const Graph &graph)
{
    cout << setw(10) << " ";
    for (int i = 0; i < graph.no_kota; i++)
    {
        cout << setw(10) << graph.rangga_2311102200[i];
    }
    cout << endl;

    for (int i = 0; i < graph.no_kota; i++)
    {
        cout << setw(10) << graph.rangga_2311102200[i];
        for (int j = 0; j < graph.no_kota; j++)
        {
            cout << setw(10) << graph.adjacencyMatrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    Graph graph;
    cout << "\n---++ (Jarak Antar Kota) ++---" << endl;
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> graph.no_kota;
    cin.ignore(); // Mengabaikan karakter newline yang tersisa

    for (int i = 0; i < graph.no_kota; i++)
    {
        cout << "Simpul " << i + 1 << ": ";
        getline(cin, graph.rangga_2311102200[i]);
    }

    cout << "Silahkan masukan bobot antar simpul" << endl;
    for (int i = 0; i < graph.no_kota; i++)
    {
        for (int j = 0; j < graph.no_kota; j++)
        {
            cout << graph.rangga_2311102200[i] << " ---> " << graph.rangga_2311102200[j] << " = ";
            cin >> graph.adjacencyMatrix[i][j];
        }
    }

    cout << endl;
    printMatrix(graph);

    return 0;
}