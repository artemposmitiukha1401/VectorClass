#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <initializer_list>
#include <iostream>
#include <string>

template <class ArrayType = int>
class MyVector {
    int size = 0;
    int capacity = 0;
    int grow = 1;
    ArrayType* arr = nullptr;
public:
    explicit MyVector(int size);
    MyVector(std::initializer_list<ArrayType> init_arr);
    template <const int SIZE>
    MyVector(const ArrayType (&init_arr)[SIZE]);
    MyVector(const MyVector& other);
    MyVector(MyVector&& other);
    ~MyVector() { delete[] arr; }
    int GetGrow() const { return grow; }
    int GetSize() const { return size; }
    void Append(const MyVector& other);
    void RemoveAll();
    void DecreaseSize() { if (size > 0) size--; }
    bool IsEmpty() const;

    ArrayType GetAt(int index) const;
    void SetAt(int index, ArrayType value);
    void GetData() const;
    void FillArr();
    void FillArr(int min_range, int max_range);
    void FillArr(int max_range);

    static int GetRandNum();
    static int GetRandNum(int min_range, int max_range);
    static int GetRandNum(int max_range);

    void SortByIncreasing() requires std::same_as<ArrayType, int> or std::same_as<ArrayType, double> or std::same_as<ArrayType, float>;
    void SortByDecreasing() requires std::same_as<ArrayType, int> or std::same_as<ArrayType, double> or std::same_as<ArrayType, float>;

    ArrayType& operator[](int index);
    const ArrayType& operator[](int index) const;
    MyVector& operator=(const MyVector& other);
    MyVector operator+(const MyVector& other) const;
    MyVector operator++(int);
    MyVector operator--(int);
    MyVector& operator*=(ArrayType value) requires std::same_as<ArrayType, int> or std::same_as<ArrayType, double> or std::same_as<ArrayType, float>;
    void operator()() const;

    void SetSize(int new_size, int new_grow);
    void PushBack(const ArrayType& value);
    void Insert(int index, const ArrayType& value);

    void SortByLength() requires std::same_as<ArrayType, std::string>;
    void SortByCmp() requires std::same_as<ArrayType, std::string>;
};
#endif

constexpr int MIN_RAND = -100;
constexpr int MAX_RAND = 100;

template <class T>
MyVector<T>::MyVector(int size) : size(size), capacity(size), arr(new T[size]{}) {}

template <class T>
MyVector<T>::MyVector(std::initializer_list<T> init_arr)
: size(init_arr.size()), capacity(init_arr.size()), arr(new T[size]) {
    int i = 0;
    for (T value : init_arr) arr[i++] = value;
}

template <class T>
template <const int SIZE>
MyVector<T>::MyVector(const T (&init_arr)[SIZE])
: size(SIZE), capacity(SIZE), arr(new T[SIZE]) {
    for (int i = 0; i < size; i++) arr[i] = init_arr[i];
}

template <class T>
MyVector<T>::MyVector(const MyVector &other)
: size(other.size), capacity(other.capacity), grow(other.grow), arr(new T[other.capacity]) {
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
}

template <class T>
MyVector<T>::MyVector(MyVector&& other)
: size(other.size), capacity(other.capacity), grow(other.grow), arr(other.arr)
{
    other.size = 0;
    other.arr = nullptr;
    other.capacity = 0;
}

template <class T>
void MyVector<T>::Append(const MyVector &other) {
    int buffer_size = capacity + other.capacity;
    T* buffer = new T[buffer_size];
    for (int i = 0; i < size; i++) buffer[i] = arr[i];
    for (int i = 0; i < other.size; i++) buffer[i + size] = other.arr[i];
    capacity = buffer_size;
    size += other.size;
    delete[] arr;
    arr = buffer;
}

template <class T>
void MyVector<T>::RemoveAll() {
    delete[] arr;
    arr = nullptr;
    capacity = 0;
    size = 0;
}
template <class T>
bool MyVector<T>::IsEmpty() const {
    return size == 0 || arr == nullptr;
}

template <class T>
T MyVector<T>::GetAt(const int index) const {
    if (index >= 0 && index < size) return arr[index];
    return -1;
}

template <class T>
void MyVector<T>::SetAt(const int index, const T value) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of bounds\n";
        return;
    }
    arr[index] = value;
}

template <class T>
void MyVector<T>::GetData() const {
    std::cout << "\n[VECTOR MEMORY ADDRESS]: " << arr << std::endl;
    std::cout << "[VECTOR VALUES]: | ";
    for (int i = 0; i < size; i++) std::cout << arr[i] << " | ";
    std::cout << std::endl;
}

template <class T>
void MyVector<T>::FillArr() {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
}

