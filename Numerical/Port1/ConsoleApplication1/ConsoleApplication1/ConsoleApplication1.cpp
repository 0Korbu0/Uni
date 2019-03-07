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
	ifstream dataMatrix("d2");



	// Make the vectors and matrix used
	VecDoub x(500);
	VecDoub y(500);
	VecDoub O1(500);
	VecDoub O2(500);
	VecDoub q(4);
	VecDoub z(1000);

	MatDoub A(1000, 4);

	// Task 1
	
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

	// Task 2

	//Load the data and calculate U, W and V and check for linear dependencies between x, y, a, b
	//Data already loaded in Task 1
	//Using SVD to calculate U, W and V
	//First make the SVD
	SVD aSVD(A);


	//Print the values of U, W and V

	//Printing A matix to make sure it is made correctly
	std::cout << "A matix" << std::endl;
	//util::print(A);

	//U matrix
	std::cout << "U matrix" << std::endl;
	//util::print(aSVD.u);

	//W matrix
	std::cout << "W matrix" << std::endl;
	//util::print(aSVD.w);

	//V matrix
	std::cout << "V matrix" << std::endl;
	//util::print(aSVD.v);


	// Task 3
	//Estimate parameters q = (x0, y0, a, b) and the residual error ||Aq - z||
	//Use the SVD and solve for parameters
	aSVD.solve(z, q);

	std::cout << "The valus of the parameters of q: " << std::endl;
	//util::print(q);

	VecDoub k(A.ncols());

	aSVD.solve(
	//VecDoub k = A * q;
	//Doub t = abs(k);
	//util::print((A * q - z));

	//util::print(abs(q[1]);

	//std::cout << abs(q[1]) << std::endl;

	//std::cout << abs(A[0][0] * q[0]) << std::endl;

	//abs(q[1]);


	/*
	vector<int> t = { 7,5,16,8 };

	for (int i = 0; i < t.size(); i++)
	{
		t[i] = abs(t[i]);
		std::cout << t[i] << std::endl;;
	}

	*/
	//std::cout << t.;

	//q=q.array

	VecDoub residualError;
	for (i = 0; i < A.ncols(); i++)
	{
		for (j = 0; j < A.nrows(); j++)
		{
			//residualError = residualError
			//std::cout << j << std::endl;
		}
		//std::cout << i << std::endl;
	}


	// Task 4
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

	



	/*
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
	*/

    //std::cout << "Hello World!\n"; 


system("pause");

return 0;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



/*
using namespace util;

int main()
{


	int i, j, k, m, n;
	m = 500;
	n = 4;
	///*string txt
	//MatDoub a(m, n);
	//MatDoub uvw(m, n);
	////MatDoub b(n, 1);
	////MatDoub x(n, 1);
	//Her s�ttes dataen
	ifstream inputMatrix("d2");


	VecDoub O1(500); VecDoub O2(500); VecDoub x(500); VecDoub y(500); MatDoub A(1000, 4); VecDoub q(4); VecDoub z(1000);

	//Opgave 1
	//l�g v�rdier i de kendet variabler
	for (i = 0; i < m; i++)
	{
		inputMatrix >> O1[i];
		inputMatrix >> O2[i];
		inputMatrix >> x[i];
		inputMatrix >> y[i];

	}

	//lav A matrixen. *2 er fordi der er 2 formler. 
	//+1 er fordi de ikke skal overskirve det er st�r i forvejen
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
	//Opgave 2
	//her laves svd'en
	SVD mySVD(A);

	// A matrix
	cout << "A matrix" << endl;
	print(A);
	cout << endl;
	//u matrix
	cout << "u matrix" << endl;
	print(mySVD.u);
	cout << endl;
	//w matrix
	cout << "w matrix" << endl;
	print(mySVD.w);
	cout << endl;
	//v matrix
	cout << "v matrix" << endl;
	print(mySVD.v);
	cout << endl;

	//test
	//print(A);

	//Opgave 3
	// for de kooficenter man vil finde
	mySVD.solve(z, q);
	print(q);


	//Opgave 4
	// jeg kan ikke tr�kke dem fra hianden. Jeg ved ikke hvorfor Burde bare v�re abs(A*q-z)
	//VecDoub reserror = abs(A*q - z);





	//opgave 5
	// Beregner fejlen via formel 15.4.19
	Doub resulterror = 0;
	cout << endl;
	for (int i = 0; i < mySVD.v.nrows() - 1; i++)
	{
		for (int j = 0; j < mySVD.v.ncols() - 1; j++)
		{
			resulterror = resulterror + pow(mySVD.v[i][j] / mySVD.w[i], 2);
		}
	}
	cout << "ressult error: " << resulterror << endl;


	system("pause");




	return 0;
}


*/

/*

// SteenBjornCRVintherNumPort1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

*/