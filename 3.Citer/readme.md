# Citer
## Pengenalan Program

Program memori editor sederhana yang mengedit memory target program dengan value yang lain. Program ini berjalan pada sistem operasi Windows.

## Cara Menjalankan Program

- Compile target program dengan menjalankan file `compile.exe` pada folder `targetprogram`
- Buka terminal dan jalankan program hasil kompilasi tersebut pada terminal
- Salin alamat (address) dari nilai yang akan diubah
- Buka code program bernama `memoryeditor.cpp` pada folder memoryeditor kemudian edit baris ke-43 dan 44
```
	int newValue = 0xABCDEF;	// Nilai baru
	long long valueAddr = 0x000000455ebffdcc;	// Alamat nilai yang diubah
```
- Isi variabel newValue dengan nilai yang diinginkan
- Isi variabal valueAddr dengan alamat yang dicatat tadi
- Compile program memoryeditor.cpp dengan menjalankan file `compile.exe` pada folder `memoryeditor`
- Buka terminal baru dan jalankan program hasil kompilasi tersebut pada terminal
- Lihat kembali targetprogram.exe, lanjutkan program dengan memasukan nilai integer apa saja
- Perhatikan bahwa target value berubah nilai
