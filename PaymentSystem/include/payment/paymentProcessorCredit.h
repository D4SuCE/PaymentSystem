#pragma once

#include <memory>
#include <string_view>
#include "order/order.h"
#include "iPaymentProcessor.h"

class PaymentProcessorCredit final : public IPaymentProcessor
{
private:
	std::shared_ptr<Order> order;
	std::string_view securityCode;
public:
	explicit PaymentProcessorCredit(const Order& order, std::string_view securityCode);

	void pay() const override;
	void displayInfo() const override;
};