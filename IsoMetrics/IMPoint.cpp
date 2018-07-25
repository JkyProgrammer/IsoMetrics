//
//  IMPoint.cpp
//  IsoMetrics
//
//  Created by Javax on 18/07/2018.
//  Copyright © 2018 Javax Inc. All rights reserved.
//

//#include "IsoMetrics.hpp"
#include "IsoMetrics.hpp"

IMPoint::IMPoint (int xa, int ya, int za) {
    this->x = xa;
    this->y = ya;
    this->z = za;
}
    
void IMPoint::normalise () {
	int vals[] = {this->x, this->y, this->z};
	int smallest = smallestDiff(0, vals);
	
	
	float fx = float (this->x - smallest);
	float fy = float (this->y - smallest);
	float fz = float (this->z - smallest);
	this->x = fx;
	this->y = fy;
	this->z = fz;
}

void IMPoint::translate(IMPoint p) {
	this->x += p.x;
	this->y += p.y;
	this->z += p.z;
}

void IMPoint::rotate (int d, IMPoint p) {
	IMPoint dif = *new IMPoint (this->x - p.x, this->y - p.y, this->z - p.z);
	int pz = dif.z;
	int nx = 0;
	int py = dif.y;
	int nz = 0;
	int px = dif.x;
	int ny = 0;
	
	
	for (int i = 0; i < d; i++) {
		int tmp = pz;
		pz = ny;
		ny = px;
		px = nz;
		nz = py;
		py = nx;
		nx = tmp;
	}
	
	this->x = px-nx;
	this->y = py-ny;
	this->z = pz-nz;
}

bool IMPoint::equals(IMPoint other) {
	if ((this->x == other.x) && (this->y == other.y) && (this->z == other.z)) {
		return true;
	}
	return false;
}
