#include "../include/order.h"

#include <algorithm>
#include <stdexcept>

using namespace StockTradingSystem;

Order::Order(int id, double p, int q)
	: traider_id{id}
	, price{p}
	, quantity{q}
{
}

Order::~Order() 
{
}

int Order::getTraider_id() const
{
	return traider_id;
}

double Order::getPrice() const
{
	return price;
}

int Order::getQuantity() const
{
	return quantity;
}

std::time_t Order::getTimestamp() const
{
	return timestamp;
}

void Order::reduceQuantity(int amount)
{
	if (amount > 0 && amount <= quantity)
    	{
		quantity -= amount;
    	}
    	else
    	{
        	throw std::out_of_range{"Amount out of range."};
    	}
}

OrderType Order::getOrdertype() const {
    	return ordertype;
}

void Order::setOrderType(OrderType type) {
    	ordertype = type;
}

std::string MarketOrder::getOrderType() const
{
	return "Market Order";
}

std::string LimitOrder::getOrderType() const
{
	return "Limit Order";
}

OrderFactory::~OrderFactory()
{
}

std::unique_ptr<Order> MarketOrderFactory::createOrder(int trader_id, double price, int quantity) {
    	return std::make_unique<MarketOrder>(trader_id, price, quantity);
}

std::unique_ptr<Order> LimitOrderFactory::createOrder(int trader_id, double price, int quantity) {
    	return std::make_unique<LimitOrder>(trader_id, price, quantity);
}

OrderMatchingStrategy::~OrderMatchingStrategy()
{
}

void PriceTimeOrderMatchingStrategy::matchOrders(std::vector<std::shared_ptr<Order>>& buyOrders, std::vector<std::shared_ptr<Order>>& sellOrders) {
    	std::vector<std::shared_ptr<Order>> matchedOrders;

    	for (auto sellOrder = sellOrders.begin(); sellOrder != sellOrders.end(); ++sellOrder) {
        	for (auto it = buyOrders.begin(); it != buyOrders.end();) {
            		if ((*sellOrder)->getPrice() <= (*it)->getPrice()) {
                		matchedOrders.push_back(*it);
                		it = buyOrders.erase(it); // Remove the matched buy order
            		} else {
                		++it;
            		}
        	}
    	}

    	// Update the buyOrders vector with remaining unmatched orders
    	buyOrders.insert(buyOrders.end(), matchedOrders.begin(), matchedOrders.end());
}
