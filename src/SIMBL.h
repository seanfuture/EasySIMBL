/**
 * Copyright 2003-2009, Mike Solomon <mas63@cornell.edu>
 * SIMBL is released under the GNU General Public License v2.
 * http://www.opensource.org/licenses/gpl-2.0.php
 */
/**
 * Copyright 2012, Norio Nomura
 * EasySIMBL is released under the GNU General Public License v2.
 * http://www.opensource.org/licenses/gpl-2.0.php
 */

#import "SIMBLPlugin.h"

#define SIMBLApplicationSupportPath @"Application Support/SIMBL"
#define SIMBLPluginPath @"Plugins"
#define SIMBLScriptingAdditionsPath @"ScriptingAdditions"
#define SIMBLBundleBaseName @"EasySIMBL"
#define SIMBLBundleExtension @"osax"
#define SIMBLBundleName @"EasySIMBL.osax"
#define SIMBLHasBeenLoadedNotification @"SIMBLHasBeenLoadedNotification"

#define SIMBLStringTable @"SIMBLStringTable"
#define SIMBLApplicationIdentifier @"SIMBLApplicationIdentifier"
#define SIMBLTargetApplications @"SIMBLTargetApplications"
#define SIMBLBundleIdentifier @"BundleIdentifier"
#define SIMBLMinBundleVersion @"MinBundleVersion"
#define SIMBLMaxBundleVersion @"MaxBundleVersion"
#define SIMBLTargetApplicationPath @"TargetApplicationPath"
#define SIMBLRequiredFrameworks @"RequiredFrameworks"

#define SIMBLPrefKeyLogLevel @"SIMBLLogLevel"
#define SIMBLLogLevelDefault 2
#define SIMBLLogLevelNotice 2
#define SIMBLLogLevelInfo 1
#define SIMBLLogLevelDebug 0

@protocol SIMBLPlugin
+ (void) install;
@end

#define SIMBLLogDebug(format, ...) [SIMBL logMessage:[NSString stringWithFormat:format, ##__VA_ARGS__] atLevel:SIMBLLogLevelDebug]
#define SIMBLLogInfo(format, ...) [SIMBL logMessage:[NSString stringWithFormat:format, ##__VA_ARGS__] atLevel:SIMBLLogLevelInfo]
#define SIMBLLogNotice(format, ...) [SIMBL logMessage:[NSString stringWithFormat:format, ##__VA_ARGS__] atLevel:SIMBLLogLevelNotice]


@interface SIMBL : NSObject
{
}

+ (void) logMessage:(NSString*)message atLevel:(int)level;
+ (void) installPlugins;
+ (BOOL) shouldInstallPluginsIntoApplication:(NSBundle*)_appBundle;
+ (BOOL) loadBundleAtPath:(NSString*)_bundlePath;
+ (BOOL) shouldLoadBundleAtPath:(NSString*)_bundlePath;
+ (BOOL) shouldApplication:(NSBundle*)_appBundle loadBundleAtPath:(NSString*)_bundlePath;
+ (BOOL) shouldApplication:(NSBundle*)_appBundle loadBundle:(SIMBLPlugin*)_bundle withApplicationIdentifiers:(NSArray*)_applicationIdentifiers;
+ (BOOL) shouldApplication:(NSBundle*)_appBundle loadBundle:(SIMBLPlugin*)_bundle withTargetApplications:(NSArray*)_targetApplications;
+ (BOOL) loadBundle:(SIMBLPlugin*)_bundle;

@end
