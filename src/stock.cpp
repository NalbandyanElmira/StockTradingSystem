#include "../include/stock.h"

using namespace StockTradingSystem;

Stock::Stock() = default;

Stock::Stock(double p, const std::string& n)
	: price{p}
	, name{n}
{
}

void Stock::setPrice(double p)
{
	price = p;
}

void Stock::setName(const std::string& n)
{
	name = n;
}

double Stock::getPrice() const
{
	return price;
}

std::string Stock::getName() const
{
	return name;
}