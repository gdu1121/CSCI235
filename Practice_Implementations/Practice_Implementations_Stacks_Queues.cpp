#include <iostream>
#include <vector>
#include <queue>
#include <stack>

// Create a function where given a string consisting of only open and closed brackets,
// return true if the brackets are balanced and false otherwise.
bool isBalanced(const std::string& s){
    // Create a stack to keep track of open brackets.
    std::stack<char> brackets;
    // Iterate through each character in the string
    for(char c : s){
        // If the character is an open bracket, push it onto the stack.
        if(c == '(' || c == '{' || c == '['){
            brackets.push(c);
        }
        // If the character is a closed bracket, check if the stack is empty or the top of the stack is not the corresponding open bracket.
        else if(c == ')' || c == '}' || c == ']'){
            if(brackets.empty() || (c == ')' && brackets.top() != '(') || (c == '}' && brackets.top() != '{') || (c == ']' && brackets.top() != '[')){
                return false;
            }
            // If the top of the stack is the corresponding open bracket, pop it from the stack.
            brackets.pop();
        }
    }
    // Return true if the stack is empty, false otherwise.
    return brackets.empty();
}

//Create a function that given a sequence of letters and the symbol '#' representing a backspace, return the result as a string.
std::string applyBackspace(const std::string& s){
    // Create a stack to keep track of the characters in the string.
    std::stack<char> chars;
    // Iterate through each character in the string.
    for(char c : s){
        // If the character is not '#', push it onto the stack.
        if(c != '#'){
            chars.push(c);
        }
        // If the character is '#', pop the top element from the stack if it is not empty.
        else if(!chars.empty()){
            chars.pop();
        }
    }
    // Create a string to store the result.
    std::string result;
    // Pop the elements from the stack and append them to the result string.
    while(!chars.empty()){
        result += chars.top();
        chars.pop();
    }
    // Return the result string.
    return result;
}

//Create a function that reverses a string/vector/list using a stack.
std::string reverseString(const std::string& s){
    // Create a stack to keep track of the characters in the string.
    std::stack<char> chars;
    // Iterate through each character in the string.
    for(char c : s){
        // Push the character onto the stack.
        chars.push(c);
    }
    // Create a string to store the result.
    std::string result;
    // Pop the elements from the stack and append them to the result string.
    while(!chars.empty()){
        result += chars.top();
        chars.pop();
    }
    // Return the result string.
    return result;
}