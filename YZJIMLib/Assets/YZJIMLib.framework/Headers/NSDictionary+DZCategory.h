//
//  NSDictionary+DZCategory.h
//
//
//  Created by Darren on 15/6/16.
//
//

#import <Foundation/Foundation.h>
#import "KDComm.h"

@interface NSDictionary (DZCategory)
- (NSString *)kd_dz_stringForKey:(NSString *)strKey;
- (NSArray *)kd_dz_arrayForKey:(NSString *)strKey;
- (NSDictionary *)kd_dz_dictForKey:(NSString *)strKey;

- (NSMutableArray *)kd_dz_modelsForArrayKey:(NSString *)strKey
                          modelClassName:(NSString *)model
                                  except:(NSArray *)except
                                   block:(void (^)(NSDictionary *dictInner, id model))block;

- (id)kd_dz_modelForDictKey:(NSString *)strKey
          modelClassName:(NSString *)model
           modelInstance:(id)modelIns
                  except:(NSArray *)except
                   block:(void (^)(NSDictionary *dictInner, id model))block;

- (NSString*)kd_urlEncodedString;


- (BOOL)boolForKey:(NSString *)key;
    
- (int)intForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
    
- (KDInt64)int64ForKey:(NSString *)key;
- (KDUInt64)uint64ForKey:(NSString *)key;
    
- (float)floatForKey:(NSString *)key;
- (double)doubleForKey:(NSString *)key;
    
- (NSString *)stringForKey:(NSString *)key;
    
    //- (NSDate *)ASCDatetimeForKey:(NSString *)key;
    //- (NSDate *)ASCDatetimeWithMillionSecondsForKey:(NSString *)key;
    
- (id)objectNotNSNullForKey:(NSString *)key;
    
    ////////////////////////////////////////////////////////////////////////////////
    
- (BOOL)boolForKey:(NSString *)key defaultValue:(BOOL)value;
    
- (int)intForKey:(NSString *)key defaultValue:(int)value;
- (NSInteger)integerForKey:(NSString *)key defaultValue:(NSInteger)value;
    
- (KDInt64)int64ForKey:(NSString *)key defaultValue:(KDInt64)value;
- (KDUInt64)uint64ForKey:(NSString *)key defaultValue:(KDUInt64)value;
    
- (float)floatForKey:(NSString *)key defaultValue:(float)value;
- (double)doubleForKey:(NSString *)key defaultValue:(double)value;
    
- (NSString *)stringForKey:(NSString *)key defaultValue:(NSString *)value;

@end
