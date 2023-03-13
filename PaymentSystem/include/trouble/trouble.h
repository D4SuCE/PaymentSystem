#pragma once

#include <string>
#include <exception>

class Trouble : public std::exception
{
private:
	std::string message;
public:
	Trouble() noexcept;
	explicit Trouble(const char* const message) noexcept;
	explicit Trouble(const std::string& message) noexcept;

	virtual const char* what() const noexcept;
};