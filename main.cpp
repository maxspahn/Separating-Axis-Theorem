#include <iostream>
#include <string>

#include "Intersect.h"

int main() {

  std::cout << "Starting SAT..." << std::endl;
  std::cout << std::endl;

  std::string polygonAlpha = "0 0,0 1,2 0,0 0";
  std::string polygonBravo = "1 0,1 1,3 0,1 0";
  std::string polygonCharlie = "2 2,2 3,4 2,2 2";
  std::string polygonDelta = "10 2,4 7,11 18,15 14,10 2";
  std::string polygonErnie = "-234 -100, -10,-4 2,-234 -100";
  std::string polygonFrank = "2 -2,2 -3,4 2,2 -2";

  std::cout << "Test Alpha vs. Bravo:" << std::endl;
  if (Intersect::overlap(polygonAlpha, polygonBravo)) {
    std::cout << "OK" << std::endl;
  }

  // Alpha and Charlie are not overlapping, so if our function says there exists an overlap
  // then this is clearly not OK
  std::cout << "Test Alpha vs. Charlie:" << std::endl;
  if (Intersect::overlap(polygonAlpha, polygonCharlie)) {
    std::cout << "NOK" << std::endl;
  }
  else { std::cout << "OK" << std::endl; }

  // Different shape of the Delta polygon
  std::cout << "Test Delta vs. Bravo:" << std::endl;
  if (Intersect::overlap(polygonDelta, polygonBravo)) {
	  std::cout << "NOK" << std::endl;
  }
  else { std::cout << "OK" << std::endl; }

  // Large negative values for the coordinates of the polygon
  std::cout << "Test Ernie vs. Alpha:" << std::endl;
  if (Intersect::overlap(polygonErnie, polygonAlpha)) {
	  std::cout << "NOK" << std::endl;
  }
  else { std::cout << "OK" << std::endl; }

  // Polygons touch in only one point
  std::cout << "Test Frank vs. Bravo:" << std::endl;
  if (Intersect::overlap(polygonFrank, polygonBravo)) {
	  std::cout << "OK" << std::endl;
  }

  std::cout << std::endl;
  std::cout << "Finished SAT." << std::endl;
  return 0;
}
