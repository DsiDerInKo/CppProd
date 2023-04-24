#include <iostream>
#include <vector>

template<class InputIt, class UnaryPredicate>
bool allOf(InputIt first, InputIt last, UnaryPredicate predicate) {
    while (first!=last) {
        if (!predicate(*first)) {
            return false;
        }
        first++;
    }
    return true;
}

template<class InputIt, class UnaryPredicate>
bool oneOf(InputIt first, InputIt last, UnaryPredicate predicate) {
    bool nolessThanOne = false;
    while (first!=last) {
        
        if(predicate(*first)) {
            if(!nolessThanOne) {
                nolessThanOne = true;
            }
            else {
                return false;    
            }
            
        }
        first++;
    }
    
    return nolessThanOne;
}

template<class InputIt, class T>
InputIt findBackward(InputIt first, InputIt last, const T& value) {
    while(last!=first) {
        if(*last == value) {
            return last;
        }
        last--;
    }
}

int main(int argc, char* argv[]) {

    std::vector<int> v {2, 2, 3, 4};
    int n1 = 3;
    int n2 = 5;

    std::cout <<  allOf(v.cbegin(),v.cend(),[](int i) { return i % 2 == 0; });
    
    return 0;
}
