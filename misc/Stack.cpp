#include "Stack.h"

Stack::Stack()
    : data(new int[10]), allocated(10), size(0)
{
}

Stack::Stack(int initialAlloc)
    : data(new int[initialAlloc]), allocated(initialAlloc), size(0)
{
}

Stack::Stack(const Stack& other)
    : data(new int[other.size]), allocated(other.size), size(other.size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

Stack::~Stack()
{
    if (data != nullptr)
    {
        delete [] data;
        data = nullptr;
    }
    allocated = 0;
    size = 0;
}

Stack& Stack::operator=(const Stack& right)
{
    if (this == &right)
    {
        return *this;
    }

    // we need more space
    if (allocated < right.size)
    {
        delete [] data;
        data = new int[right.size];
        allocated = right.size;
    }
    size = right.size;
    for (int i = 0; i < size; i++)
    {
        data[i] = right.data[i];
    }
    return *this;
}

int Stack::getSize() const
{
    return size;
}

void Stack::grow()
{
    allocated = allocated * 2 + 1;
    int* temp = new int[allocated];
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
}

void Stack::push(int n)
{
    if (size >= allocated)
    {
        grow();
    }

    data[size++] = n;
}

int Stack::pop()
{
    if (size == 0)
    {
        std::cout << "Error: popping empty stack" << std::endl;
        return -1;
    }
    return data[--size];
}

int Stack::peek() const
{
    if (size == 0)
    {
        std::cout << "Error: peeking empty stack" << std::endl;
        return -1;
    }
    return data[size - 1];
}

std::string Stack::str() const
{
    std::ostringstream sout;
    for (int i = 0; i < size - 1; i++)
    {
        sout << data[i] << " ";
    }
    sout << data[size - 1];
    return sout.str();
}

Stack& Stack::operator<<(int n)
{
    push(n);
    return *this;
}

Stack& Stack::operator>>(int& n)
{
    n = pop();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Stack& s)
{
    os << s.str();
    return os;
}

int main()
{
    Stack s;
    s << 1 << 2 << 3 << 4;
    std::cout << s << std::endl;
    int n1;
    int n2;
    s >> n1 >> n2;
    std::cout << s << std::endl;
    std::cout << "n1 = " << n1 << std::endl;
    std::cout << "n2 = " << n2 << std::endl;
    return 0;
}
















