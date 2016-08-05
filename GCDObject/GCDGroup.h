//
//  GCDGroup.h
//
//  Created by 魏琦 on 16/8/2.
//  Copyright © 2016年 com.drcacom.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GCDGroup : NSObject
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe return Within the dispatch_group
 */
@property (strong, readonly, nonatomic) dispatch_group_t dispatchGroup;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @return GCDGroup instance
 */
- (instancetype)init;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @param dispatchGroup a dispatch_group_t object.
 *
 *  @return GCDGroup instance
 */
- (instancetype)initWithDispatchGroup:(dispatch_group_t)dispatchGroup;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe  block Will join the group
 *
 *  @see dispatch_group_enter()
*/
- (void)enter;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe  In the group block has been completed
 *  
 *  @see  dispatch_group_leave()
 */
- (void)leave;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe  Wait forever over the block
 *
 *  @see  dispatch_group_wait()
 */
- (void)wait;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe  Wait seconds over the block
 *
 *  @see  dispatch_group_wait()
 */
- (BOOL)wait:(double)seconds;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @param block Need to perform operation block
 */
- (void)executeWithGroupInGlobalQueue:(dispatch_block_t)block;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @desrcibe The end of the additional processing for group in main queue
 *
 *  @param block dispatch_block_t
 */
- (void)executeWithNotifyInMainQueue:(dispatch_block_t)block;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @describe In a custom queue all additional operations
 *
 *  @param queue customQueue
 *
 *  @param block dispatch_block_t
 */
- (void)executeWithGroupInCustomQueue:(dispatch_queue_t)queue withDispatchBlock:(dispatch_block_t)block;
/**
 *  @author vicky 2016-08-02 19:37
 *
 *  @desrcibe The end of the additional processing for group in custom queue
 *
 *  @param block dispatch_block_t
 */
- (void)executeWithGroupNotifyInCustomQueue:(dispatch_queue_t)queue withDispatchBlock:(dispatch_block_t)block;

@end

