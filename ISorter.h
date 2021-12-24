#include "Sequences.h"
#include <map>
template<typename T>
class ISorter {
public:
    virtual void Sort(bool(*cmp1)(const T &, const T &), Sequence<T> *seq, bool(*cmp2)(const T &, const T &)) = 0;
};

template<typename T>//сортировка подсчетом o(n+k)k-диапозон эллементов
class ICountSort : public ISorter<T> {
public:
    void
    Sort(bool(*cmp1)(const T &, const T &), Sequence<T> *seq, bool(*cmp2)(const T &, const T &) = nullptr) override {
        std::map<const T,int> count;
        for (int i = 0; i < seq->GetLength(); ++i) {// потупает функция для сравнения
            ++count[seq->Get(i)];
        }

        int index = 0;
        for(std::pair<const T,int>& item : count){
            while(item.second != 0){
                seq->Get(index) = item.first;
                item.second--;
                index++;
            }
        }
    }
};

template<typename T>
class IQuickSort : public ISorter<T> {
public:
    void
    Sort(bool(*cmp1)(const T &, const T &), Sequence<T> *seq, bool(*cmp2)(const T &, const T &) = nullptr) override {
        int i = 0;
        int j = 0;
        int left = 0;
        int right = 0;
        LinkedList<int> stack;
        stack.Append(left);
        stack.Append(seq->GetLength() - 1);

        do {
            right = stack.GetLast();
            stack.pop_back();
            left = stack.GetLast();
            stack.pop_back();

            i = left;
            j = right;

            int pivot = (left + right) / 2;
            T pivot_value = seq->Get(pivot);

            do {
                while (cmp1(seq->Get(i), pivot_value)) {
                    ++i;
                }
                while (cmp2(seq->Get(j), pivot_value)) {
                    --j;
                }
                if (i <= j) {
                    T tmp = seq->Get(i);
                    seq->Get(i) = seq->Get(j);
                    seq->Get(j) = tmp;
                    ++i;
                    --j;
                }
            } while (i <= j);
            if (i < right) {
                stack.Append(i);
                stack.Append(right);
            }
            if (j > left) {
                stack.Append(left);
                stack.Append(j);
            }
        } while (stack.GetLength());
    }
};

template<typename T>//сортировка выборомo(n2)
class ISelectionSort : public ISorter<T> {
public:
    void
    Sort(bool(*cmp1)(const T &, const T &), Sequence<T> *seq, bool(*cmp2)(const T &, const T &) = nullptr) override {
        for (int num = 0; num < seq->GetLength(); ++num) {
            int min_value = num;
            for (int item = num; item < seq->GetLength(); ++item) {
                if (cmp1(seq->Get(min_value), seq->Get(item)))
                    min_value = item;
            }
            T tmp = seq->Get(num);
            seq->Get(num) = seq->Get(min_value);
            seq->Get(min_value) = tmp;
        }
    }
};