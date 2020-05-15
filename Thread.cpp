#include "Thread.h"

Thread::Thread() {}

Thread::~Thread() {}

void Thread::empezar() {
    thread = std::thread(&Thread::ejecutar, this);
}

void Thread::unir() {
    thread.join();
}
