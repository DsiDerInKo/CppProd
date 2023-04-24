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
    auto tmp = last;
    while(last!=first) {
        if(*first == value) {
            tmp = first;
        }
        first++;
    }
    return tmp;
}

int main(int argc, char* argv[]) {

    std::vector<int> v1 {2, 2, 2, 4};
    std::vector<int> v2 {1, 2, 3, 4};
    std::vector<int> v3 {3, 3, 3, 4};
    int n1 = 3;
    int n2 = 5;

    std::cout <<  allOf(v1.cbegin(),v1.cend(),[](int i) { return i % 2 == 0; }) << '\n';
    std::cout <<  allOf(v2.cbegin(),v2.cend(),[](int i) { return i % 2 == 0; }) << '\n';

    std::cout <<  oneOf(v1.cbegin(),v1.cend(),[](int i) { return i % 2 == 0; }) << '\n';
    std::cout <<  oneOf(v3.cbegin(),v3.cend(),[](int i) { return i % 2 == 0; }) << '\n';

    int val = 3;
    auto elem = findBackward(v3.cbegin(),v3.cend(),val);
    std::cout << (*elem);
    
    return 0;
}
