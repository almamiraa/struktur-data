#include <iostream>
#include <string>

using namespace std;

// Maksimum jumlah mahasiswa yang dapat disimpan
const int max_mhs = 50;

struct Mahasiswa {
    string nama;
    int nrp; 
    int umur;
    bool jenis_kelamin; // (true = Laki-laki, false = Perempuan)
};


Mahasiswa dataMahasiswa[max_mhs];
int jmlh_mahasiswa = 0;


void InputData() {
    if (jmlh_mahasiswa < max_mhs) {
        Mahasiswa mhs;
        cout << "Masukkan Nama: ";
        cin >> mhs.nama;
        cout << "Masukkan NRP: ";
        cin >> mhs.nrp;
        cout << "Masukkan Umur: ";
        cin >> mhs.umur;
        cout << "Masukkan Jenis Kelamin (1=Laki-laki, 0=Perempuan): ";
        cin >> mhs.jenis_kelamin;
        
        dataMahasiswa[jmlh_mahasiswa] = mhs;
        jmlh_mahasiswa++;
        cout << "Data mahasiswa berhasil ditambahkan.\n";
    } else {
        cout << "Kapasitas maksimum data telah tercapai.\n";
    }
}

void DeleteData() {
    int nrp; 
    cout << "Masukkan NRP mahasiswa yang ingin dihapus: ";
    cin >> nrp;
    
    bool ditemukan = false;
    for (int i = 0; i < jmlh_mahasiswa; i++) {
        if (dataMahasiswa[i].nrp == nrp) {
            for (int j = i; j < jmlh_mahasiswa - 1; j++) {
                dataMahasiswa[j] = dataMahasiswa[j + 1];
            }
            jmlh_mahasiswa--;
            ditemukan = true;
            cout << "Data mahasiswa berhasil dihapus.\n";
            break;
        }
    }
    
    if (!ditemukan) {
        cout << "NRP tidak ditemukan.\n";
    }
}

void ChangeData() {
    int nrp; 
    cout << "Masukkan NRP mahasiswa yang ingin diubah: ";
    cin >> nrp;
    
    bool ditemukan = false;
    for (int i = 0; i < jmlh_mahasiswa; i++) {
        if (dataMahasiswa[i].nrp == nrp) {
            cout << "Masukkan Nama Baru: ";
            cin >> dataMahasiswa[i].nama;
            cout << "Masukkan NRP Baru: ";
            cin >> dataMahasiswa[i].nrp;
            cout << "Masukkan Umur Baru: ";
            cin >> dataMahasiswa[i].umur;
            cout << "Masukkan Jenis Kelamin Baru (1=Laki-laki, 0=Perempuan): ";
            cin >> dataMahasiswa[i].jenis_kelamin;
            ditemukan = true;
            cout << "Data mahasiswa berhasil diubah.\n";
            break;
        }
    }
    
    if (!ditemukan) {
        cout << "NRP tidak ditemukan.\n";
    }
}


void ShowData() {
    cout << "Data Mahasiswa:\n";
    for (int i = 0; i < jmlh_mahasiswa; i++) {
        cout << "Nama: " << dataMahasiswa[i].nama << endl;
        cout << "NRP: " << dataMahasiswa[i].nrp << endl;
        cout << "Umur: " << dataMahasiswa[i].umur << endl;
        cout << "Jenis Kelamin: " << (dataMahasiswa[i].jenis_kelamin ? "Laki-laki" : "Perempuan") << endl;
        cout << "------------------------\n";
    }
}

int main() {
    int pilihan;
    do {
        cout << "Menu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Ubah Data Mahasiswa\n";
        cout << "4. Tampilkan Data Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                InputData();
                break;
            case 2:
                DeleteData();
                break;
            case 3:
                ChangeData();
                break;
            case 4:
               ShowData();
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
