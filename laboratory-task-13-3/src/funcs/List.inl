/*===============================================================================*/
/*============================= Конструкоры =====================================*/
/*===============================================================================*/

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& rhs) : head(nullptr), size(0) {
    Node* temp = rhs.head;
    while (temp) {
        append(temp->data);
        temp = temp->next;
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}




/*===============================================================================*/
/*========================== Оператор присваивания ==============================*/
/*===============================================================================*/

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs) {
    if (this != &rhs) {
        clear();
        Node* temp = rhs.head;
        while (temp) {
            append(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}




/*===============================================================================*/
/*================================= Геттер ======================================*/
/*===============================================================================*/

template<typename T>
size_t LinkedList<T>::getSize() const {
    return this->size;
}




/*===============================================================================*/
/*======================= Основные методы List ==================================*/
/*===============================================================================*/

template<typename T>
void LinkedList<T>::prepend(const T& data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    ++size;
}

template<typename T>
void LinkedList<T>::append(const T& data) {
    if (!head) {
        prepend(data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    ++size;
}

template<typename T>
void LinkedList<T>::removeFirst() {
    if (!head) {
        throw std::logic_error("The head is missing");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    --size;
}

template<typename T>
void LinkedList<T>::removeLast() {
    if (!head) {
        throw std::logic_error("The head is missing");
    }
    if (!head->next) {
        removeFirst();
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    --size;
}

template<typename T>
void LinkedList<T>::remove(const T& data) {
    if (!head) {
        throw std::logic_error("The head is missing");
    }
    if (head->data == data) {
        removeFirst();
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        --size;
    }
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::search(const T& data, size_t& comparisons) {
    Node* temp = head;
    while (temp && temp->data != data) {
        temp = temp->next;
        ++comparisons;
    }
    return temp;
}

template<typename T>
void LinkedList<T>::modifyAll(const std::function<void(T&)>& modifier) {
    Node* temp = head;
    while (temp) {
        modifier(temp->data);
        temp = temp->next;
    }
}

template<typename T>
void LinkedList<T>::forEach(const std::function<void(const T&)>& callback) const {
    Node* temp = head;
    while (temp) {
        callback(temp->data);
        temp = temp->next;
    }
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
void LinkedList<T>::clear() {
    while (head) {
        removeFirst();
    }
}

