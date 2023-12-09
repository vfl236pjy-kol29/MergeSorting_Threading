#include <iostream>
#include<string>
#include<vector>
#include<random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MergeSortingThreading.h"
using namespace std;

int main()
{
    typedef int Data_t;
    vector<Data_t>A = input_vector();
    print_vector(A);

    time_t start, end;


    // ������������� ������
    time(&start);
    merge_sort(A);
    time(&end);
    double seconds = difftime(end, start);
    cout << "����� ������������� ���������� ����������   " << seconds << "  ������" << endl;
    for (long i = 0; i < A.size() - 1; i++) {
        if (A[i] > A[i + 1]) {
            cout << "Unsorted" << endl;
            break;
        }
    }

    cout << '\n' << endl;
    cout << '\n' << endl;


    /*for (long i = 0; i < A.size(); i++) {
        A[i] = rand() % 500000;
    }*/


    vector<Data_t>A = input_vector();
    print_vector(A);

    // ������������ ������
    make_thread = false;
    time(&start);
    merge_sort(A);
    time(&end);
    seconds = difftime(end, start);
    cout << "����� ������������� ���������� ����������   " << seconds << "  ������" << endl;
    
    return 0;
}