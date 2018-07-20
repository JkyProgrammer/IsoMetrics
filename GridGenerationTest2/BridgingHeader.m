//
//  BridgingHeader.h
//  IsoMetrics
//
//  Created by Javax on 20/07/2018.
//  Copyright © 2018 Javax Inc. All rights reserved.
//

#ifndef BridgingHeader_h
#define BridgingHeader_h

#import <Foundation/Foundation.h>
#import "IsoMetrics.hpp"

@interface IsoMetrics_bridge : NSObject

-(void) addPolygon:(IMPolygon)p;

@end

#endif /* BridgingHeader_h */