template <class T>
void MyVector<T>::FillArr(int min_range, int max_range) {
    min_range = abs(min_range);
    max_range = abs(max_range);
    if (max_range < min_range) std::swap(min_range, max_range);

    for (int i = 0; i < size; i++)
        arr[i] = rand() % (max_range - min_range + 1) + min_range;
}

template <class T>
void MyVector<T>::FillArr(int max_range) {
    max_range = abs(max_range);

    for (int i = 0; i < size; i++)
        arr[i] = rand() % max_range;
}

template <class T>
int MyVector<T>::GetRandNum() { return rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND; }

template <class T>
int MyVector<T>::GetRandNum(const int min_range, const int max_range) { return rand() % (max_range - min_range + 1) + min_range; }

template <class T>
int MyVector<T>::GetRandNum(const int max_range) { return rand() % max_range; }

template <class T>
void MyVector<T>::SortByIncreasing() requires std::same_as<T, int> or std::same_as<T, double> or std::same_as<T, float> {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = size - 1; j > i; j--) {
            if (arr[j] < arr[j - 1])
                std::swap(arr[j], arr[j - 1]);
        }
    }
}

template <class T>
void MyVector<T>::SortByDecreasing() requires std::same_as<T, int> or std::same_as<T, double> or std::same_as<T, float> {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = size - 1; j > i; j--) {
            if (arr[j] > arr[j - 1])
                std::swap(arr[j], arr[j - 1]);
        }
    }
}

template<class ArrayType>
ArrayType & MyVector<ArrayType>::operator[](int index) {
    if (index >= 0 && index < GetSize()) return arr[index];
    else return arr[0];
}

template<class ArrayType>
const ArrayType & MyVector<ArrayType>::operator[](int index) const {
    if (index >= 0 && index < GetSize()) return arr[index];
    return arr[0];
}

template <class T>
MyVector<T> & MyVector<T>::operator=(const MyVector &other) {
    if (this ==  &other) return *this;
    delete[] arr;

    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new T[capacity];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];

    return *this;
}

template <class T>
MyVector<T> MyVector<T>::operator+(const MyVector &other) const {
    int united_size = this->size + other.size;
    MyVector united_vector(united_size);
    united_vector.grow = this->grow;
    united_vector.size = this->size + other.size;
    for (int i = 0; i < size; i++) united_vector.arr[i] = arr[i];
    for (int i = 0; i < other.size; i++) united_vector.arr[i + size] = other.arr[i];
    return united_vector;
}

template <class T>
MyVector<T> MyVector<T>::operator++(int) {
    MyVector temp = *this;
    this->PushBack(T{});
    return temp;
}

template <class T>
MyVector<T> MyVector<T>::operator--(int) {
    MyVector temp = *this;
    if (size > 0) size--;
    return temp;
}

template <class T>
MyVector<T> & MyVector<T>::operator*=(const T value) requires std::same_as<T, int> or std::same_as<T, double> or std::same_as<T, float> {
    for (int i = 0; i < size; i++) arr[i] *= value;
    return *this;
}

template <class T>
void MyVector<T>::operator()() const {
    this->GetData();
    std:: cout << "[VECTOR GROW]: " <<this->GetGrow() << std::endl;
    std::cout << "[VECTOR SIZE]: " << this->GetSize() << std::endl;
}

template <class T>
void MyVector<T>::SetSize(int new_size, int new_grow) {
    grow = new_grow;

    if (new_size > capacity) {

        int new_capacity = capacity;

        while (new_capacity < new_size)
            new_capacity += grow;

        T* buffer_arr = new T[new_capacity]{};
        for (int i = 0; i < size; i++) buffer_arr[i] = arr[i];

        delete[] arr;

        arr = buffer_arr;
        capacity = new_capacity;
    }

}

template <class T>
void MyVector<T>::PushBack(const T& value) {
        if (size >= capacity) SetSize(size + 1, grow);

    arr[size] = value;
    size++;
}

template <class T>
void MyVector<T>::Insert(int index, const T& value) {
    if (index < 0 || index > size) {
        std::cerr << "Invalid index\n";
        return;
    }

    if (size >= capacity) SetSize(size + 1, grow);
    for (int i = size; i > index; i--) arr[i] = arr[i - 1];

    arr[index] = value;
    size++;
}

template <class T>
void MyVector<T>::SortByLength()
requires std::same_as<T, std::string> {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = size - 1; j > i; j--) {
            if (arr[j].length() < arr[j - 1].length())
                std::swap(arr[j], arr[j - 1]);
        }
    }
}

template <class T>
void MyVector<T>::SortByCmp() requires std::same_as<T, std::string> {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = size - 1; j > i; j--) {
            if (arr[j - 1] > arr[j])
                std::swap(arr[j], arr[j - 1]);
        }
    }
}
