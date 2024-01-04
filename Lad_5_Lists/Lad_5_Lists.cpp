/*Кураева Анна*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int EntrEdge(int x, int l, int r, bool language) //Checking the validity of values
{
    double y;
    cin >> y;
    while (y < l || y > r)
    {
        if (language)
            cout << "Enter another number\n";
        else
            cout << "Введите другое число\n";

        cin >> y;
    }
    x = y;
    return x;
}

void dfs(vector <bool>& visited, vector<vector<int>>& graph);
void toplogical(vector <bool>& visited, vector<vector<int>>& graph, vector<int>& tSort, int v);
void bfs(vector <bool>& visited, vector<vector<int>>& graph);

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

    int size;

public:
    Node* head;

    int getSize()
    {
        return size;
    }
    int getHead()
    {
        return head->data;
    }
    void pop()
    {
        if (!empty())
        {
        Node* tmp = head;
        head = head->nextN;
        delete tmp;
        }
        size--;
    }
    bool empty()
    {
        return head == nullptr;
    }

    void addOne(int value); //Add node to the begging of the list
    void addBeg(int nAdd, bool language); //Add n node to the begging
    void cOut(); //Output list on the console
    void sort(); //Sorting a simple insert
    void swapData(Node* N1, Node* N2);
    void swMinMax();
    void sum(list L);
    void swapElement(Node* before, Node* befCurrent);
    void sum2(list L);


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

void list::addBeg(int nAdd, bool language)
{
    int value = 0;
    if (language)
    {
        cout << "Enter the values of the elements\n";
    }
    else
    {
        cout << "Введите значения элементов\n";
    }
    for (int i = 0; i < nAdd; i++)
    {
        value = EntrEdge(value, INT_MIN, INT_MAX, language);
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

void list::swapData(Node* N1, Node* N2)
{
    int tmp = N1->data;
    N1->data = N2->data;
    N2->data = tmp;
}

void list::swMinMax()
{
    Node* max = head;
    Node* min = head;
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data > max->data)
            max = current;
        if (current->data < min->data)
            min = current;
        current = current->nextN;
    }
    swap(min, max);
}

void list::swapElement(Node* before, Node* befCurrent)
{
    if (before->nextN == befCurrent)
    {
        this->swapData(before->nextN, befCurrent->nextN);
        return;
    }
    Node* tmp = befCurrent->nextN->nextN;
    Node* next = before->nextN;
    before->nextN = befCurrent->nextN;
    befCurrent->nextN->nextN = next;
    befCurrent->nextN = tmp;
}

void list::sort()
{
    Node* current = head;
    Node* buf = head;
    while (current->nextN != nullptr)
    {
        if (head->data > current->nextN->data)
        {
            this->swapElement(head, current);
            current = current->nextN;
            continue;
        }
        while (buf->nextN != current->nextN)
        {
            if (buf->nextN->data > current->nextN->data)
            {
                this->swapElement(buf, current);
                break;
            }
        }
        current = current->nextN;
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

void list::sum2(list L)
{
    Node* lst1 = head;
    Node* lst2 = L.head;
    Node* newHead = nullptr;
    Node* current = nullptr;

    while (true)
    {
        if (lst1 == nullptr)
        {
            lst1 = lst2;
            return;
        }
        if (lst2 == nullptr)
            return;

        if (lst1->data > lst2->data)
        {
            Node* buf = newHead;
            newHead = lst1;
            lst1 = lst1->nextN;
            newHead->nextN - buf;
        }
        else if (lst2->data > lst1->data)
        {
            Node* buf = newHead;
            newHead = lst2;
            lst2 = lst2->nextN;
            newHead->nextN - buf;
        }
    }

    
}


// ===============================  MAIN  ===============================
int main()
{
    setlocale(LC_ALL, "Ru");
    srand(time(0));

    bool language = true, entr = true;
    int size1 = 0, size2 = 6;
    cout << "Enter the language,\n0 - Ru, 1 - En\n";
    //size1 = EntrEdge(size1, 0, 1, language);
    language = size1;

    if (language)
        cout << "Enter values from the keyboard - 1, use the prepared values - 0";
    else
        cout << "Ввести значения с клавиатуры - 1, воспользоваться заготовленными значениями - 0";
    //size1 = EntrEdge(size1, 0, 1, language);
    //entr = size1;

    if (language)
        cout << "Enter the length of the list and its values\n size = ";
    else
        cout << "Введите длину списка и его значения\n size = ";

    size1 = EntrEdge(size1, 0, INT_MAX, language);
    list lst1;
    list lst2;

    if (entr)
        lst1.addBeg(size1, language);
    else
    {
        for (int i = size2 - 1; i >= 0; i--)
        {
            lst1.addOne(rand() % 30 - 10);
        }
        cout << "lst1 =\n";
        lst1.cOut();
    }

    //======= swap max & min ========
    lst1.swMinMax();
    if (language)
        cout << "The specified list after permutation of the minimum and maximum elements" << endl;
    else
        cout << "Заданный список после перестановки минимального и максимального элементов" << endl;
    lst1.cOut();

    //========   list implementation   ========
    if (language)
        cout << "Adding an element with a value of 5 to the top of the stack" << endl;
    else
        cout << "Добавление элемента со значением 5 в верх стека" << endl;

    lst1.addOne(5);
    lst1.cOut();

    if (language)
        cout << "The current size of the list" << endl;
    else
        cout << "Текуший размер списка" << endl;

    cout << lst1.getSize() << endl;

    for (int i = size2 - 1; i >= 0; i--)
        lst2.addOne(i + 5);

    cout << "list 2 = " << endl;
    lst2.cOut();

    if (language)
        cout << "The top element of the stack" << endl;
    else
        cout << "Верхний элемент стека" << endl;
    cout << lst2.getHead();

    if (language)
        cout << "Removing the top element of the stack" << endl; ///=====================
    else
        cout << "Удаление верхнего элемента стека" << endl;

    /*lst1.sort();
    if (language)
        cout << "Sorted first list" << endl;
    else
        cout << "Отсортированный первый список" << endl;

    lst1.cOut();*/


    /*lst1.sum2(lst2);
    if (language)
        cout << "\n\nCombined lists into one sorted list" << endl;
    else
        cout << "\n\nОбъединенные списки в один отсортированный список" << endl;

    lst1.cOut();

    if (language)
        cout << "The size of the combined list " << lst1.getSize() << endl;
    else
        cout << "Размер объединённого списка " << lst1.getSize() << endl;*/


    // -------------------------   Graphs   -----------------------------
    if (language)
        cout << "\n===========   Graphs   ===========" << endl;
    else
        cout << "\n===========   Графы   ===========" << endl;

    vector<vector<int>> graph;
    if (entr)
    {
        if (language)
            cout << "Enter the dimension of the graph" << endl;
        else
            cout << "Введите размерность графа" << endl;
        size1 = EntrEdge(size1, 1, 100, language);
        graph.resize(size1);
        for (int i = 0; i < size1; i++)
            graph[i].resize(size1);
        cout << endl;

        if (language)
            cout << "Enter the values of the graph elements" << endl;
        else
            cout << "Введите значения элементов графа" << endl;
        for (int i = 0; i < size1; i++)
        {
            cout << i+1 << ". ";
            for (int j = 0; j < i; j++)
                cout << graph[i][j] << " ";
            for (int j = i; j < size1; j++)
            {
                if (i == j)
                {
                    graph[i][j] = 0;
                    cout << graph[i][j] << " ";
                    continue;
                }
                cin >> graph[i][j];
                graph[j][i] = graph[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        graph.resize(size2);
        for (int i = 0; i < size2; i++)
        graph =
        {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 0, 0},
            {1, 0, 0, 0, 0}
        };
    }
    vector <bool> visited(graph.size(), 0);

    //===============  graph output  ===============
    if (language)
        cout << "Enter the values of the graph elements" << endl;
    else
        cout << "\nГраф" << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    //-------  dfs --------
    if (language)
        cout << "dfs\n";
    else
        cout << "Поиск в глубину\n";
    
    dfs(visited, graph);
    cout << "this\n";

    //-------- bfs --------
    visited = vector<bool>(graph.size(), 0);
    if (language)
        cout << "bfs\n";
    else
        cout << "Поиск в ширину\n";
     
    bfs(visited, graph);
     
    //-------- topological --------
    vector <int> tSort;
    cout << "size = " << tSort.size() << endl;
    for (int x : tSort)
        cout << x << " ";
     
    vector<vector<int>> graph2;
    if (entr)
    {
        if (language)
            cout << "Enter the dimension of the graph" << endl;
        else
            cout << "Введите размерность графа" << endl;
        size1 = EntrEdge(size1, 1, 100, language);
        graph.resize(size1);
        for (int i = 0; i < size1; i++)
            graph[i].resize(size1);
        cout << endl;

        if (language)
            cout << "Enter the values of the graph elements" << endl << "It is important that the graph is cycle-free!" << endl;
        else
            cout << "Введите значения элементов графа" << endl << "Важно чтобы граф был без циклов!" << endl;

        for (int i = 0; i < size1; i++)
        {
            cout << i + 1 << ". ";
            for (int j = 0; j < size1; j++)
            {
                if (i == j)
                {
                    graph[i][j] = 0;
                    cout << graph[i][j] << " ";
                    continue;
                }
                graph[i][j] = EntrEdge(graph[i][j], 0, 1, language);
                graph[j][i] = graph[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        graph2.resize(4);
        for (int i = 0; i < graph2.size(); i++)
            graph[i].resize(graph2.size());
            graph2 =
        {
            {0, 0, 0, 1},
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0}
        };
    }
    
    //===============  graph output  ===============
    if (language)
        cout << "Enter the values of the graph elements" << endl;
    else
        cout << "\nГраф" << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    

    vector <bool> visited2(graph2.size(), 0);
    if (language)
        cout << "Topological sorting\n";
    else
        cout << "Топологическая сортировка\n";
     
    toplogical(visited2, graph2, tSort, 0);

    cout << "End program, enter anything...";
    char a;
    cin >> a;

    lst1.~list();
    lst2.~list();
    return 0;
}
// ======================================================================

void dfs(vector <bool>& visited, vector<vector<int>>& graph)
{
    list v; // v - the vertex of the graph
    v.addOne(0);
    while (!v.empty())
    {
        int currV = v.getHead();
        if (!visited[currV])
            cout << "v = " << currV << endl;
        visited[currV] = true;
        v.pop();
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[currV][i] && !visited[i])
            {
                v.addOne(i);
            }
        }
    }
}

void toplogical(vector <bool>& visited, vector<vector<int>>& graph, vector<int>& tSort, int v)
{
    visited[v] = true;
    cout << "v = " << v << endl;
    for (int i = 0; i < graph.size(); i++)
    {

        if (graph[v][i] && !visited[i])
        {
            toplogical(visited, graph, tSort, i);
        }
    }

    tSort.push_back(v);
}

void bfs(vector <bool>& visited, vector<vector<int>>& graph)
{
    queue<int> v;
    v.push(0);
    while (!v.empty())
    {
        int currV = v.front();
        if (!visited[currV])
            cout << "v = " << currV << endl;
        visited[currV] = true;
        v.pop();
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[currV][i] != 0 && !visited[i])
                v.push(i);
        }
    }
}
