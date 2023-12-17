#ifndef RAII_MUTEX_H
#define RAII_MUTEX_H

#include <mutex>

class RaiiMutex {
public:
    void lock();
    void unlock();

private:
    std::mutex mutex;
};

class RaiiMutexLock {
public:
    explicit RaiiMutexLock(RaiiMutex& mutex);
    ~RaiiMutexLock();

private:
    RaiiMutex& mutex;
};

#endif // RAII_MUTEX_H
