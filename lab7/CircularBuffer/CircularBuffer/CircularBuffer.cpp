#include <iostream>
#include <iterator>

template<typename T>
class iterator: public std::iterator<std::random_access_iterator_tag,T>{
private:
    T* ptr;
public:
    iterator():ptr(nullptr){}
    iterator(T* ptrs):ptr(ptrs){}
    iterator(const iterator &t):ptr(t.ptr){}

    T& operator *() const{
        return *ptr;
    }
    T* operator ->() const{
        return ptr;
    }
    T& operator[](typename std::iterator<std::random_access_iterator_tag,T>::difference_type diff){ 
        return ptr[diff];
    }
    iterator operator +=(typename std::iterator<std::random_access_iterator_tag,T>::difference_type diff){
        ptr+=diff;
        return *this;
    }
    iterator operator ++(){
        ptr++;
        return *this;
    }
    iterator& operator ++(T){
        iterator tmp(*this);
        ptr++;
        return tmp;
    }
    bool operator ==(const iterator& t){
        return ptr==t.ptr;
    }
    bool operator <(const iterator& t){
        return ptr<t.ptr;
    }
    
    iterator operator +(typename std::iterator<std::random_access_iterator_tag,T>::difference_type diff){
        return iterator(ptr+diff);
    }
    
    typename std::iterator<std::random_access_iterator_tag,T>::difference_type operator -(const iterator &t){
        return ptr-t.ptr;
    }
    
};


template<class T>
class CCircleBuffer {
public:
    class iterator;

    iterator begin() {
        return buff;
    }

    iterator end() {
        return buff + capacity;
    }

    CCircleBuffer(int size_) {
        capacity = size_;
        tailPointer = size_-1;
        headPointer = 0;
        currentSize = 0;
        buff = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            buff[i] = 0;
        }
    }

    ~CCircleBuffer() {
        delete[] buff;
    }

    int length() {
        return capacity;
    }

    T &operator[](int i) {
        return i < capacity ? buff[i] : buff[0];
    }

    T &operator[](iterator i) {
        return *i;
    }

    void push_front(const T &value) {
        if (buff[headPointer]==0) {
            currentSize++;
        }
        
        buff[headPointer] = value;
        headPointer = headPointer + 1 < capacity ? headPointer + 1 : 0;
    }

    void push_back(const T &value) {
        if (buff[tailPointer]==0) {
            currentSize++;
        }
        
        buff[tailPointer] = value;
        tailPointer = tailPointer - 1 < 0 ? capacity - 1 : tailPointer - 1;
    }

    T &pop_back() {
        if (currentSize == 0)
        {
            return buff[0];
            //throw "Buff is empty";
        }
        currentSize--;
        tailPointer = tailPointer + 1 < capacity ? tailPointer + 1 : 0; 
        T tmp = buff[tailPointer];
        buff[tailPointer] = 0;
        
        return tmp;
    }

    T &pop_front() {
        if (currentSize == 0)
        {
            return buff[0];
            //throw "Buff is empty";
        }
        currentSize--;
        headPointer = headPointer - 1 < 0 ? capacity - 1 : headPointer - 1;
        T tmp = buff[headPointer];
        buff[headPointer] = 0;
        
        return tmp;
    }

    void resize(int n) {
        T *newBuff = new T[n];
        for (int i = 0; i < n; i++) {
            newBuff[i] = i < capacity ? buff[i] : 0;
        }
        buff = newBuff;
        capacity = n;
    }
    T *buff;
private:
    int capacity, headPointer, tailPointer, currentSize;
    
};



int main(int argc, char* argv[]){

    CCircleBuffer<int>* circleBuffer = new CCircleBuffer<int>(10);

    circleBuffer->push_front(1);
    circleBuffer->push_front(100);
    circleBuffer->push_front(200);
    circleBuffer->push_back(2);
    circleBuffer->push_back(5);
    circleBuffer->push_back(5);
    circleBuffer->push_back(5);
    circleBuffer->push_back(5);
    circleBuffer->push_back(5);
    circleBuffer->push_back(5);
    circleBuffer->push_back(5);
    circleBuffer->push_back(333);
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_back();
    circleBuffer->pop_front();

    for (int i = 0; i < 10; ++i) {
        std::cout << circleBuffer->buff[i] << '\n';
    }
    
    return 0;
}
