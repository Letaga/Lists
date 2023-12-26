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
            data = data1;
            nextN = Next;
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
    void sort(); //Sorting a simple insert
    void swap(Node* N1, Node* N2);
    void swMinMax();
    void sum(list L);

    //int& operator[] (int);
    //void addEnd(int n);//Добавление элемента в конец
    //int get(int ind);

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

void list::swap(Node* N1, Node* N2)
{
    int tmp = N1->data;
    N1->data = N2->data;
    N2->data = tmp;
}

void list::swMinMax()
{
    Node* max = head;
    Node* min = head;
    Node* cerrent = head;
    while (cerrent != nullptr)
    {
        if (cerrent->data > max->data)
            max = cerrent;
        if (cerrent->data < min->data)
            min = cerrent;
        cerrent = cerrent->nextN;
    }
    swap(min, max);
}

void list::sort()
{
    int buf;
    Node* tmp = head;
    Node* iN = head;
    Node* jN;
    while (iN!=nullptr)
    {
        tmp = iN;
        jN = head;
        while (tmp->data > jN->data && jN != iN)
        {
            jN = jN->nextN;
        }
        buf = jN->data;
        jN->data = tmp->data;
        iN->data = buf;
        iN = iN->nextN;
    }
}

void list::sum(list L)
{
    Node* current = L.head;
    while (current != nullptr)
    {
        this->addOne(current->data);
        current = current->nextN;
    }

    this->sort();
}



// ===============================  MAIN  ===============================
int main()
{
    setlocale(LC_ALL, "");

    int size1 = 0, size2 = 5;

    cout << "Введите длину списка и его значения\n size = ";
    size1 = EntrEdge(size1, 1, INT_MAX);
    list lst1;
    list lst2;
    for (int i = size2 - 1; i >= 0; i--)
    {
        lst2.addOne(i + 5);
    }

    lst1.addBeg(size1);


    cout << "list 1 = " << endl;
    lst1.cOut();

    cout << "swap" << endl;
    lst1.swMinMax();

    cout << "Заданный список после перестановки минимального и максимального элементов" << endl;
    lst1.cOut();

    lst1.sort();
    cout << "Отсортированный первый список" << endl;
    lst1.cOut();

    cout << "list 2 = " << endl;
    lst2.cOut();

    lst1.sum(lst2);
    cout << "\n\nОбьединённые списки" << endl;
    lst1.cOut();

    cout << "Размер объединённого списка " << lst1.getSize() << endl;

     cout << "End program, enter anything...";
     cin >> size1;
     
    lst1.~list();
    lst2.~list();
    return 0;
}
// ======================================================================