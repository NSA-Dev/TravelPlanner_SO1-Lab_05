#define _USE_MATH_DEFINES
#include "distance.h"
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
double routeDistance(const double* lat, const double* lon, int count)
{
	double result = 0;

	for (int i = 0; i < (count - 1); i++)
	{

		result += distanceKm(rad(*(lon + i)), rad(*(lat + i)), rad(*(lon + i + 1)), rad(*(lat + i + 1)));
		
	}

	return result;
}