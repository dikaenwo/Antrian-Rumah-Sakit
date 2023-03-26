#include <iostream>
#define MAX 5
using namespace std;
void enqueue();
void Tampil();
void Panggil();
bool Full();
bool Kosong();
void Clear();
int top, ttl = 0;
int count_panggil = 1;
int pilihan;
string nama[MAX];

int main()
{
queue:
    system("cls");
    cout << "============================" << endl;
    cout << "= ANTRIAN RUMAH SAKIT PDIP =" << endl;
    cout << "=  Jl. Jiwaku Membanteng   =" << endl;
    cout << "============================" << endl;

    cout << endl;
    cout << "1.Tambah Antrian\n2.Panggil Antrian\n3.Lihat Antrian\n4.Clear\n5.Total Pengunjung\n6.Exit\n";
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
    case 1:
        system("cls");
        enqueue();
        cout << "Press Any Key To Back Menu" << endl;
        getchar();
        goto queue;
        break;
    case 2:
        system("cls");
        Panggil();
        cout << "Press Any Key To Back Menu" << endl;
        getchar();
        goto queue;
        break;
    case 3:
        system("cls");
        Tampil();
        cout << "Press Any Key To Back Menu" << endl;
        getchar();
        goto queue;
        break;
    case 4:
        system("cls");
        Clear();
        cout << "Press Any Key To Back Menu" << endl;
        getchar();
        goto queue;
        break;
    case 5:
        system("cls");
        cout << "============================" << endl;
        cout << "Total Pengunjung " << ttl << " Orang \n";
        cout << "============================" << endl;
        cout << "Press Any Key To Back Menu" << endl;
        getchar();
        goto queue;
        break;
    case 6:
        cout << "Keluar Dari Program....." << endl;
        break;
    default:
        cout << "Masukkan Pilihan (1/2/3/4/5)";
        cout << "Press Any Key To Back Menu" << endl;
        goto queue;
        getchar();
        goto queue;
        break;
    }
}

bool Full()
{
    if (top >= MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Kosong()
{
    if (top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue()
{

    if (!Full())
    {
        cout << "Masukkan Data : ";
        getline(cin, nama[top]);
        top++;
        ttl++;
    }
    else
    {
        cout << "Antrian Penuh" << endl;
    }
}

void Tampil()
{
    cout << "===== DAFTAR ANTRIAN =====" << endl;

    if (!Kosong())
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << i + 1 << ". " << nama[i] << endl;
        }
    }
    else
    {
        cout << "Antrian Kosong" << endl;
    }
    cout << "=========================" << endl;
}

void Panggil()
{

    if (!Kosong())
    {

        for (int j = 0; j < 1; j++)
        {
            cout << "==================================================" << endl;
            cout << "Antrian dengan Nomor " << count_panggil << " " << nama[j] << " Silahkan Masuk" << endl;
            cout << "==================================================" << endl;
        }
        count_panggil++;
        for (int i = 0; i < top - 1; i++)
        {
            nama[i] = nama[i + 1];
        }
        top--;
    }
    else
    {
        cout << "Antrian Kosong" << endl;
    }
}

void Clear()
{
    if (!Kosong())
    {
        top = 0;
    }
}
