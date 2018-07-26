//
//  IsoMetrics.hpp
//  IsoMetrics
//
//  Created by Javax on 18/07/2018.
//  Copyright © 2018 Javax Inc. All rights reserved.
//

#ifndef IsoMetrics_hpp
#define IsoMetrics_hpp

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
//#include <tuple>


using namespace std;

/**
 Defines the possible axes an IMPoint can be located along, doubled to give a positive and negative sub-axis for each.
 */
struct Segment {
	static const int px = 2;
	static const int nx = 5;
	static const int py = 4;
	static const int ny = 1;
	static const int pz = 0;
	static const int nz = 3;
};

/**
 Manages the values on the three navigational axes.
 
 @author Jake Costen
 
 @version v1.0
 */
class IMPoint {
public:
	/**
	 Determines if the object has unrendered changes. Should only be used internally, not client side.
	 */
	bool hasUnrenderedChanges;
	
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
	
	/**
	 Determine if two IMPoints are equal in virtual location.
	 
	 @param other The IMPoint with which to compare.
	 
	 @return true if the two IMPoints are equal, and false otherwise.
	 */
	bool equals (IMPoint other);
	
	/**
	 Check if the object needs its graphics updating.
	 
	 @return true if the object needs a graphics refresh, otherwise false.
	 */
	bool needsUpdate ();
	
	/**
	 Generates a two-axis 2D coordinate tuple for drawing the point in square-based grid systems.
	 
	 @return A tuple of 'float, float', containing the 'x, y' square grid coordinates (respectively).
	 */
	tuple<float, float> squareGridCoordinates ();
};


/**
 Manages a set of IMPoints, which make up a closed loop linked path.
 
 @author Jake Costen
 
 @version v1.0
 */
class IMPolygon {
private:
	/**
	 Stores the vector of IMPoints. Can be accessed by clients, allowing for use in drawing mechanisms.
	 */
	vector<IMPoint> points;

public:
	/**
	 Determines if the object has unrendered changes. Should only be used internally, not client side.
	 */
	bool hasUnrenderedChanges;
	
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
	 
	 @return a pointer to an IMPoint object if the IMPoint vector contains the specified IMPoint, otherwise NULL.
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
	
	/**
	 Check if the object needs its graphics updating.
	 
	 @return true if the object needs a graphics refresh, otherwise false.
	 */
	bool needsUpdate ();
};


/**
 Controller class for the IsoMetrics Scene.
 
 @author Jake Costen
 
 @version v1.0
 */
class IsoMetrics {
protected:
	/**
	 Stores the vector of IMPolygons.
	 */
	vector<IMPolygon> objs;

	/**
	 Function pointer variable to the a drawing function. Funtion reference should have single 'vector<IMPolygon>' argument. Called when a graphis refresh is needed.
	 @param v The vector of IMPolygons.
	 */
	void (*drawAll) (vector<IMPolygon> v);

public:
	/**
	 Check if the object needs its graphics updating.
	 
	 @return true if the object needs a graphics refresh, otherwise false.
	 */
	bool needsUpdate ();
	
	/**
	 Retrieve an IMPolygon from the IMPolygon vector based on name.
	 
	 @param name The name of the IMPolygon to be searched for.
	 
	 @return A pointer to the IMPolygon with the specified name, or NULL if it cannot be found.
	 */
	IMPolygon* getPolygon (string name);
	
	/**
	 Add an IMPolygon to the IMPolygon vector.
	 
	 @param p The IMPolygon to be added.
	 */
	void addPolygon (IMPolygon p);
	
	/**
	 Remove an IMPolygon from the IMPolygon vector based on name.
	 
	 @param name The name of the IMPolygon to be removed.
	 
	 @return true if the IMPolygon existed (and was successfully removed), otherwise false.
	 */
	bool removePolygon (string name);
	
	/**
	 Assign a new drawing code pointer, to be executed when the graphics representation needs updating for some reason.
	 
	 @param newDrawCode The function pointer to the new drawing code.
	 */
	void assignNewDrawCode (void (*newDrawCode) (vector<IMPolygon>));
	
	/**
	 Initialise a new IsoMetrics object.
	 */
	IsoMetrics ();
	
	/**
	 The graphics loop function, will make a call to the function pointer stored in drawAll if a graphics refresh is required.
	 */
	void update ();
	
	/**
	 Store the two ratios defining the directional ratios of hexagons on square grids.
	 */
	constexpr static const float xRatio = 0.866;
	constexpr static const float yRatio = 0.5000439981;
	
	/**
	 Get the value from an array with the smallest difference between it and the specified value.
	 
	 @param from The integer to compare items with.
	 @param values The set of integers to compare against the specified integer.
	 
	 @return The integer from the array which is closest to the specified integer.
	 */
	static int smallestDiff (int from, int values[]);
};

class IMPresets {
public:
	
	/**
	 Generate an IMPolygon in the shape of a hexagon.
	 
	 @param center The center point of the hexagon.
	 @param radius The radius of the hexagon.
	 
	 @return An IMPolygon intialised with a vector of IMPoints.
	 */
	static IMPolygon hexagon (IMPoint center, int radius);
	
	/**
	 Generate an IMPolygon in the shape of a tube with closed ends.
	 
	 @param start The starting point of the tube
	 @param radius The radius of the tube, with ends being curved in the shape of a hemi-hexagon.
	 @param pushOut The distance the secondary (non-starting) end should be pushed out along the specified axis, with 0 returning a simple hexagon.
	 @param segment The hexagon segment axis along which to push the secondary end.
	 
	 @return An IMPolygon intialised with a vector of IMPoints.
	 */
	static IMPolygon closedTube (IMPoint start, int radius, int pushOut, int segment);
};

#endif /* IsoMetrics_hpp */
