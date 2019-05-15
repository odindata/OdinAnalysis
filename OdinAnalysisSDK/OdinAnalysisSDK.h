//
//  AodanalysisSDK.h
//  AodanalysisSDK
//
//  Created by nathan on 2019/2/26.
//  Copyright © 2019 Odin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OdinAnalysisSDK : NSObject


/*
 * 初始化SDK
 * @param   appkey      APP注册时获取唯一标识符
 * @param   channel     当前使用渠道，设置nil默认APP Store
 */
+ (void)initSDKWithAPPKey:(NSString *)appkey Channel:(NSString *)channel;

/*
 * 注册事件统计
 * @param   userId     用户id(用户注册成功后获取)
 */
+ (void)eventRegister:(NSString *)userId;

/*
 * 登录接口
 * @param   userId          用户id(用户登录成功后获取)
 * @param   state           登录状态;1成功0失败。
 */
+ (void)eventLogin:(NSString *)userId status:(NSInteger)status;

/*
 * 开始登录统计（用于统计登录时长）
 */
+ (void)beginEventLogin;

/*
 * 结束登录统计(配合开始登录使用)
 * @param   userId          用户id(用户登录成功后获取，失败传空)
 * @param   state           登录状态;1成功0失败。
 */
+ (void)endEventLogin:(NSString *)userId status:(NSInteger)status;

/*
 * 支付事件
 * @param   payAmount       支付金额
 * @param   orderNumber     订单编号
  * @param  amount          数量
 */
+ (void)eventPay:(double)payAmount orderNumber:(NSString *)orderNumber amount:(NSString *)amount;

/*
 * 操作事件统计（点击、双击、滑动等）
 * @param   eventId         事件名称
 */
+ (void)eventOperation:(NSString *)eventId;

/*
 * 自定义事件
 * @param   eventId       事件eventId 说明：不超过20位，必须小写英文字母加下划线，英文字母结尾，每个事件名称唯一
 * @param   attributes      自定义属性{"key1":"value1","key2":"value2"}
 */
+ (void)eventCustom:(NSString *)eventId attributes:(NSDictionary *)attributes;

/**
 自定定义事件时长统计开始

 @param eventId 自定义事件名称或者ID
 @param attributes 为自定义事件的属性和取值(@"key1":@"value1",@"key1":@"value1")
 */
+ (void)beginEventCustom:(NSString *)eventId attributes:(NSDictionary *)attributes;

/**
 自定定义事件时长统计结束

 @param eventId 自定义事件名称或者ID
 @param attributes 为自定义事件的属性和取值(@"key1":@"value1",@"key1":@"value1")
 */
+ (void)endEventCustom:(NSString *)eventId attributes:(NSDictionary *)attributes;


/**
 异常事件统计
 @param title 异常标题
 @param context 异常内容
 */
+ (void)eventErrorTitle:(NSString *)title context:(NSString *)context;


/**
 针对PageView的统计

 @param pageName 开始页面的名称
 */
+ (void)pageStart:(NSString *)pageName;
/**
 针对PageView的统计
 
 @param pageName 结束页面的名称
 */
+ (void)pageEnd:(NSString *)pageName;

/*
 * 是否支持打印log信息
 * @param   canLog      默认NO，仅开发调试用，正式上传必须关闭
 */
+ (void)setEnableLog:(BOOL)enable;

//仅供测试使用
+ (void)getAllEventData:(void (^)(NSArray *dataArr))complete;
+ (NSString *)getDataSendPath;
@end
