//
//  IMHexagon.cpp
//  IsoMetrics
//
//  Created by Javax on 18/07/2018.
//  Copyright © 2018 Javax Inc. All rights reserved.
//

#include "IsoMetrics.hpp"

IMPolygon IMPresets::hexagon (IMPoint center, int radius) {
	return *new IMPolygon ({
		*new IMPoint(center.x + radius, center.y, center.z),
		*new IMPoint(center.x, center.y, center.z - radius),
		*new IMPoint(center.x, center.y + radius, center.z),
		*new IMPoint(center.x - radius, center.y, center.z),
		*new IMPoint(center.x, center.y, center.z + radius),
		*new IMPoint(center.x, center.y - radius, center.z)
	});
}

IMPolygon IMPresets::closedTube (IMPoint start, int radius, int pushOut, int segment) {
	if (pushOut != 0) {
		if (segment == Segment::pz) {
			return *new IMPolygon ({
				*new IMPoint(start.x, start.y + radius, start.z),
				*new IMPoint(start.x, start.y, start.z - radius),
				*new IMPoint(start.x + radius, start.y, start.z),
				
				*new IMPoint(start.x, start.y - radius, start.z + pushOut),
				*new IMPoint(start.x, start.y, start.z + radius + pushOut),
				*new IMPoint(start.x - radius, start.y, start.z + pushOut)
			});
		} else if (segment == Segment::nz) {
			return *new IMPolygon ({
				*new IMPoint(start.x, start.y - radius, start.z),
				*new IMPoint(start.x, start.y, start.z + radius),
				*new IMPoint(start.x - radius, start.y, start.z),
				
				*new IMPoint(start.x, start.y + radius, start.z - pushOut),
				*new IMPoint(start.x, start.y, start.z - radius - pushOut),
				*new IMPoint(start.x + radius, start.y, start.z - pushOut)
			});
		} else if (segment == Segment::px) {
			return *new IMPolygon ({
				*new IMPoint(start.x, start.y + radius, start.z),
				*new IMPoint(start.x - radius, start.y, start.z),
				*new IMPoint(start.x, start.y, start.z + radius),
				
				*new IMPoint(start.x + pushOut, start.y - radius, start.z),
				*new IMPoint(start.x + radius + pushOut, start.y, start.z),
				*new IMPoint(start.x + pushOut, start.y, start.z - radius)
			});
		}
		// NEEDS FINISHING.
	} else {
		return hexagon(start, radius);
	}
}

IMPolygon IMPresets::openTube (IMPoint start, int radius, int pushOut, int segment) {
	
}
