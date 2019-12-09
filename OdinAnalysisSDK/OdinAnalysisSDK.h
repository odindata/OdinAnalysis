//
//  AodanalysisSDK.h
//  AodanalysisSDK
//
//  Created by nathan on 2019/2/26.
//  Copyright © 2019 Odin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OdinAnalysisSDK : NSObject


/**
 * 初始化SDK
 * @param   appkey      APP注册时获取唯一标识符
 * @param   channel     当前使用渠道，设置nil默认APP Store
 */
+ (void)initSDKWithAPPKey:(NSString *_Nonnull)appkey Channel:(nullable NSString *)channel;

/**
 * 注册事件统计
 * @param   userId     用户id(用户注册成功后获取)
 */
+ (void)eventRegister:(NSString *_Nonnull)userId;

/**
 * 登录接口
 * @param   userId          用户id(用户登录成功后获取)
 * @param   status           登录状态;1成功0失败。
 */
+ (void)eventLogin:(NSString *_Nonnull)userId status:(NSInteger)status;

/**
 * 开始登录统计（用于统计登录时长）
 */
+ (void)beginEventLogin;

/**
 * 结束登录统计(配合开始登录使用)
 * @param   userId          用户id(用户登录成功后获取，失败传空)
 * @param   status           登录状态;1成功0失败。
 */
+ (void)endEventLogin:(NSString *_Nonnull)userId status:(NSInteger)status;


/**
 * 支付事件
 * @param   payAmount       支付金额
 * @param   orderNumber     订单编号
 * @param   amount          数量
 */
+ (void)eventPay:(double)payAmount orderNumber:(NSString *_Nonnull)orderNumber amount:(NSString *_Nonnull)amount;

/**
 * 操作事件统计（点击、双击、滑动等）
 * @param   eventId         事件名称
 */
+ (void)eventOperation:(NSString *_Nonnull)eventId;

/**
 异常事件统计（用户反馈）
 @param title 异常标题
 @param context 异常内容
 */
+ (void)eventErrorTitle:(NSString *_Nonnull)title context:(NSString *_Nonnull)context;


/**
 针对PageView的统计

 @param pageName 开始页面的名称
 */
+ (void)pageStart:(NSString *_Nonnull)pageName;
/**
 针对PageView的统计
 
 @param pageName 结束页面的名称
 */
+ (void)pageEnd:(NSString *_Nonnull)pageName;


/**
 泛事件
 
 @param event_id 事件id
 @param param 事件参数
 */
+ (void)trackEvent:(NSString *_Nonnull)event_id param:(NSDictionary *_Nonnull)param;

/**
 * 是否支持打印log信息
 * @param   enable      默认NO，仅开发调试用，正式上传必须关闭
 */
+ (void)setEnableLog:(BOOL)enable;

//仅供测试使用
+ (void)getAllEventData:(void (^_Nonnull)(NSArray * _Nullable dataArr))complete;
+ (NSString *_Nullable)getDataSendPath;
@end
