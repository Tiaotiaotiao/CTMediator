//
//  CTMediator.h
//  CTMediator
//
//  Created by casa on 16/3/13.
//  Copyright © 2016年 casa. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * _Nonnull const kCTMediatorParamsKeySwiftTargetModuleName;

#define kCTMediator [CTMediator sharedInstance]

@interface CTMediator : NSObject

+ (instancetype _Nonnull)sharedInstance;

// 远程App调用入口
- (id _Nullable)performActionWithUrl:(NSURL * _Nullable)url completion:(void(^_Nullable)(NSDictionary * _Nullable info))completion;
// 本地组件调用入口


- (id)performTarget:(NSString *)targetName action:(NSString *)actionName shouldCacheTarget:(BOOL)shouldCacheTarget;

- (id _Nullable )performTarget:(NSString * _Nullable)targetName action:(NSString * _Nullable)actionName params:(NSDictionary * _Nullable)params shouldCacheTarget:(BOOL)shouldCacheTarget;

- (void)releaseCachedTargetWithFullTargetName:(NSString * _Nullable)fullTargetName;
// 检查 是否有引源码
- (BOOL)check:(NSString * _Nullable)targetName moduleName:(NSString * _Nullable)moduleName;
@end
  
// 简化调用单例的函数
CTMediator* _Nonnull CT(void);
