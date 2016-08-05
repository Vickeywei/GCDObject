//
//  GCDQueue.h
//  GCD信号量使用案例
//
//  Created by 魏琦 on 16/8/2.
//  Copyright © 2016年 com.drcacom.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class GCDGroup;

@interface GCDQueue : NSObject

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return The dispatch queue object.
 */
@property (strong, readonly, nonatomic) dispatch_queue_t dispatchQueue;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return mainQueue
 *  @see dispatch_get_main_queue()
 */
+ (GCDQueue *)mainQueue;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return the DEFAULT priority global concurrent queue
 *  @see dispatch_get_global_queue()
 */
+ (GCDQueue *)globalQueue;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return the HIGH priority global concurrent queue
 *  @see dispatch_get_global_queue()
 */
+ (GCDQueue *)highPriorityGlobalQueue;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return the LOW priority global concurrent queue
 *  @see dispatch_get_global_queue()
 */
+ (GCDQueue *)lowPriorityGlobalQueue;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return the BACKGROUND priority global concurrent queue
 *  @see dispatch_get_global_queue()
 */
+ (GCDQueue *)backgroundPriorityGlobalQueue;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return YES:is mian queue Otherwise no
 */
+ (BOOL)isMainQueue;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return the queue.
 *
 *  @describe  creat a new serial queue
 *
 *  @see dispatch_queue_create()
 */
- (instancetype)init;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return the queue.
 *
 *  @describe  creat a new serial queue
 *
 *  @see dispatch_queue_create()
 */
- (instancetype)initSerial;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return the queue.
 *
 *  @describe  creat a new concurrent queue
 *
 *  @see dispatch_queue_create()
 */
- (instancetype)initConcurrent;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @param dispatchQueue queue
 *
 *  @return the queue
 */
- (instancetype)initWithDispatchQueue:(dispatch_queue_t)dispatchQueue;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe Asynchronous execution of this block
 *
 *  @param need to perform the block
 *
 *  @see dispatch_async()
 */
- (void)queueBlock:(dispatch_block_t)block;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @After delay to submit the piece to the queue
 *
 *  @param block The block to submit.
 *
 *  @param afterDelay The delay in seconds.
 *
 *  @see dispatch_after()
 */
- (void)queueBlock:(dispatch_block_t)block afterDelay:(double)seconds;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe Synchronous submit this task to the queue
 *
 *  @param block dispatch_block_t
 *
 *  @see dispatch_sync()
 */
- (void)queueAndAwaitBlock:(dispatch_block_t)block;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe Submit a piece of execution in the queue for many times, waiting, until all finished executing.
 *
 *  @param block dispatch_block_t
 *
 *  @param iterationCount The number of times to execute the block.
 *
 *  @see dispatch_apply()
 */
- (void)queueAndAwaitBlock:(void (^)(size_t))block iterationCount:(size_t)count;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe Submit a set of queue tasks, and in this group
 *
 *  @param block dispatch_block_t
 *
 *  @param inGroup The group to associate the block with.
 *
 *  @see dispatch_group_async()
 */
- (void)queueBlock:(dispatch_block_t)block inGroup:(GCDGroup *)group;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @decribe The end of a group of tasks, notice the end task execution
 *
 *  @param block dispatch_block_t
 *
 *  @param inGroup The group to observe.
 *
 *  @see dispatch_group_notify()
 */
- (void)queueNotifyBlock:(dispatch_block_t)block inGroup:(GCDGroup *)group;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @decribe Submit a barrier block async to perform tasks to the queue.
 *
 *  @param block dispatch_block_t
 *
 *  @see dispatch_barrier_async()
 */
- (void)queueBarrierBlock:(dispatch_block_t)block;

/**
 *  @describe Submit a barrier block sync to perform tasks to the queue.
 *
 *  @param block dispatch_block_t
 *
 *  @see dispatch_barrier_sync()
 */
- (void)queueAndAwaitBarrierBlock:(dispatch_block_t)block;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe Suspend the running queue
 *
 *  @see dispatch_suspend()
 */
- (void)suspend;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe resume the suspend queue
 *
 *  @see dispatch_resume()
 */
- (void)resume;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe return the contextual a key.
 *
 *  @see dispatch_get_specific()
 */
- (void *)contextForKey:(const void *)key;

/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe Set the contextual a key.
 *
 *  @see dispatch_queue_set_specific()
 */
- (void)setContext:(void *)context forKey:(const void *)key;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe Asynchronous execution of this block on mainQueue
 *
 *  @param block Asynchronous execution of this block
 */

+(void)executeInGlobalQueue:(dispatch_block_t)block;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe Asynchronous execution of this block on mainQueue
 *
 *  @param block Asynchronous execution of this block on mainQueue
 */
+(void)executeInMainQueue:(dispatch_block_t)block;

@end
