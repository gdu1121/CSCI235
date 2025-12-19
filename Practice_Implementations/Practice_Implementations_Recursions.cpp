#include <iostream>
#include <vector>
#include <string>

// Create a function that calculates the factorial of n using recursion
int factorial(int n){
    // Base case: if n is 0 or 1, return 1
    if(n == 0 || n == 1){
        return 1;
    }
    // Recursive case: n * factorial of (n-1)
    return n * factorial(n - 1); // This will call the function until it reaches the base case
}

// Create a function that calculates the nth Fibonacci number using recursion
int fibonacci(int n){
    // The forumla for Fibonacci is:
    // F(0) = 0
    // F(1) = 1
    // F(n) = F(n-1) + F(n-2) for n > 1
    // Base cases: if n is 0 or 1, return n
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    // Recursive case: F(n) = F(n-1)+F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2); // This will call the function until it reaches the base case
}

// Create a function to determine whether a string is a palindrome using recursion
bool isPalindrome(const std::string& str, int start, int end){
    // Base case: if the start index is greater than or equal to the end index, return true
    if(start >= end){
        return true;
    }
    // Recursive case: check if the characters at the start and end indices are the same
    if(str[start] != str[end]){
        return false;
    }
    // Move towards the center of the string
    return isPalindrome(str, start + 1, end - 1); // This will call the function until it reaches the base case
}

// Create a function that determines whether a number is a power of two using recursion
bool isPowerOfTwo(int n){
    // Base case: if n is 1, return true (2^0 = 1)
    if(n == 1){
        return true;
    }
    // Base case: if n = 0, return false (0 is not a power of two)
    if(n == 0){
        return false;
    }
    // Recursive case: check if n is divisible by 2 and if the quotient is a power of two
    return (n % 2 == 0) && isPowerOfTwo(n / 2); // This will call the function until it reaches the base case
}
