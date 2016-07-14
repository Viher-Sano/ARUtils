//
//  ARUtils.h
//  ARUtils
//
//  Created by Alexander Rudyk on 06.07.16.
//  Copyright © 2016 Alexander Rudyk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 * @typedef DateFormate
 * @brief A list of date formate.
 * @constant DateFormateUser dd MMM yyyy HH:mm.
 * @constant DateFormateServer yyyy-MM-dd HH:mm:ss.
 */

typedef enum {
    DateFormateUser,        // dd MMM yyyy HH:mm    --> 06 jul. 2016 13:30
    DateFormateServer       // yyyy-MM-dd HH:mm:ss  --> 2016-07-06 13:30:00
} DateFormate;

/*!
 * @typedef AlertStyle
 * @brief A list of alert style.
 * @constant AlertStyleError title Error.
 * @constant AlertStyleInfo title Info.
 * @constant AlertStyleWarning title Warning.
 */

typedef enum {
    AlertStyleError,
    AlertStyleInfo,
    AlertStyleWarning
} AlertStyle;

@interface ARUtils : NSObject

/*!
 * @discussion singleton method that creates or returns ARUtils.
 * @return ARUtils that was created or extracted from memory.
 */

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
 * @discussion This method creates alert which makes it impossible to use the program on.
 * @param message At NSString by message you want to display to the user.
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

/*!
 * @discussion This method converts NSDate to NSString with format.
 * @param date At NSDate you want to convert.
 * @param formate At DateFormate format you want the output.
 * @return NSString the date in the appropriate format.
 */

- (NSString*) stringWithDate:(NSDate*) date andFormate:(DateFormate) formate;

#pragma mark - Date

/*!
 * @discussion This method converts NSString to NSDate with server format.
 * @param string At NSString you want to convert.
 * @return NSDate.
 */

- (NSDate*) dateWithStringServer:(NSString*) string;

/*!
 * @discussion This method converts NSDate to NSString in the time interval. Example: "5 days".
 * @param date At NSDate you want to convert.
 * @return NSString the time interval.
 */

- (NSString*) striingWithPostDate:(NSDate *) date;

#pragma mark - Image

/*!
 * @discussion loads the image to the specified URL.
 * @param URLString URL the picture you want to download.
 * @param success block is executed after loading.
 */

- (void) imageWithURLString:(NSString*) URLString
                    success:(void (^)(id image))success;

/*!
 * @discussion loads the image to the specified URL.
 * @param URLString URL the picture you want to download.
 * @param defaultImage if the image that will return an error when loading.
 * @param success block is executed after loading.
 */

- (void) imageWithURLString:(NSString*) URLString
              andErrorImage:(UIImage*) defaultImage
                    success:(void (^)(id image))success;
@end

