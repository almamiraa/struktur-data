#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode* next;
};

TNode* head, * tail;

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (tail == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void insertDepan(int databaru) {
    TNode* baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if (isEmpty() == 1) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        baru->next = head;
        head = baru;
    }
    cout << "Data berhasil ditambah\n";
}

void hapusDepan() {
    TNode* hapus;
    int d;
    if (isEmpty() == 0) {
        if (head != tail) {
            hapus = head;
            d = hapus->data;
            head = head->next;
            delete hapus;
        }
        else {
            d = tail->data;
            head = tail = NULL; 
        }
        cout << d << " Data berhasil terhapus\n";
    }
    else cout << "Masih kosong\n";
}

void show() {
    TNode* bantu;
    bantu = head;
    if (isEmpty() == 0) {
        while (bantu != NULL) {
            cout << bantu->data << " \n";
            bantu = bantu->next;
        }
    }
    else cout << "Data Masih Kosong\n";
}

void clear() {
    TNode* bantu = head;
    while (bantu != nullptr) {
        TNode* hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = nullptr;
    cout << "Clear" << endl;
}

int main() {
    int pil, databaru;
    do {
        cout << "Menu:\n";
        cout << "1. Masukan Data Depan\n";
        cout << "2. Hapus Data Depan\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Clear\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pil;

        switch (pil) {
        case 1: {
            cout << "Masukan Data = ";
            cin >> databaru;
            insertDepan(databaru);
            break;
        }
        case 2: {
            hapusDepan();
            break;
        }
        case 3: {
            show();
            break;
        }
        case 4: {
            clear();
            break;
        }
        case 5: {
            return 0;
        }
        default: {
            cout << "\n Pilihan yang anda pilih tidak tersedia";
        }
        }
    } while (pil != 5);

    return 0;
}
