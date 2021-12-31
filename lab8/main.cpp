#include <iostream>
#include "Stack.h"
#include "Calculate.h"

int main() {

    Calculate calculate1; // for incorrect input
    calculate1.InputExpression("12/0");
    calculate1.Result();
    calculate1.PrintResult(std::cout);
    calculate1.InputExpression("12+-");
    calculate1.Result();
    calculate1.PrintResult(std::cout);
    calculate1.InputExpression("12+a");
    calculate1.Result();
    calculate1.PrintResult(std::cout);
    calculate1.InputExpression("12+((12*2)-1");
    calculate1.Result();
    calculate1.PrintResult(std::cout);
    calculate1.InputExpression("12(13)");
    calculate1.Result();
    calculate1.PrintResult(std::cout);
    calculate1.InputExpression("12*1+3+");
    calculate1.Result();
    calculate1.PrintResult(std::cout);
    calculate1.InputExpression("12*)1+3");
    calculate1.Result();
    calculate1.PrintResult(std::cout);
    return 0;
}
