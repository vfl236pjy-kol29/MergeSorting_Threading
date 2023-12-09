#include <iostream>
#include<string>
#include<vector>
#include<random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<future>
#include "MergeSortingThreading.h"
using namespace std;


typedef int Data_t;
vector <Data_t> input_vector()
{
	srand(0);
	long arr_size;
	cout << "Введите размер массива-вектора, не менее 10000000 элементов" << endl;
	cin >> arr_size;
	cout << "Размер массива:   " << arr_size << endl;
	vector<Data_t>A;
	for (long i = 0; i < arr_size; i++) {
		A[i] = rand() % 500000;
		A.push_back(A[i]);
	}
	return A;
}

void print_vector(const std::vector<int>& A)
{
	for (auto& x : A)
	{
		cout << x << "  ";
	}
	cout << '\n';
}

void merge_sort(vector <Data_t>& A)
{
	size_t N = A.size();
	if (N <= 1) return;
	vector<Data_t> left; vector<Data_t> right;
	for (int i = 0; i < N / 2; i++)
		{
		left.push_back(A[i]);
		}
	for (int i = N / 2; i < N; i++)
		{
		right.push_back(A[i]);
		}	
	merge_sort(left);
	merge_sort(right);
	merge_sorted_vectors(left, right, A);

	if (make_thread )
	{
		
		auto f = async(launch::async, [&]() {merge_sort(left);});
		merge_sort(right);
	}
	else {
		// запускаем обе части синхронно
		merge_sort(left);
		merge_sort(right);
		merge_sorted_vectors(left, right, A);
	}




}

void merge_sorted_vectors(const vector<Data_t>& A, const vector<Data_t>& B, const vector<Data_t>& C)
{
	A.size(); B.size(); 
	vector<Data_t>C;



	size_t i = 0; int k = 0; int n = 0;
	while (A.size() and B.size())
		{
		if (A[i] <= B[k])
			{
			C[n] = A[i];
			n++; i++;
			}
		else
			{
			if (A[i] > B[k])
					{
				C[n] = B[k]; n++; k++;
					}
			}
		}
	while (k < B.size())
		{
		C[n] = B[k]; k++; n++;
		}
	while (i < A.size())
		{
		C[n] = A[i]; i++; n++;
		}
}




