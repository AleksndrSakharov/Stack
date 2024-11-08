#include <iostream>
using namespace std;
template <typename T>
class Stack
{
private:
    T* _array;
    size_t _size;
    size_t _top;
    bool _isEmpty = true;
    void Expand(){
        _size *= 2;
        T* arr = new T[_size];
        for (size_t i = 0; i < _size / 2; i++) arr[i] = _array[i];
        delete [] _array;
        _array = arr;
    }
public:
    Stack (size_t size) : _size(size), _top(0), _array(new T[size]){
        
    }// Push Pop IsEmpty IsFull Expand Reduce
    inline bool isEmpty() const{
        return _isEmpty;
    }
    inline bool isFull() const{
        return _top == _size - 1;
    }
    
    void Push(const T& elem){
        if (_isEmpty) _isEmpty = false;
        else _top++;
        if (isFull()) Expand();
        _array[_top] = elem;
    }

    const T& Pop(){
        if (_isEmpty) throw;
        if (_top == 0) {
            _isEmpty = true;
            return _array[_top];
        }
        return _array[_top--];
    }

    const T& Check() const{
        if (_isEmpty) throw;
        return _array[_top];
    }
    
    ~Stack(){
        delete [] _array;
    }
};

