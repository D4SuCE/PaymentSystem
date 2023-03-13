#pragma once

class IAuthorizer
{
public:
	virtual bool isAuthorized() const = 0;
	virtual ~IAuthorizer() = default;
};