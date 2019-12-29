#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <sstream>

#include "animals.h"


using Zoo = std::vector<std::unique_ptr<Animal>>;

Zoo CreateZoo(std::istream& in)
{
	Zoo zoo;
	std::string word;
	while(in >> word)
	{
		if(word == "Tiger")
		{
			std::unique_ptr<Animal> tiger = std::make_unique<Tiger>();
			zoo.push_back(std::move(tiger));
		}
		if(word == "Wolf")
		{	
			std::unique_ptr<Animal> wolf = std::make_unique<Wolf>();
			zoo.push_back(std::move(wolf));
		}
		if(word == "Fox")
		{
			std::unique_ptr<Animal> fox = std::make_unique<Fox>();
			zoo.push_back(std::move(fox));
		}
		else
		{
			throw std::runtime_error (" unknown Animal ");
		}
	}
	return zoo;
}

void Process(const Zoo& zoo, std::ostream& out){	
	for(const auto& x :zoo)
	{
		out << x->Voice() << "\n";
	}
}


int main(){
	return 0;
}