#pragma once

#include <string_view>
#include "iAuthorizer.h"

class SMSAuthorizer final : public IAuthorizer
{
private:
	bool authorized;
public:
	SMSAuthorizer();

	bool isAuthorized() const override;
	void verifyCode(std::string_view code);
};