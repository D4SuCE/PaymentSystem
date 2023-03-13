#pragma once

#include <string>

enum class Status
{
	OPEN = 0,
	PAID
};

std::string statusToString(const Status& status);