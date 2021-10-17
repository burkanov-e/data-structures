#include <iostream>

using namespace std;

void badSwap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void goodSwap01(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void goodSwap02(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

template <typename T>
void auSwap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    cout << "1st int: ";
    int a;
    cin >> a;

    cout << "2nd int: ";
    int b;
    cin >> b;

    cout << "std::swap\n";
    cout << "Before swap a = " << a << ", b = " << b << "\n";
    swap(a, b);
    cout << "After swap a = " << a << ", b = " << b << "\n";

    cout << "badSwap:\n";
    cout << "Before swap a = " << a << ", b = " << b << "\n";
    badSwap(a, b);
    cout << "After swap a = " << a << ", b = " << b << "\n";

    cout << "goodSwap01:\n";
    cout << "Before swap a = " << a << ", b = " << b << "\n";
    goodSwap01(&a, &b);
    cout << "After swap a = " << a << ", b = " << b << "\n";

    cout << "goodSwap02:\n";
    cout << "Before swap a = " << a << ", b = " << b << "\n";
    goodSwap02(a, b);
    cout << "After swap a = " << a << ", b = " << b << "\n";

    cout << "general swap for doubles:\n";
    double d1 = 2.34;
    double d2 = 1.45;
    cout << "Before swap d1 = " << d1 << ", d2 = " << d2 << "\n";
    auSwap(d1, d2);
    cout << "After swap d1 = " << d1 << ", d2 = " << d2 << "\n";

    cout << "general swap for strings:\n";
    string s1 = "Hello";
    string s2 = "World";
    cout << "Before swap s1 = " << s1 << ", s2 = " << s2 << "\n";
    auSwap(s1, s2);
    cout << "After swap s1 = " << s1 << ", s2 = " << s2 << "\n";
}