#include "order/order.h"
#include "spdlog/spdlog.h"
#include "authorizer/authorizer.h"
#include "payment/paymentProcessor.h"

int main()
{
	Item item1("Keyboard", 1, 50.0);
	Item item2("Mouse", 1, 30.0);
	Item item3("HDD", 2, 100.0);

	Order order;

	order.addItem(item1);
	order.addItem(item2);
	order.addItem(item3);

	order.printOrder();

	auto authorizer1 = std::make_shared<SMSAuthorizer>();

	PaymentProcessorDebit payProc1(order, "65413", authorizer1);
	try
	{
		payProc1.displayInfo();
		authorizer1->verifyCode("873451");
		payProc1.pay();
	}
	catch (const std::exception& e)
	{
		spdlog::error(e.what());
	}

	PaymentProcessorCredit payProc2(order, "91835");
	try
	{
		payProc2.displayInfo();
		payProc2.pay();
	}
	catch (const std::exception& e)
	{
		spdlog::error(e.what());
	}

	auto authorizer3 = std::make_shared<NotARobot>();

	PaymentProcessorPaypal payProc3(order, "example@gmail.com", authorizer3);
	try
	{
		payProc3.displayInfo();
		authorizer3->verify();
		payProc3.pay();
	}
	catch (const std::exception& e)
	{
		spdlog::error(e.what());
	}
	
	return 0;
}