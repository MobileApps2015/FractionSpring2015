/**
 * Program Name: cis25Spring2015FractionDriver0414.cpp
 * Discussion:   Lab 4 Exercise 1
 * Written By:   YourName
 * Date:         2015/04/14
 */
#include <iostream>
#include "cis25Spring2015Fraction.h"
#include "cis25Spring2015FractionSusanS.h"
#include "cis25Spring2015FractionUtility.h"
#include "cis25Spring2015SwapUtil.h"
using namespace std;

// Just making notation

void doFraction(void);

int returnInt(void);

int returnSum(int, int);

Fraction returnFraction(void);

Fraction sumFraction(Fraction arg1, Fraction arg2);

int main() {
  Fraction f1(5);
  Fraction f2(9, 7);

  sumFraction(f1, f2);

  return 0; // destructor calls if any
}

// Function Definitions

Fraction sumFraction(Fraction arg1, Fraction arg2) {
  Fraction tmp;

  return arg1;
}

Fraction returnFraction() {
  Fraction tmp1(5);
  Fraction tmp2(6, 7);

  return tmp1;
}

int returnSum(int arg1, int arg2) {
  int val1;
  int val2;

  cin >> val1;
  cin >> val2;

  return arg1 + arg2 + val1 + val2;
}

int returnInt() {
  int value;

  cin >> value;

  return value;
}

void doFraction() {
  //fr1;
  cout << "\nHa ..." << endl;
}

