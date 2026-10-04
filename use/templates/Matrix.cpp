#include <iostream>
#include <cassert>
#include <string>

template <typename T, std::size_t N, std::size_t M>
class Matrix {
private:
    T data[N][M];

public:
    void set(int row, int col, T value) {
        data[row][col] = value;
    }

    T get(int row, int col) const {
        return data[row][col];
    }

    void print() const {
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < M; ++j) {
                std::cout << data[i][j];

                if (j + 1 < M) {
                    std::cout << ' ';
                }
            }

            std::cout << '\n';
        }
    }

    Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) const {
        Matrix<T, N, M> result;

        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < M; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }
};

void test_Matrix() {
    Matrix<int, 2, 3> first;

    first.set(0, 0, 1);
    first.set(0, 1, 2);
    first.set(0, 2, 3);
    first.set(1, 0, 4);
    first.set(1, 1, 5);
    first.set(1, 2, 6);

    assert(first.get(0, 0) == 1);
    assert(first.get(0, 2) == 3);
    assert(first.get(1, 1) == 5);

   
    Matrix<int, 2, 3> second;

    second.set(0, 0, 10);
    second.set(0, 1, 20);
    second.set(0, 2, 30);
    second.set(1, 0, 40);
    second.set(1, 1, 50);
    second.set(1, 2, 60);

    Matrix<int, 2, 3> sum = first + second;

    assert(sum.get(0, 0) == 11);
    assert(sum.get(0, 1) == 22);
    assert(sum.get(0, 2) == 33);
    assert(sum.get(1, 0) == 44);
    assert(sum.get(1, 1) == 55);
    assert(sum.get(1, 2) == 66);

    
    Matrix<double, 2, 2> decimals;

    decimals.set(0, 0, 1.5);
    decimals.set(0, 1, 2.5);
    decimals.set(1, 0, 3.5);
    decimals.set(1, 1, 4.5);

    assert(decimals.get(0, 0) == 1.5);
    assert(decimals.get(1, 1) == 4.5);

    
    Matrix<std::string, 2, 2> words;

    words.set(0, 0, "Hello");
    words.set(0, 1, " ");
    words.set(1, 0, "World");
    words.set(1, 1, "!");

    assert(words.get(0, 0) == "Hello");
    assert(words.get(0, 1) == " ");
    assert(words.get(1, 0) == "World");
    assert(words.get(1, 1) == "!");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    Matrix<int, 2, 3> first;

    first.set(0, 0, 1);
    first.set(0, 1, 2);
    first.set(0, 2, 3);
    first.set(1, 0, 4);
    first.set(1, 1, 5);
    first.set(1, 2, 6);

    std::cout << "First matrix:" << '\n';
    first.print();

    Matrix<int, 2, 3> second;

    second.set(0, 0, 10);
    second.set(0, 1, 20);
    second.set(0, 2, 30);
    second.set(1, 0, 40);
    second.set(1, 1, 50);
    second.set(1, 2, 60);

    std::cout << "Second matrix:" << '\n';
    second.print();

    Matrix<int, 2, 3> sum = first + second;

    std::cout << "Sum:" << '\n';
    sum.print();

    test_Matrix();

    return 0;
}