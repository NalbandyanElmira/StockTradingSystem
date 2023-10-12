#ifndef STOCK_TRADING_SYSTEM_TRADER_H
#define STOCK_TRADING_SYSTEM_TRADER_H

#include "stock.h"
#include "order.h"
#include "orderBook.h"

#include <string>

namespace StockTradingSystem
{

class TraderException : public std::exception
{
public:
    	TraderException(const std::string&);
    	virtual const char* what() const noexcept override;
private:
    	std::string message;
};


class Trader
{
public:
	Trader();
	Trader(const std::string&);
	Trader(const std::string&, const std::vector<Stock>&, OrderFactory*, OrderBook*);
	void buy(const Stock&, int);
	void sell(const Stock&, int);
	void trade(double, double, int, int);
	int getID() const;
	const std::vector<std::shared_ptr<Order>>& getOrders() const;
	void addStock(const Stock&);
	std::vector<Stock> getStocks() const;
	~Trader();
private:
	static int id_counter;
	int id;
	std::string name;
	std::vector<Stock> stocks;
	OrderFactory* orderFactory;
	OrderBook* orderBook;
	std::vector<std::shared_ptr<Order>> orders;
};

} // StockTradingSystem

#endif // STOCK_TRADING_SYSTEM_TRADER_H
