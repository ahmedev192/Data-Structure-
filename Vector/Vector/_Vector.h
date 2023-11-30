#pragma once

template <typename T>
class _Vector
{
private:
    T* arr{ nullptr };
    int size{ 0 };
    int capacity{};
    void expandCapacity();

public:
    _Vector();
    ~_Vector();

    int getSize();
    T getFront();
    T getBack();
    T get(int idx);
    void set(int idx, T val);

    void printAll();
    int find(T value);
    void pushBack(T value);
    void insert(int idx,T value );
    void rotateVector();
    void rightRotate(int steps);
    void pop();
    void deleteElement(int idx);
};

