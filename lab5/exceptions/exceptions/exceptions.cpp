
#include <iostream>
#include <string>
#include <vector>

template<typename V>
V _pow(V value, int degree) {
    V tmp = value;
    for(int i = 0;i<degree-1;i++) {
        tmp*=value;
    }
    return tmp;
}

class IndexOutOfRangeException : public std::exception
{
    public:
    
    IndexOutOfRangeException(const std::string& message): message{message}{}
    const char* what() const noexcept override {
        return message.c_str();     // получаем из std::string строку const char*
    }
    
    private:
    
    std::string message;
};

template<class T>
class Matrix {
    public:
    
    Matrix(int N, int M) {
        
        n = N;    
        m = M;

        matrix = new T*[N];
        for(int  i = 0;i<N;i++) {
            matrix[i] = new T[M];
        }
    }

    ~Matrix() {
        
        for(int  i = 0;i<n;i++) {
            delete matrix[i];
        }
        delete matrix;
    }
    
    T get(int N, int M) {
        if((N>n)||(N<0)||(M>m)||(M<0)) {
            throw IndexOutOfRangeException("Wrong index");
        }
        return matrix[N][M];
    }

    void set(int N, int M, T value) {
        if((N>n)||(N<0)||(M>m)||(M<0)) {
            throw IndexOutOfRangeException("Wrong index");
        }
        matrix[N][M] = value;
    }
    
    void print() const {
        for (int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                std::cout << matrix[i][j] + " ";
            }
            std::cout << '\n';
        }
        
    }
    
    private:
    
    int n;
    int m;
    T** matrix;
    
};
  
void testMatrix(int i,int j){
    try{
        Matrix<std::string>* matr = new Matrix<std::string>(2,2);
        std:: cout << matr->get(i,j);
        matr->print();
    }
    catch (const IndexOutOfRangeException& error){
        std::cout << "IndexOutOfBounce: " << error.what() << '\n';
        }
    catch (const std::exception&)   {
        std::cout << "Something wrong"<< '\n';
        }
}
int main() {
    std::cout << _pow(2,10) << '\n';
    std::cout << _pow(0.5,5) << '\n';
    
    testMatrix(100,100);
    testMatrix(150,2);
}