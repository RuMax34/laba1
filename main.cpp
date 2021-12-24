#include <iostream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Functions.h"
#include <time.h>
#include <ctime>
int main() {

    int N;
    std::cin >> N;
    int *data=new int[N];
    std::cout << "Start data : ";
    for (int i = 0; i < N; ++i) {
        data[i] = rand() % 1000;
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
    {
        unsigned int start_time =  clock();
        std::cout << "Array SelectionSort : ";
        ArraySequence<int> a(data, N);
        a.SelectionSort(cmp3);
        a.Print();
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time;
        std::cout <<"search time"<<search_time;
    }
    {
        unsigned int start_time =  clock();
        std::cout << "List SelectionSort : ";
        LinkedListSequence<int> a(data, N);
        a.SelectionSort(cmp3);
        a.Print();
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time;
        std::cout <<"search time"<<search_time;
    }

    {
        unsigned int start_time =  clock();
        std::cout << "Array QuickSort : ";
        ArraySequence<int> a(data, N);
        a.QuickSort(cmp2, cmp3);
        a.Print();
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time;
        std::cout <<"search time"<<search_time;
    }
    {
        unsigned int start_time =  clock();
        std::cout << "List QuickSort : ";
        LinkedListSequence<int> a(data, N);
        a.QuickSort(cmp2, cmp3);
        a.Print();
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time;
        std::cout <<"search time"<<search_time;
    }

    {
        unsigned int start_time =  clock();
        std::cout << "Array CountSort : ";
        ArraySequence<int> a(data, N);
        a.CountSort();
        a.Print();
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time;
        std::cout <<"search time"<<search_time;
    }
    {
        unsigned int start_time =  clock();
        std::cout << "List CountSort : ";
        LinkedListSequence<int> a(data, N);
        a.CountSort();
        a.Print();
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time;
        std::cout <<"search time"<<search_time;
    }


    return 0;
}
