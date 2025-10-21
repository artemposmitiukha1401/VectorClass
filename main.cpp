#include <iostream>
#include <string.h>
#include "MyVector.h"

template <class T>
MyVector<T>& operator+(const int value, MyVector<T> &v) {
    for (int i = 0; i < v.GetSize(); ++i)
        v[i] += value;
    return v;
}

template <class T>
MyVector<T>& operator--(MyVector<T> &v) {
    if (v.GetSize() <= 0) return v;

    for (int i = 0; i < v.GetSize() - 1; i++) v[i] = v[i + 1];

    v.DecreaseSize();
    return v;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& v) {
    for (int i = 0; i < v.GetSize(); i++) os << "[" << v[i] << "] ";
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, MyVector<T>& v) {
    int min_range = 0;
    int max_range = 0;
    std::cout << "Enter min range for values: ";
    is >> min_range;
    std::cout << "Enter max range for values: ";
    is >> max_range;
    v.FillArr(min_range, max_range);
    std::cout << v;
    return is;
}
int main() {
    srand(time(nullptr));

    // MyVector vector{{34, 5, 3, 53}};
    // MyVector<double> vector2{{342.32 , 342.42542}};
    // vector2.GetData();
    // std::string arr = {"4534534", "dfgdfg"};
    MyVector<std::string> vector_3{"sfdfds", "fgfdsg"};
    // vector_3 = arr;
    vector_3.GetData();
    vector_3.PushBack("dgsfg");
    vector_3.GetData();


    // std::cout << vector;
    // vector();


    // vector.GetData();
    // vector *= 5;
    // vector.GetData();
    // MyVector vector_2 = 10 + vector;
    // vector_2.GetData();
    // MyVector vector_3 = --vector_2;
    // vector_3.GetData();
    // vector_2.GetData();
    // vector.SetSize(15, 4);
    // vector.PushBack(344);
    // vector.PushBack(543);
    // vector.Insert(3, 9999);
    // vector.Insert(16, 342);
    // vector.GetData();
    // MyVector vector2{{43,13 ,1 ,4 }};
    // MyVector copy(vector);
    // MyVector test = vector + vector2;
    // vector.Append(vector2);
    // vector.SetAt(1, 367);
    // std::cout << vector.GetAt(1) << std::endl;
    // vector.GetData();
    // MyVector copy2(10);
    // copy2.FillArr(10);
    // copy2.SortByIncreasing();
    // copy2.GetData();
    // vector.SortByIncreasing();
    // vector.GetData();

    return 0;
}