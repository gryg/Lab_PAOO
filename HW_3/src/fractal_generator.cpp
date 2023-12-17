#include "fractal_generator.h"
#include <fstream>
#include <complex>

FractalGenerator::FractalGenerator(int width, int height) : width(width), height(height) {
    buffer.resize(width * height * 3); // Inițializarea bufferului pentru imaginea RGB
}

void FractalGenerator::generate(int threadId, int totalThreads) {
    int fromRow = (height / totalThreads) * threadId;
    int toRow = (height / totalThreads) * (threadId + 1);

    for (int y = fromRow; y < toRow; ++y) {
        for (int x = 0; x < width; ++x) {
            std::complex<float> point((float)x / width - 1.5, (float)y / height - 0.5);
            std::complex<float> z = 0;
            unsigned char iteration = 0;

            while (abs(z) < 2 && iteration < 255) {
                z = z * z + point;
                ++iteration;
            }

            RaiiMutexLock lock(bufferMutex); // Blocaj RAII
            buffer[(y * width + x) * 3] = iteration;     // R
            buffer[(y * width + x) * 3 + 1] = iteration; // G
            buffer[(y * width + x) * 3 + 2] = iteration; // B
        }
    }
}

void FractalGenerator::save(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    file << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < buffer.size(); i += 3) {
        file << static_cast<unsigned char>(buffer[i])
             << static_cast<unsigned char>(buffer[i + 1])
             << static_cast<unsigned char>(buffer[i + 2]);
    }
}
