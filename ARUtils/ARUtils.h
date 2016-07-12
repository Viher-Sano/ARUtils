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

/*!
 * @discussion This method creates alert accordance with the chosen style.
 * @param style Style alert you selected from AlertStyle.
 * @param message At NSString by message you want to display to the user.
 * @return UIAlertController that you customized.
 */

- (UIAlertController*) showAlertWithStule:(AlertStyle) style andMessage:(NSString*) message;

/*!
 * @discussion This method creates alert accordance with the chosen style.
 * @param style Style alert you selected from AlertStyle.
 * @return UIAlertController that you customized.
 */

- (UIAlertController*) showStopAlertWithMessage:(NSString*) message;

#pragma mark - String

/*!
 * @discussion This method converts panels in NSString.
 * @warning The array must contain only NSString.
 * @param array At NSArray by the array you want to convert.
 * @return NSString what was created from an array.
 */

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

