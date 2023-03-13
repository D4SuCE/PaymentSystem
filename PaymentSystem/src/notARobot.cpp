#include "spdlog/spdlog.h"
#include "authorizer/notARobot.h"

NotARobot::NotARobot()
	: authorized(false)
{
}

void NotARobot::verify()
{
	spdlog::debug("Are you a robot? Not");
	authorized = true;
}

bool NotARobot::isAuthorized() const
{
	return authorized;
}