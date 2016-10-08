/* 
 * File:   libbignumber.h
 * Author: 13513060 - NURSYAHRINA
 *
 *
 * Library C++ untuk operasi aritmatika bilangan bigInt (type = string)
 * Operasi aritmatika yang termasuk :
 * 	1--Operasi Penjumlahan dan Pengurangan (algoritma brute force)
 * 	2--Operasi Perkalian (algoritma A.A Karatsuba)
*/

#ifndef LIBBIGNUMBER_H
#define LIBBIGNUMBER_H


#ifdef BIGNUMBER_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)

#endif /* LIBBIGNUMBER_H */

#endif

