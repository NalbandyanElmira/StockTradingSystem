#ifndef STOCK_TRADING_SYSTEM_ORDERBOOK_H
#define STOCK_TRADING_SYSTEM_ORDERBOOK_H

#include "order.h"

#include <vector>
#include <memory>

namespace StockTradingSystem
{

class OrderBook
{
public:
	OrderBook();
	void addOrder(std::shared_ptr<Order>);
	void matchOrders();
	void printOrderBook() const;
	void setStrategy(OrderMatchingStrategy*);
private:
	std::vector<std::shared_ptr<Order>> book;
	OrderMatchingStrategy* strategy;
};

} // StockTradingSystem

#endif // STOCK_TRADING_SYSTEM_ORDERBOOK_H