# Solution for Lab 5: Memory management & structures

## Overview
This lab exercise was designed to teach how to: 
* Allocate and free dynamic memory as required
* Group data in structures

The program reads data from standard input (pairs of XY coordinates, presented in the table below), and calculates distance. The second part (17.2) utilizes structure for coordinate storage. 
Sample input/output:
```
Enter a number of waypoints: three
Invalid input.Please, provide an integer number (>= 0): 3
Enter waypoints as <latitude> <longtitude>:
Waypoint 1: 53.56 10.02
Waypoint 2: 48.86 2.29
Waypoint 3: 39.56 2.66

By taking this route you will travel: 1786.2 km
```

## Data table


|Location  | Latitude |  Longtitude |
| ------------- | -------------  | ------------- |
| HAW Hamburg   | 53.557078   | 10.023109  |
| Eiffel Tower  | 48.858363    | 2.294481  |
| Palma de Mallorca   | 39.562553   | 2.661947  |
| Las Vegas  | 36.156214   | -115.148736  |
| Copacabana    | -22.971177   | -43.182543  |
| Waikiki Beach  | 21.281004   | 157.837456  |
| Surfer’s Paradise   | -28.002695   | 153.431781  |
## Lab requirements
* Users shall enter the number of waypoints (i. e., place of departure and the destinations).
* Users shall enter the geographic coordinates of all waypoints
* After correct user input the program shall print the overall length of the route to the console.
* In case of invalid input, the application will repeat the request until users enter correct data.
* Dynamically allocate 1-D arrays to hold the latitudes and the longitudes of the waypoints.
* Make sure to free dynamically allocated memory before the application exits.
* (PART 2) Modify your program so that it uses the structure to store the coordinates of the waypoints.
The functionality implemented in the first assignment must not be changed
