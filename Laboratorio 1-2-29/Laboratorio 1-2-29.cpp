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
    List(const List& copy);
    ~List();
    int size();
    void push_front(int value);
    void push_back(int value);
    bool pop_front(int& value);
    bool pop_back(int& value);

    int at(int index);
    void insert_at(int index, int value);
    void remove_at(int index);

private:
    Node* head;
    Node* tail;
};

List::List() : head(nullptr), tail(nullptr)
{
}

List::List(const List& copy) : head(nullptr), tail(nullptr) //Para que no compartan nodos las listas copia, (que no apunten a la misma direccion de memoria),
{
    Node* curr = copy.head;
    while (curr != nullptr) {           //Y aquí se inicializan
        push_back(curr->value);
        curr = curr->next;
    }
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

    if (head->next == nullptr)
    {
        tail = head;
    }
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
        Node* popped = head;        
        head = head->next;         
        value = popped->value;      
        delete popped;              
        return true;
    }
    return false;
}

bool List::pop_back(int& value)
{
    if (tail != nullptr)
    {
        if (head == tail)
        {
            value = head->value;
            delete head;
            head = tail = nullptr;
            return true; 
        }

        Node* new_tail = head;

        while (new_tail->next != tail)
        {
            new_tail = new_tail->next;
        }

        value = tail->value;
        delete tail;
        tail = new_tail;
        tail->next = nullptr;
        return true;
    }
    // implement the pop
    // don't forget to delete the popped node!
    // and fix the return value
    return false;
}

int List::at(int index) 
{ 
    if (index < 0 || index >= size()) {
        cout << "Invalid index" << endl;
        return 0;
    }

    Node* Reco = head;
    for (int i = 0; i < index; i++) {
        Reco = Reco->next;
    }
    return Reco->value;
}


void List::remove_at(int index)
{
    if (index >= size() || index < 0) { cout << "Invalid index" << endl;return; }

    Node* DeletedNode = head;
    Node* DeletedNodePrev = head;

    if (index == 0) {   //Para indice 0 y listas de un solo elemento
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete DeletedNode;
        return;
    }

    for (int i = 0;i < index;i++)
    {
        DeletedNodePrev = DeletedNode;
        DeletedNode = DeletedNode->next;
    }

    if (DeletedNode == tail)
    {
        DeletedNodePrev->next = nullptr;
        tail = DeletedNodePrev;
    }
    else
    {
        DeletedNodePrev->next = DeletedNode->next;
    }

    delete DeletedNode;
}

void List::insert_at(int index, int value)
{
    if (index > size() || index < 0) { cout << "Invalid index" << endl;return; }
    else if (index == 0)
    {
        push_front(value);
        return;
    }
    else if (index == size())
    {
        push_back(value);
        return;
    }

    Node* RecoPrev = head;
    Node* NewNode = new Node(value);

    for (int i = 0;i < index - 1;i++)
    {
        RecoPrev = RecoPrev->next;
    }

    NewNode->next = RecoPrev->next;
    RecoPrev->next = NewNode;

}

void printList(List& list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << "list[" << i << "] == " << list.at(i) << endl;
    }
}

int main()
{
    List list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    printList(list);
    cout << endl;

    list.remove_at(2);
    printList(list);
    cout << endl;

    list.insert_at(1, 6);
    printList(list);

    return 0;
}