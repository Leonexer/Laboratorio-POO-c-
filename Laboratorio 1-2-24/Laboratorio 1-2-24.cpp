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
    void push_front(int value);
    bool pop_front(int& value);
private:
    Node* head;
};

List::List() : head(nullptr)
{
}

void List::push_front(int value)
{
    Node* new_head = new Node(value);
    new_head->next = head;
    head = new_head;
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
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    int value = 0;
    while (list.pop_front(value))
    {
        cout << value << endl;
    }
    return 0;
}