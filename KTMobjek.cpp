#include <iostream>
#include <string>
using namespace std;

struct KTM {
    string nama;
    string nim;
    string kelas;
    KTM* next;
};

KTM* head = nullptr;

KTM* buatNode(string nama, string nim, string kelas) {
    KTM* baru = new KTM;
    baru->nama = nama;
    baru->nim = nim;
    baru->kelas = kelas;
    baru->next = nullptr;
    return baru;
}

void tambahDepan(string nama, string nim, string kelas) {
    KTM* baru = buatNode(nama, nim, kelas);
    baru->next = head;
    head = baru;
}

void tambahBelakang(string nama, string nim, string kelas) {
    KTM* baru = buatNode(nama, nim, kelas);
    if (head == nullptr) {
        head = baru;
    } else {
        KTM* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
    }
}

void tambahTengah(string nama, string nim, string kelas, string nimSebelum) {
    KTM* temp = head;
    while (temp != nullptr && temp->nim != nimSebelum)
        temp = temp->next;

    if (temp != nullptr) {
        KTM* baru = buatNode(nama, nim, kelas);
        baru->next = temp->next;
        temp->next = baru;
    } else {
        cout << "NIM " << nimSebelum << " tidak ditemukan.\n";
    }
}

void hapusDepan() {
    if (head != nullptr) {
        KTM* hapus = head;
        head = head->next;
        delete hapus;
    } else {
        cout << "List kosong.\n";
    }
}

void hapusBelakang() {
    if (head == nullptr) {
        cout << "List kosong.\n";
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        KTM* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
}

void hapusTengah(string nim) {
    if (head == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    if (head->nim == nim) {
        hapusDepan();
        return;
    }

    KTM* temp = head;
    while (temp->next != nullptr && temp->next->nim != nim)
        temp = temp->next;

    if (temp->next != nullptr) {
        KTM* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
    } else {
        cout << "NIM " << nim << " tidak ditemukan.\n";
    }
}

void cariData(string nim) {
    KTM* temp = head;
    while (temp != nullptr) {
        if (temp->nim == nim) {
            cout << "Data ditemukan:\n";
            cout << "Nama  : " << temp->nama << "\n";
            cout << "NIM   : " << temp->nim << "\n";
            cout << "Kelas : " << temp->kelas << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
}

void tampilkan() {
    KTM* temp = head;
    cout << "\nIsi Data KTM:\n";
    if (head == nullptr) {
        cout << "List kosong.\n";
    }
    while (temp != nullptr) {
        cout << "Nama  : " << temp->nama << "\n";
        cout << "NIM   : " << temp->nim << "\n";
        cout << "Kelas : " << temp->kelas << "\n";
        cout << "----------------------\n";
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    string nama, nim, kelas, nimSebelum;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Tengah\n";
        cout << "3. Tambah Belakang\n";
        cout << "4. Hapus Depan\n";
        cout << "5. Hapus Tengah\n";
        cout << "6. Hapus Belakang\n";
        cout << "7. Cari Data (berdasarkan NIM)\n";
        cout << "8. Tampilkan Semua Data\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Nama  : "; getline(cin, nama);
                cout << "NIM   : "; getline(cin, nim);
                cout << "Kelas : "; getline(cin, kelas);
                tambahDepan(nama, nim, kelas);
                break;
            case 2:
                cout << "Masukkan NIM sebelum data baru: ";
                getline(cin, nimSebelum);
                cout << "Nama  : "; getline(cin, nama);
                cout << "NIM   : "; getline(cin, nim);
                cout << "Kelas : "; getline(cin, kelas);
                tambahTengah(nama, nim, kelas, nimSebelum);
                break;
            case 3:
                cout << "Nama  : "; getline(cin, nama);
                cout << "NIM   : "; getline(cin, nim);
                cout << "Kelas : "; getline(cin, kelas);
                tambahBelakang(nama, nim, kelas);
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                cout << "Masukkan NIM yang ingin dihapus: ";
                getline(cin, nim);
                hapusTengah(nim);
                break;
            case 6:
                hapusBelakang();
                break;
            case 7:
                cout << "Masukkan NIM yang dicari: ";
                getline(cin, nim);
                cariData(nim);
                break;
            case 8:
                tampilkan();
                break;
            case 0:
                cout << "Terima kasih.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
