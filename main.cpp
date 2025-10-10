#include <iostream>
#include "MyVector.h"

int main() {
    srand(time(nullptr));

    MyVector vector({34, 5, 3, 53});
    vector.GetData();
    vector *= 5;
    vector.GetData();
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