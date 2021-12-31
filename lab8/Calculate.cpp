#include <iostream>
#include "Calculate.h"
#include "Stack.h"

int Calculate::Priority(char symbol) {
    if (symbol == '+' || symbol == '-') { return 1; }
    if (symbol == '*' || symbol == '/') { return 2; }
    else return 0;
}

bool Calculate::SimplifyMathExpression(Stack<Leksema> &stack_of_numbers,
                                       Stack<Leksema> &stack_of_operations,
                                       Leksema item) {
    double first_top, after_first_top, current_top;
    first_top = stack_of_numbers.GetTopValue().value;
    stack_of_numbers.pop();
    switch (stack_of_operations.GetTopValue().type) {
        case '+':after_first_top = stack_of_numbers.GetTopValue().value;
            stack_of_numbers.pop();
            current_top = first_top + after_first_top;
            break;
        case '-':after_first_top = stack_of_numbers.GetTopValue().value;
            stack_of_numbers.pop();
            current_top = after_first_top - first_top;
            break;
        case '*':after_first_top = stack_of_numbers.GetTopValue().value;
            stack_of_numbers.pop();
            current_top = after_first_top * first_top;
            break;
        case '/':after_first_top = stack_of_numbers.GetTopValue().value;
            if (first_top == 0) {
                throw std::runtime_error("You can't divide by zero");
            }
            stack_of_numbers.pop();
            current_top = after_first_top / first_top;
            break;
        default:std::cerr << "Error";
            return false;
    }
    stack_of_operations.pop();
    item.type = '0';
    item.value = current_top;
    stack_of_numbers.push(item);
    return true;
}

void Calculate::ReadExpression(const std::string &expression_) {
    char symbol;
    std::string expression = ProcessExpression(expression_);
    for (int i= 0; i< expression.size(); ++i ) {
        symbol = expression[i];

        if (symbol == ' ') {
            continue;
        }

        if (symbol >= '0' && symbol <= '9' || symbol == '-' && flag == 1 || symbol == '+' && flag == 1) {
            int k = i;
            while (symbol >= '0' && symbol <= '9'|| symbol== '.' ){
                ++i;
                symbol = expression[i];

            }
            if (i != expression.length()){
                --i;
            }
            std:: string string_value;
            string_value = expression.substr(k, (i-k+1));
            value = std::stod(string_value);
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
                continue;
            }

            if (!stack_of_operations.isEmpty() &&
                Priority(symbol) > Priority(stack_of_operations.GetTopValue().type)) {
                item.type = symbol;
                item.value = 0;
                stack_of_operations.push(item);
                continue;
            }
            if (!stack_of_operations.isEmpty() &&
                Priority(symbol) <= Priority(stack_of_operations.GetTopValue().type)) {
                if (!SimplifyMathExpression(stack_of_numbers, stack_of_operations,
                                            item)) {
                    throw std::runtime_error("Something wrong");
                }

                stack_of_operations.push(Leksema(symbol, 0));
                continue;
            }
        }
        if (symbol == '(') {
            flag = 1;
            item.type = symbol;
            item.value = 0;
            stack_of_operations.push(item);
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

void Calculate::ReadExpression(std::istream &in) {
    std::string expression;
    in >> expression;
    ReadExpression(expression);
}

bool Calculate::IsNumber(char c) {
    return c >= '0' && c <= '9';
}

std::string Calculate::ProcessExpression(std::string _expression) {
    if (!IsNumber(_expression[0]))
        _expression.insert(0, "0");
    for (int i = 0; i < _expression.length(); ++i) {
        if (_expression[i] == '(' && !IsNumber(_expression[i + 1]))
            _expression.insert(i + 1, "0");
    }
    size_t pos = _expression.find("+-");
    if (pos != std::string::npos)
        _expression.replace(pos, 2, "+0-");
    pos = _expression.find("-+");
    if (pos != std::string::npos)
        _expression.replace(pos, 2, "-");
    pos = _expression.find("--");
    if (pos != std::string::npos)
        _expression.replace(pos, 2, "+");
    pos = _expression.find("++");
    if (pos != std::string::npos)
        _expression.replace(pos, 2, "+");
    return _expression;
}

void Calculate::InputExpression(const std::string &str) {
    ReadExpression(str);
}

