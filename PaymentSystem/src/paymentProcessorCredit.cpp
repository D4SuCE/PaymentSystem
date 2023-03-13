#include "spdlog/spdlog.h"
#include "payment/paymentProcessorCredit.h"

PaymentProcessorCredit::PaymentProcessorCredit(const Order& order, std::string_view securityCode)
	: order(std::make_shared<Order>(order)), securityCode(securityCode)
{
}

void PaymentProcessorCredit::pay() const
{
	spdlog::info("Processing credit payment type");
	spdlog::info("Vefivying security code: {}", securityCode);
	order->setStatus(Status::PAID);
}

void PaymentProcessorCredit::displayInfo() const
{
	spdlog::info("Credit payment processor for order " + uuids::to_string(order->getId()));
}