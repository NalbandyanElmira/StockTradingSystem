#ifndef STOCK_TRADING_SYSTEM_ORDER_H
#define STOCK_TRADING_SYSTEM_ORDER_H

#include <string>
#include <memory>
#include <vector>
#include <ctime>

namespace StockTradingSystem
{

enum OrderType { BUY, SELL };

class Order
{
public:
	Order(int, double, int);
	virtual ~Order();
	virtual std::string getOrderType() const = 0;
	int getTraider_id() const;
	double getPrice() const;
	int getQuantity() const;
	std::time_t getTimestamp() const;
	void reduceQuantity(int);
    	OrderType getOrdertype() const;
    	void setOrderType(OrderType);
private:
	int traider_id;
	double price;
	int quantity;
	std::time_t timestamp;
	OrderType ordertype;
};

class MarketOrder : public Order 
{
public:
	MarketOrder(int trader_id, double price, int quantity) : Order(trader_id, price, quantity) {}
	std::string getOrderType() const override;
};

class LimitOrder : public Order 
{
public:
	LimitOrder(int trader_id, double price, int quantity) : Order(trader_id, price, quantity) {}
	std::string getOrderType() const override;
};

class OrderFactory {
public:
    	virtual std::unique_ptr<Order> createOrder(int, double, int) = 0;
    	virtual ~OrderFactory();
};

class MarketOrderFactory : public OrderFactory {
public:
    	std::unique_ptr<Order> createOrder(int, double, int) override;
};

class LimitOrderFactory : public OrderFactory {
public:
    	std::unique_ptr<Order> createOrder(int, double, int) override;
};

class OrderMatchingStrategy {
public:
    	virtual void matchOrders(std::vector<std::shared_ptr<Order>>&, std::vector<std::shared_ptr<Order>>&) = 0;
    	virtual ~OrderMatchingStrategy();
};

class PriceTimeOrderMatchingStrategy : public OrderMatchingStrategy {
public:
    	void matchOrders(std::vector<std::shared_ptr<Order>>&, std::vector<std::shared_ptr<Order>>&) override;
};

} // StockTradingSystem

#endif // STOCK_TRADING_SYSTEM_ORDER_H
