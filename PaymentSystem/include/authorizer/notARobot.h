#pragma once

#include "iAuthorizer.h"

class NotARobot : public IAuthorizer
{
private:
	bool authorized;
public:
	NotARobot();

	void verify();
	bool isAuthorized() const override;
};