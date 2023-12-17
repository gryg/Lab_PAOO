#ifndef FRACTAL_GENERATOR_H
#define FRACTAL_GENERATOR_H

#include "raii_mutex.h"
#include <vector>

class FractalGenerator {
public:
    FractalGenerator(int width, int height);
    void generate(int threadId, int totalThreads);
    void save(const std::string& filename);

private:
    int width, height;
    std::vector<unsigned char> buffer;
    RaiiMutex bufferMutex; // Mutex pentru accesul la buffer
};

#endif // FRACTAL_GENERATOR_H
