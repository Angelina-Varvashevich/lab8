#include <iostream>
#include "Stack.h"
#include "Calculate.h"

int main() {
    /*Stack<int> a;
    a.push(34);
    a.push(356);
    a << 14;
    a << 56;
    std::cout << a[0] << std::endl;
    std::cout << a[1] << std::endl;
    std::cout << a[2] << std::endl;
    std::cout << std::endl;

    a.print(std::cout);
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
    v.print(std::cout);*/

    /*Stack <int>  a;
    std:: cout<< a.isEmpty()<< std::endl;
    for (int i =0; i<5; i++){
        a.push(i*(i+1));
    }
    std:: cout<< a.GetTopValue()<< std::endl;
    while (!a.isEmpty()){
        std:: cout<< a.pop()<< " ";

    }*/

    Calculate calculate;
    calculate.ReadExpression();
    calculate.Result();
    calculate.PrintResult(std::cout);

    /*Calculate::ReadExpression();
    Calculate::PrintResult(std::cout);*/


    return 0;
}
