#include "trouble/trouble.h"

Trouble::Trouble() noexcept
	: message()
{
}

Trouble::Trouble(const char* const message) noexcept
	: message(message)
{
}

Trouble::Trouble(const std::string& message) noexcept
	: message(message)
{
}

const char* Trouble::what() const noexcept
{
	return message.c_str();
}