//
//  Condition.hpp
//  ThreadKit
//
//  Created by SuXinDe on 2018/4/2.
//  Copyright © 2018年 SkyPrayer Studio. All rights reserved.
//

#ifndef Condition_hpp
#define Condition_hpp

#include <pthread.h>
#include "Mutex.hpp"

namespace ThreadKit {
    class Condition : public Mutex {
    protected:
        pthread_cond_t mCondition;
        
    public:
        Condition();
        
        virtual ~Condition();
        
        int wait();
        
        int signal();
    };
};

#endif /* Condition_hpp */
