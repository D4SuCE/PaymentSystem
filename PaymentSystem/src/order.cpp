#include "order/order.h"
#include "spdlog/spdlog.h"

Order::Order()
	: id(uuids::uuid_system_generator{}()), items(), status(Status::OPEN)
{
}

const uuids::uuid& Order::getId() const
{
	return id;
}

void Order::addItem(const Item& item)
{
	items.push_back(item);
}

void Order::setStatus(Status status)
{
	this->status = status;
}

double Order::totalPrice() const
{
	double totalPrice = 0;

	for (const auto& item : items)
	{
		totalPrice += item.getPrice() * item.getQuantity();
	}

	return totalPrice;
}

void Order::printOrder() const
{
	spdlog::info("The id of the order is " + uuids::to_string(id) + ", with items:");
	for (const auto& item : items)
	{
		spdlog::info(item.getName());
	}
	spdlog::info("and the status is " + statusToString(status));
}