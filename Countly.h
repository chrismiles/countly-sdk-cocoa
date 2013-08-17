
// Countly.h
//
// This code is provided under the MIT License.
//
// Please visit www.count.ly for more information.

#import <Foundation/Foundation.h>

extern NSString * const CountlyAttributesAPIKey;
extern NSString * const CountlyAttributesHost;
extern NSString * const CountlyAttributesSessionDurationTrackingEnabled; // optional, default is YES
extern NSString * const CountlyAttributesEventsSendingViaWWANEnabled; // optional, default is YES
extern NSString * const CountlyAttributesSessionDurationUpdateInterval; // optional, default is 30 sec (should be under 60 to match server session timeout logic)

extern NSString * const CountlyUserDefaultsUUID;

@interface Countly : NSObject

+ (instancetype)sharedInstance;

- (void)startWithAttributes:(NSDictionary *)attributes;

- (void)recordEvent:(NSString *)key count:(NSUInteger)count;
- (void)recordEvent:(NSString *)key count:(NSUInteger)count sum:(CGFloat)sum;
- (void)recordEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(NSUInteger)count;
- (void)recordEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(NSUInteger)count sum:(CGFloat)sum;

/** Open or extend a user session.
 
 Session will automatically end after CountlyAttributesSessionDurationUpdateInterval seconds
 */
- (void)openSession;

@end
