#include "gtest/gtest.h"
#include "Stack.h"
#include "Calculate.h"

TEST (StackFunctions, Exeptions) {
    Stack<double> a;
    EXPECT_ANY_THROW(a >> 0);
    EXPECT_ANY_THROW(a.GetTopValue());
    EXPECT_ANY_THROW(a.pop());
}

TEST(StackFunctions, PushOperator) {
    Stack<double> a;
    a << 12.2;
    a << 0;
    a << 3.7;
    ASSERT_EQ(3, a.Size());
}

TEST(StackFunctions, GetTopValue) {
    Stack<double> a;
    a << 12.2;
    a << 0;
    a << 3.7;
    ASSERT_EQ(a.GetTopValue(), 3.7);
}

TEST(StackFunctions, PopOperator) {
    Stack<double> a;
    a << 12.2;
    a << 0;
    a << 3.7;
    ASSERT_EQ(a.GetTopValue(), 3.7);
    ASSERT_EQ(a >> 2, 3.7);
    ASSERT_EQ(a >> 1, 0);
    ASSERT_EQ(a >> 0, 12.2);
    ASSERT_TRUE(a.isEmpty());
}

TEST(StackFunctions, ComparisonOperator1) {
    Stack<double> a;
    a.push(12.2);
    a.push(0);
    a.push(3.7);
    Stack<double> b;
    b.push(13.2);
    b.push(10);
    b.push(-13);
    ASSERT_TRUE(!(a < b));
}

TEST(StackFunctions, ComparisonOperator2) {
    Stack<double> a;
    a.push(12.2);
    a.push(0);
    a.push(3.7);
    Stack<double> b;
    b.push(13.2);
    b.push(10);
    ASSERT_TRUE(!(a < b));
}

TEST(StackFunctions, ComparisonOperator3) {
    Stack<double> a;
    a.push(12.2);
    a.push(0);
    Stack<double> b;
    b.push(13.2);
    b.push(10);
    b.push(-13);
    ASSERT_TRUE(a < b);
}

TEST(StackFunctions, Equal){
    Stack<double> a;
    Stack<double> b;
    a.push(12.2);
    a.push(0);

    b.push(13.2);
    b.push(10);
    b.push(-13);
    b.push(3.4);
    a = b;
    ASSERT_EQ(a.GetTopValue(), 3.4);
    ASSERT_EQ(a.Size(), 4);
    ASSERT_EQ(a[2], -13);
    ASSERT_EQ(a[1], 10);
    ASSERT_EQ(a[0], 13.2);

}

TEST(StackFunctions, EqualBackward){
    Stack<double> a;
    Stack<double> b;
    a.push(12.2);
    a.push(0);
    b.push(13.2);
    b.push(10);
    b.push(-13);
    b.push(3.4);
    b = a;
    ASSERT_EQ(b.GetTopValue(), 0);
    ASSERT_EQ(b.Size(), 2);
    ASSERT_EQ(b[1], 0);
    ASSERT_EQ(b[0], 12.2);
    EXPECT_ANY_THROW(a[2]);
}

TEST(StackFunctions, EqualComparisonOperatorFalse) {
    Stack<double> a;
    a.push(12.2);
    a.push(0);

    Stack<double> b;
    b.push(13.2);
    b.push(10);
    b.push(-13);
    //a<b;
    ASSERT_TRUE(!(a == b));
}

TEST(StackFunctions, EqualComparisonOperatorTrue) {
    Stack<double> a;
    a.push(12.2);
    a.push(0);
    a.push(16);
    Stack<double> b;
    b.push(13.2);
    b.push(10);
    b.push(-13);
    ASSERT_TRUE((a == b));
}

TEST(StackFunctions, IndexOperatorTrue) {
    Stack<double> a;
    a.push(12.2);
    a.push(0);
    a.push(16);
    ASSERT_EQ(a[2], 16);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[0], 12.2);
}

TEST(StackFunctions, Pop) {
    Stack<double> a;
    a << 12.2;
    a << 0;
    a << 3.7;
    ASSERT_EQ(3.7, a.GetTopValue());
    a.pop();
    ASSERT_EQ(0, a.GetTopValue());
    a.pop();
    ASSERT_EQ(12.2, a.GetTopValue());
    a.pop();
    ASSERT_TRUE(a.isEmpty());
}

TEST(StackFunctions, isEmpty) {
    Stack<double> a;
    a.isEmpty();
    ASSERT_TRUE(true);
}


