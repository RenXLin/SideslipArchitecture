//
//  RXLSideSlipViewController.h
//  SideslipArchitecture
//
//  Created by renxiaolin on 14/11/10.
//  Copyright (c) 2014年 https://github.com/RenXLin/. All rights reserved.
//

#import <UIKit/UIKit.h>


#if __IPHONE_OS_VERSION_MAX_ALLOWED > __IPHONE_6_1

#define IF_IOS7_OR_GREATER(...) \
if (kCFCoreFoundationVersionNumber > kCFCoreFoundationVersionNumber_iOS_6_1) \
{ \
__VA_ARGS__ \
}

#else

#define IF_IOS7_OR_GREATER(...)

#endif



@class RXLSideSlipViewController;

@protocol RXLSideMenuDelegate <NSObject>

@optional

- (void)sideMenu:(RXLSideSlipViewController *)sideMenu didRecognizePanGesture:(UIPanGestureRecognizer *)recognizer;

- (void)sideMenu:(RXLSideSlipViewController *)sideMenu willShowMenuViewController:(UIViewController *)menuViewController;

- (void)sideMenu:(RXLSideSlipViewController *)sideMenu didShowMenuViewController:(UIViewController *)menuViewController;

- (void)sideMenu:(RXLSideSlipViewController *)sideMenu willHideMenuViewController:(UIViewController *)menuViewController;

- (void)sideMenu:(RXLSideSlipViewController *)sideMenu didHideMenuViewController:(UIViewController *)menuViewController;

@end


@interface RXLSideSlipViewController : UIViewController<UIGestureRecognizerDelegate>


@property (strong, readwrite, nonatomic) UIViewController *contentViewController;
@property (strong, readwrite, nonatomic) UIViewController *leftMenuViewController;
@property (strong, readwrite, nonatomic) UIViewController *rightMenuViewController;
@property (weak, readwrite, nonatomic) id<RXLSideMenuDelegate> delegate;


//手势时间：
@property (assign, readwrite, nonatomic) NSTimeInterval animationDuration;
//背景图片：
@property (strong, readwrite, nonatomic) UIImage *backgroundImage;
//开启手势：
@property (assign, readwrite, nonatomic) BOOL panGestureEnabled;
//边缘检测手势：
@property (assign, readwrite, nonatomic) BOOL panFromEdge;
//滑动的阈值：
@property (assign, readwrite, nonatomic) NSUInteger panMinimumOpenThreshold;
//交互手势：
@property (assign, readwrite, nonatomic) IBInspectable BOOL interactivePopGestureRecognizerEnabled;


@property (assign, readwrite, nonatomic) IBInspectable BOOL fadeMenuView;
@property (assign, readwrite, nonatomic) IBInspectable BOOL scaleContentView;
@property (assign, readwrite, nonatomic) IBInspectable BOOL scaleBackgroundImageView;
@property (assign, readwrite, nonatomic) IBInspectable BOOL scaleMenuView;

@property (assign, readwrite, nonatomic) IBInspectable BOOL contentViewShadowEnabled;
@property (strong, readwrite, nonatomic) IBInspectable UIColor *contentViewShadowColor;
@property (assign, readwrite, nonatomic) IBInspectable CGSize contentViewShadowOffset;
@property (assign, readwrite, nonatomic) IBInspectable CGFloat contentViewShadowOpacity;
@property (assign, readwrite, nonatomic) IBInspectable CGFloat contentViewShadowRadius;
@property (assign, readwrite, nonatomic) IBInspectable CGFloat contentViewFadeOutAlpha;
@property (assign, readwrite, nonatomic) IBInspectable CGFloat contentViewScaleValue;
@property (assign, readwrite, nonatomic) IBInspectable CGFloat contentViewInLandscapeOffsetCenterX;
@property (assign, readwrite, nonatomic) IBInspectable CGFloat contentViewInPortraitOffsetCenterX;

@property (assign, readwrite, nonatomic) IBInspectable CGFloat parallaxMenuMinimumRelativeValue;
@property (assign, readwrite, nonatomic) IBInspectable CGFloat parallaxMenuMaximumRelativeValue;
@property (assign, readwrite, nonatomic) IBInspectable CGFloat parallaxContentMinimumRelativeValue;
@property (assign, readwrite, nonatomic) IBInspectable CGFloat parallaxContentMaximumRelativeValue;

@property (assign, readwrite, nonatomic) CGAffineTransform menuViewControllerTransformation;
@property (assign, readwrite, nonatomic) IBInspectable BOOL parallaxEnabled;
@property (assign, readwrite, nonatomic) IBInspectable BOOL bouncesHorizontally;
@property (assign, readwrite, nonatomic) UIStatusBarStyle menuPreferredStatusBarStyle;
@property (assign, readwrite, nonatomic) IBInspectable BOOL menuPrefersStatusBarHidden;

- (id)initWithContentViewController:(UIViewController *)contentViewController
             leftMenuViewController:(UIViewController *)leftMenuViewController
            rightMenuViewController:(UIViewController *)rightMenuViewController;

- (void)presentLeftMenuViewController;

- (void)presentRightMenuViewController;

- (void)hideMenuViewController;

- (void)setContentViewController:(UIViewController *)contentViewController animated:(BOOL)animated;

@end
