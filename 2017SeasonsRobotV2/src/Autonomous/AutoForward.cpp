/*
 * AutoBaseLine.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: neoadmin
 */
/*
#include <Autonomous/AutoBaseLine.h>
#define FORWARD  0
#define BACKWARD 1

namespace frc {

AutoBaseLine::AutoBaseLine(FourWheelDrive *FWD, Constant* C) : Command("ABL") {
	Drive = FWD;
	constants=C;
}

AutoBaseLine::~AutoBaseLine() {
	// TODO Auto-generated destructor stub
}

} */
/* namespace frc */
/*
bool  AutoBaseLine::IsFinished()  {

	if (!running_) {
		Drive->arcadeDrive(0.0,0.0,false,false); // stop
	}

	return(!running_);

}

void AutoBaseLine::End()
{

}

void AutoBaseLine::Initialize()
{

}

void AutoBaseLine::Execute(){

	// Drive Autonomously until we get to our spot
	char myst[200];
	char value[200];

	sprintf(value, "We are running the code");
	sprintf(myst,"Encoder Constant is %f, Encoder is %d\n",
			constants->Get("AutoBaseLineEncoder"),Drive->RightEncoder());

	perror(myst);

	int REnc = Drive->RightEncoder();
	sprintf(value, "REnc reading: %d", REnc);
	//  get the Drive encoder --- if we get to the encoder value then we are done, other wise drive
	if (auto_case == FORWARD){
		if (constants->Get("AutoBaseLineEncoder") > Drive->RightEncoder()) {
			//running_ = false;
			Drive->arcadeDrive(0.0,0.0,false,false);
			//auto_case = BACKWARD;
		}
		else {
			Drive->arcadeDrive(0.0,-0.5,false,false);
		}
	} */
	/*else if (auto_case == BACKWARD){
		if (constants->Get("AutoBaseLineBackEncoder") < Drive->LeftEncoder()) running_=false;
		else    Drive->arcadeDrive(0,0.5,false,false);
	}*/
//}

/*
 * AutoBaseLine.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: neoadmin
 */

#include <Autonomous/AutoForward.h>

namespace frc {

AutoForward::AutoForward(FourWheelDrive *FWD, Constant* C, float distance1, float speed1) : Command("AutoForward") {
	Drive = FWD;
	running_=true;
	constants=C;

	distance = distance1;
	speed = speed1;
}

AutoForward::~AutoForward() {
	// TODO Auto-generated destructor stub
}

} /* namespace frc */

bool  AutoForward::IsFinished()  {

	if (!running_) {
		Drive->arcadeDrive(0,0,0,0); // stop
		Drive->ResetEncoders();
	}

	return(!running_);

}

void AutoForward::End()
{

}

void AutoForward::Initialize()
{
	Drive->ResetEncoders(); //set encoder to 0 so we know how far to go
}

void AutoForward::Execute(){

	// Drive Autonomously until we get to our spot
	char myst[200];

	sprintf(myst,"Encoder Constant is %f, Encoder is %d\n",
			distance,Drive->RightEncoder());

	perror(myst);

	//  get the Drive encoder --- if we get to the encoder value then we are done, other wise drive
	if (distance < abs(Drive->RightEncoder())) running_=false;
	else    Drive->arcadeDrive(0,-speed,false,false);

}
