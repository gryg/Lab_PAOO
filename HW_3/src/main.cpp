#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include "fractal_generator.h"
#include "raii_mutex.h"

int main() {
    const int num_threads = 4;
    std::vector<std::thread> threads;

    auto fractalGenerator = std::make_unique<FractalGenerator>(800, 600); // Utilizarea smart pointer-ului

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([fractalGenerator = fractalGenerator.get(), i, num_threads]() {
            fractalGenerator->generate(i, num_threads);
        });
    }

    for (auto &thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    // fractalGenerator->save("fractal.ppm");
    fractalGenerator->save("fractal");

    return 0;
}
