// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <nr3.h>
#include <svd.h>
#include <utilities.h>
#include <cmath>
#include <fstream>
#include <vector>

//using namespace util;

int main()
{

	// Start by making variables and give value
	//int i, j, k, m, n;
	int m = 500;
	int n = 4;
	int i;
	int j;
	//int k;
	//m = 1000;


	//int i, j, k, m, n;
	//m = 500;
	//n = 4;

	// Load data from file
	ifstream dataMatrix("d1");



	// Make the vectors and matrix used
	VecDoub x(500);
	VecDoub y(500);
	VecDoub O1(500);
	VecDoub O2(500);
	VecDoub q(4);
	VecDoub z(1000);

	MatDoub A(1000, 4);

	
	
	//Need to load data to make A matrix
	//Insert values in matrix
	for (i = 0; i < m; i++)
	{
		dataMatrix >> O1[i];
		dataMatrix >> O2[i];
		dataMatrix >> x[i];
		dataMatrix >> y[i];
	}


	//Find expressions for the elements in matrix A
	//Make A matrix
	for (int i = 0; i < m; i++)
	{
		A[i * 2][0] = 1;
		A[i * 2 + 1][0] = 0;
		A[i * 2][1] = 0;
		A[i * 2 + 1][1] = 1;
		A[i * 2][2] = cos(O1[i]);
		A[i * 2 + 1][2] = sin(O1[i]);
		A[i * 2][3] = cos(O1[i] + O2[i]);
		A[i * 2 + 1][3] = sin(O1[i] + O2[i]);
		z[i * 2] = x[i];
		z[i * 2 + 1] = y[i];
	}

	

	//Load the data and calculate U, W and V and check for linear dependencies between x, y, a, b
	//Data already loaded in Task 1
	//Using SVD to calculate U, W and V
	//First make the SVD
	SVD aSVD(A);


	//Print the values of U, W and V

	//Printing A matix to make sure it is made correctly
	std::cout << "A matix" << std::endl;
	util::print(A);

	//U matrix
	std::cout << "U matrix" << std::endl;
	util::print(aSVD.u);

	//W matrix
	std::cout << "W matrix" << std::endl;
	util::print(aSVD.w);

	//V matrix
	std::cout << "V matrix" << std::endl;
	util::print(aSVD.v);


	
	//Estimate parameters q = (x0, y0, a, b) and the residual error ||Aq - z||
	//Use the SVD and solve for parameters
	aSVD.solve(z, q);

	std::cout << "The valus of the parameters of q: " << std::endl;
	util::print(q);


	
	//x^i, y^i have an uncertainty of 1mm
	//Estimate the error using NR Eq 15.5.19

	//Make a error variable that gets written over	
	Doub resError = 0;

	
	//Eq 15.5.19 in code form
	for (int i = 0; i < aSVD.v.nrows() - 1; i++)
	{
		for (int j = 0; j < aSVD.v.ncols() - 1; j++)
		{
			resError = resError + pow(aSVD.v[i][j] / aSVD.w[i], 2);
		}
	}

	//Print the error
	std::cout << "The resulting errors using Eq 15.5.19: " << resError << std::endl;

	


	// Task 5
	//Compare results from both datasets


system("pause");

return 0;

}

