#include "spdlog/spdlog.h"
#include "authorizer/smsAuthorizer.h"

SMSAuthorizer::SMSAuthorizer()
	: authorized(false)
{
}

bool SMSAuthorizer::isAuthorized() const
{
	return authorized;
}

void SMSAuthorizer::verifyCode(std::string_view code)
{
	spdlog::debug("Verified SMS {}", code);
	authorized = true;
}