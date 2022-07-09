# Rakit
## Pengenalan Program

Program yang saya buat adalah progaram kuis sederhana yang membaca soal dan kunci jawaban dari file eksternal, meminta user menjawab soal, dan menentukan apakah jawaban user benar atau salah.

## Cara Kerja Program

- Program membaca file `problem.txt` kemudian menampilkannya ke console sebagai pertanyaan
- Program membaca file `solution.txt` kemudian menyimpannya ke dalam variabel
- Program meminta input jawaban kepada user berdasarkan pertanyaan dari `problem.txt`
- Program menentukan apakah jawaban user benar atau salah
- Program menuliskan riwayat pada `log.txt`

## Cara Menjalankan Program

- Assemble program tersebut dengan perintah

```
nasm -f elf amogus.asm
```

- File objek `amogus.o` akan tercipta
- Buat file executable bernama amogus dengan mengetikkan

```
ld -m elf_i386 -s -o amogus amogus.o
```

- Jalankan program dengan mengetikkan

```
./amogus
```

## Catatan Pengembang

Program amogus didesain untuk jawaban sepanjang dua digit. Jawaban yang kurang atau lebih dari dua digit mungkit membuat program tidak berjalan dengan semestinya
