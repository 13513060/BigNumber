/*
	Library C++ untuk operasi aritmatika bilangan bigInt (type = string)
	Operasi aritmatika yang termasuk :
	1--Operasi Penjumlahan dan Pengurangan (algoritma brute force)
	2--Operasi Perkalian (algoritma A.A Karatsuba)
*/

/*
	File 	: bignumber.cpp
	Author	: 13513060 - NURSYAHRINA

	Header Library bigInt
*/
#include <string>
#include <sstream>
#include <cstdlib>

#define BIGNUMBER_DLL
#include "bignumber.h"



using namespace std;

void bignumber::addbigint(string A, string B, string * hasil, int * count){

	if (A == "0"){
		*hasil = B;
	} else if (B == "0"){
		*hasil = A;
	}
	else if (A[0] == '-'){
		if (B[0] == '-'){
			add(A.substr(1,A.length()-1), B.substr(1,B.length()-1), hasil, count);
			(*hasil).insert(0,"-");
		} else {
			subtract(A.substr(1,A.length()-1), B, hasil, count);
			(*hasil).insert(0,"-");
		}
	} else if (A[0] != '-'){
		if (B[0] == '-'){
			subtract(A, B.substr(1,B.length()-1), hasil, count);
		} else {
			add(A, B, hasil, count);
		}
	}
}

void bignumber::subtractbigint(string A, string B, string * hasil, int * count){


	if (A == "0"){
		*hasil = B;
		if ((*hasil)[0] == '-'){
			*hasil = (*hasil).substr(1,(*hasil).length()-1);
		}
	} else if (B == "0"){
		*hasil = A;
	}
	else if (A[0] == '-'){
		if (B[0] == '-'){
			subtract(B.substr(1,B.length()-1), A.substr(1,A.length()-1), hasil, count);
		} else {
			add(A.substr(1,A.length()-1), B, hasil, count);
			(*hasil).insert(0,"-");
		}
	} else if (A[0] != '-') {
		if (B[0] == '-'){
			add(A, B.substr(1,B.length()-1), hasil, count);
		} else {
			subtract(A, B, hasil, count); 
		}
	}
}

void bignumber::add(string A, string B, string * addition, int * count){
	//KAMUS
	int temp = 0;

	int hasil;
	int n;

	//ALGORITMA
	if (A.length() > B.length()){
		n = A.length()-B.length();
		for (int i = 0; i < n; i++){
			B.insert(0,"0"); 
		} 
	} else if (A.length() < B.length()) {
		n = B.length()-A.length();
		for (int i = 0; i < n; i++){
			A.insert(0,"0");
		} 
	} 
	for (int i = A.length()-1; i >= 0; i--){
		int a = toInt(A[i]);
		int b = toInt(B[i]);
		hasil = (a + b + temp);
		(*count)++;
		stringstream s;
		s << (hasil % 10);
		(*addition).insert(0,s.str());
		temp = hasil/10; 
	}
	if (temp > 0){
		stringstream ss;
		ss << temp;
		(*addition).insert(0,ss.str());
	}
}

