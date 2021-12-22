#include <iostream>
#include "Calculate.h"
#include "Stack.h"

int Calculate::Priority(char symbol) {
    if (symbol == '+' || symbol == '-') { return 1; }
    if (symbol == '*' || symbol == '/') { return 2; }
    else return 0;
}

bool
Calculate::SimplifyMathExpression(Stack<Leksema> &stack_of_numbers, Stack<Leksema> &stack_of_operations, Leksema item) {
    double first_top, after_first_top, current_top;
    first_top = stack_of_numbers.GetTopValue().value;
    stack_of_numbers.pop();
    switch (stack_of_operations.GetTopValue().type) {
        case '+':
            after_first_top = stack_of_numbers.GetTopValue().value;
            stack_of_numbers.pop();
            current_top = first_top + after_first_top;
            break;
        case '-':
            after_first_top = stack_of_numbers.GetTopValue().value;
            stack_of_numbers.pop();
            current_top = after_first_top - first_top;
            break;
        case '*':
            after_first_top = stack_of_numbers.GetTopValue().value;
            stack_of_numbers.pop();
            current_top = after_first_top * first_top;
            break;
        case '/':
            after_first_top = stack_of_numbers.GetTopValue().value;
            if (first_top == 0) {
                std::cerr << "You can't divide by zero" << std::endl;
                return false;
            }
            stack_of_numbers.pop();
            current_top = after_first_top / first_top;
            break;
        default:
            std::cerr << "Error";
            return false;
    }
    stack_of_operations.pop();
    item.type = '0';
    item.value = current_top;
    stack_of_numbers.push(item);
    return true;
}

void Calculate::ReadExpression() {
    char symbol;
    while (10) {
        symbol = std::cin.peek();
        if (symbol == '\n')
        {
            break;
        }

        if (symbol == ' ') {
            std::cin.ignore();
            continue;
        }

        if (symbol >= '0' && symbol <= '9' || symbol == '-' && flag == 1 || symbol == '+' && flag == 1) {
            std::cin >> value;
            item.type = '0';
            item.value = value;
            stack_of_numbers.push(item);
            flag = 0;
            continue;
        }
        if (symbol == '+' && flag == 0 || symbol == '-' && flag == 0 || symbol == '*' || symbol == '/') {

            if (stack_of_operations.Size() == 0) {
                item.type = symbol;
                item.value = 0;
                stack_of_operations.push(item);
                std::cin.ignore();
                continue;
            }

            if (!stack_of_operations.isEmpty() && Priority(symbol) > Priority(stack_of_operations.GetTopValue().type)) {
                item.type = symbol;
                item.value = 0;
                stack_of_operations.push(item);
                std::cin.ignore();
                continue;
            }
            if (!stack_of_operations.isEmpty() &&
                Priority(symbol) <= Priority(stack_of_operations.GetTopValue().type)) {
                if (!SimplifyMathExpression(stack_of_numbers, stack_of_operations,
                                            item)) {
                    std::cerr << "Something wrong" << std::endl;
                }
                continue;
            }
        }
        if (symbol == '(') {
            flag=1;
            item.type = symbol;
            item.value = 0;
            stack_of_operations.push(item);
            std::cin.ignore();
            continue;
        }
        if (symbol == ')') {
            while (stack_of_operations.GetTopValue().type != '(') {
                if (!SimplifyMathExpression(stack_of_numbers, stack_of_operations,
                                            item)) {
                    throw std::runtime_error("Incorrect input. Not enough )");
                } else continue;
            }
            stack_of_operations.pop();
            std::cin.ignore();
            continue;
        } else {
            throw std::runtime_error("Input isn't correct");
        }
    }
}

double Calculate::Result() {
    while (!stack_of_operations.isEmpty()) {
        if (!SimplifyMathExpression(stack_of_numbers, stack_of_operations, item)) {
            throw std::runtime_error("Something wrong!");
        } else continue;
    }
    return stack_of_numbers.GetTopValue().value;
}

void Calculate::PrintResult(std::ostream &out) {
    std::cout << "Answer: " << stack_of_numbers.GetTopValue().value << std::endl;
}

/*bool Calculate::SymbolNearSymbol(Stack<Leksema> &stack_of_numbers, Stack<Leksema> &stack_of_operations){
    if(stack_of_operations.Size()> stack_of_numbers.Size()-1) {
        throw std::runtime_error("Number near number");
    }
    return true;
}*/

/*bool Calculate::SymbolsNear(char ch){
    double fist_n = stack_of_numbers.GetTopValue().value;
    stack_of_numbers.pop();
    double prev_n = stack_of_numbers.GetTopValue().value;
    stack_of_numbers.pop();
    double current;
    Leksema item;
    if (fist_n && prev_n && ( ch=='-' && stack_of_operations.GetTopValue().type == '+') ){
        current == prev_n - fist_n;
    }

    if (fist_n && prev_n && ( ch== '+' &&  stack_of_operations.GetTopValue().type == '-') ){
        current == prev_n + fist_n;

    }
    item.value=current;
    item.type='0';
    stack_of_numbers.push(item);
    return true;

}*/
