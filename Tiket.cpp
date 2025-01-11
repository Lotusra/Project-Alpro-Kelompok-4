#include <iostream>
using namespace std;

void pembelian_tiket_bioskop ()
 {
 int pilihan,angka;

  do
 {
     cout << "\t   Bioskop XXI Sukabumi"; cout << endl;
     cout << "\t JL.Bhayangkara Sukabumi"; cout << endl;
     cout << " =============================================" << endl;
     cout << "\t      DAFTAR MENU "; cout << endl;
     cout << "\t---------------------------------" << endl;
     cout << "\t| 1. Pembelian Tiket            |" << endl;
     cout << "\t| 2. Cek Sisa Kursi             |" << endl;
     cout << "\t| 3. Keluar \t		|" << endl;
     cout << "\t---------------------------------" << endl;
     cout << " =============================================" << endl;
     cout << endl;
 
     cout << " Masukan Pilihan Anda (1-3) : "; cin >> pilihan;
     cout << endl;
     
     system ("cls");
     
     switch (pilihan)

   {

    case 1:

     mulai:
     int jenisTKT,jumlahTKT,totalTKT;
     char* jenisTXT;
     char ulang,belanjaKmbln;

       cout << " =============================================" << endl;
       cout << "\t   Pembelian Tiket "; cout << endl;
       cout << " =============================================" << endl;     
       cout << " Keterangan" << endl;
       cout << " 1. Tiket Dewasa  : Rp. 35.000" << endl;
       cout << " 2. Tiket Anak-anak  : Rp. 20.000" << endl;
       cout << " =============================================" << endl;
       cout << " Input Pembelian Tiket" << endl;
       cout << " Jenis Tiket (1-2)  : "; cin >> jenisTKT;
       cout << " Jumlah Tiket   : "; cin >> jumlahTKT; cout << endl;
       cout << " =============================================" << endl;
       
       
     if (jenisTKT==1)
     {
      totalTKT=jumlahTKT*35000;
      jenisTXT="Dewasa";
     }
     else if (jenisTKT==2)
     {
      totalTKT=jumlahTKT*20000;
      jenisTXT="Anak-anak";
     }
     else
     {
      cout << " Angka Yang Anda Input Salah";
      cout << endl;
      goto mulai;
     }
       cout << " Jenis Tiket   : " << jenisTXT << endl;
       cout << " Jumlah Tiket   : " << jumlahTKT << endl;
       cout << " ---------------------------------------------" << endl;
       cout << " Total Bayar   : Rp. " <<totalTKT << endl;
       cout << " ==============================================" << endl;
       cout << endl;

       break;
       
       
     case 2:

      int KursiTerisi[2],kursiKSONG[2];
       cout << " ==============================================" << endl;
       cout << "\t   Cek Sisa Kursi "; cout << endl;
       cout << " ==============================================" << endl;
       cout << " Keterangan" << endl;
       cout << " Jumlah Kursi Di Bioskop SerbaBebas sebangak 50 Kursi" << endl;
       cout << " ==============================================" << endl;
       cout << " Input Jumlah Kursi Yang Ingin Dipesan" << endl;
       
       angka=0;

      do
     {
      cout << " Jumlah Pemesanan Kursi  : "; cin >> KursiTerisi[angka];
       angka++;
     }
     while (angka<1);
      for (angka=0;angka<1;angka++)
       kursiKSONG[angka]=50-KursiTerisi[angka];      
	   cout << " ==============================================" << endl;
       for (angka=0;angka<1;angka++)
      {
       cout << " Sisa Kursi   : "<< kursiKSONG[angka]; cout << endl;
       cout << " ==============================================" << endl;
       cout << endl;
      }
      
        break;

   }

 }
 while (pilihan!=3);
 }       
 
 int main ()
 {
 	pembelian_tiket_bioskop();
 	return 0;
 }
