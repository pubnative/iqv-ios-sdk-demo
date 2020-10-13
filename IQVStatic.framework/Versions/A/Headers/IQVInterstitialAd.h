//
//  Copyright © 2018 PubNative. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import "IQVAd.h"
#import "IQVSignalDataProcessor.h"

@protocol IQVInterstitialAdDelegate<NSObject>

- (void)interstitialDidLoad;
- (void)interstitialDidFailWithError:(NSError *)error;
- (void)interstitialDidTrackImpression;
- (void)interstitialDidTrackClick;
- (void)interstitialDidDismiss;

@end

@interface IQVInterstitialAd : NSObject <IQVSignalDataProcessorDelegate>

@property (nonatomic, strong) IQVAd *ad;
@property (nonatomic, assign) BOOL isReady;
@property (nonatomic, assign) BOOL isMediation;

- (instancetype)initWithZoneID:(NSString *)zoneID andWithDelegate:(NSObject<IQVInterstitialAdDelegate> *)delegate;
- (instancetype)initWithDelegate:(NSObject<IQVInterstitialAdDelegate> *)delegate;
- (void)load;
- (void)prepareAdWithContent:(NSString *)adContent;

/// Presents the interstitial ad modally from the current view controller.
///
/// This method will do nothing if the interstitial ad has not been loaded (i.e. the value of its `isReady` property is NO).
- (void)show;

/**
* Presents the interstitial ad modally from the specified view controller.
*
* This method will do nothing if the interstitial ad has not been loaded (i.e. the value of its
* `isReady` property is NO).
*
* @param viewController The view controller that should be used to present the interstitial ad.
*/
- (void)showFromViewController:(UIViewController *)viewController;
- (void)hide;

- (void)setSkipOffset:(NSInteger)seconds;

@end
