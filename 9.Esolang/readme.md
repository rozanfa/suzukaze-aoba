# Jovo
Bahasa Jovo adalah pemrograman [esoteric](https://esolangs.org/wiki/Main_Page) yang menggunakan referensi bahasa Jawa. Bahasa ini memiliki fitur branching, looping, input dari stdin, dan output ke stdout.

## Requirements
Python 3

## Cara Menjalankan Interpreter
```
python3 interpreter.py <file-jovo>
```


## Daftar Command
| Command | Kegunaan |
| ------------ | ------------- |
| ono \<var> | Mendaftarkan \<var> sebagai variabel |
| tambah \<var> |  Menambahkan bilangan \<var> sebesar 1 |
| kurang \<var> | Mengurangkan bilangan \<var> sebesar 1 |
| tulis \<var> | Menuliskan \<var> ke stdout |
| woco \<var> | Membaca satu kata dari stdin kemudian memasukkannya ke \<var> |
| wocokalimat \<var> | Membaca input sampai endline dari stdin kemudian memasukkannya ke \<var> |
| lungo \<line> | Pergi ke baris \<line> |
| kalo \<expression> lungo \<line> | Pergi ke baris \<line> jika \<expression> terpenuhi dengan \<expression> adalah \<var> [ == \| != \| > \| \< \| >= \| \<= ] \<int> | 
| \<var> iku tulisan \<string> | Memasukkan \<string> ke dalam variabel \<var> |
| \<var> iku angka \<int> | Memasukkan \<int> ke dalam variabel \<var> |

## Contoh Program
Contoh program Hello World
```
ono variabel
variabel iku tulisan Hello, World
tulis variabel
```

Contoh program mencetak Hello World sebanyak 5 kali
```
ono a
a iku tulisan Hello, World!
ono b
b iku angka 0

tulis a
tambah b
kalo b < 5 lungo 6
```

## Link Video Demonstrasi
https://youtu.be/BTFvmdI2oOo