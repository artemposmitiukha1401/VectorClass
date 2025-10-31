#include <iostream>
#include <string.h>
#include "MyVector.h"
#include "Subscriber.h"

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
    std::cout << "Enter min range for values: "; is >> min_range;
    std::cout << "Enter max range for values: "; is >> max_range;
    v.FillArr(min_range, max_range);
    std::cout << v;
    return is;
}

typedef MyVector<> vec_i;
typedef MyVector<double> vec_d;
typedef MyVector<std::string> vec_s;
typedef MyVector<float> vec_f;
typedef MyVector<long> vec_l;
typedef MyVector<long long> vec_ll;
typedef MyVector<unsigned int> vec_ui;
typedef MyVector<unsigned long> vec_ul;
typedef MyVector<char> vec_c;
typedef MyVector<bool> vec_b;

int main() {
    srand(time(nullptr));
    // // int arr[] = {4,4233,425};
    // // vec_i vector{(arr)};
    // // vector.GetData();
    // // MyVector<double> vector2{{342.32 , 342.42542}};
    // // vector2.GetData();
    // // std::string arr = {"4534534", "dfgdfg"};
    vec_s string_vector{{"dfsfdsfds", "fsdfdsf", "fdsf"}};
    string_vector.GetData();
    string_vector.SortByCmp();
    string_vector.GetData();
    string_vector.Insert(99, "fdsfg");
    // vec_i nums_vector{{4543, 653, 234}};
    // nums_vector.GetData();
    // nums_vector *= 5;
    // nums_vector.GetData();
    // // string_vector.SortByCmp();
    // // string_vector.GetData();
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

    // Subscriber sub2("Elena Kovalenko", "38756421", "50912345");
    // Subscriber sub1("Artem Posmitiukha", "45234532", "45423524");
    // Subscriber sub3("Dmitry Shevchenko", "41298765", "63847291");
    // Subscriber sub4("Natalia Bondarenko", "39654123", "52173648");
    // Subscriber sub5("Igor Tkachenko", "44567890", "61234987");
    // Subscriber sub6("Svetlana Marchenko", "37891234", "58903421");
    // Subscriber sub7("Alexey Moroz", "42345678", "54678123");
    // Subscriber sub8("Olga Petrenko", "40987654", "59876543");
    // Subscriber sub9("Viktor Lysenko", "43216789", "57654321");
    // Subscriber sub10("Anastasia Kravchenko", "46789012", "62345789");
    // MyVector<Subscriber> subs{{sub2, sub1, sub3, sub4, sub5, sub6, sub7, sub8}};

    return 0;
}