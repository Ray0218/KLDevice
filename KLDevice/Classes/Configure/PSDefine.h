//
//  PSDefine.h
//  LoanMarket
//
//  Created by apple on 2018/8/8.
//  Copyright © 2018年 吴孔亮. All rights reserved.
//

#ifndef PSDefine_h
#define PSDefine_h

/************************* 设备信息 *************************/
#define DEVICE_USERNAME        [[UIDevice currentDevice] name]
#define DEVICE_SYSTEMNAME      [[UIDevice currentDevice] systemName]
#define DEVICE_VESION          ([[[UIDevice currentDevice] systemVersion] floatValue])
#define DEVICE_VESION_STR       [[UIDevice currentDevice] systemVersion]
#define DEVICE_IPHONEORPAD     [[UIDevice currentDevice] userInterfaceIdiom]
#define DEVICE_ISIPAD          (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define DEVICE_ADUUID          [[[ASIdentifierManager sharedManager] advertisingIdentifier]UUIDString]

/************************ 颜色宏定义 ************************/

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0x00FF0000) >> 16)) / 255.0     green:((float)((rgbValue & 0x0000FF00) >>  8)) / 255.0 blue:((float)((rgbValue & 0x000000FF) >>  0)) / 255.0 alpha:1.0]
#define kBlackColor UIColorFromRGB(0x000000)

#define kBaseColor UIColorFromRGB(0x1CDDB1) // UIColorFromRGB(0xFF7A3F)
#define kBackGroundColor [UIColor colorWithRed:0.96 green:0.96 blue:0.96 alpha:1.00]
#define kColor98 UIColorFromRGB(0x989898)

#define kWhiteColor [UIColor whiteColor]

#define kLineColor UIColorFromRGB(0xEEEEEE)
#define kColor43 UIColorFromRGB(0x434343)
#define kColor89 UIColorFromRGB(0x898989)

/************************ 屏幕尺寸宏定义 ************************/
//设备屏幕宽度(320)
#define SCREEN_WIDTH   CGRectGetWidth([[UIScreen mainScreen] bounds])
//设备屏幕高度(480/568)
#define SCREEN_HEIGHT  CGRectGetHeight([[UIScreen mainScreen] bounds])


/************************* 导航栏宏定义 *************************/


#define IS_IPHONE_X \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})
//#define IS_IPHONE_X (SCREEN_HEIGHT == 812.0f) ? YES : NO

#define NAV_TITLE_COLOR [UIColor whiteColor]
#define NAV_TITLE_FONT [UIFont systemFontOfSize:18.0]
#define NAV_BACKGROUND_COLOR  [UIColor whiteColor]
#define NAV_BUTTON_WIDTH 80.0
#define NAV_BUTTON_HEIGHT 44.0
#define NAV_BUTTON_FONT [UIFont systemFontOfSize:13.0]
#define NAV_BUTTON_COLOR  kNavRedColor
#define NAV_LEFTBUTTON_ICON [UIImage imageNamed:@"com_back"]

#define NAV_HEIGHT    ((IS_IPHONE_X==YES)?88.0f: 64.0f)
#define StatusBar_Height ((IS_IPHONE_X==YES)?44.0f: 20.0f)

/************************* 字母数字宏定义 *************************/

#define kNUM @"0123456789"
#define kALPHA @"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define kALPHANUM @"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"


/************************* App *************************/
#define kAppCacheName @"getpesoAPP"
#define kCellPhoneNumCache @"kCellPhoneNumCache"
#define kUserInfoCache @"GetPesokUserInfoCache"

#define kSignTimeCache @"kSignTimeCache"

#define kAppVisionKey @"kGetPesoAppVisionKey"

#define kEndRefreshNotify @"endrefreshNotify"

#define kFBLogFinish @"kFBLogFinish"


#define kActionKey @"action"

#define kIsFirstOpen @"firstOpenPeso"


/************************* 重写NSLog,Debug模式下打印日志和当前行数*************************/
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif



/************************* 多语种函数 *************************/

//#define kLocalized(key)  [[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] objectForKey:@"userLanguage"]] ofType:@"lproj"]] localizedStringForKey:(key) value:nil table:@"Language"]

/**
 数字符号化
 
 @param num 数字
 @return 格式化数据
 */
static inline NSString *TTNumberFormatString(NSNumber *num ){
    
    NSNumberFormatter *numFormatter = [[NSNumberFormatter alloc] init];
    numFormatter.numberStyle = NSNumberFormatterDecimalStyle;
    numFormatter.alwaysShowsDecimalSeparator = NO ;
    numFormatter.allowsFloats = YES;
    numFormatter.minimumFractionDigits = 0;
    numFormatter.maximumFractionDigits = 0 ;
    // 小数点样式
//    numFormatter.decimalSeparator = @".";
//    numFormatter.groupingSeparator = @".";
    numFormatter.formatterBehavior = NSNumberFormatterBehavior10_4;
    
    NSString *textl =  @"0";
    
    if (num && [num isKindOfClass:[NSNumber class]]) {
        textl = [numFormatter stringFromNumber:num];
    }
    return textl;
}


static inline NSMutableAttributedString * TTFormateColorString( NSString*text,NSString *redString,CGFloat font ,UIColor *normalColor ,UIColor* redColor ){
    
    NSMutableAttributedString *att = [[NSMutableAttributedString  alloc]initWithString:text attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:font],NSForegroundColorAttributeName:normalColor}] ;
    NSRange range = [text rangeOfString:redString] ;
    
    [att addAttribute:NSForegroundColorAttributeName value:redColor range:range ] ;
    
    return att ;
    
} ;


static inline NSString *TTDecimalNumberWithDouble(double conversionValue){
    NSString *doubleString        = [NSString stringWithFormat:@"%lf", conversionValue];
    NSDecimalNumber *decNumber    = [NSDecimalNumber decimalNumberWithString:doubleString];
    return [decNumber stringValue];
};


#endif /* PSDefine_h */
