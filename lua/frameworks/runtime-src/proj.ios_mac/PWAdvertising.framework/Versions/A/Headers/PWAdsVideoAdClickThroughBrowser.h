//
//  PWAdsVideoAdClickThroughBrowser.h
//  Video Ads SDK
//
//  Created by Kevin Truong on 4/30/13.
//
//  Declares the PWAdsVideoAdClickThroughBrowser interface that is used to display click-
//  through links in a browser in the app. It also defines a delegate protocol
//  for notifying the app that the browser has been shown or hidden.
//

#import <UIKit/UIKit.h>

@protocol PWAdsVideoAdClickThroughBrowserDelegate;

/**
 @Deprecated
 This class is used to display clickthrough links in the app.
 */
__deprecated_msg("PWAdsVideoAdClickThroughBrowser has been deprecated.")
@interface PWAdsVideoAdClickThroughBrowser : UIViewController<UIWebViewDelegate, UIActionSheetDelegate>

/**
 Enables displaying any click through in an in-app browser.
 By default, clicking/tapping the ad will cause the default iOS browser to be
 opened, switching away from the app. Call this method to enable a custom
 in-app browser that will be created in the |viewController| provided.
 If provided, the |delegate| can be used to track the opening and closing
 of the in-app browser.
 */
+ (void)enableInAppBrowserWithViewController:(UIViewController *)viewController
            delegate:(id<PWAdsVideoAdClickThroughBrowserDelegate>)delegate;

/**
 Disables displaying any click through in an in-app browser.
 */
+ (void)disableInAppBrowser;

@end


/**
 Protocol that will be used by IMAClickThroughBrowser to signal that it has
 been opened or closed.
 */
__deprecated_msg("PWAdsVideoAdClickThroughBrowserDelegate has been deprecated.")
@protocol PWAdsVideoAdClickThroughBrowserDelegate

@required
- (void)browserDidOpen;
- (void)browserDidClose;

@end
