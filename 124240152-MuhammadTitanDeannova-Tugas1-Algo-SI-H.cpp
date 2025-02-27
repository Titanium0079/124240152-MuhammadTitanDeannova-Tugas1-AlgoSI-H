#include <iostream>
using namespace std;
string soldier[3] = {"Infantry", "Cavalry", "Archer"};

struct Batalyon {
    int ID;
    string namaJenderal;
    string tipePasukan;
    int jumlahPasukan;
};

Batalyon batalyon[100];
int jumlahBatalyon = 0;

bool cekNamaJenderal(string nama) {
    for (int i = 0; i < jumlahBatalyon; i++) {
        if (batalyon[i].namaJenderal == nama) {
            return true;
        }
    }
    return false;
}

bool cekTipePasukan(string tipe) {
    for (int i = 0; i < 3; i++) {
        if (soldier[i] == tipe) {
            return true;
        }
    }
    return false;
}

void tambahBatalyon() {
    if (jumlahBatalyon >= 100) {
        cout << "Batalyon full!\n";
        return;
    }

    cout << "Input general name: ";
    cin.ignore();
    getline(cin, batalyon[jumlahBatalyon].namaJenderal);

    if (cekNamaJenderal(batalyon[jumlahBatalyon].namaJenderal)) {
        cout << "Error: General name already exist!\n";
        return;
    }

    cout << "Input soldier type (Infantry/Cavalry/Archer): ";
    cin >> batalyon[jumlahBatalyon].tipePasukan;

    if (!cekTipePasukan(batalyon[jumlahBatalyon].tipePasukan)) {
        cout << "Error: Soldier invalid!\n";
        return;
    }

    cout << "Input Soldier Quantity: ";
    cin >> batalyon[jumlahBatalyon].jumlahPasukan;

    if (batalyon[jumlahBatalyon].jumlahPasukan < 1) {
        cout << "Error: Soldier Quantity must be more than 0!\n";
        return;
    }

    batalyon[jumlahBatalyon].ID = jumlahBatalyon + 1;
    jumlahBatalyon++;

    cout << "Batalyon training complete!\n";
}

void cariBatalyon() {
    if (jumlahBatalyon == 0) {
        cout << "No Batalyon!\n";
        return;
    }

    string cariNama;
    cout << "Search General Name: ";
    cin.ignore();
    getline(cin, cariNama);

    int kiri = 0, kanan = jumlahBatalyon - 1, tengah;
    bool ditemukan = false;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (batalyon[tengah].namaJenderal == cariNama) {
            ditemukan = true;
            break;
        } else if (batalyon[tengah].namaJenderal < cariNama) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    if (ditemukan) {
        cout << "General found!\n";
        cout << "ID: " << batalyon[tengah].ID << endl;
        cout << "Nama: " << batalyon[tengah].namaJenderal << endl;
        cout << "Tipe: " << batalyon[tengah].tipePasukan << endl;
        cout << "Jumlah: " << batalyon[tengah].jumlahPasukan << endl;
    } else {
        cout << "No Batalyon!\n";
    }
}

bool kembaliKeMenu() {
    char pilihan;
    cout << "Apakah Anda ingin kembali ke menu atau logout? (Y/N): ";
    cin >> pilihan;
    return (pilihan == 'Y' || pilihan == 'y');
}

void menu() {
    int pilihan;
    bool lanjut = true;

    while (lanjut) {
        cout << "\n=== Battle of Heaven ===\n";
        cout << "1. Tambah Batalyon\n";
        cout << "2. Cari Batalyon\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBatalyon();
                lanjut = kembaliKeMenu();
                break;
            case 2:
                cariBatalyon();
                lanjut = kembaliKeMenu();
                break;
            case 3:
                cout << "As your command my Lord.\n";
                lanjut = false;
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
