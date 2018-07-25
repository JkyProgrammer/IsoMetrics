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

/**
 Defines the possible axes an IMPoint can be located along, doubled to give a positive and negative sub-axis for each.
 */
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
	 The absolute location of the IMPoint on the x axis.
	 */
	int x;
	
	/**
	 The absolute location of the IMPoint on the y axis.
	 */
	int y;
	
	/**
	 The absolute location of the IMPoint on the z axis.
	 */
	int z;
	
	/**
	 Create a new IMPoint object at the specified location.
	 
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
	 Rotate the object around an IMPoint other than its own center.
	 
	 @param d The degree of rotation to apply (in the form of the number of segments to rotate through).
	 @param p The IMPoint to rotate the object around.
	 */
	void rotate (int d, IMPoint p);
};

/**
 Manages a set of IMPoints, which make up a closed loop linked path.
 
 @author Jake Costen
 
 @version v1.0
 */
class IMPolygon {
	/**
	 Stores the vector of IMPoints. Can be accessed by clients, allowing for use in drawing mechanisms.
	 */
protected:
	vector<IMPoint> points;

public:
	/**
	 A recognisable identifier, enabling the object to be retrieved later from the IsoMetrics' IMPolygon vector.
	 */
	string name;
	
	/**
	 Initialises an IMPolygon with the given set of IMPoints.
	 
	 @param pts The starting set of IMPoints for the IMPolygon to be intialised around.
	 */
	IMPolygon (vector<IMPoint> pts);
	
	/**
	 Initialises an empty IMPolygon with a name.
	 
	 @param nm The name for the IMPolygon.
	 */
	IMPolygon (string nm);
	
	/**
	 Initialises an IMPolygon with the given set of IMPoints, and a name.
	 
	 @param pts The starting set of IMPoints for the IMPolygon to be intialised around.
	 @param nm The name for the IMPolygon.
	 */
	IMPolygon (vector<IMPoint> pts, string nm);
	
	/**
	 Initialises a blank IMPolygon.
	 */
	IMPolygon ();
	
	/**
	 Adds a new IMPoint to the IMPoint vector.
	 
	 @param p The IMPoint to added.
	 */
	void addPoint (IMPoint p);
	
	/**
	 Attempts to remove the specified IMPoint from the IMPoint vector.
	 
	 @param p The IMPoint to removed.
	 
	 @return true if the IMPoint exists in the IMPoint vector (and was consequently moved), otherwise returns false.
	 */
	bool removePointIfExists (IMPoint p);
	
	/**
	 Returns a pointer to the first IMPoint in the IMPoint vector who's position is equal to the IMPoint specified. This allows rotation and translation operations to be performed.
	 
	 @param p The IMPoint to be searched for in the IMPoint vector.
	 
	 @return a pointer to an IMPoint object if the IMPoint vector contains the specified IMPoint, otherwise null.
	 */
	IMPoint* pointerToPoint (IMPoint p);
	
	/**
	 Translates the entire IMPolygon by the specified delta value set (contained in an IMPoint), by translating each individual IMPoint.
	 
	 @param d The delta value set, specified in the form of the three-axis IMPoint.
	 */
	void translate (IMPoint d);
	
	/**
	 Rotates the entire IMPolygon by the specified angle, around the specified IMPoint, by rotating each individual IMPoint.
	 
	 @param d The degree of rotation to apply (in the form of the number of segments to rotate through).
	 @param p The IMPoint around which to rotate the IMPolygon.
	 */
	void rotate (int d, IMPoint p);
};

class IsoMetrics {
private:
	vector<IMPolygon> objs;

public:
	void (*draw) (void);
	
	void start ();
	void drawAll ();
	
	void getPolygon (string);
	
	void addPolygon (IMPolygon);
	void removePolygon (IMPolygon);
	
	void assignNewDrawCode (void (*newDrawCode) (void));
	
	IsoMetrics ();
};

class IMHexagon : public IMPolygon {
public:
	IMHexagon (IMPoint, int);
};

#include "Utilities.cpp"

#endif /* IsoMetrics_hpp */
