#include <iostream>

using namespace std;

int EntrEdge(int x, int l, int r) //Checking the validity of values
{
    double y;
    cin >> y;
    while (y < l || y > r)
    {
        cout << "Введите другое число\n";
        cin >> y;
    }
    x = y;
    return x;
}


class list
{
private:
    class Node
    {
    public:
        Node(int data1, Node* addres)
        {
            data = data1;
            nextN = addres;
        }

        int data;
        Node* nextN;
    };

    Node* head;
    int size;

public:
    int getSize()
    {
        return size;
    }

    void addBeg(int value);

    list()
    {
        size = 0;
        head = nullptr;
    }
    ~list();

};

list::~list()
{
    while (size)
    {
        if (size <= 0) return;
        Node* temp = head;
        head = head->nextN;
        delete temp;
        size--;
    }
}



void list::addBeg(int value)
{
    if (head == nullptr)
    {
        head = new Node(value, nullptr);
        size++;
    }
    else
    {
        Node tmp(value, nullptr);
        size++;
    }

}

// ===============================  MAIN  ===============================
int main()
{
    setlocale(LC_ALL, "");

    int size_1 = 0, size_2 = 5;

    cout << "Введите длину списка и его значения\n size = ";
    size_1 = EntrEdge(size_1, 0, INT_MAX);
    list lst_1;
    list lst_2;

    lst_1.addBeg(5);
    lst_1.addBeg(7);
    cout << "Размер списка " << lst_1.getSize();

    cout << "End program, enter anything...";
    cin >> size_1;
}
// ======================================================================