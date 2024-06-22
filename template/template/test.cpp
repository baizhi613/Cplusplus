#include<iostream>
using namespace std;
template<typename T>
class Base
{
public:
    T _a;
public:
    Base(T n) :_a(n) {}
    T get() const { return _a; }
};
template<typename T, typename U>
class Derive :public Base<U>
{
public:
    U _b;
public:
    Derive(T t, U u) :Base<T>(t), _b(u) {}
    U sum() const { return _b + U(Base::get()); }
};
int main()
{

    return 0;
}