/*#define _USE_MATH_DEFINES*/			// use math.h constants M_PI 
#define D_EQUATOR 111.3				// distance at the equator
#define R_EARTH 6378.388			// Earth's radius

// declare structure
struct geoCoord
{
	double latitude;
	double longtitude;
};

//function prototypes
double rad(double value);
double distanceKm(double lo_1, double la_1, double lo_2, double la_2);
double routeDistance(struct geoCoord* waypoints, int count);