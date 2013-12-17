// (c) 2013 True Interactions
#ifndef NW_SRC_API_CONTROL_CONTROL_DELEGATE_MAC
#define NW_SRC_API_CONTROL_CONTROL_DELEGATE_MAC
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
namespace nwapi {
  class Control;
}
@interface ControlDelegateMac : NSObject <NSToolbarDelegate> {
@private
  NSObject *control_;
}
@property base::DictionaryValue *options;
@property nwapi::Control *native;
@property (retain) NSString *name;
@property (retain) NSString *type;
@property (retain) NSMutableArray *items;
- (id)initWithOptions:(const base::DictionaryValue&)option nativeObject:(nwapi::Control *)obj;
- (void)append:(nwapi::Control *)item;
- (void)insert:(nwapi::Control *)item atIndex:(int)pos;
- (void)removeAtIndex:(int)pos;
/** NSToolbar Delegate **/
- (NSArray *)toolbarDefaultItemIdentifiers:(NSToolbar *)toolbar;
- (NSToolbarItem *)toolbar:(NSToolbar *)toolbar itemForItemIdentifier:(NSString *)itemIdentifier willBeInsertedIntoToolbar:(BOOL)flag;
- (NSArray *)toolbarAllowedItemIdentifiers:(NSToolbar *)toolbar;
- (void)toolbarDidRemoveItem:(NSNotification *)notification;
- (void)toolbarWillAddItem:(NSNotification *)notification;
- (void)processOptions:(const base::DictionaryValue&)option;
- (NSObject *)getBackObj;
/** Events & Responder **/
- (BOOL)acceptsFirstResponder;
- (void)mouseDown:(NSEvent *)theEvent;
- (void)mouseUp:(NSEvent *)theEvent;
- (void)mouseMoved:(NSEvent *)theEvent;
- (void)mouseEntered:(NSEvent *)theEvent;
- (void)mouseExited:(NSEvent *)theEvent;
- (void)keyDown:(NSEvent *)theEvent;
- (void)keyUp:(NSEvent *)theEvent;
@end
#endif
