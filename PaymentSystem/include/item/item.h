#pragma once

#include <string_view>

class Item
{
private:
	std::string_view itemName;
	int quantity;
	double price;

public:
	Item(std::string_view itemName, int quantity, double price);

	std::string_view getName() const;
	int getQuantity() const;
	double getPrice() const;
};