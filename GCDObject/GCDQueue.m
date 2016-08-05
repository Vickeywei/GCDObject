//
//  GCDQueue.m
//  GCD信号量使用案例
//
//  Created by 魏琦 on 16/8/2.
//  Copyright © 2016年 com.drcacom.com. All rights reserved.
//

#import "GCDQueue.h"
#import "GCDGroup.h"
static GCDQueue *mainQueue;
static GCDQueue *globalQueue;
static GCDQueue *highPriorityGlobalQueue;
static GCDQueue *lowPriorityGlobalQueue;
static GCDQueue *backgroundPriorityGlobalQueue;
static dispatch_queue_t dispatch_global_queue;
static dispatch_queue_t dispatch_main_queue;


static uint8_t mainQueueMarker[] = {0};
@interface GCDQueue ()
@property (nonatomic, strong,readwrite)dispatch_queue_t dispatchQueue;
@end

@implementation GCDQueue
+ (void)executeInGlobalQueue:(dispatch_block_t)block {
    if (!dispatch_global_queue) {
        dispatch_global_queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    }
    dispatch_async(dispatch_global_queue, block);
}

+ (void)executeInMainQueue:(dispatch_block_t)block {
    if (!dispatch_main_queue) {
        dispatch_main_queue = dispatch_get_main_queue();
    }
    dispatch_async(dispatch_main_queue, block);
}

+ (GCDQueue *)mainQueue {
    return mainQueue;
}

+ (GCDQueue *)globalQueue {
    return globalQueue;
}

+ (GCDQueue *)highPriorityGlobalQueue{
    return highPriorityGlobalQueue;
    
}

+ (GCDQueue *)lowPriorityGlobalQueue{
    return lowPriorityGlobalQueue;
    
}

+ (GCDQueue *)backgroundPriorityGlobalQueue{
    return backgroundPriorityGlobalQueue;
    
}
+ (BOOL)isMainQueue{
    return dispatch_get_specific(mainQueueMarker) == mainQueueMarker;
    
}

- (instancetype)init{
    return [self initSerial];
}

- (instancetype)initSerial{
    return [self initWithDispatchQueue:dispatch_queue_create("com.dispatch_serial.queue", NULL)];
}

- (instancetype)initConcurrent{
    return [self initWithDispatchQueue:dispatch_queue_create("com.dispatch_concurrent.queue", DISPATCH_QUEUE_CONCURRENT)];
}

+ (void)initialize {
    if (self == [GCDQueue class]) {
        mainQueue = [[GCDQueue alloc] initWithDispatchQueue:dispatch_get_main_queue()];
        globalQueue = [[GCDQueue alloc] initWithDispatchQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)];
        highPriorityGlobalQueue = [[GCDQueue alloc] initWithDispatchQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0)];
        lowPriorityGlobalQueue = [[GCDQueue alloc] initWithDispatchQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0)];
        backgroundPriorityGlobalQueue = [[GCDQueue alloc] initWithDispatchQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0)];
        
        [mainQueue setContext:mainQueueMarker forKey:mainQueueMarker];
    }
}

- (instancetype)initWithDispatchQueue:(dispatch_queue_t)dispatchQueue{
    if (self = [super init]) {
        self.dispatchQueue = dispatchQueue;
    }
    return self;
}

- (void)queueBlock:(dispatch_block_t)block{
    dispatch_async(self.dispatchQueue, block);
}

- (void)queueBlock:(dispatch_block_t)block afterDelay:(double)seconds{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(seconds * NSEC_PER_SEC)),self.dispatchQueue, block);
}

- (void)queueAndAwaitBlock:(dispatch_block_t)block{
    dispatch_sync(self.dispatchQueue, block);
    
}

- (void)queueAndAwaitBlock:(void (^)(size_t))block iterationCount:(size_t)count{
    dispatch_apply(count, self.dispatchQueue, block);
}

- (void)queueBlock:(dispatch_block_t)block inGroup:(GCDGroup *)group{
    dispatch_group_async(group.dispatchGroup, self.dispatchQueue, block);
}

- (void)queueNotifyBlock:(dispatch_block_t)block inGroup:(GCDGroup *)group{
    dispatch_group_notify(group.dispatchGroup, self.dispatchQueue, block);
}

- (void)queueBarrierBlock:(dispatch_block_t)block{
    dispatch_barrier_async(self.dispatchQueue, block);
}

- (void)queueAndAwaitBarrierBlock:(dispatch_block_t)block{
    dispatch_barrier_sync(self.dispatchQueue, block);
}

- (void)suspend{
    dispatch_suspend(self.dispatchQueue);
}
- (void)resume{
    dispatch_resume(self.dispatchQueue);
    
}
- (void *)contextForKey:(const void *)key{
    return dispatch_get_specific(key);
}

- (void)setContext:(void *)context forKey:(const void *)key{
    dispatch_queue_set_specific(self.dispatchQueue, key, context, NULL);
}


@end

