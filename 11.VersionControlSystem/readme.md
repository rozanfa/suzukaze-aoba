# Version Control System

## Pengenalan Program

Version Control System sederhana untuk version tracking suatu repository. VCS ini menggunakan cara snapshot karena lebih mudah dipahami.

## Cara Mem-buildl Program

- Lakukan inisiasi dengan perintah berikut

```
make
```

- Untuk menambahkan file ke PATH, jalankan perintah berikut
```
export PATH="$PATH:`pwd`"
```

## Cara Menggunakan Program
Jika program ditambahkan ke PATH, maka ketikkan syntax berikut pada directory yang akan atau sedang menjadi repository
```
kud <command>
```

Jika program tidak ditambahkan ke PATH, maka ketikkan syntax berikut pada directory yang akan atau sedang menjadi repository
```
./<path-ke-sini>/kud <command>
```

## Command Yang Tersedia
- `init` - Untuk membuat repository pada pwd
- `commit <commit-msg>` - Untuk menambahkan kondisi repository saat ini menjadi versi baru  
- `log` - Untuk melihat riwayat commit
- `head <version-id>` - Untuk mengganti current directory ke versi yang sesuai
- `tag <version-id> <nama-tag>` - Untuk membuat symbolic link version-id yang sesuai pada folder `.kud/refs/tags`