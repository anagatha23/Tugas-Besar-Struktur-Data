#include <iostream>
#define firstPenumpang(L) (L.firstPenumpang)
#define firstpesawat(L) (L.firstpesawat)
#define firstTiket(P) ((P)->firstTiket)
#define nextPenumpang(P) ((P)->nextPenumpang)
#define nextpesawat(P) ((P)->nextpesawat)
#define nextTiket(P) ((P)->nextTiket)
#define infoPenumpang(P) ((P)->infoPenumpang)
#define infopesawat(P) ((P)->infopesawat)
#define tiketpesawat(P) ((P)->tiketpesawat)
#define noKursi(P) ((P)->noKursi)

using namespace std;

typedef struct elmTiket *adrTiket;
typedef struct elmPenumpang *adrPenumpang;
typedef struct elmpesawat *adrpesawat;

// parent 

struct Penumpang{
    string nama;
    string email;
    string noHP;
    int jumlahTiket;
};

struct elmPenumpang{
    Penumpang infoPenumpang;
    adrPenumpang nextPenumpang;
    adrTiket firstTiket;

};

struct listPenumpang{
    adrPenumpang firstPenumpang;
};

//child

struct pesawat{
    string nama;
    int menitDurasi;
    string jamTayang;
};

struct elmpesawat{
    pesawat infopesawat;
    adrpesawat nextpesawat;
};

struct listpesawat{
    adrpesawat firstpesawat;
};

// relasi

struct elmTiket{
    string noKursi;
    adrpesawat tiketpesawat;
    adrTiket nextTiket;
};

void createListPenumpang(listPenumpang &LP);
void createListpesawat(listpesawat &LF);
adrPenumpang createElmPenumpang(string nama, string email, string noHP);
adrpesawat createElmpesawat(string nama, int menitDurasi, string jamTayang);
void membeliTiket(listPenumpang &LP, listpesawat LF, string namaPenumpang, string namapesawat, string noKursi);
void tambahPenumpang(listPenumpang &LP, adrPenumpang PPenumpang);
void tambahpesawat(listpesawat &LF, adrpesawat Ppesawat);
void printAllPenumpang(listPenumpang LP);
void printAllpesawat(listpesawat LF);
void hapusElmPenumpang(listPenumpang &LP, string nama);
void hapusElmpesawat(listpesawat &LF, string nama, listPenumpang &LP);
void hapusElmTiket(listPenumpang &LP, listpesawat LF, adrPenumpang &PPenumpang, string namaPenumpang, string namapesawat);
void deleteFirstTiket(listPenumpang &LP, adrPenumpang &PPenumpang);
void deleteLastTiket(listPenumpang &LP, adrPenumpang &PPenumpang);
void deleteAfterTiket(listPenumpang &LP, adrPenumpang &PPenumpang, adrTiket precTiket);
void deleteAllTiket(listPenumpang &LP, adrPenumpang &PPenumpang);
void deleteTiketWithSpesificpesawat(listPenumpang &LP, adrpesawat Ppesawat, listpesawat &LF);
void deleteFirstPenumpang(listPenumpang &LP);
void deleteLastPenumpang(listPenumpang &LP);
void deleteAfterPenumpang(listPenumpang &LP, adrPenumpang prec);
void deleteFirstpesawat(listpesawat &LF, listPenumpang &LP);
void deleteLastpesawat(listpesawat &LF, listPenumpang &LP);
void deleteAfterpesawat(listpesawat &LF, adrpesawat prec, listPenumpang &LP);
adrPenumpang searchPenumpang(listPenumpang LP, string nama);
adrpesawat searchpesawat(listpesawat LF, string nama);
adrTiket searchTiket(listPenumpang LP, listpesawat LF, string namaPenumpang, string namapesawat);
adrTiket searchNoKursiWithpesawat(listPenumpang LP, string namapesawat, string noKursi);
void printSpecificTiket(listPenumpang LP, listpesawat LF, string namaPenumpang, string namapesawat);
void printAllTiket(adrPenumpang PPenumpang);
void printAllPenumpangWithTiket(listPenumpang LP, listpesawat LF);
int selectMenu();
