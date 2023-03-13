#include "status/status.h"

std::string statusToString(const Status& status)
{
	switch (status)
	{
		case Status::OPEN:
		{
			return "OPEN";
		};

		case Status::PAID:
		{
			return "PAID";
		}
	}
}