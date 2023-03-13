#pragma once

#include <vector>
#include "uuid/uuid.h"
#include "item/item.h"
#include "status/status.h"

class Order
{
private:
	uuids::uuid id;
	std::vector<Item> items;
	Status status;
public:
	Order();

	const uuids::uuid& getId() const;
	void addItem(const Item& item);
	void setStatus(Status status);
	double totalPrice() const;
	void printOrder() const;
};