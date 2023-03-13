#include "item/item.h"

Item::Item(std::string_view itemName, int quantity, double price)
	: itemName(itemName), quantity(quantity), price(price)
{
}

std::string_view Item::getName() const
{
	return itemName;
}

int Item::getQuantity() const
{
	return quantity;
}

double Item::getPrice() const
{
	return price;
}