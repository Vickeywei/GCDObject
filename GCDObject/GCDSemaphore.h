//
//  GCDSemaphore.h
//  GCD信号量使用案例
//
//  Created by 魏琦 on 16/8/2.
//  Copyright © 2016年 com.drcacom.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GCDSemaphore : NSObject
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return a dispatch_semaphore instance
 */
- (instancetype)init;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @param value The initial value
 *
 *  @return a dispatch_semaphore instance
 */
- (instancetype)initWithValue:(long)value;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @param dispatch_semaphore A given dispatch_semaphore
 *
 *  @return a dispatch_semaphore instance
 */
- (instancetype)initWithDispatchSemaphore:(dispatch_semaphore_t)dispatch_semaphore;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe wait forever the semaphore
 */
- (void)wait;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe if return yes Said this thread awoken otherwise NO
 *
 *  @return yes or no
 */
- (BOOL)signal;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe wait forever the semaphore
 *
 *  @param seconds Waiting for the length of the
 *
 *  @return return yes or no
 */
- (BOOL)waitWithSeconds:(double)seconds;


@end
