//
//  ZBSettings.h
//  Zebra
//
//  Created by Thatchapon Unprasert on 31/8/19.
//  Copyright © 2019 Wilson Styres. All rights reserved.
//

@class ZBSource;
@class ZBPackage;
@class ZBPackageFilter;
@class ZBSourceFilter;

#import <Foundation/Foundation.h>

#pragma mark - Settings Keys

//Old settings keys
#define oledModeKey @"oledMode"
#define tintSelectionKey @"tintSelection"
#define thirteenModeKey @"thirteenMode"
#define randomFeaturedKey @"randomFeatured"
#define wantsFeaturedKey @"wantsFeatured"
#define wantsNewsKey @"wantsNews"
#define liveSearchKey @"liveSearch"
#define iconActionKey @"packageIconAction"
#define wishListKey @"wishList"
#define darkModeKey @"darkMode"
#define finishAutomaticallyKey @"finishAutomatically"
#define featuredBlacklistKey @"blackListedRepos"

#pragma mark - Interface Styles

#pragma mark - Featured Type

typedef enum : NSUInteger {
    ZBFeaturedTypeSource,
    ZBFeaturedTypeRandom,
} ZBFeaturedType;

#pragma mark - Swipe Action Style

typedef enum : NSUInteger {
    ZBSwipeActionStyleText,
    ZBSwipeActionStyleIcon,
} ZBSwipeActionStyle;

#pragma mark - Package Sorting Style

typedef enum : NSUInteger {
    ZBSortingTypeABC,
    ZBSortingTypeDate,
    ZBSortingTypeInstalledSize
} ZBSortingType;

NS_ASSUME_NONNULL_BEGIN

@interface ZBSettings : NSObject

#pragma mark - Theming

+ (BOOL)pureBlackMode;
+ (void)setPureBlackMode:(BOOL)pureBlackMode;

+ (NSString *_Nullable)appIconName;
+ (void)setAppIconName:(NSString *_Nullable)appIconName;

#pragma mark - Filters

+ (NSArray *)filteredSections;
+ (void)setFilteredSections:(NSArray *)filteredSources;
+ (NSDictionary *)filteredSources;
+ (void)setFilteredSources:(NSDictionary *)filteredSources;

+ (BOOL)isSectionFiltered:(NSString *)section forSource:(ZBSource *)source;
+ (void)setSection:(NSString *)section filtered:(BOOL)filtered forSource:(ZBSource *)source;

+ (NSDictionary *)blockedAuthors;
+ (void)setBlockedAuthors:(NSDictionary *)blockedAuthors;
+ (BOOL)isAuthorBlocked:(NSString *)name email:(NSString *)name;

+ (BOOL)isPackageFiltered:(ZBPackage *)package;

+ (ZBPackageFilter *)filterForSource:(ZBSource *)source section:(NSString *)section;
+ (void)setFilter:(ZBPackageFilter *)filter forSource:(ZBSource *)source section:(NSString *)section;

+ (ZBSourceFilter *)sourceFilter;
+ (void)setSourceFilter:(ZBSourceFilter *)filter;

#pragma mark - Homepage settings

+ (BOOL)wantsFeaturedPackages;
+ (void)setWantsFeaturedPackages:(BOOL)wantsFeaturedPackages;

+ (ZBFeaturedType)featuredPackagesType;
+ (void)setFeaturedPackagesType:(NSNumber *)featuredPackagesType;

+ (NSArray *)sourceBlacklist;
+ (void)setSourceBlacklist:(NSArray *)blacklist;

#pragma mark - Sources Settings

+ (BOOL)wantsAutoRefresh;
+ (void)setWantsAutoRefresh:(BOOL)autoRefresh;

+ (NSInteger)sourceRefreshTimeoutIndex;
+ (NSTimeInterval)sourceRefreshTimeout;
+ (void)setSourceRefreshTimeout:(NSNumber *)time;

+ (BOOL)wantsInstalledPackagesCount;
+ (void)setWantsInstalledPackagesCount:(BOOL)wantsInstalledPackagesCount;

#pragma mark - Changes Settings

+ (BOOL)wantsCommunityNews;
+ (void)setWantsCommunityNews:(BOOL)wantsCommunityNews;

#pragma mark - Packages Settings

+ (BOOL)alwaysInstallLatest;
+ (void)setAlwaysInstallLatest:(BOOL)alwaysInstallLatest;

+ (uint8_t)role;
+ (void)setRole:(NSNumber *)role;

+ (NSArray *)ignoredUpdates;
+ (BOOL)areUpdatesIgnoredForPackageIdentifier:(NSString *)identifier;
+ (void)setUpdatesIgnored:(BOOL)updatesIgnored forPackageIdentifier:(NSString *)identifier;

//#pragma mark - Search Settings
//
//+ (BOOL)wantsLiveSearch;
//+ (void)setWantsLiveSearch:(BOOL)liveSearch;

#pragma mark - Console Settings

+ (BOOL)wantsFinishAutomatically;
+ (void)setWantsFinishAutomatically:(BOOL)finishAutomatically;

#pragma mark - Swipe Action Settings

+ (ZBSwipeActionStyle)swipeActionStyle;
+ (void)setSwipeActionStyle:(NSNumber *)style;

#pragma mark - Favorites

+ (NSArray *)favoritePackages;
+ (void)setFavoritePackages:(NSArray *)favorites;

#pragma mark - Package Sorting Type

+ (ZBSortingType)packageSortingType;
+ (void)setPackageSortingType:(ZBSortingType)sortingType;

#pragma mark - Crash Reporting

+ (BOOL)allowsCrashReporting;
+ (void)setAllowsCrashReporting:(BOOL)crashReporting;

#pragma mark - Source Update

+ (NSDate *)lastSourceUpdate;
+ (void)updateLastSourceUpdate;

@end

NS_ASSUME_NONNULL_END