#include <iostream>
#include <stack>
#include <string>
#include <cassert>

bool isBalanced(const std::string& str) {
    std::stack<char> s;

    for(char c : str){
        if(c == '(' || c=='[' || c == '{'){
            s.push(c);
        }
    else if(c == ')' || c == ']' || c == '}'){
        if(s.empty()){
            return false;
        }
        char top = s.top();
        s.pop();

        if((c == ')' && top != '(') ||
          (c == ']' && top != '[') ||
          (c == '}' && top != '{')){
            return false;
          }
    }            
    }
    return s.empty();
}

int main() {
    assert(isBalanced("({[]})") == true);
    assert(isBalanced("([)]") == false);
    assert(isBalanced("{[}]") == false);
    assert(isBalanced("") == true);
    assert(isBalanced("(") == false);
    assert(isBalanced("({}") == false);
    assert(isBalanced(")") == false);

    std::cout << "All tests passed!" ;
    
    return 0;
}