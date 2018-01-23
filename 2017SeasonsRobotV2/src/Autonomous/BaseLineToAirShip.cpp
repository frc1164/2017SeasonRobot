/*
 * BaseLineToAirShip.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: neoadmin
 */

#include <Autonomous/BaseLineToAirShip.h>

namespace frc {

BaseLineToAirShip::BaseLineToAirShip(FourWheelDrive *FWD, Constant* C) : Command("BaseLineToAirShip") {
	Drive = FWD;
	Drive->ResetEncoders(); //set encoder to 0 so we know how far to go
	running_=true;
	constants=C;

}

BaseLineToAirShip::~BaseLineToAirShip() {
	// TODO Auto-generated destructor stub
}

} /* namespace frc */

bool  BaseLineToAirShip::IsFinished()  {

	if (!running_) {
		Drive->arcadeDrive(0,0,0,0); // stop
		Drive->ResetEncoders();
	}

	return(!running_);

}

void BaseLineToAirShip::End()
{

}

void BaseLineToAirShip::Initialize()
{

}

void BaseLineToAirShip::Execute(){

	// Drive Autonomously until we get to our spot
	char myst[200];

	sprintf(myst,"Encoder Constant is %f, Encoder is %d\n",
			constants->Get("AutoGearPilotForwardEncoder"),Drive->RightEncoder());

	perror(myst);
	//  get the Drive encoder --- if we get to the encoder value then we are done, other wise drive
	if (constants->Get("AutoGearPilotForwardEncoder") > Drive->RightEncoder()) running_=false;
	else    Drive->arcadeDrive(0,-0.5,false,false);

}

