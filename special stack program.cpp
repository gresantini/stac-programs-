#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class SpecialStack {
private:
    stack<int> mainStack; // Main stack to hold the elements

public:
    // Push an element onto the stack
    void push(int value) {
        mainStack.push(value);
    }

    // Pop the top element from the stack
    void pop() {
        if (mainStack.empty()) {
            throw runtime_error("Stack is empty");
        }
        mainStack.pop();
    }

    // Pop the latest added odd number
    void popOdd() {
        if (mainStack.empty()) {
            throw runtime_error("Stack is empty");
        }

        stack<int> tempStack;
        bool foundOdd = false;

        // Search for the most recent odd number
        while (!mainStack.empty()) {
            int top = mainStack.top();
            mainStack.pop();
            if (!foundOdd && top % 2 != 0) {
                foundOdd = true; // Found the odd number to pop
                continue;
            }
            tempStack.push(top); // Temporarily hold the rest of the elements
        }

        // Restore the stack
        while (!tempStack.empty()) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }

        if (!foundOdd) {
            throw runtime_error("No odd numbers in stack");
        }
    }

    // Pop the latest added even number
    void popEven() {
        if (mainStack.empty()) {
            throw runtime_error("Stack is empty");
        }

        stack<int> tempStack;
        bool foundEven = false;

        // Search for the most recent even number
        while (!mainStack.empty()) {
            int top = mainStack.top();
            mainStack.pop();
            if (!foundEven && top % 2 == 0) {
                foundEven = true; // Found the even number to pop
                continue;
            }
            tempStack.push(top); // Temporarily hold the rest of the elements
        }

        // Restore the stack
        while (!tempStack.empty()) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }

        if (!foundEven) {
            throw runtime_error("No even numbers in stack");
        }
    }

    // Peek at the top element of the stack
    int peek() const {
        if (mainStack.empty()) {
            throw runtime_error("Stack is empty");
        }
        return mainStack.top();
    }

    // Check if the stack is empty
    bool empty() const {
        return mainStack.empty();
    }

    // Print the stack
    void printStack() const {
        if (mainStack.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        stack<int> tempStack = mainStack;
        while (!tempStack.empty()) {
            cout << tempStack.top() << endl;
            tempStack.pop();
        }
    }
};

// Main program
int main() {
    SpecialStack one, two, three, four;

    try {
        cout << "Stack one" << endl;
        one.push(41);
        one.push(66);
        one.push(91);
        one.push(88);
        one.push(33);
        one.popEven();
        one.printStack();
    } catch (runtime_error &e) {
        cout << "Unable to complete operations" << endl << endl;
    }

    try {
        cout << "Stack two" << endl;
        two.push(1);
        two.push(9);
        two.push(6);
        two.push(2);
        two.push(8);
        two.push(6);
        two.push(4);
        two.popOdd();
        two.printStack();
    } catch (runtime_error &e) {
        cout << "Unable to complete operations"<< endl << endl;
    }

    try {
        cout << "Stack three" << endl;
        three.popEven();
        three.printStack();
    } catch (runtime_error &e) {
        cout << "Unable to complete operations" << endl << endl;
    }

    try {
        cout << "Stack four" << endl;
        four.pop();
        four.printStack();
    } catch (runtime_error &e) {
        cout << "Unable to complete operations" << endl << endl;
    }

    return 0;
}