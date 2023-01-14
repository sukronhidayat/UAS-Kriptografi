//Nama : Sukron Hidayat
//Nim : 312010346
//Kelas : TI.20.D3
//UAS Kriptografi

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

main(int argc, char *argv[])
{
	FILE *Fin, *Fout;
	char p, c;
	string K;
	int i;
	
	Fin = fopen(argv[1], "rb");
	if (Fin == NULL) {
		cout << "Berkas" << argv[1] <<" Tidak Ada" << endl;
		exit(0);
	}
	
	Fout = fopen(argv[2], "wb");
	
	cout << "Kata Kunci : ", cin >> K;
	cout << "Enkripsi" << argv[1] << "Menjadi" << argv[2] << "....";
	i = 0;
	while (!feof(Fin)) {
		p = getc(Fin);
		c = p ^ K[i];
		putc(c, Fout);
		i = (i + 1) % K.length();
	}
	fclose (Fin);
	fclose (Fout);
}
