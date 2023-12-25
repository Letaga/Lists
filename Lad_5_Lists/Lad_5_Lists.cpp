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

// Класс список
class list
{
private:
    class Node
    {
    public:
        Node(int data1, Node* Next)
        {
            this->data = data1;
            this->nextN = Next;

            //data = data1;
            //nextN = Next;
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

    void addOne(int value); //Add node to the begging of the list
    void addBeg(int nAdd); //Add n node to the begging
    void cOut(); //Output list on the console

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
        if (size <= 0) 
            return;
        Node* tmp = head;
        head = head->nextN;
        delete tmp;
        size--;
    }
}

void list::addOne(int value)
{
    head = new Node(value, head);
    size++;
}

void list::addBeg(int nAdd)
{
    int value = 0;
    cout << "Введите значения элементов\n";
    for (int i = 0; i < nAdd; i++)
    {
        value = EntrEdge(value, INT_MIN, INT_MAX);
        this->addOne(value);
    }
}

void list::cOut()
{
    Node* tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->nextN;
    }
    cout << endl;
}


// ===============================  MAIN  ===============================
int main()
{
    setlocale(LC_ALL, "");

    int size1 = 0, size2 = 5;

    cout << "Введите длину списка и его значения\n size = ";
    size1 = EntrEdge(size1, 0, INT_MAX);
    list lst1;
    list lst2;
    for (int i = size2 - 1; i >= 0; i--)
    {
        lst2.addOne(i + 5);
    }

    lst1.addBeg(size1);

    cout << "list 1 = " << endl;
    lst1.cOut();

    cout << "list 2 = " << endl;
    lst2.cOut();

    cout << "Размер списка 2 = " << lst2.getSize() << endl;

    cout << "End program, enter anything...";
    cin >> size1;
}
// ======================================================================