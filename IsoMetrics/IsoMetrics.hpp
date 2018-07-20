//
//  IsoMetrics.hpp
//  IsoMetrics
//
//  Created by Javax on 18/07/2018.
//  Copyright © 2018 Javax Inc. All rights reserved.
//

// COMMENT UP //
// IMPLEMENT  //

#ifndef IsoMetrics_hpp
#define IsoMetrics_hpp

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <tuple>


using namespace std;

struct Segment {
	static int px;
	static int nx;
	static int py;
	static int ny;
	static int pz;
	static int nz;
};

/**
 Manages the values on the three navigational axes.
 
 @author Jake Costen
 
 @version v1.0
*/
class IMPoint {
public:
	
	/**
	 The absolute location of the point on the x axis.
	*/
	int x;
	
	/**
	 The absolute location of the point on the y axis.
	*/
	int y;
	
	/**
	 The absolute location of the point on the z axis.
	*/
	int z;
	
	/**
	 Create a new IMPoint object pointing to the specified location.
	 
	 @param xa The proposed x value for the new object.
	 @param ya The proposed y value for the new object.
	 @param za The proposed z value for the new object.
	*/
	IMPoint (int xa, int ya, int za);
	
	/**
	 Ensure that at least one of the axis values is 0.
	*/
	void normalise ();
	
	/**
	 Move the object by delta values stored in the xyz values of another IMPoint object.
	 
	 @param p The delta xyz value set to translate by.
	*/
	void translate (IMPoint p);
	
	/**
	 Rotate the object around it's own center. Irrelevant to a single point.
	 
	 @param d The number of degree segments to rotate the object by.
	*/
	void rotate (int d);
	
	/**
	 Rotate the object around a point other than its own center.
	 
	 @param d The number of degree segments to rotate the object by.
	 @param p The point to rotate the object around.
	*/
	void rotate (int d, IMPoint p);
};

class IMPolygon {
public:
	vector<IMPoint> points;
	string name;
	
	IMPolygon (vector<IMPoint>);
	
	IMPolygon ();
	
	void translate (IMPoint);
	
	void rotate (int);
	void rotate (int, IMPoint);
};

class IMHexagon : public IMPolygon {
public:
	IMHexagon (IMPoint, int);
};

class IsoMetrics {
public:
	
    vector<IMPolygon> objs;
	
	void (*draw) (void);
	
    void start ();
    void drawAll ();
	
	void getPolygon (string);
	
	void addPolygon (IMPolygon);
	void removePolygon (IMPolygon);
	
	void assignNewDrawCode (void (*newDrawCode) (void));
	
	IsoMetrics ();
};

#include "Utilities.cpp"

#endif /* IsoMetrics_hpp */
