#include "MyVector.h"
#include <iostream>
#include <__ostream/basic_ostream.h>

const int MIN_RAND = -100;
const int MAX_RAND = 100;

MyVector::MyVector(int size) : capacity(size), arr(new int[size]{}), size(size), grow(1) {}

MyVector::MyVector(std::initializer_list<int> init_arr)
: size(init_arr.size()), arr(new int[size]), capacity(init_arr.size()), grow(1) {
    int i = 0;
    for (int value : init_arr) arr[i++] = value;
}

MyVector::MyVector(const int *init_arr, const int &size)
: size(size), arr(new int[size]), capacity(size), grow(1) {
    for (int i = 0; i < size; i++) arr[i] = init_arr[i];
}

MyVector::MyVector(const MyVector &other)
: size(other.size), arr(new int[other.capacity]), capacity(other.capacity), grow(other.grow) {
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
}
MyVector::MyVector(MyVector&& other)
: size(other.size), arr(other.arr), capacity(other.capacity), grow(other.grow)
{
    other.size = 0;
    other.arr = nullptr;
    other.capacity = 0;
}

void MyVector::Append(const MyVector &other) {
    int buffer_size = capacity + other.capacity;
    int* buffer = new int[buffer_size];
    for (int i = 0; i < size; i++) buffer[i] = arr[i];
    for (int i = 0; i < other.size; i++) buffer[i + size] = other.arr[i];
    capacity = buffer_size;
    size += other.size;
    delete[] arr;
    arr = buffer;
}

void MyVector::RemoveAll() {
    delete[] arr;
    arr = nullptr;
    capacity = 0;
    size = 0;
}

bool MyVector::IsEmpty() const {
    return size == 0 || arr == nullptr;
}

int MyVector::GetAt(const int index) const {
    if (index >= 0 && index < size) return arr[index];
    return -1;
}

void MyVector::SetAt(const int index, const int value) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of bounds\n";
        return;
    }
    arr[index] = value;
}

void MyVector::GetData() const {
    std::cout << "\n[VECTOR MEMORY ADDRESS]: " << arr << std::endl;
    std::cout << "[VECTOR VALUES]: | ";
    for (int i = 0; i < size; i++) std::cout << arr[i] << " | ";
    std::cout << std::endl;
}


void MyVector::FillArr() {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
}

void MyVector::FillArr(int min_range, int max_range) {
    min_range = abs(min_range);
    max_range = abs(max_range);
    if (max_range < min_range) std::swap(min_range, max_range);

    for (int i = 0; i < size; i++)
        arr[i] = rand() % (max_range - min_range + 1) + min_range;
}

void MyVector::FillArr(int max_range) {
    max_range = abs(max_range);

    for (int i = 0; i < size; i++)
        arr[i] = rand() % max_range;
}

int MyVector::GetRandNum() { return rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND; }

int MyVector::GetRandNum(const int min_range, const int max_range) { return rand() % (max_range - min_range + 1) + min_range; }

int MyVector::GetRandNum(const int max_range) { return rand() % max_range; }


void MyVector::SortByIncreasing() {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = size - 1; j > i; j--) {
            if (arr[j] < arr[j - 1])
                std::swap(arr[j], arr[j - 1]);
        }
    }
}

void MyVector::SortByDecreasing() {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = size - 1; j > i; j--) {
            if (arr[j] > arr[j - 1])
                std::swap(arr[j], arr[j - 1]);
        }
    }
}


MyVector & MyVector::operator=(const MyVector &other) {
    if (this ==  &other) return *this;
    delete[] arr;

    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new int[capacity];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];

    return *this;
}

MyVector MyVector::operator+(const MyVector &other) const {
    int united_size = this->size + other.size;
    MyVector united_vector(united_size);
    united_vector.grow = this->grow;
    united_vector.size = this->size + other.size;
    for (int i = 0; i < size; i++) united_vector.arr[i] = arr[i];
    for (int i = size; i < other.size; i++) united_vector.arr[i + size] = other.arr[i];
    return united_vector;
}
void MyVector::SetSize(int new_size, int new_grow) {
    grow = new_grow;

    if (new_size > capacity) {

        int new_capacity = capacity;

        while (new_capacity < new_size)
            new_capacity += grow;

        int* buffer_arr = new int[new_capacity]{};
        for (int i = 0; i < size; i++) buffer_arr[i] = arr[i];

        delete[] arr;
        arr = buffer_arr;
        capacity = new_capacity;
    }

}

void MyVector::PushBack(int value) {
    if (size >= capacity) SetSize(size + 1, grow);

    arr[size] = value;
    size++;
}

void MyVector::Insert(int index, int value) {
    if (index < 0 || index > size) {
        std::cerr << "Invalid index\n";
        return;
    }

    if (size >= capacity) SetSize(size + 1, grow);
    for (int i = size; i > index; i--) arr[i] = arr[i - 1];

    arr[index] = value;
    size++;
}