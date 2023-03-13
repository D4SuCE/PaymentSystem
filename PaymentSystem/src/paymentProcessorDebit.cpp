#include "spdlog/spdlog.h"
#include "trouble/trouble.h"
#include "payment/paymentProcessorDebit.h"

PaymentProcessorDebit::PaymentProcessorDebit(const Order& order, std::string_view securityCode, std::shared_ptr<IAuthorizer> authorizer)
	: order(std::make_shared<Order>(order)), securityCode(securityCode), authorizer(std::move(authorizer))
{
}

void PaymentProcessorDebit::pay() const
{
	if (!authorizer->isAuthorized())
	{
		throw Trouble("Not authorized");
	}

	spdlog::info("Processing debit payment type");
	spdlog::info("Vefivying security code: {}", securityCode);
	order->setStatus(Status::PAID);
}

void PaymentProcessorDebit::displayInfo() const
{
	spdlog::info("Debit payment processor for order " + uuids::to_string(order->getId()));
}