//
//  Mutex.hpp
//  ThreadKit
//
//  Created by SuXinDe on 2018/4/2.
//  Copyright © 2018年 SkyPrayer Studio. All rights reserved.
//

#ifndef Mutex_hpp
#define Mutex_hpp

#include <stdio.h>
#include <pthread.h>

namespace ThreadKit {
    class Mutex {
    protected:
        pthread_mutex_t mMutex;
    public:
        Mutex();
        
        ~Mutex();
        
        int lock();
        
        int unlock();
        
        int tryLock();
    };
}

#endif /* Mutex_hpp */
