#pragma once

#include <iostream>
#include <string>

class Animal{
public:
	virtual std::string Voice() const
	{
		return "Not impleented yet!";
	}

	virtual ~Animal() = default;
};

class Tiger : public Animal{
public:
	std::string Voice() const
	{
		return "Rrrrr!";
	}
};


class Wolf : public Animal{
public:
	std::string Voice() const override
	{
		return "Woooo";
	}
};


class Fox : public Animal{
public:
	std::string Voice() const override
	{
		return "tyaf !";
	}
};
