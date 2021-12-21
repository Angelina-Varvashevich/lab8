#include "Stack.h"

#ifndef LAB8_CALCULATE_H
#define LAB8_CALCULATE_H

struct Leksema;

class Calculate {

private:

    struct Leksema {
        char type;
        double value;

        Leksema() : type('X'), value(-1) {};

        explicit Leksema(char type_, double value_) : type(type_), value(value_) {}

    };

    double value;
    bool flag = 1;
    Stack<Leksema> stack_of_numbers;
    Stack<Leksema> stack_of_operations;
    Leksema item;

    static int Priority(char symbol);

    static bool
    SimplifyMathExpression(Stack<Leksema> &stack_of_numbers, Stack<Leksema> &stack_of_operations, Leksema item);


public:
    Calculate() = default;

    Calculate(double value_, const Leksema &item_) : value(value_), item(item_) {}

    double Result();

    void ReadExpression();

    void PrintResult(std::ostream &out);


};


#endif //LAB8_CALCULATE_H
