#include <iostream>
#include <string>
#define EMPTY 0

using namespace std;


class Stack {
    int size;
    char* arr;
    int top;
public:
    Stack() = delete;
    Stack(int size) : size(size) {
        arr = new char[size];
        top = EMPTY;
    }
    bool Push(int elem) {
        if (top < size - 1) {
            arr[++top] = elem;
            return true;
        }
        size *= 2;
        char* temp = new char[size];
        for (int i = 0; i < size / 2; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        temp = nullptr;
        arr[++top] = elem;
        return true;
    }
    int getSize()const {
        return size;
    }
    bool isFull() const {
        return top == size - 1;
    }
    bool isEmpty() const {
        return top == EMPTY;
    }
    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return 0;
    }
    int getCount()const {
        return top + 1;
    }
    int peek() const {
        if (!isEmpty()) {
            return arr[top];
        }
        return 0;
    }
    bool isElemTrueOne(char ele) {
        if (ele == ')' && this->arr[this->top] == '(' || ele == '}' && this->arr[this->top] == '{' || ele == ']' && this->arr[this->top] == '[') {
            return true;
        }
        else {
            return false;
        }
    }
    void show() {
        for (int i = 0; i < top + 1; i++)
        {
            cout << this->arr[i];
        }
    }
    ~Stack()
    {
        if (arr != nullptr) {
            delete[] arr;
            arr = nullptr;
        }
    }
};

int main()
{
    Stack st1(8);
    string a;
    getline(cin, a);
    for (char ch : a) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st1.Push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st1.isElemTrueOne(ch) == true) {
                st1.pop();
                cout << "Right";
                break;
            }
            else {
                st1.show();
                break;
            }
        }
    }
}