void bignumber::subtract(string A, string B, string * subtraction, int * count){
	//KAMUS
	int temp = 0;
	int hasil;
	int n;

	//ALGORITMA
	char bigger = BiggerValue(A, B); 
	if (A.length() > B.length()){
		n = A.length()-B.length();
		for (int i = 0; i < n; i++){
			B.insert(0,"0"); 
		} 
	} else if (A.length() < B.length()) {
		n = B.length()-A.length();
		for (int i = 0; i < n; i++){
			A.insert(0,"0");
		} 
	} 
	if (bigger == 'A'){
		for (int i = A.length()-1; i >= 0; i--){
			int a = toInt(A[i]);
			int b = toInt(B[i]);
			hasil = (a - b + temp);
			(*count)++;
			if ((a < b) || (hasil == -1)){
				temp = -1;
				hasil += 10;
			} else{
				temp = 0;
			}
			stringstream s;
			s << hasil;
			(*subtraction).insert(0,s.str()); 
		}
	} else if (bigger == 'B'){
		for (int i = A.length()-1; i >= 0; i--){
			int a = toInt(A[i]);
			int b = toInt(B[i]);
			hasil = (b - a + temp);
			(*count)++;
			if (b < a){
				temp = -1;
				hasil += 10;
			} else{
				temp = 0;
			}
			stringstream s;
			s << hasil;
			(*subtraction).insert(0,s.str()); 
		}
	}
	while ((*subtraction)[0] == '0'){
		*subtraction = (*subtraction).substr(1,(*subtraction).length()-1);
	}
	if (bigger == 'B'){
		(*subtraction).insert(0,"-");
	}
	if ((*subtraction).length() == 0){
		(*subtraction).insert(0,"0");
	}
}
void bignumber::multiplebigint(string A, string B, int n , string * hasil, int * count){

	if ((A == "0") || (B == "0")){
		*hasil = "0";
	} else if (A == "1"){
		*hasil = B;
	} else if (B == "1"){
		*hasil = A;
	}
	else if (A[0] == '-'){
		if (B[0] == '-'){
			multiple(A.substr(1,A.length()-1), B.substr(1,B.length()-1), n, hasil, count);
		} else {
			multiple(A.substr(1,A.length()-1), B, n, hasil, count);
			(*hasil).insert(0,"-");
		}
	} else if (A[0] != '-') {
		if (B[0] == '-'){
			multiple(A, B.substr(1,B.length()-1), n, hasil, count);
			(*hasil).insert(0,"-");
		} else {
			multiple(A, B, n, hasil, count);
		}
	}
}
void bignumber::multiple(string A, string B, int n, string * multiple, int * count){
	//KAMUS
	int x;
	int k;
	int nn = 0;

	//ALGORITMA
	
	if (A.length() > B.length()){
		x = A.length()-B.length();
		for (int i = 0; i < x; i++){
			B.insert(0,"0");
		} 
	} else if (A.length() < B.length()) {
		x = B.length()-A.length();
		for (int i = 0; i < x; i++){
			A.insert(0,"0");
		} 
	} 
	if (n == 1){
		if ((A.length() == 1) && (B.length() == 1)){
			int x = toInt(A[0]);
			int y = toInt(B[0]);
			stringstream s;
			s << (x*y);
			(*count)++;
			(*multiple) = s.str(); 
		} else {
			int x = atoi(A.c_str());
			int y = atoi(B.c_str());
			stringstream s;
			s << (x*y);
			(*count)++; 
			(*multiple) = s.str(); 
		}
	} else {
		int s = n/2;
		string a = div10sbigint(A,s);
		string b = mod10sbigint(A,s);
		string c = div10sbigint(B,s);
		string d = mod10sbigint(B,s);
		
		string p = "";
		multiplebigint(a, c, s, &p, count); 
		string q = "";
		multiplebigint(b, d, ((n/2) + (n%2)), &q, count);

		string add1 = "";
		add(a, b, &add1, &nn);
		string add2 = "";
		add(c, d, &add2, &nn);

		k = LongerString(add1, add2);

		string r = "";
		multiplebigint(add1, add2, k, &r, count); 

		s = (n/2) + (n % 2);
		string px = multiple10s(p,(2*s)); 

		string rp = "";
		subtractbigint(r, p, &rp, &nn);
		string rpq = "";
		subtractbigint(rp, q, &rpq, &nn);
		rpq = multiple10s(rpq,s); 
		string add3 = "";
		string add4 = "";
		addbigint(px, rpq, &add3, &nn);
		addbigint(add3, q, &add4, &nn);

		(*multiple) = add4;
		
	}
}
string bignumber::div10sbigint(string A, int s){
	return A.substr(0,s);
}
string bignumber::mod10sbigint(string A, int s){
	return A.substr(s,A.length()-s);
}
string bignumber::multiple10s(string A, int s){
	string hasil = A;

	if (A != "0"){
		for (int i = 0; i < s; i++){
			hasil += '0';
		}
	}
	return hasil;
}
int bignumber::toInt(char c){
	switch (c) {
		case '0' : return 0; break;
		case '1' : return 1; break;
		case '2' : return 2; break;
		case '3' : return 3; break;
		case '4' : return 4; break;
		case '5' : return 5; break;
		case '6' : return 6; break;
		case '7' : return 7; break;
		case '8' : return 8; break;
		case '9' : return 9; break;
	}
}
char bignumber::BiggerValue(string A, string B){
	char bigger;
	if (A.length() > B.length()){
		bigger = 'A';
	} else if (A.length() < B.length()){
		bigger = 'B';
	} else {
		bool found = false;
		int i = 0;
		while ((i < A.length()) && (!found)){
			if (toInt(A[i]) > toInt(B[i])){
				bigger = 'A';
				found = true;
			} else if (toInt(A[i]) < toInt(B[i])){
				bigger = 'B';
				found = true;
			}
			i++;
		}
	}
	return bigger;
}
int bignumber::LongerString(string A, string B){
	int k;

	if (A.length() >= B.length()){
		k = A.length();
	} else {
		k = B.length();
	}

	return k;
}