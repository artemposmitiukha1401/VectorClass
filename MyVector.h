#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <initializer_list>

class MyVector {
    int size = 0;
    int capacity = 0;
    int grow = 1;
    int* arr = nullptr;
public:
    MyVector(int size);
    MyVector(std::initializer_list<int> init_arr);
    MyVector(const int* init_arr, const int& size);
    MyVector(const MyVector& other);
    MyVector(MyVector&& other);
    ~MyVector() { delete[] arr; }
    int GetSize() const { return size; }
    void Append(const MyVector& other);
    void RemoveAll();
    bool IsEmpty() const;
    int GetAt(int index) const;
    void SetAt(const int index, const int value);
    void GetData() const;
    void FillArr();
    void FillArr(const int min_range, const int max_range);
    void FillArr(const int max_range);
    static int GetRandNum();
    static int GetRandNum(const int min_range, const int max_range);
    static int GetRandNum(const int max_range);
    void SortByIncreasing();
    void SortByDecreasing();

    int& operator[](int index) {
        if (index >= 0 && index < GetSize()) return arr[index];
        else return arr[0];
    }
    const int& operator[](int index) const {
        if (index >= 0 && index < GetSize()) return arr[index];
        else return arr[0];
    }
    MyVector& operator=(const MyVector& other);
    MyVector operator+(const MyVector& other) const;
    MyVector operator++(int);
    MyVector operator--(int);
    void SetSize(int new_size, int new_grow);
    void PushBack(int value);
    void Insert(int index, int value);

};

#endif
