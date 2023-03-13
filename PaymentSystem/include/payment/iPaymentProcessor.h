#pragma once

class IPaymentProcessor
{
public:
	virtual void pay() const = 0;
	virtual void displayInfo() const = 0;
	virtual ~IPaymentProcessor() = default;
};