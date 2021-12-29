#include "Employee.h"
#include <map>
#include <iostream>

class EmployeeFactory {
private:
	std::map<int, std::shared_ptr<Employee>> _prototypes;
	inline static std::shared_ptr<EmployeeFactory> _instance = NULL;
public:
	std::map<int, std::shared_ptr<Employee>> prototypes() { return _prototypes; }
public:
	EmployeeFactory();
public:
	std::shared_ptr<Employee> create(std::string category);
public:
	std::shared_ptr<Employee> create(int choice);
public:
	static std::shared_ptr<EmployeeFactory> instance();
public:
	void displayMenu();
};