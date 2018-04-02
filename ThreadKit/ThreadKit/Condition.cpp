//
//  Condition.cpp
//  ThreadKit
//
//  Created by SuXinDe on 2018/4/2.
//  Copyright © 2018年 SkyPrayer Studio. All rights reserved.
//

#include "Condition.hpp"

using namespace ThreadKit;

Condition::Condition() {
    pthread_cond_init(&mCondition, NULL);
}


Condition::~Condition() {
    pthread_cond_destroy(&mCondition);
}

int Condition::wait() {
    return pthread_cond_wait(&mCondition, &mMutex);
}

int Condition::signal() {
    return pthread_cond_signal(&mCondition);
}
