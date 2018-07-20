//
//  Use this file to import your target's public headers that you would like to expose to Swift.
//
#import <Foundation/Foundation.h>
#import <libIsoMetrics.dylib>

@interface IMPolygon_bridge : NSObject

@end

@interface IsoMetrics_bridge : NSObject

-(IsoMetrics_bridge) IsoMetrics_bridge : NSObject
-(void) addPolygon:(IMPolygon_bridge*)p;

@end
