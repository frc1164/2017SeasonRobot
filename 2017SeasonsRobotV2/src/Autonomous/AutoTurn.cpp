/*
 * AutoTurnToPilot.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: neoadmin
 */
/*
#include <Autonomous/AutoTurnToPilot.h>
#define WALL_FORWARD 0
#define TURN         1
#define TO_PILOT     2
#define BACK         3

AutoTurnToPilot::AutoTurnToPilot(FourWheelDrive *FWD, NavxCode *N,Constant * C, bool left)
                 : Command("AutoTurnToPilot") {
	Drive = FWD;
	running_=true;
	constant=C;
	mynavx = N;
	auto_case = WALL_FORWARD;
	if (left)
	  target_angle=mynavx->GetYawAngle() - C->Get("AutoTurnPilotAngle");
	else
		target_angle=mynavx->GetYawAngle() + C->Get("AutoTurnPilotAngle");

}

AutoTurnToPilot::~AutoTurnToPilot() {
	// TODO Auto-generated destructor stub
}

bool  AutoTurnToPilot::IsFinished()  {

	if (!running_) {
		Drive->arcadeDrive(0,0,0,0); // stop
	}

	return(!running_);

}

void AutoTurnToPilot::End()
{

}

void AutoTurnToPilot::Initialize()
{
	mynavx->ResetYaw();
	Drive->ResetEncoders(); //set encoder to 0 so we know how far to go
}

void AutoTurnToPilot::Execute(){

	double window=2.0;

	double difference=target_angle - mynavx->GetYawAngle();
	double direction;

	if (difference < 0) direction =-1.0;
	else direction = 1.0;

	direction=direction*-1;

	// Turn Autonomously until we get to our target angle

	//  get the Drive encoder --- if we get to the encoder value then we are done, other wise drive
	if (auto_case == WALL_FORWARD){
		if (constant->Get("AutoGearForwardEncoder") > Drive->LeftEncoder()){
			auto_case = TURN; Drive->ResetEncoders(); mynavx->ResetYaw();
		}
		else    Drive->arcadeDrive(0,-0.5,false,false);
	}
	else if (auto_case == TURN){
		if ((target_angle  < (mynavx->GetYawAngle() + window))   &&
			(target_angle > (mynavx->GetYawAngle() - window)) ) {
			auto_case = TO_PILOT; Drive->ResetEncoders(); mynavx->ResetYaw();
		}

		else    Drive->arcadeDrive(direction*0.25,0.,false,false);
	}
	else if (auto_case == TO_PILOT){
		if (constant->Get("AutoGearPilotForwardEncoder") > Drive->LeftEncoder()) {
			Drive->ResetEncoders(); mynavx->ResetYaw(); auto_case = BACK;
		}
		else    Drive->arcadeDrive(0,-0.5,false,false);
	}
	else if (auto_case == BACK){
		if (constant->Get("AutoGearBackEncoder") < Drive->LeftEncoder()) running_ = false;
		else    Drive->arcadeDrive(0,0.5,false,false);
	}
}*/

/*
 * AutoTurnToPilot.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: neoadmin
 */

#include <Autonomous/AutoTurn.h>

AutoTurn::AutoTurn(FourWheelDrive *FWD, NavxCode *N,Constant * C, bool left, float turn)
                 : Command("AutoTurn") {
	Drive = FWD;
	running_=true;
	constant=C;
	mynavx = N;
	mynavx->ResetYaw();
	turn_ = turn;

}

AutoTurn::~AutoTurn() {
	// TODO Auto-generated destructor stub
}

bool  AutoTurn::IsFinished()  {

	if (!running_) {
		Drive->arcadeDrive(0,0,0,0); // stop
		Drive->ResetEncoders();
	}

	return(!running_);

}

void AutoTurn::End()
{

}

void AutoTurn::Initialize()
{
	Drive->ResetEncoders(); //set encoder to 0 so we know how far to go
	if (left)
	  target_angle=mynavx->GetYawAngle() - turn_;
	else
		target_angle=mynavx->GetYawAngle() + turn_;

}

void AutoTurn::Execute(){

	double window=2.0;

	double difference=target_angle - mynavx->GetYawAngle();
	double direction;

	if (difference < 0) direction =-1.0;
	else direction = 1.0;

	direction=direction*-1;

	// Turn Autonomously until we get to our target angle

	//  get the Drive encoder --- if we get to the encoder value then we are done, other wise drive
	if ((target_angle  < (mynavx->GetYawAngle() + window))   &&
		(target_angle > (mynavx->GetYawAngle() - window)) ) running_=false;

	else    Drive->arcadeDrive(direction*0.5,0.,false,false);

}
