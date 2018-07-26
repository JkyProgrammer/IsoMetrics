//
//  IsoMetrics.cpp
//  IsoMetrics
//
//  Created by Javax on 18/07/2018.
//  Copyright © 2018 Javax Inc. All rights reserved.
//

#include "IsoMetrics.hpp"
#include <thread>

using namespace std;

// * MACH-O as Executable
// * Write bridging headers (various)

IsoMetrics::IsoMetrics () {
	thread looper (&IsoMetrics::update, *this);
}

void IsoMetrics::update () {
	if (needsUpdate()) {
		drawAll (this->objs);
	}
}

bool IsoMetrics::needsUpdate() {
	for (int n = 0; n < objs.size(); n++) {
		if (objs[n].needsUpdate()) {
			return true;
		}
	}
	return false;
}

void IsoMetrics::addPolygon(IMPolygon p) {
	objs.push_back(p);
}

IMPolygon* IsoMetrics::getPolygon(string name) {
	for (int n = 0; n < objs.size(); n++) {
		if (objs[n].name == name) {
			return &(objs[n]);
		}
	}
	return NULL;
}

bool IsoMetrics::removePolygon(string name) {
	for (int n = 0; n < objs.size(); n++) {
		if (objs[n].name == name) {
			objs.erase(objs.begin() + n);
			return true;
		}
	}
	return false;
}

void IsoMetrics::assignNewDrawCode(void (*newDrawCode)(vector<IMPolygon>)) {
	drawAll = newDrawCode;
}

int IsoMetrics::smallestDiff (int from, int values[]) {
	int smallestDiff = abs(double (from-values[0]));
	int smallest = 0;
	int i = 0;
	
	vector<int> vec (*values);
	
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
