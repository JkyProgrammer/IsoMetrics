//
//  IMHexagon.cpp
//  IsoMetrics
//
//  Created by Javax on 18/07/2018.
//  Copyright © 2018 Javax Inc. All rights reserved.
//

#include "IsoMetrics.hpp"

IMHexagon::IMHexagon (IMPoint centre, int radius) {
    points = {
        *new IMPoint(centre.x + radius, centre.y, centre.z),
        *new IMPoint(centre.x, centre.y, centre.z - radius),
        *new IMPoint(centre.x, centre.y + radius, centre.z),
        *new IMPoint(centre.x - radius, centre.y, centre.z),
        *new IMPoint(centre.x, centre.y, centre.z + radius),
        *new IMPoint(centre.x, centre.y - radius, centre.z)
    };
}
