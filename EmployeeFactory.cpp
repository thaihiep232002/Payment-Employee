#include "EmployeeFactory.h"

std::shared_ptr<Employee> EmployeeFactory::create(std::string category) {
	std::shared_ptr<Employee> result = NULL;
	if (category == "DailyEmployee") {
		result = std::make_shared<DailyEmployee>();
	}
	else if (category == "HourlyEmployee") {
		result = std::make_shared<HourlyEmployee>();
	}
	else if (category == "ProductEmployee") {
		result = std::make_shared<ProductEmployee>();
	}
	else if (category == "Manager") {
		result = std::make_shared<Manager>();
	}
	return result;
}

std::shared_ptr<Employee> EmployeeFactory::create(int choice) {
	auto result = _prototypes[choice]->clone();
	return result;
}

EmployeeFactory::EmployeeFactory() {
	auto e1 = std::make_shared<DailyEmployee>();
	auto e2 = std::make_shared<HourlyEmployee>();
	auto e3 = std::make_shared<ProductEmployee>();
	auto e4 = std::make_shared<Manager>();

	_prototypes.insert({ 1, e1 });
	_prototypes.insert({ 2, e2 });
	_prototypes.insert({ 3, e3 });
	_prototypes.insert({ 4, e4 });
}

std::shared_ptr<EmployeeFactory> EmployeeFactory::instance() {
	if (_instance == NULL) {
		_instance = std::make_shared<EmployeeFactory>();
	}
	return _instance;
}

void EmployeeFactory::displayMenu() {
	for (auto item : _prototypes) {
		std::cout << "    " << item.first << ". " << item.second->magicWord() << std::endl;
	}
}