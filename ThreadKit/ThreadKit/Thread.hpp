//
//  Thread.hpp
//  ThreadKit
//
//  Created by SuXinDe on 2018/4/2.
//  Copyright © 2018年 SkyPrayer Studio. All rights reserved.
//

#ifndef Thread_hpp
#define Thread_hpp

#include <stdio.h>
#include <pthread.h>

namespace ThreadKit {
    class Thread {
    private:
        pthread_t mThread;
        volatile enum {
            THREAD_STOPPED,
            THREAD_PENDING,
            THREAD_RUNNING
        } mStatus;
        
    protected:
        
        static void* entry(void *ptrThis);
        
        virtual int run() = 0;
        
    public:
        Thread();
        
        virtual ~Thread();
        
        int start();
        
        int join();
        
    };
}

#endif /* Thread_hpp */
