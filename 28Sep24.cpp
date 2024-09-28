//    https://leetcode.com/problems/design-circular-deque/description/
class NodeOfDeque {
public:
    int value;
    NodeOfDeque* prev;
    NodeOfDeque* next;

    NodeOfDeque(int value, NodeOfDeque* prev = nullptr, NodeOfDeque* next = nullptr) 
        : value(value), prev(prev), next(next) {}
};

class MyCircularDeque {
private:
    int size;
    int maxSize;
    NodeOfDeque* front;
    NodeOfDeque* rear;

public:
    MyCircularDeque(int k) : size(0), maxSize(k), front(nullptr), rear(nullptr) {}

    bool insertFront(int value) {
        if (isFull())
            return false;
        if (!front) 
            front = rear = new NodeOfDeque(value);
        else 
            front = front->prev = new NodeOfDeque(value, nullptr, front);
        size += 1;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        if (!front) 
            front = rear = new NodeOfDeque(value);
        else 
            rear = rear->next = new NodeOfDeque(value, rear, nullptr);
        size += 1;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        if (front == rear) 
            front = rear = nullptr;
        else 
            (front = front->next)->prev = nullptr;
        size -= 1;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        if (front == rear) 
            front = rear = nullptr;
        else 
            (rear = rear->prev)->next = nullptr;
        size -= 1;
        return true;
    }

    int getFront() {
        return front ? front->value : -1;
    }

    int getRear() {
        return rear ? rear->value : -1;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == maxSize;
    }
};
