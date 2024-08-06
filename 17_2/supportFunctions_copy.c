#define _USE_MATH_DEFINES
#include "distanceCopy.h"
#include <math.h>



double rad(double value)  // convert degrees to radians
{
	return (value * (M_PI / 180.0));

}

// Note format: (longtitude, latitude)
double distanceKm(double lo_1, double la_1, double lo_2, double la_2)
{	// variable declaration
	double sineLat, cosLat, cosLon, distance;

	// preliminary calculations (see formula)
	sineLat = sin(la_1) * sin(la_2);
	cosLat = cos(la_1) * cos(la_2);
	cosLon = cos((lo_2 - lo_1));
	// global distance calculation
	distance = R_EARTH * acos(sineLat + cosLat * cosLon);
	// return result to the caller
	return distance;

}

// Calculate entire route using arrays 
double routeDistance(struct geoCoord* waypoints, int count)
{
	double result = 0;

	for (int i = 0; i < (count - 1); i++)
	{

		result += distanceKm(rad(waypoints[i].longtitude), rad(waypoints[i].latitude), rad(waypoints[i + 1].longtitude), rad(waypoints[i + 1].latitude));

	}

	return result;
}