//
//  PWAdsModule.h
//  PWAdvertising
//
//  Created by Ricardo Guillen on 11/23/16.
//  Copyright © 2016 Phunware, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const PWAdsHTTPSPrefix;
extern NSString * const PWAdsHTTPPrefix;

typedef NS_ENUM(NSInteger, PWAdsServerEnvironment) {
    PWAdsServerEnvironmentDevelopment = 1,
    PWAdsServerEnvironmentStaging = 2,
    PWAdsServerEnvironmentProduction = 3
};

@interface PWAdsModule : NSObject

@property (nonatomic) PWAdsServerEnvironment pwAdsServerEnvironment;
@property (nonatomic, strong) NSString *pwAdsServerHomeDirectory;
@property (nonatomic) BOOL pwAdsEnableSSL;

+ (id)sharedManager;

@end
