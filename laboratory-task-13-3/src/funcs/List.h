#include <iostream>
#include <functional>


template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& newData) : data(newData), next(nullptr) {}
    };

    Node* head;
    size_t size;

public:
    // ������������ � ���������� 
    LinkedList();
    LinkedList(const LinkedList& rhs);
    ~LinkedList();

    // �������� ���������
    LinkedList& operator=(const LinkedList& rhs);

    // ������
    size_t getSize() const;

    // �������� ������ List
    void prepend(const T& data);
    void append(const T& data);
    void removeFirst();
    void removeLast();
    void remove(const T& data);
    Node* search(const T& data, size_t& comparisons);
    void modifyAll(const std::function<void(T&)>& modifier);
    void forEach(const std::function<void(const T&)>& callback) const;
    bool isEmpty();
    void clear();
};

#include "List.inl"

