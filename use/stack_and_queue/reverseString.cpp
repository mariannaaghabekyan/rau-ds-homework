#include <iostream>
#include <stack>
#include <string>
#include <cassert>

void reverseString(std::string& s){
    std::stack<char> st;

    for(char c : s){
        st.push(c);
    }
    for(int i = 0; i < static_cast<int>(s.size()); ++i){
        s[i] = st.top();
        st.pop();
    }
}
int main(){
    std::string s = "Hello";
    reverseString(s);

    std::cout << s<< '\n';
    assert(s == "olleH");

    std::string s2 = "abc";
    reverseString(s2);
    assert(s2 == "cba");

    std::string s3 = " ";
    reverseString(s3);
    assert(s3 == " ");

    std::cout << "All tests passed!";
    return 0;
}
