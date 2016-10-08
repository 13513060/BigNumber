/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bignumber.h
 * Author: NURSYAHRINA
 *
 * Created on February 28, 2016, 6:12 AM
 */

#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#define BIGNUMBER_DLL

#include "libbignumber.h"

#include <string>
using namespace std;

class DLL_EXPORT bignumber  
{
public :
    bignumber() {}
    ~bignumber() {}
    
    void add(string A, string B, string * addition, int * count);
    void addbigint(string A, string B, string * hasil, int * count);
    void subtract(string A, string B, string * subtraction, int * count);
    void subtractbigint(string A, string B, string * hasil, int * count);
    void multiplebigint(string A, string B, int n , string * hasil, int * count);
    void multiple(string A, string B, int n, string * multiple, int * count);
    string div10sbigint(string A, int s);
    string mod10sbigint(string A, int s);
    string multiple10s(string A, int s);
    int toInt(char c);
    char BiggerValue(string A, string B);
    int LongerString(string A, string B);
};

#endif /* BIGNUMBER_H */

