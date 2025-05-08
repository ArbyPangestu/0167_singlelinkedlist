#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class singlelinkedlist
{
    Node *START;

public:
    singlelinkedlist()
    {
        START = NULL;
    }
    void addNode()
    {
        int nim;
        cout << "\nMasukan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodebaru = new Node;
        nodebaru->noMhs = nim;

        if (START == NULL || nim == START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodebaru->next = START;
            START = nodebaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodebaru->next = current;
        previous->next = nodebaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool Search(int nim, Node **Previous, Node **current)
    {
        *Previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *Previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!Search(nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList kosong\n";
        }
        else
        {
            cout << "\nData didalam list adalah:\n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    singlelinkedlist Mhs;
    int nim;
    char ch;
    while (1)
    {
        cout << endl
             << "menu";
        cout << endl
             << "1. menambah data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list" << endl;
        cout << "3. menampilkan semua data di dalam list" << endl;
        cout << "4. mencari data dalam list" << endl;
        cout << "5. keluar" << endl;
        cout << endl
             << "masukan pilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            Mhs.addNode();
        }
        break;

        case '2':
        {
            if (Mhs.listEmpty())
            {
                cout << endl
                     << "list kosong" << endl;
                break;
            }
            cout << endl
                 << "\nMasukan no mahasiswa yang akan dihapus : ";
            cin >> nim;
            if (Mhs.delNode(nim) == false)
                cout << endl
                     << "data tidak ditemukan" << endl;
            else
                cout << endl
                     << "data dengan nomor mahasiswa" << nim << " berhasil dihapus " << endl;
        }
        break;
        case '3':
        {
            Mhs.traverse();
        }
        break;
        case '4':
        {
            if (Mhs.listEmpty() == true)
            {
                cout << "\nList kosong\n";
                break;
            }
            Node *previous, *current;
            cout << endl
                 << "masukan no mahasiswa yang dicari : ";
            cin >> nim;
            if (Mhs.Search(nim, &previous, &current) == false)
                cout << endl
                     << "data tidak dittemukann" << endl;
            else
            {
                cout << endl
                     << "data ditemukan" << endl;
                cout << "\nNo Mahasiswa : " << current->noMhs << endl;
                cout << "\n";
            }
        }