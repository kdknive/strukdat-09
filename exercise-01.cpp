/*
* Author    : Kevin Dyandradiva
* NPM       : 140810180046
* Kelas     : B
* Deskripsi : Exercise 1
* Tanggal   : 7 Mei 2019
*/

#include <iostream>
#include <string.h>
using namespace std;

const int maxElemen=255;
struct Stack{
	char isi[maxElemen];
	int TOP;
};
Stack S;

void createStack(Stack& S){
	S.TOP=-1;
}

void push(Stack& S, char elemenBaru){
	if(S.TOP==maxElemen-1){
		cout<<"Tumpukan Sudah Penuh"<<endl;
	}else{
		S.TOP++;
		S.isi[S.TOP]=elemenBaru;
	}
}

void pop(Stack& S, char& kata){
	if(S.TOP<0){
		cout<<"Tumpukan Sudah Kosong"<<endl;
	}else{
		kata=S.isi[S.TOP];
		S.TOP--;
	}
}

void reverse(Stack& S, char kata[]){
	for(int i=0; i<strlen(kata); i++)
	{
		push(S, kata[i]);
	}
	for(int i=0; i<strlen(kata); i++)
	{
		kata[i] = S.TOP;
		pop(S, kata[i]);
	}
}

int main(){
	char string[255];
	char temp;
	createStack(S);

	cout << "Masukkan Kata      :"; cin.getline(string, 255);
	cout << "Kata               : " << string << endl;

	reverse(S, string);

	cout << "Reversed String    : " << string;

	return 0;
}
