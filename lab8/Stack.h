#ifndef LAB8_STACK_H
#define LAB8_STACK_H

#include <iostream>

template<typename T>
class Stack {
public:
    Stack() : top(-1), size(0) {}

    bool isEmpty();

    T GetTopValue();

    int Size();

    T &operator[](size_t index) {
        if (index > top || index <0 ) {
            throw std::runtime_error("Go through board");
        }
        return array_for_stack[index];
    }

    T pop();

    T &operator>>(int top) {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        size--;
        return array_for_stack[top--];

    }

    void push(T value);

    void operator<<(T value) {
        resize_if_needed();
        array_for_stack[++top] = value;
        ++size;
    }

    bool operator==(const Stack<T> &other) {
        return this->size == other.size;
    }

    bool operator<(const Stack<T> &other) {
        return this->size < other.size;
    }

    Stack &operator=(const Stack <T> &other) {
        if (size!=0) {
            delete[] this->array_for_stack;
        }
        this->size = other.size;
        this->top = other.top;
        this->array_for_stack = new T[other.size];
        for (int i = 0; i < other.size; i++) {
            this->array_for_stack[i] = other.array_for_stack[i];
        }
        return *this;
    }

    void print(std::ostream &out);

private:
    static const int MIN_CAPACITY;
    static const int GROWTH_FACTOR;
    int size;
    int capacity = MIN_CAPACITY;
    T *array_for_stack = new T[capacity];
    int top;

    void resize_if_needed();

};

template<typename T>
const int Stack<T>::MIN_CAPACITY = 10;

template<typename T>
const int Stack<T>::GROWTH_FACTOR = 2;

template<class T>
bool Stack<T>::isEmpty() {
    return size == 0;
}

template<typename T>
T Stack<T>::GetTopValue() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return array_for_stack[top];
}

template<typename T>
int Stack<T>::Size() {
    return size;
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    size--;
    return array_for_stack[top--];

}

template<typename T>
void Stack<T>::push(T value) {
    resize_if_needed();
    array_for_stack[++top] = value;
    ++size;
}

template<typename T>
void Stack<T>::print(std::ostream &out) {
    for (int i = top - 1; i >= 0; i--) {
        out << array_for_stack[i] << "  ";
    }
}

template<typename T>
void Stack<T>::resize_if_needed() {
    if (size + 1 == capacity) {
        T *new_array_for_stack = new T[capacity * GROWTH_FACTOR];
        for (int i = 0; i < size; ++i) {
            new_array_for_stack[i] = array_for_stack[i];
        }
        delete[] array_for_stack;
        array_for_stack = new_array_for_stack;
        capacity *= GROWTH_FACTOR;
    }
}

#endif //LAB8_STACK_H
