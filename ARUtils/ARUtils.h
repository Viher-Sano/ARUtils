//
//  ARUtils.h
//  ARUtils
//
//  Created by Alexander Rudyk on 06.07.16.
//  Copyright © 2016 Alexander Rudyk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum {
    DateFormateUser,        // dd MMM yyyy HH:mm    --> 06 jul. 2016 13:30
    DateFormateServer       // yyyy-MM-dd HH:mm:ss  --> 2016-07-06 13:30:00
} DateFormate;

typedef enum {
    AlertStyleError,
    AlertStyleInfo,
    AlertStyleWarning
} AlertStyle;

@interface ARUtils : NSObject

+ (ARUtils*) sharedUtils;

#pragma mark - Alert

- (UIAlertController*) showAlertWithStule:(AlertStyle) style andMessage:(NSString*) message;
- (UIAlertController*) showStopAlertWithMessage:(NSString*) message;

#pragma mark - String

- (NSString*) stringWithArray:(NSArray*) array;
- (NSString*) stringWithDate:(NSDate*) date andFormate:(DateFormate) formate;

#pragma mark - Date

- (NSDate*) dateWithStringServer:(NSString*) string;
- (NSString*) striingWithPostDate:(NSDate *) date;

#pragma mark - Image

- (void) imageWithURLString:(NSString*) URLString
                    success:(void (^)(id image))success;

- (void) imageWithURLString:(NSString*) URLString
              andErrorImage:(UIImage*) defaultImage
                    success:(void (^)(id image))success;
@end

