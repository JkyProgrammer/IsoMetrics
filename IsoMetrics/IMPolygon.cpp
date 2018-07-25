//
//  IMPolygon.cpp
//  IsoMetrics
//
//  Created by Javax on 19/07/2018.
//  Copyright © 2018 Javax Inc. All rights reserved.
//

#include "IsoMetrics.hpp"

IMPolygon::IMPolygon () {
	
}

IMPolygon::IMPolygon (string nm) {
	name = nm;
}

IMPolygon::IMPolygon (vector<IMPoint> pts, string nm) {
	name = nm;
	points = pts;
}

IMPolygon::IMPolygon (std::vector<IMPoint> pts) {
    points = pts;
}

void IMPolygon::addPoint(IMPoint p) {
	points.push_back(p);
}

bool IMPolygon::removePointIfExists(IMPoint p) {
	for (int n = 0; n < points.size(); n++) {
		if (points[n].equals(p)) {
			points.erase (points.begin() + n);
			return true;
		}
	}
	return false;
}

IMPoint* IMPolygon::pointerToPoint(IMPoint p) {
	for (int n = 0; n < points.size(); n++) {
		if (points[n].equals(p)) {
			return &(points[n]);
		}
	}
	return NULL;
}

void IMPolygon::translate(IMPoint d) {
	for (int n = 0; n < points.size(); n++)
		points[n].translate(d);
}

void IMPolygon::rotate(int d, IMPoint p) {
	for (int n = 0; n < points.size(); n++)
		points[n].rotate(d, p);
}
