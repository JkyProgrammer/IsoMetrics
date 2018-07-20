//
//  Utilities.cpp
//  IsoMetrics
//
//  Created by Javax on 19/07/2018.
//  Copyright © 2018 Javax Inc. All rights reserved.
//

#include "IsoMetrics.hpp"

#ifndef Utilities_cpp
#define Utilities_cpp

static int smallestDiff (int from, int values[]) {
    int smallestDiff = abs(double (from-values[0]));
    int smallest = 0;
    int i = 0;
	
    std::vector<int> vec (*values);
    
    for (int n : vec) {
        int currentDiff = abs (double (from-n));
        if (currentDiff < smallestDiff) {
            smallestDiff = currentDiff;
            smallest = i;
        }
        i += 1;
    }
    return values[smallest];
};


static float xRatio = 0.866;
static float yRatio = 0.5000439981;



static std::tuple<float, float> convertToSquareGrid (IMPoint p) {
	float dx = 0.000;
	float dy = 0.000;
	
	
	int vals[] = {p.x, p.y, p.z};
	int smallest = smallestDiff(0, vals);
	
	
	float fx = float (p.x - smallest);
	float fy = float (p.y - smallest);
	float fz = float (p.z - smallest);
	
	// Apply z
	dy += fz;
	
	// Apply x
	dx += fx * xRatio;
	dy -= fx * yRatio;
	
	// Apply y
	dx -= fy * xRatio;
	dy -= fy * yRatio;
	
	return std::make_tuple (dx, dy);
}
#endif
