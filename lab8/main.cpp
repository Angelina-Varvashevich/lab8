#include <iostream>

class Stack {
public:
    Stack() : top(-1), size(0) {
    }

    int recapacity(int size) {
        if (size > capacity)
            return capacity + 50;
    }

    bool isEmpty() {
        return !size;
    }

    int GetTopValue() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return array_for_stack[top];
    }

    int &operator[](size_t index) {
        if (index > top) {
            throw std::runtime_error("Go through board");
        }
        return array_for_stack[index];
    }

    int pop() {/// возвращает тот, который извлекли
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        size--;
        return array_for_stack[top--];///  сначала берем значение, потом удаляем

    }

    int &operator>>(int top) {//////////// аккуратненько здесь, ведь делитаеть нужно только с вершинки
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        size--;
        return array_for_stack[top--];

    }

    void push(int value) {
        recapacity(size);
        array_for_stack[++top] = value;
        ++size;
    }

    void operator<<(int value) {
        recapacity(size);
        array_for_stack[++top] = value;
        ++size;
    }

    bool operator==(const Stack &other) {
        return this->size == other.size;
    }

    bool operator<(const Stack &other) {
        return this->size < other.size;
    }

    Stack &operator=(const Stack &other) {
        if (size!=0) {
            delete[] this->array_for_stack;
        }
        this->size = other.size;
        this->top = other.top;
        this->array_for_stack = new int[other.size];
        for (int i = 0; i < other.size; i++) {
            this->array_for_stack[i] = other.array_for_stack[i];
        }
        return *this;
    }

    void print(std::ostream &out) {
        for (int i = top - 1; i >= 0; i--) {
            out << array_for_stack[i] << "  ";
        }
    }

private:
    int size; // можно обойтись и без сайз, если топ больше капасити, то увеличиваем капасити фция ресайз
    int capacity = 100;
    int *array_for_stack = new int[capacity]; /// добавить еще одну переменую и сравнивать с сайз  и делать ресайз
    int top;

};

int main() {
    Stack a;
    a.push(34);
    a.push(356);
    a << 14;
    a << 56;
    std::cout << a[0] << std::endl;
    std::cout << a[1] << std::endl;
    std::cout << a[2] << std::endl;
    std::cout << std::endl;
    std::cout << a.pop() << std::endl;
    std::cout << (a >> 1) << std::endl;
    std::cout << a[0] << std::endl;
    std::cout << a[1] << std::endl;
    std::cout << a[2] << std::endl;
    /// std::cout<< a.pop()<< std::endl;
    /// std::cout<< a[3]<< std::endl;
    a.print(std::cout);
    std::cout << "-----------------------------";
    Stack b;
    b.push(34);
    b.push(356);
    b << 14;
    b << 56;
    b << 110;
    b << 123;
    a = b;
    a.print(std::cout);

    Stack v;
    v<< 11;
    v<< 22;
    Stack c;
    c<< 33;
    c<< 44;
    c<< 55;
    c<< 77;
    v=c;
    v.print(std::cout);


    return 0;
}
