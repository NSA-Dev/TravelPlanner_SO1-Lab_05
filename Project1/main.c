
#define _CRT_SECURE_NO_DEPRECATE	// Make MSVC shut up
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "distance.h"



double* createArray(int size); 
int main(void) 
{
	int waypoints_num;
	double *latitudes, *longtitudes;
	

	// prompt the user for number of waypoints, check for input errors 
	printf("Enter a number of waypoints: ");
	
	
	while((scanf("%d", &waypoints_num) != 1)) 
	{
		printf("Invalid input.Please, provide an integer number (>= 0): ");
		// clear the buffer
		while (getchar() != '\n'); 
	}

	// create an array of structures using the number of waypoints (use malloc)  
	latitudes = createArray(waypoints_num);
	longtitudes = createArray(waypoints_num);

	//user enters coordinate pairs of WP 1-X
	printf("Enter waypoints as ""<latitude> <longtitude>"":\n");
	for(int i = 0; i < waypoints_num; i++) 
	{
		printf("Waypoint %d: ", (i+1));
		while((scanf("%lf %lf", &latitudes[i], &longtitudes[i])) != 2) // Note to self: scanf returns the number of correct inputs, thus 2 in our condition
		{
			printf("Invalid input. Please, provide a coordinate pair\n");
			// clear the buffer
			while (getchar() != '\n');
		}
	}
	// call routeDistance to calculate the entire route, print the output
	printf("\nBy taking this route you will travel: %.1lf km\n", routeDistance(latitudes, longtitudes, waypoints_num)); 
	 
	// free() memory
	free(latitudes);
	free(longtitudes);
	

	getchar();
	return 0; 
} 


//allocate memory for an array
double* createArray(int size)
{
	double* arrayPointer = (double*)malloc(size * sizeof(double));

	 if(arrayPointer == NULL)
	 {
		 printf("malloc() failed\n");
		 exit(EXIT_FAILURE);
	 }
	 else
	 {
		 return arrayPointer; 
	 }
}