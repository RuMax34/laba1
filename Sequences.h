#pragma once

#include "DynamicArray.h"
#include "LinkedList.h"

template<typename T>//виртуальные абстрактный класс в возможностью определения методов
class Sequence {
public:

    virtual T &GetFirst() = 0;// без реализации

    virtual T &GetLast() = 0;

    virtual T &Get(int index) = 0;

    virtual void CountSort() = 0;

    virtual void QuickSort(bool(*cmp1)(const T &, const T &), bool(*cmp2)(const T &, const T &)) = 0;

    virtual void SelectionSort(bool(*cmp)(const T &, const T &)) = 0;

    virtual int GetLength() = 0;

    virtual void Append(T item) = 0;

    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, int index) = 0;


    virtual void Print() = 0;
};


