#include "raii_mutex.h"

void RaiiMutex::lock() {
    mutex.lock();
}

void RaiiMutex::unlock() {
    mutex.unlock();
}

RaiiMutexLock::RaiiMutexLock(RaiiMutex& mutex) : mutex(mutex) {
    mutex.lock();
}

RaiiMutexLock::~RaiiMutexLock() {
    mutex.unlock();
}
