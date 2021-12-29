//
//  main.cpp
//  Project02
//
//  Created by ThaiHiep on 08/12/2021.
//
#include "DbSet.h"
#include "Company.h"

int main(int argc, const char* argv[]) {
    auto company = std::make_shared<Company>();
    Company::DisplayMenuUI();
    company->CompanyLoop();
    return 0;
}
