#include <string>
#include <vector>
#include <memory>
#include "Dollar.h"

class Employee {
protected:
	std::string _name;
	Dollar _salaryPayment;
public:
	Employee() {
		_name = "";
	}

	Employee(std::string name, std::string salaryPayment) 
		:_name(name), _salaryPayment(salaryPayment) {}
public:
	std::string getName() { return _name; }
	Dollar getSalaryPayment() { return _salaryPayment; }
	virtual Dollar fixedPayment() = 0;
	virtual unsigned int getTotal() = 0;
	virtual Dollar getPaid() = 0;
public:
	void setName(std::string name) { _name = name; }
	void setSalaryPayment(Dollar value) { _salaryPayment = value; }
	virtual void setTotal(unsigned int) = 0;
	virtual void setFixedPayment(Dollar fixedPayment) = 0;
public:
	virtual std::string toString() = 0;
	virtual std::shared_ptr<Employee> clone() = 0;
	virtual std::string magicWord() = 0;
};

class DailyEmployee : public Employee {
private:
	unsigned int _totalDays;
public:
	DailyEmployee() {
		_totalDays = 0;
	}

	DailyEmployee(std::string name, std::string salaryPayment, unsigned int totalDays) 
		:_totalDays(totalDays)
	{
		_name = name;
		_salaryPayment = salaryPayment;
	}
public:
	unsigned int getTotal() { return _totalDays; }
	void setTotal(unsigned int totalDays) { _totalDays = totalDays; }
public:
	Dollar fixedPayment() {
		Dollar fake("0$");
		return fake;
	}
	void setFixedPayment(Dollar fixedPayment) {}
public:
	Dollar getPaid();
public:
	std::string toString();
	std::shared_ptr<Employee> clone() { return std::make_shared<DailyEmployee>(); }
	std::string magicWord() { return "DailyEmployee"; }
};

class HourlyEmployee : public Employee {
private:
	unsigned int _totalHours;
public:
	HourlyEmployee() {
		_totalHours = 0;
	}

	HourlyEmployee(std::string name, std::string salaryPayment, unsigned int totalHours)
		:_totalHours(totalHours)
	{
		_name = name;
		_salaryPayment = salaryPayment;
	}
public:
	unsigned int getTotal() { return _totalHours; }
	void setTotal(unsigned int totalHours) { _totalHours = totalHours; }
public:
	Dollar fixedPayment() {
		Dollar fake("0$");
		return fake;
	}
	void setFixedPayment(Dollar fixedPayment) {}
public:
	Dollar getPaid();
public:
	std::string toString();
	std::shared_ptr<Employee> clone() { return std::make_shared<HourlyEmployee>(); }
	std::string magicWord() { return "HourlyEmployee"; }
};

class ProductEmployee : public Employee {
private:
	unsigned int _totalProducts;
public:
	ProductEmployee() {
		_totalProducts = 0;
	}

	ProductEmployee(std::string name, std::string salaryPayment, unsigned int totalProducts)
		:_totalProducts(totalProducts)
	{
		_name = name;
		_salaryPayment = salaryPayment;
	}
public:
	unsigned int getTotal() { return _totalProducts; }
	void setTotal(unsigned int totalProducts) { _totalProducts = totalProducts; }
public:
	Dollar fixedPayment() {
		Dollar fake("0$");
		return fake;
	}
	void setFixedPayment(Dollar fixedPayment) {}
public:
	Dollar getPaid();
public:
	std::string toString();
	std::shared_ptr<Employee> clone() { return std::make_shared<ProductEmployee>(); }
	std::string magicWord() { return "ProductEmployee"; }
};

class Manager : public Employee {
private:
	Dollar _fixedPayment;
	unsigned int _totalEmployees;
public:
	Manager() {
		_totalEmployees = 0;
	}

	Manager(std::string name, std::string salaryPayment,
		unsigned int totalEmployees,
		Dollar fixedPayment)
		:_totalEmployees(totalEmployees), _fixedPayment(fixedPayment)
	{
		_name = name;
		_salaryPayment = salaryPayment;
	}
public:
	unsigned int getTotal() { return _totalEmployees; }
	void setTotal(unsigned int totalEmployees) { _totalEmployees = totalEmployees; }
public:
	Dollar fixedPayment() { return _fixedPayment; }
	void setFixedPayment(Dollar fixedPayment) { _fixedPayment = fixedPayment; }
public:
	Dollar getPaid();
public:
	std::string toString();
	std::shared_ptr<Employee> clone() { return std::make_shared<Manager>(); }
	std::string magicWord() { return "Manager"; }
};