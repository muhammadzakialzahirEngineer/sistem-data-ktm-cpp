# KTMobjek — Sistem Manajemen Data KTM Mahasiswa (Linked List)

Program C++ sederhana berbasis **command-line interface (CLI)** untuk mengelola data Kartu Tanda Mahasiswa (KTM) menggunakan struktur data **singly linked list**. Setiap data mahasiswa (nama, NIM, kelas) disimpan sebagai node dalam linked list, sehingga operasi tambah dan hapus data dapat dilakukan secara dinamis tanpa batas ukuran array.

## ✨ Fitur

- **Tambah Data**
  - Tambah di depan list
  - Tambah di tengah list (berdasarkan NIM referensi)
  - Tambah di belakang list
- **Hapus Data**
  - Hapus dari depan list
  - Hapus dari tengah list (berdasarkan NIM)
  - Hapus dari belakang list
- **Cari Data** berdasarkan NIM
- **Tampilkan Semua Data** yang tersimpan dalam list
- Menu interaktif berbasis teks (looping hingga user memilih keluar)

## 🧠 Struktur Data

Setiap node KTM terdiri dari:

```cpp
struct KTM {
    string nama;
    string nim;
    string kelas;
    KTM* next;
};
```

## 📋 Contoh Tampilan Menu

<img width="780" height="386" alt="Screenshot 2026-09-20 141735" src="https://github.com/user-attachments/assets/f8da33cc-9444-4bc9-af48-96a6c5ef7a51" />


```
===== MENU =====
1. Tambah Depan
2. Tambah Tengah
3. Tambah Belakang
4. Hapus Depan
5. Hapus Tengah
6. Hapus Belakang
7. Cari Data (berdasarkan NIM)
8. Tampilkan Semua Data
0. Keluar
Pilih:
```

## 📂 Struktur Proyek

```
KTMobjek/
├── ktmobjek.cpp     # Source code utama
└── README.md        # Dokumentasi proyek
```

## 🎯 Tujuan Proyek

Proyek ini dibuat sebagai latihan implementasi **struktur data linked list** dalam bahasa C++, mencakup operasi dasar seperti insert, delete, dan search pada berbagai posisi (depan, tengah, belakang).

## 🏷️ Topik

`cpp` `linked-list` `data-structures` `singly-linked-list` `cli-app` `struktur-data` `mahasiswa`

## 📄 Lisensi

Bebas digunakan untuk keperluan belajar dan pengembangan lebih lanjut.
