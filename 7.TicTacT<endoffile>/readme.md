# TicTacT\<end of file\>

## Pengenalan Program

Program permainan Tic-Tac-Toe yang dimainkan secara multiplayer. Kedua player bermain pada program yang berbeda. Satu player akan menjadi server sedangkan player lainnya menjadi client.

## Cara Menjalankan Program

- Buka file `src/client.cpp` dan `src/server.cpp` pada baris ke-28. Ubahlah string yang terdapat pada baris tersebut alamat localhost device anda.
```c++
// server.cpp
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost
                                             ^^^^^^^^^^
```


```c++
// client.cpp
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");   //localhost
                                             ^^^^^^^^^^
```
- Compile kedua program tersebut dengan memuka terminal pada directory ini kemudian ketikkan perintah berikut
```bash
make
```
- Akan muncul program bernama `server` dan `client` pada direktori ini
- Buka dua buah terminal, jalankan program `server` terlebih dahulu pada terminal pertama, diikuti dengan program `client` pada terminal kedua