Calculate calculate;
TEST(Calculate, PositiveNumbers) {
    calculate.InputExpression("2+2");
    ASSERT_EQ(calculate.Result(), 4);
    calculate.InputExpression("2.2+3.2");
    ASSERT_EQ(calculate.Result(), 5.4);
    calculate.InputExpression("2-2");
    ASSERT_EQ(calculate.Result(), 0);
    calculate.InputExpression("2.2-3.2");
    ASSERT_EQ(calculate.Result(), -1);
    calculate.InputExpression("2*2");
    ASSERT_EQ(calculate.Result(), 4);
    calculate.InputExpression("2.5*2");
    ASSERT_EQ(calculate.Result(), 5);
    calculate.InputExpression("2.2/2");
    ASSERT_EQ(calculate.Result(), 1.1);
    calculate.InputExpression("4/2");
    ASSERT_EQ(calculate.Result(), 2);
}

TEST(Calculate, NegativeNumbers){
    calculate.InputExpression("-2+(-2)");
    ASSERT_EQ(calculate.Result(), -4);
    calculate.InputExpression("-2.2+(-3.2)");
    ASSERT_EQ(calculate.Result(), -5.4);
    calculate.InputExpression("-2-(-2)");
    ASSERT_EQ(calculate.Result(), 0);
    calculate.InputExpression("-2.2-(-3.2)");
    ASSERT_EQ(calculate.Result(), 1);
    calculate.InputExpression("-2*(-2)");
    ASSERT_EQ(calculate.Result(), 4);
    calculate.InputExpression("(-2.5)*(-2)");
    ASSERT_EQ(calculate.Result(), 5);
    calculate.InputExpression("-2.2/(-2)");
    ASSERT_EQ(calculate.Result(), 1.1);
    calculate.InputExpression("(-4)/(-2)");
    ASSERT_EQ(calculate.Result(), 2);
}

TEST(Calculate, NegativePositiveNumbers){
    calculate.InputExpression("-2+2");
    ASSERT_EQ(calculate.Result(), 0);
    calculate.InputExpression("-2.2+3.2");
    ASSERT_EQ(calculate.Result(), 1);
    calculate.InputExpression("-2-2");
    ASSERT_EQ(calculate.Result(), -4);
    calculate.InputExpression("-2.2-3.2");
    ASSERT_EQ(calculate.Result(), -5.4);
    calculate.InputExpression("-2*2");
    ASSERT_EQ(calculate.Result(), -4);
    calculate.InputExpression("(-2.5)*2");
    ASSERT_EQ(calculate.Result(), -5);
    calculate.InputExpression("-2.2/2");
    ASSERT_EQ(calculate.Result(), -1.1);
    calculate.InputExpression("(-4)/2");
    ASSERT_EQ(calculate.Result(), -2);
}

TEST(Calculate, Brackets){
    calculate.InputExpression("(((25-5)*0.5-3)-5)");
    ASSERT_EQ(calculate.Result(), 2);
    calculate.InputExpression("2+2*(3*(2+5)+1)");
    ASSERT_EQ(calculate.Result(), 46);
    calculate.InputExpression("2+3*(2+5)");
    ASSERT_EQ(calculate.Result(), 23);
    calculate.InputExpression("2+2*(3*(2+5))");
    ASSERT_EQ(calculate.Result(), 44);
}

TEST(Calculate, Gaps){
    calculate.InputExpression("(   ((25   -5)*0.5  -  3)-  5)");
    ASSERT_EQ(calculate.Result(), 2);
    calculate.InputExpression("2+    2 *   (3*    (2+  5)+  1)");
    ASSERT_EQ(calculate.Result(), 46);
    calculate.InputExpression("    2+ 3*(2+5   )");
    ASSERT_EQ(calculate.Result(), 23);
}

TEST(Calculate, BinaryAndUnaryOperators){
    calculate.InputExpression("23+-4 +3");
    ASSERT_EQ(calculate.Result(), 22);
    calculate.InputExpression("23--5*5");
    ASSERT_EQ(calculate.Result(), 48);
    calculate.InputExpression("1++13/2");
    ASSERT_EQ(calculate.Result(), 7.5);
}

TEST(Calculate, Complex){
    calculate.InputExpression("12.56/123.6*896 -(-1/1235/89*52) + (65/(30/15+3*3)+-9 +36*7)/65");
    ASSERT_FLOAT_EQ(calculate.Result(), 94.87968);
    calculate.InputExpression("(25*34-26)*23*135-39.3/25/0.3");
    ASSERT_EQ(calculate.Result(), 2558514.76);
}



















