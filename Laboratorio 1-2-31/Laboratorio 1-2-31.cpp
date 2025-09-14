#include <iostream>
using namespace std;

class Node {
public:
    Node(int val);
    ~Node();
    int value;
    Node* next;
    Node* prev;
};

Node::Node(int val) : value(val), next(nullptr), prev(nullptr) {}
Node::~Node() {}

class List {
public:
    List();
    List(const List& copy);
    ~List();
    int size() const;
    void push_front(int value);
    void push_back(int value);
    bool pop_front(int& value);
    bool pop_back(int& value);

    int at(int index) const;
    void insert_at(int index, int value);
    void remove_at(int index);

private:
    Node* head;
    Node* tail;
};

List::List() : head(nullptr), tail(nullptr) {}

List::List(const List& copy) : head(nullptr), tail(nullptr) {
    Node* curr = copy.head;
    while (curr != nullptr) {
        push_back(curr->value);
        curr = curr->next;
    }
}

List::~List() {
    while (head != nullptr) {
        Node* n = head;
        head = head->next;
        delete n;
    }
}

int List::size() const {
    int totalSize = 0;
    Node* curr = head;
    while (curr != nullptr) {
        totalSize++;
        curr = curr->next;
    }
    return totalSize;
}

void List::push_front(int value) {
    Node* new_head = new Node(value);
    new_head->next = head;
    if (head != nullptr) {
        head->prev = new_head;
    }
    else {
        tail = new_head; // lista estaba vacía
    }
    head = new_head;
}

void List::push_back(int value) {
    Node* new_tail = new Node(value);
    if (tail != nullptr) {
        tail->next = new_tail;
        new_tail->prev = tail;
        tail = new_tail;
    }
    else {
        head = tail = new_tail;
    }
}

bool List::pop_front(int& value) {
    if (head == nullptr) return false;
    Node* popped = head;
    value = popped->value;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr; // la lista quedó vacía
    }
    delete popped;
    return true;
}

bool List::pop_back(int& value) {
    if (tail == nullptr) return false;
    Node* popped = tail;
    value = popped->value;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    }
    else {
        head = nullptr; // lista quedó vacía
    }
    delete popped;
    return true;
}

int List::at(int index) const {
    if (index < 0 || index >= size()) {
        cout << "Invalid index" << endl;
        return 0;
    }
    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->value;
}

void List::insert_at(int index, int value) {
    if (index < 0 || index > size()) {
        cout << "Invalid index" << endl;
        return;
    }
    if (index == 0) {
        push_front(value);
        return;
    }
    if (index == size()) {
        push_back(value);
        return;
    }

    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    Node* new_node = new Node(value);
    Node* prev_node = curr->prev;

    new_node->next = curr;
    new_node->prev = prev_node;
    prev_node->next = new_node;
    curr->prev = new_node;
}

void List::remove_at(int index) {
    if (index < 0 || index >= size()) {
        cout << "Invalid index" << endl;
        return;
    }
    if (index == 0) {
        int dummy;
        pop_front(dummy);
        return;
    }
    if (index == size() - 1) {
        int dummy;
        pop_back(dummy);
        return;
    }

    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    Node* prev_node = curr->prev;
    Node* next_node = curr->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;

    delete curr;
}

void printList(const List& list) {
    for (int i = 0; i < list.size(); i++) {
        cout << "list[" << i << "] == " << list.at(i) << endl;
    }
}

int main() {
    List list1;
    list1.push_front(1);
    list1.push_front(2);
    list1.push_front(3);
    list1.push_front(4);
    cout << "list1" << endl;
    printList(list1);
    cout << endl;

    List list2(list1);
    cout << "list2" << endl;
    printList(list2);
    cout << endl;

    list1.insert_at(1, 6);
    list2.remove_at(2);

    cout << "list1" << endl;
    printList(list1);
    cout << "list2" << endl;
    printList(list2);
    cout << endl;

    return 0;
}
