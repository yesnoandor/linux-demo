// stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_

template <class Type>	// 定义一个类模板
class Stack
{
private:
    enum {MAX = 10};    // constant specific to class
    Type items[MAX];    // holds stack items
    int top;            // index for top stack item
public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Type & item); // add item to stack
    bool pop(Type & item);        // pop top into item
};

template <class Type>	// 定义一个成员函数模板
Stack<Type>::Stack()
{
    top = 0;
}

template <class Type>	// 定义一个成员函数模板
bool Stack<Type>::isempty()
{
    return top == 0;
}

template <class Type>	// 定义一个成员函数模板
bool Stack<Type>::isfull()
{
    return top == MAX;
}

template <class Type>	// 定义一个成员函数模板
bool Stack<Type>::push(const Type & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>	// 定义一个成员函数模板
bool Stack<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false; 
}

#endif
