#pragma once

#include "Sequences.h"

//переопредиление методов
template<typename T>
class LinkedListSequence : public Sequence<T> {
public:

    LinkedListSequence() : data() {}

    LinkedListSequence(T *items, int count) : data(items, count) {}

    LinkedListSequence(int count) : data(count) {}


    LinkedListSequence(const LinkedList<T> &list) {//конструктор по объекту
        LinkedList<T> *tmp = new LinkedList<T>(list);
        std::cout << "Constructor by object . . .\n";
        data = *tmp;
    }

    int GetLength() {
        return data.GetLength();
    }

    T &GetFirst() {
        return data.GetFirst();
    }

    T &GetLast() {
        return data.GetLast();
    }


    T &Get(int index) {
        return data.Get(index);
    }

    void Append(T item) {
        data.Append(item);
    }

    void Prepend(T item) {
        data.Prepend(item);
    }

    void InsertAt(T item, int index) {
        data.InsertAt(item, index);
    }

    void removeAt(int index) {
        data.removeAt(index);
    }

    void Print() {
        data.print_from_begin();
    }

    void CountSort() override {
        ICountSort<T> obj;
        obj.Sort(nullptr,this);
    }

    void QuickSort(bool(*cmp1)(const T &, const T &), bool(*cmp2)(const T &, const T &)) override {
        IQuickSort<T> obj;
        obj.Sort(cmp1, this, cmp2);
    }

    void SelectionSort(bool(*cmp)(const T &, const T &)) override {
        ISelectionSort<T> obj;
        obj.Sort(cmp, this);
    }

private:
    LinkedList<T> data;
};
