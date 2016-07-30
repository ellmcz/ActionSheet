//
//  Sheet.h
//  MovieCenter
//
//  Created by 王钱宝 on 16/6/25.
//  Copyright © 2016年 ellmcz. All rights reserved.
//

#import <UIKit/UIKit.h>
@class Sheet;


typedef void(^SheetBlock)(NSInteger buttonIndex);


#pragma mark - Delegate

@protocol SheetDelegate <NSObject>

@optional

/**
 *  点击了 buttonIndex 处的按钮
 */
- (void)actionSheet:(Sheet *)sheet didClickedButtonAtIndex:(NSInteger)buttonIndex;

@end
@interface Sheet : UIView
@property (nonatomic, copy) NSString *title;

@property (nonatomic, assign) NSInteger redButtonIndex;

@property (nonatomic, copy) SheetBlock clickedBlock;

/**
 *  Localized cancel text. Default is "取消"
 */
@property (nonatomic, strong) NSString *cancelText;

/**
 *  Default is [UIFont systemFontOfSize:18]
 */
@property (nonatomic, strong) UIFont *textFont;

/**
 *  Default is Black
 */
@property (nonatomic, strong) UIColor *textColor;

/**
 *  Default is 0.3 seconds
 */
@property (nonatomic, assign) CGFloat animationDuration;

/**
 *  Opacity of background, default is 0.3f
 */
@property (nonatomic, assign) CGFloat backgroundOpacity;



#pragma mark - Delegate Way

/**
 *  返回一个 ActionSheet 对象, 类方法
 *
 *  @param title          提示标题
 *  @param buttonTitles   所有按钮的标题
 *  @param redButtonIndex 红色按钮的 index
 *  @param delegate       代理
 *
 *  Tip: 如果没有红色按钮, redButtonIndex 给 `-1` 即可
 */
+ (instancetype)sheetWithTitle:(NSString *)title
                  buttonTitles:(NSArray *)buttonTitles
                redButtonIndex:(NSInteger)redButtonIndex
                      delegate:(id<SheetDelegate>)delegate;

/**
 *  返回一个 ActionSheet 对象, 实例方法
 *
 *  @param title          提示标题
 *  @param buttonTitles   所有按钮的标题
 *  @param redButtonIndex 红色按钮的 index
 *  @param delegate       代理
 *
 *  Tip: 如果没有红色按钮, redButtonIndex 给 `-1` 即可
 */
- (instancetype)initWithTitle:(NSString *)title
                 buttonTitles:(NSArray *)buttonTitles
               redButtonIndex:(NSInteger)redButtonIndex
                     delegate:(id<SheetDelegate>)delegate;




#pragma mark - Block Way

/**
 *  返回一个 ActionSheet 对象, 类方法
 *
 *  @param title          提示标题
 *  @param buttonTitles   所有按钮的标题
 *  @param redButtonIndex 红色按钮的 index
 *  @param clicked        点击按钮的 block 回调
 *
 *  Tip: 如果没有红色按钮, redButtonIndex 给 `-1` 即可
 */
+ (instancetype)sheetWithTitle:(NSString *)title
                  buttonTitles:(NSArray *)buttonTitles
                redButtonIndex:(NSInteger)redButtonIndex
                       clicked:(SheetBlock)clicked;

/**
 *  返回一个 ActionSheet 对象, 实例方法
 *
 *  @param title          提示标题
 *  @param buttonTitles   所有按钮的标题
 *  @param redButtonIndex 红色按钮的 index
 *  @param clicked        点击按钮的 block 回调
 *
 *  Tip: 如果没有红色按钮, redButtonIndex 给 `-1` 即可
 */
- (instancetype)initWithTitle:(NSString *)title
                 buttonTitles:(NSArray *)buttonTitles
               redButtonIndex:(NSInteger)redButtonIndex
                      clicked:(SheetBlock)clicked;


#pragma mark - Custom Way

/**
 *  Add a button with callback block
 *
 *  @param button
 *  @param block
 */
- (void)addButtonTitle:(NSString *)button;


#pragma mark - Show

/**
 *  显示 ActionSheet
 */
- (void)show;

@end
