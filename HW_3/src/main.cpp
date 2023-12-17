#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include "fractal_generator.h"
#include "raii_mutex.h"

int main() {
    const int num_threads = 4;
    std::vector<std::thread> threads;

    // utilizarea smart pointer-ului pentru a crea un generator de fractali
    auto fractalGenerator = std::make_unique<FractalGenerator>(800, 600);

    // crearea si pornirea thread-urilor
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([fractalGenerator = fractalGenerator.get(), i, num_threads]() {
            fractalGenerator->generate(i, num_threads); // generare fractal . în fiecare fir
        });
    }

    // wait for thread to finish
    for (auto &thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    // salvare fractal in .png
    fractalGenerator->save("fractal.png");

    return 0;
}
