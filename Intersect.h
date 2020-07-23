#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

class Intersect {
public:
  static bool overlap(std::string polygonA, std::string polygonB);


private:
};


bool Intersect::overlap(std::string polygonA, std::string polygonB) {

  // your implementation goes here
	
	// definition of the struct "polygon" to store the data points
	struct polygon { std::vector<int> x; std::vector<int> y; } polygon1, polygon2;

	// // READ 1ST POLYGON from string to new data type
	std::string delimiter = ",";
	size_t pos = 0;
	std::string token;
	while ((pos = polygonA.find(delimiter)) != std::string::npos) {
		token = polygonA.substr(0, pos);
		polygon1.x.push_back((int)token[0] - 48);
		polygon1.y.push_back((int)token[2] - 48);
		polygonA.erase(0, pos + delimiter.length());
	}
	polygon1.x.push_back((int)polygonA[0] - 48);
	polygon1.y.push_back((int)polygonA[2] - 48);
	

	// READ 2ND POLYGNON from string to new data type
	size_t posB = 0;
	while ((posB = polygonB.find(delimiter)) != std::string::npos) {
		token = polygonB.substr(0, posB);
		polygon2.x.push_back((int)token[0] - 48);
		polygon2.y.push_back((int)token[2] - 48);
		polygonB.erase(0, posB + delimiter.length());
	}
	polygon2.x.push_back((int)polygonB[0] - 48);
	polygon2.y.push_back((int)polygonB[2] - 48);


	// // SEPARATING AXIS THEOREM:
	// "If we find an axis that separates the both polygons, then the polygons cannot overlap!" this works only for convex polygons!

	// Loop over the sides of first polygon
	for (int i = 0; i < polygon1.x.size()-1; i++)
	{
		// // construct normalized projection axis
		double axis[2]			= {};
		double perpendicular[2] = {};
		std::vector<double> projectionsA;
		std::vector<double> projectionsB;

		// compute axis of polygon sides
		axis[0] = (double)polygon1.x[i + 1] - (double)polygon1.x[i];
		axis[1] = (double)polygon1.y[i + 1] - (double)polygon1.y[i];

		// normalize vector
		double length_axis = sqrt(axis[0] * axis[0] + axis[1] * axis[1]);
		axis[0] = axis[0] / length_axis;
		axis[1] = axis[1] / length_axis;

		// find the perpendicular axis [x,y] = [-y,x]
		perpendicular[0] = -axis[1];
		perpendicular[1] =  axis[0];

		// // project all the points on the projection axis
		// Loop over vertices of 1st polygon
		for (int j = 0; j < polygon1.x.size(); j++)
		{
			// dot product maps vertices on 1D-line
			double dot_product = polygon1.x[j] * perpendicular[0] + polygon1.y[j] * perpendicular[1];
			projectionsA.push_back(dot_product);
		}
		// Loop over vertices of 2nd polygon
		for (int j = 0; j < polygon2.x.size(); j++)
		{
			// dot product maps vertices on 1D-line
			double dot_product = polygon2.x[j] * perpendicular[0] + polygon2.y[j] * perpendicular[1];
			projectionsB.push_back(dot_product);
		}

		// find min and max values of both projections of the polygons
		double minA, minB, maxA, maxB;
		minA = *std::min_element(projectionsA.begin(), projectionsA.end());
		maxA = *std::max_element(projectionsA.begin(), projectionsA.end());
		minB = *std::min_element(projectionsB.begin(), projectionsB.end());
		maxB = *std::max_element(projectionsB.begin(), projectionsB.end());


		if (maxA < minB || minA > maxB) { 
			return false; // return false, if a separating axis is found and the polygons are not overlapping
		}
	} // end for-loop around the sides of 1st polygon

	// Loop over sides of second polygon
	for (int i = 0; i < polygon2.x.size() - 1; i++)
	{
		// // construct normalized projection axis
		double axis[2] = {};
		double perpendicular[2] = {};
		std::vector<double> projectionsA;
		std::vector<double> projectionsB;

		// compute axis of polygon sides
		axis[0] = (double)polygon2.x[i + 1] - (double)polygon2.x[i];
		axis[1] = (double)polygon2.y[i + 1] - (double)polygon2.y[i];

		// normalize vector
		double length_axis = sqrt(axis[0] * axis[0] + axis[1] * axis[1]);
		axis[0] = axis[0] / length_axis;
		axis[1] = axis[1] / length_axis;

		// find the perpendicular axis [x,y] = [-y,x]
		perpendicular[0] = -axis[1];
		perpendicular[1] = axis[0];

		// // project all the points on the projection axis
		// Loop over vertices of 1st polygon
		for (int j = 0; j < polygon1.x.size(); j++)
		{
			// dot product maps vertices on 1D-line
			double dot_product = polygon1.x[j] * perpendicular[0] + polygon1.y[j] * perpendicular[1];
			projectionsA.push_back(dot_product);
		}
		// Loop over vertices of 2nd polygon
		for (int j = 0; j < polygon2.x.size(); j++)
		{
			// dot product maps vertices on 1D-line
			double dot_product = polygon2.x[j] * perpendicular[0] + polygon2.y[j] * perpendicular[1];
			projectionsB.push_back(dot_product);
		}

		// find min and max values of both projections of the polygons
		double minA, minB, maxA, maxB;
		minA = *std::min_element(projectionsA.begin(), projectionsA.end());
		maxA = *std::max_element(projectionsA.begin(), projectionsA.end());
		minB = *std::min_element(projectionsB.begin(), projectionsB.end());
		maxB = *std::max_element(projectionsB.begin(), projectionsB.end());

		if (maxA < minB || minA > maxB) {
			return false; // return false, if a separating axis is found and the polygons are not overlapping
		}		
	} // end for-loop around sides of 2nd polygon

  return true;
}