#include "Employee.h"
#include <sstream>

Dollar DailyEmployee::getPaid() {
	Dollar result;
	result = Util::Mutilply(_salaryPayment, _totalDays);
	return result;
}

std::string DailyEmployee::toString() {
	std::stringstream builder;
	builder << "Name: " << this->getName()
		<< ", TotalDays: "<< this->getTotal()
		<< ", DailyPayment: " << this->getSalaryPayment().getValue()
		<< "\n\t--> FinalPayment: " << this->getPaid().getValue();
	std::string result = builder.str();
	return result;
}

Dollar HourlyEmployee::getPaid() {
	Dollar result;
	result = Util::Mutilply(_salaryPayment, _totalHours);
	return result;
}

std::string HourlyEmployee::toString() {
	std::stringstream builder;
	builder << "Name: " << this->getName()
		<< ", TotalHours: " << this->getTotal()
		<< ", HourlyPayment: " << this->getSalaryPayment().getValue()
		<< "\n\t--> FinalPayment: " << this->getPaid().getValue();
	std::string result = builder.str();
	return result;
}

Dollar ProductEmployee::getPaid() {
	Dollar result;
	result = Util::Mutilply(_salaryPayment, _totalProducts);
	return result;
}

std::string ProductEmployee::toString() {
	std::stringstream builder;
	builder << "Name: " << this->getName()
		<< ", TotalProducts: " << this->getTotal()
		<< ", PaymentPerProduct: " << this->getSalaryPayment().getValue()
		<< "\n\t--> FinalPayment: " << this->getPaid().getValue();
	std::string result = builder.str();
	return result;
}

Dollar Manager::getPaid() {
	bool isSuccess = true;
	int error_code = 0;
	std::string message = "";
	Dollar result;
	result = Util::Mutilply(_salaryPayment, _totalEmployees);
	result = Util::Add(result, _fixedPayment);
	return result;
}

std::string Manager::toString() {
	std::stringstream builder;
	builder << "Name: " << this->getName()
		<< ", TotalEmployees: " << this->getTotal()
		<< ", PaymentPerEmployee: " << this->getSalaryPayment().getValue()
		<< ", FixedPayment: " << this->fixedPayment().getValue()
		<< "\n\t--> FinalPayment: " << this->getPaid().getValue();
	std::string result = builder.str();
	return result;
}