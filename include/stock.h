#ifndef STOCK_TRADING_SYSTEM_STOCK_H
#define STOCK_TRADING_SYSTEM_STOCK_H

#include <string>

namespace StockTradingSystem
{

class Stock
{
public:
	Stock();
	Stock(double, const std::string&);
	void setPrice(double);
	void setName(const std::string&);
	double getPrice() const;
	std::string getName() const;
private:
	double price;
	std::string name;
};

} // StockTradingSystem

#endif // STOCK_TRADING_SYSTEM_STOCK_H