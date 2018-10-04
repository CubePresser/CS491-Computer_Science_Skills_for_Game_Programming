#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"

//Remove these includes
#include <iostream>
#include "glm/gtx/string_cast.hpp"



glm::vec3
WhatPartOfALivesInBDir( glm::vec3 a, glm::vec3 b )
{
	return glm::normalize(b) * glm::dot( a, glm::normalize(b) );
}


glm::vec3
WhatPartOfALivesPerpToB( glm::vec3 a, glm::vec3 b )
{
	return a  -  WhatPartOfALivesInBDir( a, b );
}


glm::vec3
UnitSurfaceNormal( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	return glm::normalize(glm::cross((r-q),(s-q)));
}


float
Area( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	return glm::length(glm::cross((r-q),(s-q))) * 0.5;
}


bool
IsPointInTriangle( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	glm::vec3 n = glm::cross((r-q), (s-q));

	return ((glm::dot(n, glm::cross((r-q), (p-q)))) > 0) && ((glm::dot(n, glm::cross((s-r), (p-r)))) > 0) && ((glm::dot(n, glm::cross((q-s), (p-s)))) > 0);
}



float
DistanceFromPointToPlane( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	return glm::dot((p-q), UnitSurfaceNormal(q, r, s));
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Jonathan Jones";
	yourEmailAddress = "jonesjon@oregonstate.edu" ;
}

int main()
{
	glm::vec3 v1 = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 v2 = glm::vec3(1.0, 0.0, 0.0);
	glm::vec3 v3 = glm::vec3(0.0, 0.0, 1.0);

	glm::vec3 p1 = glm::vec3(0.1, 0.0, 0.1);
	glm::vec3 p2 = glm::vec3(9182349, 423, 0.5);

	std::cout<<"UnitSurfaceNormal: " + glm::to_string(UnitSurfaceNormal(v1, v3, v2))<<std::endl;
	std::cout<<"Area: " << Area(v1, v2, v3)<<std::endl;
	std::cout<<"Point in triangle: p1(" << IsPointInTriangle(v1, v2, v3, p1) << ") p2(" << IsPointInTriangle(v1, v2, v3, p2) << ")\n";
	std::cout<<"Distance from plane: p2(" << DistanceFromPointToPlane(v1, v3, v2, p2) << ")\n";
    return 0;
}