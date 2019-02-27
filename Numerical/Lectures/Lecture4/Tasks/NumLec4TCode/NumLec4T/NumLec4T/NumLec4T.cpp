// NumLec4T.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "nr3.h"
#include "utilities.h"
#include <iostream>
#include <svd.h>
#include <ludcmp.h>
#include <fstream>

int main()
{

	//Start test of the code
	std::cout << "Start test code" << std::endl;

	// Import Data

	//Pontius

	VecDoub xPont(40); VecDoub yPont(40);
	std::ifstream Pont("../Uni/Data/Lecture4/PontiusData.dat");
	for (int i = 0; i < 40; i++) {
		Pont >> yPont[i];
		Pont >> xPont[i];
	}

	std::cout << yPont[1] << std::endl;

	//Filip
	/*
	VecDoub xFilip(82); VecDoub yFilip(82);
	ifstream Filip("C:\\Users\\Korbu\\Desktop\\SmartgitMappe\\NumericalMethode\\Lectures\\Lecture2V2\\EkstraData\\FilipData.dat");
	for (int i = 0; i < 82; i++) {
		Filip >> yFilip[i];
		Filip >> xFilip[i];
	}
	*/



	/*

	MatDoub A(3, 4);
	A[0][0] = 1; A[0][1] = 1; A[0][2] = 0; A[0][3] = 1;
	A[1][0] = 0; A[1][1] = 0; A[1][2] = 0; A[1][3] = 1;
	A[2][0] = 1; A[2][1] = 1; A[2][2] = 0; A[2][3] = 0;

	MatDoub x(4, 5);
	MatDoub b(4, 5);



	MatDoub TestA(3, 3);
	TestA[0][0] = 1; TestA[0][1] = 2; TestA[0][2] = 4;
	TestA[1][0] = 2; TestA[1][1] = 1; TestA[1][2] = 3;
	TestA[2][0] = 3; TestA[2][1] = 2; TestA[2][2] = 5;

	MatDoub TestMatb(2, 2);
	TestMatb[0][0] = 1; TestMatb[0][1] = 0;
	TestMatb[1][0] = 0; TestMatb[1][1] = 1;

	MatDoub TestMatx(2, 2);
	TestMatx[0][0] = 0; TestMatx[0][1] = 0;
	TestMatx[1][0] = 0; TestMatx[1][1] = 0;

	VecDoub TestVecb(3);
	TestVecb[0] = 0;
	TestVecb[1] = 0;
	VecDoub TestVecx(3);
	TestVecx[0] = 0;
	TestVecx[1] = 0;

	util::print(TestA);

	SVD svdTestA(TestA);

	

	//std::cout << k;

	std::cout << svdTestA.rank() << endl;

	std::cout << svdTestA.nullity() << endl;

	util::print(svdTestA.range());

	util::print(svdTestA.nullspace());

	//util::print(svdTestA.eps);

	std::cout << svdTestA.eps << endl;

	util::print(svdTestA.u);
	util::print(svdTestA.w);



	//std::cout << svdTestA.tsh << endl;

	//svdTestA.solve(TestVecb, TestVecx, svdTestA.eps);
	
	//util::print(TestVecx);

	//util::print(svdTestA.inv_condition);


	//std::cout << svdTestA.range << endl;

	//std::cout << svdTestA.nullspace << endl;

	//util::print(svdTestA.rank);

	//LUdcmp ludmpTestA(TestA);

	//ludmpTestA.solve(TestVecb, TestVecx);

	//util::print(TestVecx);

	//svdTestA.solve(TestVecb, TestVecx, svdTestA.eps);

	//util::print(TestVecx);

	//util::print

	//svdTestA.solve(Testb, Testx);

	//util::print(Testx);
	//util::print(Testb);
	//util::print(A);

	//util::print(x);

	SVD svdA(A);

	//util::print();

	//svdA.solve(b, x);



	//svdA.rank();

	//std::cout << svdA.rank() << endl;

	//util::print

	//std::cout << svdA.solve(A, x);

	//util::print(A);

	//std::cout << svdA.solve;

	//util::print(svdA.rank);


	//svdA.solve(A, x);

	*/

	system("pause");

    return 0;
}

