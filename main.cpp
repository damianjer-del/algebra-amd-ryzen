#include <iostream>
#include <chrono>
#include <Eigen/Dense>

int main() {
    std::cout << "--- Specyfikacja optymalizacji Eigen ---" << std::endl;
    #if defined(__AVX2__)
        std::cout << "[ OK ] AVX2 jest włączone i wspierane przez kompilator!" << std::endl;
    #endif
    #if defined(__FMA__)
        std::cout << "[ OK ] FMA3 (Fused Multiply-Add) jest włączone!" << std::endl;
    #endif

    const int size = 1500; 
    
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(size, size);
    Eigen::MatrixXd C = Eigen::MatrixXd::Zero(size, size);

    std::cout << "\nMnożenie macierzy " << size << "x" << size << " przy użyciu AMD AVX2..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    C = A * B;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Czas obliczeń: " << duration.count() << " sekund." << std::endl;
    std::cout << "Suma kontrolna (ślad macierzy): " << C.trace() << std::endl;

    return 0;
}

