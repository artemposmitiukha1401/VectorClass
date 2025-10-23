#include<iostream>
using namespace std;

class A
{
    int a;
    double c;
public:
    A()
    {
        a = 0;
        c = 0;
    }
    A(int a1, double c1)
    {
        a = a1;
        c = c1;
    }
    int GetA()const
    {
        return a;
    }
    int GetC()const
    {
        return c;
    }
    //A operator +(A & obj) // если закоментировать , то в шаблоне класса + работать не будет!!
    //{
    //  cout << "A + \n";
    //  A rez;
    //  rez.a = a + obj.a;
    //  rez.c = c + obj.c;
    //  return rez;
    //}
};
// через константный указатель(сущности), можно вызвать ТОЛЬКО константные методы, поэтому GetA  const!!
//ostream& operator<<(ostream & os, const A & obj)//  "Правильная"  перегрузка  :)
//{
//  os << obj.GetA() << endl;
//  os << obj.GetC() << endl;
//  return os;
//}
class B
{
    double b;
public:
    B()
    {
        b = 0;
    }
    B(double b1)
    {
        b = b1;
    }
    double GetB()const
    {
        return b;
    }
    /*B operator +(B & obj)
    {
      cout << "B + \n";
      B rez(b + obj.b);
      return rez;
    }*/

};
//ostream& operator<<(ostream & os, const B & obj)  //  "Правильная"  перегрузка  :)
//{
//  os << obj.GetB() << endl;
//  return os;
//}

template<class T1, class T2>
class Test
{
    T1 a;
    T2 b;
public:
    Test()
    {
        a = 0;
        b = 0;
    }
    Test(T1 a1, T2 b1)
    {
        a = a1;
        b = b1;
    }
    Test operator +(Test & obj2)
    {
        cout << "Test +\n";
        Test rez(a + obj2.a, b + obj2.b);
        return rez;
    }
    void Show()
    {
        cout << "A - "<<a<<"B - " << b << endl;
    }
};

void main()
{
    Test<int, double> obj1(1,1.3);
    Test<int, double> obj2(2, 2.3);

    Test<int, double> obj3 = obj1 + obj2;
    obj3.Show();


    //Test<A, B> obj1(A(1,2.4), B(7.9));
    //Test<A, B> obj2(A(2,3.6), B(2.2));

    //Test<A, B> rez = obj1 + obj2;
    //rez.Show();

    system("pause");
}