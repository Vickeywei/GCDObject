//
//  GCDGroup.m
//  GCD信号量使用案例
//
//  Created by 魏琦 on 16/8/2.
//  Copyright © 2016年 com.drcacom.com. All rights reserved.
//

#import "GCDGroup.h"
@interface GCDGroup ()
@property (nonatomic, strong,readwrite)dispatch_group_t dispatchGroup;
@end
@implementation GCDGroup
#pragma -mark initialized
- (instancetype)init {
  return [self initWithDispatchGroup:dispatch_group_create()];
}

- (instancetype)initWithDispatchGroup:(dispatch_group_t)dispatchGroup {
    if (self = [super init]) {
        self.dispatchGroup = dispatchGroup;
    }
    return self;
}
#pragma -mark dispatch_group_method
- (void)enter {
    dispatch_group_enter(self.dispatchGroup);
}

- (void)leave {
    dispatch_group_leave(self.dispatchGroup);
}

- (void)wait {
    dispatch_group_wait(self.dispatchGroup, DISPATCH_TIME_FOREVER);
}

- (BOOL)wait:(double)seconds {
  return   dispatch_group_wait(self.dispatchGroup, dispatch_time(DISPATCH_TIME_NOW, (seconds * NSEC_PER_SEC)) == 0);
                        
}

- (void)executeWithGroupInGlobalQueue:(dispatch_block_t)block {
    dispatch_group_async(self.dispatchGroup, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block);
}

- (void)executeWithNotifyInMainQueue:(dispatch_block_t)block {
    dispatch_group_notify(self.dispatchGroup, dispatch_get_main_queue(), block);
}

- (void)executeWithGroupInCustomQueue:(dispatch_queue_t)queue withDispatchBlock:(dispatch_block_t)block {
    dispatch_group_async(self.dispatchGroup, queue, block);
}

- (void)executeWithGroupNotifyInCustomQueue:(dispatch_queue_t)queue withDispatchBlock:(dispatch_block_t)block {
    dispatch_group_notify(self.dispatchGroup, queue, block);
}

@end
