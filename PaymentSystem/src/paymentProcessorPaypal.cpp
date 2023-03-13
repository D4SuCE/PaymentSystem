#include "spdlog/spdlog.h"
#include "trouble/trouble.h"
#include "payment/paymentProcessorPaypal.h"

PaymentProcessorPaypal::PaymentProcessorPaypal(const Order& order, std::string_view emailAddress, std::shared_ptr<IAuthorizer> authorizer)
	: order(std::make_shared<Order>(order)), emailAddress(emailAddress), authorizer(std::move(authorizer))
{
}

void PaymentProcessorPaypal::pay() const
{
	if (!authorizer->isAuthorized())
	{
		throw Trouble("Not authorized");
	}

	spdlog::info("Processing paypal payment type");
	spdlog::info("Vefivying email address: {}", emailAddress);
	order->setStatus(Status::PAID);
}

void PaymentProcessorPaypal::displayInfo() const
{
	spdlog::info("Paypal payment processor for order " + uuids::to_string(order->getId()));
}