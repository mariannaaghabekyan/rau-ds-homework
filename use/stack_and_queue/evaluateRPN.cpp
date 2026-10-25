#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cassert>

int evaluateRPN(const std::vector<std::string>& expr) {
    std::stack<int> s;

    for (const std::string& token : expr) {
        if (token == "+" || token == "-" ||
            token == "*" || token == "/") {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            if (token == "+") {
                s.push(a + b);
            } else if (token == "-") {
                s.push(a - b);
            } else if (token == "*") {
                s.push(a * b);
            } else {
                s.push(a / b);
            }
        } else {
            s.push(std::stoi(token));
        }
    }

    return s.top();
}

int main() {
    std::vector<std::string> expr = {"2", "1", "+", "3", "*"};

    std::cout << evaluateRPN(expr) << '\n';

    assert(evaluateRPN({"10", "4", "-"}) == 6);
    assert(evaluateRPN({"3", "4", "*"}) == 12);
    assert(evaluateRPN({"8", "2", "/"}) == 4);

    std::cout << "All tests passed!" << '\n';

    return 0;
}