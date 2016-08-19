//
//  ARUtils.m
//  ARUtils
//
//  Created by Alexander Rudyk on 06.07.16.
//  Copyright © 2016 Alexander Rudyk. All rights reserved.
//

#import "ARUtils.h"

@implementation ARUtils

+ (ARUtils*) sharedUtils {
    static ARUtils* utils = nil;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        utils = [[ARUtils alloc] init];
    });
    
    return utils;
}

#pragma mark - Alert

- (UIAlertController*) showAlertWithStule:(AlertStyle) style andMessage:(NSString*) message {
    NSString * title = @"";
    switch (style) {
        case AlertStyleError:
            title = @"Error";
            break;
        case AlertStyleInfo:
            title = @"Info";
            break;
        case AlertStyleWarning:
            title = @"Warning";
            break;
    }
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:title
                                                                   message:message
                                                            preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction* okButton = [UIAlertAction actionWithTitle:@"OK"
                                                       style:UIAlertActionStyleDefault
                                                     handler:nil];
    [alert addAction:okButton];
    
    return alert;
    
}

- (UIAlertController*) showStopAlertWithMessage:(NSString*) message {
    
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"Error"
                                                                   message:message
                                                            preferredStyle:UIAlertControllerStyleAlert];
    
    return alert;
}

#pragma mark - String

- (NSString*) stringWithArray:(NSArray*) array {
    NSString * result = @"";
    
    for (int index = 0; index < [array count]; index++) {
        result = [result stringByAppendingString:[NSString stringWithFormat:@"%@ ", array[index]]];
    }
    
    if ([result length] > 0) result = [result substringToIndex:[result length] - 1];
    
    return result;
}

- (NSString*) stringWithDate:(NSDate*) date andFormate:(DateFormate) formate {
    
    NSDateFormatter* dateFormatter = [[NSDateFormatter alloc] init];
    
    switch (formate) {
        case DateFormateUser: // <-- user formate
            [dateFormatter setDateFormat:@"dd MMM yyyy HH:mm"];
            break;
        case DateFormateServer: // <-- server formate
            [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
            break;
    }
    
    
    NSString * result = [dateFormatter stringFromDate:date];
    
    return result;
}

#pragma mark - Date

- (NSDate*) dateWithStringServer:(NSString*) string {
    if (![string isKindOfClass:[NSNull class]]) {
        string = [string stringByReplacingOccurrencesOfString:@"T" withString:@" "];
        
        NSDateFormatter* dateFormatter = [[NSDateFormatter alloc] init];
        
        [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss.000Z"];
        
        NSDate * date = [dateFormatter dateFromString:string];
        
        return date;
    }
    return nil;
}

- (NSString*) striingWithPostDate:(NSDate *) date {
    
    NSDate *curentDate = [NSDate date];
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    [calendar setTimeZone:[NSTimeZone localTimeZone]];
    
    NSDateComponents *components = [calendar components:(NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitMonth | NSCalendarUnitYear)
                                               fromDate:date
                                                 toDate:curentDate
                                                options:0];
    NSString *time;
    
    BOOL ifSeconds = 0;
    
    if (components.year != 0) {
        
        if(components.year == 1) time = [NSString stringWithFormat:@"%ld year", (long)components.year];
        else if(components.year < 5) time = [NSString stringWithFormat:@"%ld year", (long)components.year];
        else time = [NSString stringWithFormat:@"%ld yearі", (long)components.year];
        
    } else if (components.month != 0) {
        
        if (components.month == 1) time = [NSString stringWithFormat:@"%ld month", (long)components.month];
        else if (components.month < 5) time = [NSString stringWithFormat:@"%ld month", (long)components.month];
        else time = [NSString stringWithFormat:@"%ld months", (long)components.month];
        
    } else if (components.day != 0) {
        
        if (components.day == 1) time = [NSString stringWithFormat: @"%ld day", (long)components.day];
        else  if (components.day < 5) time = [NSString stringWithFormat: @"%ld days", (long)components.day];
        else time = [NSString stringWithFormat: @"%ld deys ", (long)components.day];
        
    } else if (components.hour!= 0) {
        
        if (components.hour == 1) time = [NSString stringWithFormat: @"%ld hour", (long)components.hour];
        else  if (components.hour < 5) time = [NSString stringWithFormat: @"%ld hours", (long)components.hour];
        else time = [NSString stringWithFormat: @"%ld hours",(long)components.hour];
        
    } else if (components.minute != 0) time = [NSString stringWithFormat: @"%ld min", (long)components.minute];
    else if (components.second >= 0)  {
        time = [NSString stringWithFormat: @"just now"];
        ifSeconds = 1;
    }
    
    if (ifSeconds) {
        return [NSString stringWithFormat:@"Just now"];
    } else {
        return [NSString stringWithFormat:@"%@ beack",time];
    }
    
}

#pragma mark - Image

- (void) imageWithURLString:(NSString*) URLString
                    success:(void (^)(id _Nonnull image))success {
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
        
        NSURL * url = [NSURL URLWithString:URLString];
        NSData * imageData = [NSData dataWithContentsOfURL:url];
        UIImage * image = [UIImage imageWithData:imageData];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            if (image) {
                success(image);
            } else {
                NSLog(@"Error load image!");
            }
        });
    });
}

- (void) imageWithURLString:(NSString*) URLString
              andErrorImage:(UIImage*) defaultImage
                    success:(void (^)(id _Nonnull image))success {
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
        
        NSURL * url = [NSURL URLWithString:URLString];
        NSData * imageData = [NSData dataWithContentsOfURL:url];
        UIImage * image = [UIImage imageWithData:imageData];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            if (image) {
                success(image);
            } else {
                NSLog(@"Error load image!");
                
                success(defaultImage);
            }
        });
    });
}

@end
