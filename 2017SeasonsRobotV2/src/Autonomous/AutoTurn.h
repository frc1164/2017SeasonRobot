/*
 * AutoTurnToPilot.h
 *
 *  Created on: Feb 25, 2017
 *      Author: neoadmin
 */
/*
#ifndef SRC_AUTONOMOUS_AUTOTURNTOPILOT_H_
#define SRC_AUTONOMOUS_AUTOTURNTOPILOT_H_
#include <WPILib.h>

#include <DriverStation.h>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Subsystems/FourWheelDrive.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/NavxCode.h"
#include <Constant.h>
#include <Joystick.h>
#include <TalonSRX.h>
#include <RobotDrive.h>
#include <Autonomous/FetchZed.h>

namespace frc {


class AutoTurnToPilot : public Command {
public:
	AutoTurnToPilot(FourWheelDrive *FWD, NavxCode *N,Constant * C, bool left);
	virtual ~AutoTurnToPilot();
	bool running_;
	FourWheelDrive * Drive;
	Constant *constant;
	NavxCode * mynavx;

	double target_angle;
	int auto_case;

	bool IsFinished();
	void End();
	void Initialize();
	void Execute();
};


} // of frc namespace

*/
/*
 * AutoTurnToPilot.h
 *
 *  Created on: Feb 25, 2017
 *      Author: neoadmin
 */

#ifndef SRC_AUTONOMOUS_AUTOTURN_H_
#define SRC_AUTONOMOUS_AUTOTURN_H_
#include <WPILib.h>

#include <DriverStation.h>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Subsystems/FourWheelDrive.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/NavxCode.h"
#include <Constant.h>
#include <Joystick.h>
#include <TalonSRX.h>
#include <RobotDrive.h>
#include <Autonomous/FetchZed.h>

namespace frc {


class AutoTurn : public Command {
public:
	AutoTurn(FourWheelDrive *FWD, NavxCode *N,Constant * C, bool left, float turn);
	virtual ~AutoTurn();
	bool running_;
	FourWheelDrive * Drive;
	Constant *constant;
	NavxCode * mynavx;

	double target_angle;
	float turn_;

	bool IsFinished();
	void End();
	void Initialize();
	void Execute();
};


} // of frc namespace


#endif /* SRC_AUTONOMOUS_AUTOTURNTOPILOT_H_ */
