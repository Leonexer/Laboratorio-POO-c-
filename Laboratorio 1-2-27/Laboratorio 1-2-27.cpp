#include <iostream>

using namespace std;

class Node
{
public:
    Node(int val);
    ~Node();
    int value;
    Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
}

Node::~Node()
{
}
class List
{
public:
    List();
    ~List();
    int size();
    void push_front(int value);
    void push_back(int value);
    bool pop_front(int& value);
private:
    Node* head;
    Node* tail;
};

List::List() : head(nullptr), tail(nullptr)
{
}

List::~List()
{
    while (head != nullptr) {
        Node* n = head;
        head = head->next;
        delete n;
    }
}

int List::size()
{
    int totalSize{ 0 };
    Node* reco = head;
    while (reco != nullptr) {
        totalSize += 1;
        reco = reco->next;
    }
    return totalSize;
}

void List::push_front(int value)
{
    Node* new_head = new Node(value);
    new_head->next = head;
    head = new_head;
    tail = head;
}

void List::push_back(int value) 
{
    if (head == nullptr)
    {
        push_front(value);
        return;
    }

    Node* new_tail = new Node(value);
    tail->next = new_tail;
    tail = new_tail;
}

bool List::pop_front(int& value)
{
    if (head != nullptr)
    {
        Node* popped = head;        // guarda el objeto a borrar
        head = head->next;          // mueve el tope al siguiente nodo
        value = popped->value;      // retornar el valor del objeto a borrar mediante la referencia
        delete popped;              // borrar el  objeto sin referencias
        return true;
    }
    // implement the pop
    // don't forget to delete the popped node!
    // and fix the return value
    return false;
}

int main()
{
    List list;
    //
    for (int i = 1;i < 5;i++)
    {
        list.push_back(i);
       // cout << "Pushed:: " << i << " Size : " << list.size() << endl;
    }


    int value = 0;
    while (list.pop_front(value))
    {
        cout << "Popped: " << value << "  Size : " << list.size() << endl;
    }

    return 0;
}