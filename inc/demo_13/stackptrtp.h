// stcktp1.h -- modified Stack template
#ifndef STACKPTRTP_H_
#define STACKPTRTP_H_

template <class Type>
class StackPtr
{
private:
    enum {SIZE = 10};    // default size
    int stacksize;
    Type * items;       // holds stack items
    int top;            // index for top stack item
public:
    explicit StackPtr(int ss = SIZE);
    StackPtr(const StackPtr & st);
    ~StackPtr() { delete [] items; }
    bool isempty() { return top == 0; }
    bool isfull() { return top == stacksize; }
    bool push(const Type & item);   // add item to stack
    bool pop(Type & item);          // pop top into item
    StackPtr & operator=(const StackPtr & st);
};

template <class Type>
StackPtr<Type>::StackPtr(int ss) : stacksize(ss), top(0)
{
    items = new Type [stacksize];
}

template <class Type>
StackPtr<Type>::StackPtr(const StackPtr & st)
{
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for (int i = 0; i < top; i++)
        items[i] = st.items[i];
}

template <class Type>
bool StackPtr<Type>::push(const Type & item)
{
    if (top < stacksize)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool StackPtr<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

template <class Type>
StackPtr<Type> & StackPtr<Type>::operator=(const StackPtr<Type> & st)
{
    if (this == &st)
        return *this;
    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for (int i = 0; i < top; i++)
        items[i] = st.items[i];
    return *this; 
}

#endif
