#pragma once
#include <iostream>
#include<string>
#include<vector>
using namespace std;

typedef int Data_t;
bool make_thread = true;
vector <Data_t> input_vector();
void print_vector(const std::vector<int>& A);
void merge_sort(vector <Data_t>& A);
void merge_sorted_vectors(const vector<Data_t>& A, const vector<Data_t>& B, const vector<Data_t>& C);
