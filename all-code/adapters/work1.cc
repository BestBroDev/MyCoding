// ф-ция должна проверить, сбалансированы ли скобки в строке:
// (), {}, [].

#include <stack>
#include <string>

bool IsBalanced(const std::string &expression) {
    std::stack<char> st;

    auto matches = [](char open, char close) {
        return ((open == '{' && close == '}') || 
        (open == '[' && close == ']') || (open == '(' && close == ')'));
    };

    for (auto e : expression) {
        // ##### ПЕРВЫЙ ВАРИАНТ #####
        // if (e == '[' || e == '(' || e == '{') {
        //     st.push(e);
        // } else if (e == '}' || e == ']' || e == ')') {
        //     if (st.empty()) {
        //         return false; // если первая скобка закрывающая
        //     }

        //     char top = st.top();
        //     if ((top == '[' && e == ']') || (top == '(' && e == ')') ||
        //     (top == '{' && e == '}')) {
        //         st.pop();
        //     } else {
        //         return false; // если скобки не подошли друг другу
        //     }
        // }

        if (e == '[' || e == '(' || e == '{') {
            st.push(e);
        } else if (e == ')' || e == '}' || e == ']') {
            if (st.empty() || !matches(st.top(), e)) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}