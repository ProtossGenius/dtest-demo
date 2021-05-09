#include "my_strategy.h"
#include "smdtest/user.h"
#include <iostream>
namespace demo{
	MyStrategy::MyStrategy():_ticker(smnet::GetTickManager().getTicker(200)), _login(std::make_shared<smdtest::Process>("LoginProcess")){
			smdtest::Business bus(std::vector<std::string>{smdtest::NameLoginAction}, "LoginBusiness", 1);
			_login->getBussnessVector().emplace_back(bus);
		}
std::shared_ptr<smdtest::Process> MyStrategy::getProcess(smdtest::User &usr, const std::string &err) {
			auto str = usr.getSharedData<std::string>("", "Success");
			if (*str != ""){
				closeUser(usr);
			}
			_login->clean();
			return _login;
		}
}
