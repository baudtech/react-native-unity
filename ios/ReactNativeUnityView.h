#import <Foundation/Foundation.h>
#import <React/RCTView.h>
#import <React/RCTEventDispatcher.h>

#if __has_include(<UnityFramework/UnityFramework.h>) && __has_include(<UnityFramework/NativeCallProxy.h>)
#include <UnityFramework/UnityFramework.h>
#include <UnityFramework/NativeCallProxy.h>
@interface ReactNativeUnityView : RCTView <NativeCallsProtocol, UnityFrameworkListener>
#else
@interface ReactNativeUnityView : RCTView
#endif

@property (nonatomic, strong) UIView* _Nullable uView;

@property (nonatomic, copy) RCTBubblingEventBlock _Nullable onUnityMessage;
@property (nonatomic, copy) RCTBubblingEventBlock _Nullable onPlayerUnload;
@property (nonatomic, copy) RCTBubblingEventBlock _Nullable onPlayerQuit;

+ (void)UnityPostMessage:(NSString* _Nonnull )gameObject methodName:(NSString* _Nonnull)methodName message:(NSString* _Nonnull) message;
+ (void)unloadUnity;
+ (void)pauseUnity:(BOOL * _Nonnull)pause;

@end
