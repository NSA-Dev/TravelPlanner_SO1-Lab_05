
#define _CRT_SECURE_NO_DEPRECATE	// Make MSVC shut up
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "distanceCopy.h"



struct geoCoord* createStructArray(int size);
int main(void)
{
	int waypoints_num;
	struct geoCoord* waypoints;


	// prompt the user for number of waypoints, check for input errors 
	printf("Enter a number of waypoints: ");


	while ((scanf("%d", &waypoints_num) != 1))
	{
		printf("Invalid input.Please, provide an integer number (>= 0): ");
		// clear the buffer
		while (getchar() != '\n');
	}

	// create an array of structures using the number of waypoints (use malloc)  
	waypoints = createStructArray(waypoints_num);

	//user enters coordinate pairs of WP 1-X
	printf("Enter waypoints as ""<latitude> <longtitude>"":\n");
	for (int i = 0; i < waypoints_num; i++)
	{
		printf("Waypoint %d: ", (i + 1));
		while ((scanf("%lf %lf", &waypoints[i].latitude, &waypoints[i].longtitude)) != 2) // Note to self: scanf returns the number of correct inputs, thus 2 in our condition
		{
			printf("Invalid input. Please, provide a coordinate pair\n");
			// clear the buffer
			while (getchar() != '\n');
		}
	}
	// call routeDistance to calculate the entire route, print the output
	printf("\nBy taking this route you will travel: %.1lf km\n", routeDistance(waypoints, waypoints_num));

	// free() memory
	free(waypoints);


	getchar();
	return 0;
}


//allocate memory for struct array
struct geoCoord* createStructArray(int size)
{
	struct geoCoord* arrayPointer = (struct geoCoord*)malloc(size * sizeof(struct geoCoord));

	if (arrayPointer == NULL)
	{
		printf("malloc() failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		return arrayPointer;
	}
}