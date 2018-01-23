/*
 * BaseLineTurnLeft.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: neoadmin
 */

#include <Autonomous/BaseLineTurnLeft.h>

namespace frc {

BaseLineTurnLeft::BaseLineTurnLeft(FourWheelDrive *FWD, NavxCode *N,Constant * C, bool left) {
	// TODO Auto-generated constructor stub
	AddSequential(new AutoForward(FWD,C,C->Get("AutoGearTurnEncoder"), 0.5));
	AddSequential(new AutoTurn(FWD,N,C,left,C->Get("AutoTurnPilotAngle")));
	AddSequential(new AutoForward(FWD,C,C->Get("AutoGearPilotForwardEncoder"), 0.5));
}

BaseLineTurnLeft::~BaseLineTurnLeft() {
	// TODO Auto-generated destructor stub
}

} /* namespace frc */
