//
//  GCDSemaphore.m
//  GCD信号量使用案例
//
//  Created by 魏琦 on 16/8/2.
//  Copyright © 2016年 com.drcacom.com. All rights reserved.
//

#import "GCDSemaphore.h"
@interface GCDSemaphore ()
@property (nonatomic, strong) dispatch_semaphore_t semaphore;
@end

@implementation GCDSemaphore
- (instancetype)init {
    return [self initWithValue:0];
}

- (instancetype)initWithValue:(long)value {
    return [self initWithDispatchSemaphore:dispatch_semaphore_create(value)];
}

- (instancetype)initWithDispatchSemaphore:(dispatch_semaphore_t)dispatch_semaphore {
    if (self = [super init]) {
        self.semaphore = dispatch_semaphore;
    }
    return self;
}

- (void)wait {
    dispatch_semaphore_wait(_semaphore, DISPATCH_TIME_FOREVER);
}

- (BOOL)signal {
    return dispatch_semaphore_signal(self.semaphore) != 0;
}

- (BOOL)waitWithSeconds:(double)seconds {
    return dispatch_semaphore_wait(self.semaphore, dispatch_time(DISPATCH_TIME_NOW, (seconds * NSEC_PER_SEC))) == 0;
}

@end
