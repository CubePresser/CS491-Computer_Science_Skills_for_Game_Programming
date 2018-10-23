// (Theta part 1, theta part 2, theta part 3, length part 1, length part 2,
//  transform 1 w/r ground, transform 2 w/r ground, transform 3 w/r ground)
void
Forward(float th1, float th2, float th3, float l1, float l2,
	glm::mat4 & x1g, glm::mat4 & x2g, glm::mat4 & x3g)
{
	//Conversion to radians
	th1 *= (M_PI / 180.); //Theta for part 1
	th2 *= (M_PI / 180.); //Theta for part 2
	th3 *= (M_PI / 180.); //Theta for part 3
	
	glm::mat4 tl1 = glm::translate(glm::mat4(1.f), glm::vec3(l1, 0, 0)); //Translate by the length of part 1
	glm::mat4 tl2 = glm::translate(glm::mat4(1.f), glm::vec3(l2, 0, 0)); //Translate by the length of part 2
	glm::mat4 r1 = glm::rotate(glm::mat4(1.f), th1, glm::vec3(0, 0, 1));  //Rotate by part 1 angle
	glm::mat4 r2 = glm::rotate(glm::mat4(1.f), th2, glm::vec3(0, 0, 1));  //Rotate by part 2 angle
	glm::mat4 r3 = glm::rotate(glm::mat4(1.f), th3, glm::vec3(0, 0, 1));  //Rotate by part 3 angle
	glm::mat4 x21 = tl1 * r2; //Transformation matrix of part 2 with respect to part 1  -- [[T_2/1]*[R_th2]]
	glm::mat4 x32 = tl2 * r3; //Transoformation matrix of part 3 with respect to part 2 -- [[T_3/2]*[R_th3]]

	

	x1g = r1; //Transformation of 1 with respect to ground -- [M_1/g] = [T_1/g] * [R_th1]
	x2g = x1g * x21; //Transformation of 2 with respect to ground -- [M_2/g] = [M_1/g] * [[T_2/1]*[R_th2]]
	x3g = x2g * x32; //Transformation of 3 with respect to ground -- [M_3/g] = [M_1/g] * [[T_2/1]*[R_th2]] * [[T_3/2]*[R_th3]]
}

void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
        yourName = "Jonathan Jones";
        yourEmailAddress = "jonesjon@oregonstate.edu" ;
}

}