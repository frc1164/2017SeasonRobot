/*
 * AutoBaseLine.h
 *
 *  Created on: Feb 23, 2017
 *      Author: neoadmin
 */

/*
#ifndef SRC_AUTOBASELINE_H_
#define SRC_AUTOBASELINE_H_
#include <iostream>
#include <memory>
#include <string>

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

class AutoBaseLine : public Command  {
public:
	AutoBaseLine(FourWheelDrive *FWD, Constant* C);
	virtual ~AutoBaseLine();
	bool IsFinished();
	void End();
	void Initialize();
	void Execute();
	bool running_ = true;
	int auto_case = 0;
	Constant * constants;

private:
	FourWheelDrive * Drive;
};

}
*/
/* namespace frc */

/*
 * AutoBaseLine.h
 *
 *  Created on: Feb 23, 2017
 *      Author: neoadmin
 */

#ifndef SRC_AUTOFORWARD_H_
#define SRC_AUTOFORWARD_H_
#include <iostream>
#include <memory>
#include <string>

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

class AutoForward : public Command  {
public:
	AutoForward(FourWheelDrive *FWD, Constant* C, float distance1, float speed1);
	virtual ~AutoForward();
	bool IsFinished();
	void End();
	void Initialize();
	void Execute();
	bool running_;
	Constant * constants;

	float distance;
	float speed;

private:
	FourWheelDrive * Drive;
};

} /* namespace frc */

#endif /* SRC_AUTOFORWARD_H_ */

