//
//  Thread.cpp
//  ThreadKit
//
//  Created by SuXinDe on 2018/4/2.
//  Copyright © 2018年 SkyPrayer Studio. All rights reserved.
//

#include "Thread.hpp"

using namespace ThreadKit;

Thread::Thread() : mStatus(THREAD_STOPPED) {}

Thread::~Thread() {
    while (mStatus == THREAD_PENDING);
    if (mStatus == THREAD_RUNNING) {
        pthread_detach(mThread);
    }
}

void* Thread::entry(void *ptrThis) {
    Thread *obj = static_cast<Thread *>(ptrThis);
    obj->run();
    return NULL;
}

int Thread::start() {
    if (mStatus != THREAD_STOPPED) {
        return 1;
    }
    mStatus = THREAD_RUNNING;
    int ret = pthread_create(&mThread,
                             NULL,
                             &Thread::entry,
                             this);
    if (ret == 0) {
        mStatus = THREAD_RUNNING;
    } else {
        mStatus = THREAD_STOPPED;
    }
    return ret;
}

int Thread::join() {
    mStatus = THREAD_PENDING;
    int ret = pthread_join(mThread, NULL);
    mStatus = THREAD_STOPPED;
    return ret;
}
