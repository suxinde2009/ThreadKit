//
//  Mutex.cpp
//  ThreadKit
//
//  Created by SuXinDe on 2018/4/2.
//  Copyright © 2018年 SkyPrayer Studio. All rights reserved.
//

#include "Mutex.hpp"

using namespace ThreadKit;

Mutex::Mutex() {
    pthread_mutex_init(&mMutex, NULL);
}

Mutex::~Mutex() {
    pthread_mutex_destroy(&mMutex);
}

int Mutex::lock() {
    return pthread_mutex_lock(&mMutex);
}

int Mutex::unlock() {
    return pthread_mutex_unlock(&mMutex);
}

int Mutex::tryLock() {
    return pthread_mutex_trylock(&mMutex);
}
