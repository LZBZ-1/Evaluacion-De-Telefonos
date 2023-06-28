#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

template <typename U>
struct Node {
    U data;
    unique_ptr<Node<U>> next = nullptr;
};

template <typename U>
class List {
private:
    unique_ptr<Node<U>> firstNode = nullptr;
    Node<U>* lastNode = nullptr;
    int count = 0;

    void addValues(U value) {
        push_back(value);
    }

    template <typename... Args>
    void addValues(U value, Args... args) {
        push_back(value);
        addValues(args...);
    }

public:
    List() = default;

    template <typename... Args>
    List(Args... args) : firstNode(nullptr) {
        addValues(args...);
    }

    bool isEmpty() const {
        return firstNode == nullptr;
    }

    void push_back(U value) {
        auto newNode = make_unique<Node<U>>();
        newNode->data = value;
        if (isEmpty()) {
            firstNode = std::move(newNode);
            lastNode = firstNode.get();
        } else {
            lastNode->next = std::move(newNode);
            lastNode = lastNode->next.get();
        }
        count++;
    }

    void push_front(U value) {
        auto newNode = make_unique<Node<U>>();
        newNode->data = value;
        if (isEmpty()) {
            firstNode = std::move(newNode);
            lastNode = firstNode.get();
        } else {
            newNode->next = std::move(firstNode);
            firstNode = std::move(newNode);
        }
        count++;
    }

    void insert(int position, U value) {
        if (position == 0) {
            push_front(value);
        } else if (position > 0 && position <= count) {
            auto newNode = make_unique<Node<U>>();
            newNode->data = value;
            Node<U>* previousNode = firstNode.get();
            int currentPosition = 1;

            while (currentPosition < position) {
                previousNode = previousNode->next.get();
                currentPosition++;
            }

            newNode->next = std::move(previousNode->next);
            previousNode->next = std::move(newNode);
            count++;
        } else {
            throw out_of_range("Invalid position");
        }
    }

    void pop_back() {
        if (isEmpty()) {
            return;
        }

        if (firstNode->next == nullptr) {
            firstNode.reset(nullptr);
            lastNode = nullptr;
            count = 0;
            return;
        }

        Node<U>* temp = firstNode.get();
        while (temp->next->next != nullptr) {
            temp = temp->next.get();
        }

        temp->next.reset(nullptr);
        lastNode = temp;
        count--;
    }

    void pop_front() {
        if (isEmpty()) {
            return;
        }

        firstNode = std::move(firstNode->next);
        if (firstNode == nullptr) {
            lastNode = nullptr;
        }
        count--;
    }

    void erase(int position) {
        if (position == 0) {
            pop_front();
        } else if (position > 0 && position < count) {
            Node<U>* previousNode = firstNode.get();
            int currentPosition = 0;

            while (currentPosition < position - 1) {
                previousNode = previousNode->next.get();
                currentPosition++;
            }

            previousNode->next = std::move(previousNode->next->next);
            if (previousNode->next == nullptr) {
                lastNode = previousNode;
            }
            count--;
        } else {
            throw out_of_range("Invalid position");
        }
    }

    int size() const {
        return count;
    }

    void clear() {
        firstNode.reset(nullptr);
        lastNode = nullptr;
        count = 0;
    }

    U operator[](int position) const {
        Node<U>* current = firstNode.get();
        int currentPosition = 0;

        while (current != nullptr && currentPosition < position) {
            current = current->next.get();
            currentPosition++;
        }

        if (current != nullptr) {
            return current->data;
        } else {
            throw out_of_range("Invalid position");
        }
    }
};