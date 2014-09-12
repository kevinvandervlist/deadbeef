/*
    DeaDBeeF -- the music player
    Copyright (C) 2009-2014 Alexey Yakovenko and other contributors

    This software is provided 'as-is', without any express or implied
    warranty.  In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.
*/

#import <Cocoa/Cocoa.h>
#import "widgets/DdbTabStrip.h"
#include "deadbeef.h"

#define MAX_COLUMNS 20

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property id tfRedrawTimer;
@property int tf_redraw_track_idx;
@property DB_playItem_t *tf_redraw_track;

+ (int)ddb_message:(int)_id ctx:(uint64_t)ctx p1:(uint32_t)p1 p2:(uint32_t)p2;

@property (assign) IBOutlet NSWindow *window;
@property (unsafe_unretained) IBOutlet NSTableView *playlist;
@property (unsafe_unretained) IBOutlet DdbTabStrip *tabStrip;


@property (unsafe_unretained) IBOutlet NSWindow *addFilesWindow;
@property (unsafe_unretained) IBOutlet NSTextField *addFilesLabel;
- (IBAction)addFilesCancel:(id)sender;
@property (unsafe_unretained) IBOutlet NSTextField *statusBar;


// file menu
- (IBAction)openFilesAction:(id)sender;
- (IBAction)addFilesAction:(id)sender;
- (IBAction)addFoldersAction:(id)sender;

// edit menu
- (IBAction)clearAction:(id)sender;
- (IBAction)removeSelectionAction:(id)sender;

// playback menu
- (IBAction)previousAction:(id)sender;
- (IBAction)playAction:(id)sender;
- (IBAction)pauseAction:(id)sender;
- (IBAction)stopAction:(id)sender;
- (IBAction)nextAction:(id)sender;

@property (unsafe_unretained) IBOutlet NSMenuItem *orderLinear;
@property (unsafe_unretained) IBOutlet NSMenuItem *orderRandom;
@property (unsafe_unretained) IBOutlet NSMenuItem *orderShuffle;
@property (unsafe_unretained) IBOutlet NSMenuItem *orderShuffleAlbums;
- (IBAction)orderLinearAction:(id)sender;
- (IBAction)orderRandomAction:(id)sender;
- (IBAction)orderShuffleAction:(id)sender;
- (IBAction)orderShuffleAlbumsAction:(id)sender;

@property (unsafe_unretained) IBOutlet NSMenuItem *loopNone;
@property (unsafe_unretained) IBOutlet NSMenuItem *loopAll;
@property (unsafe_unretained) IBOutlet NSMenuItem *loopSingle;
- (IBAction)loopNoneAction:(id)sender;
- (IBAction)loopAllAction:(id)sender;
- (IBAction)loopSingleAction:(id)sender;

@property (unsafe_unretained) IBOutlet NSSlider *seekBar;
- (IBAction)seekBarAction:(id)sender;

@property (unsafe_unretained) IBOutlet NSMenuItem *cursorFollowsPlayback;
- (IBAction)cursorFollowsPlaybackAction:(id)sender;

@property (unsafe_unretained) IBOutlet NSMenuItem *scrollFollowsPlayback;
- (IBAction)scrollFollowsPlaybackAction:(id)sender;

@property (unsafe_unretained) IBOutlet NSMenuItem *stopAfterCurrent;
- (IBAction)stopAfterCurrentAction:(id)sender;

@property (unsafe_unretained) IBOutlet NSMenuItem *stopAfterCurrentAlbum;
- (IBAction)stopAfterCurrentAlbumAction:(id)sender;

- (IBAction)deselectAllAction:(id)sender;
- (IBAction)invertSelectionAction:(id)sender;
- (IBAction)selectionCropAction:(id)sender;
- (IBAction)jumpToCurrentAction:(id)sender;

// window menu
- (IBAction)showMainWinAction:(id)sender;


@end