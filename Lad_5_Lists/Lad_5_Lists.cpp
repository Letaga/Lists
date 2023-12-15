#include <iostream>
#include <string>

using namespace std;

template <typename T>
class list
{

    class Cnot
    {
        Cnot* beforCnot;
        Cnot* nextCnot;
        T data;
        Cnot(T t)
        {
            beforCnot = nextCnot = nullptr;
            data = t;
        }
        Cnot()
        {
            beforCnot = nextCnot = nullptr;
            data = 0;
        }
    };
    Cnot* begin;
    Cnot* end;
    int size;

public:
    list()
    {
        size = 0;
        begin = end = nollptr;
    }

};

int main()
{
    list<char> Text;
    list<int> Nomber;
    cout << "hello world";
}