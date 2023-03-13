#pragma once

#include <memory>
#include <string_view>
#include "order/order.h"
#include "iPaymentProcessor.h"
#include "authorizer/iAuthorizer.h"

class PaymentProcessorPaypal final : public IPaymentProcessor
{
private:
	std::shared_ptr<Order> order;
	std::string_view emailAddress;
	std::shared_ptr<IAuthorizer> authorizer;
public:
	explicit PaymentProcessorPaypal(const Order& order, std::string_view emailAddress, std::shared_ptr<IAuthorizer> authorizer);

	void pay() const override;
	void displayInfo() const override;
};