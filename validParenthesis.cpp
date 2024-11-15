#include <iostream>
#include <string>

std::string validParenthesis(std::string input) {
    char stack[input.size()];
    int top = -1;

    for (char bracket : input) {
        switch (bracket) {
        case '(':
        case '{':
        case '[':
            stack[++top] = bracket;
            break;

        case ')':
            if (top == -1 || stack[top] != '(') {
                return "Invalid";
            }
            top--;
            break;

        case '}':
            if (top == -1 || stack[top] != '{') {
                return "Invalid";
            }
            top--;
            break;

        case ']':
            if (top == -1 || stack[top] != '[') {
                return "Invalid";
            }
            top--;
            break;

        default:
            return "Invalid";
        }
    }

    return top == -1 ? "Valid" : "Invalid";
}

int main() {
    std::string input;

    std::cout << "Enter the input: ";
    std::getline(std::cin, input);

    std::cout << "Output: " << validParenthesis(input) << std::endl;

    return 0;
}
