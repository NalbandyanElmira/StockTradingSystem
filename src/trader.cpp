#include "../include/trader.h"

#include <iostream>

using namespace StockTradingSystem;

TraderException::TraderException(const std::string& mess) 
    	: message(mess) 
{
}

const char* TraderException::what() const noexcept
{ 
    	return message.c_str(); 
}

int Trader::id_counter = 0;

Trader::Trader()
	: name{""}
	, id{id_counter++}
	, orderFactory{nullptr}
	, orderBook{nullptr}
{
}

Trader::Trader(const std::string& n)
    	: name{n}
    	, orderBook{nullptr}
    	, orderFactory{nullptr}
    	, id{id_counter++}
{
}

Trader::Trader(const std::string& n, const std::vector<Stock>& s, OrderFactory* o, OrderBook* b)
    	: id{id_counter++}
    	, name{n}
    	, stocks{s}
    	, orderFactory{o}
    	, orderBook{b}
{
}

void Trader::buy(const StockTradingSystem::Stock& stock, int quantity)
{
    	try
    	{
        	if (orderFactory != nullptr && orderBook != nullptr) {
            		std::shared_ptr<Order> ord = orderFactory->createOrder(id, stock.getPrice(), quantity);
            		orders.push_back(ord);
            		if (ord != nullptr) {
                		orderBook->addOrder(ord);
            		}
        	}
    	}
    	catch (const TraderException& e) {
        	// Handle trader-specific exceptions
        	std::cerr << "Trader Exception: " << e.what() << std::endl;
    	} catch (const std::exception& e) {
        	// Handle other exceptions (if any)
        	std::cerr << "Exception: " << e.what() << std::endl;
    	}
}

void Trader::sell(const StockTradingSystem::Stock& stock, int quantity)
{
    	try
    	{
        	if (orderFactory != nullptr && orderBook != nullptr) {
            		std::shared_ptr<Order> ord = orderFactory->createOrder(id, -stock.getPrice(), quantity);
            		orders.push_back(ord);
            		if (ord != nullptr) {
                		orderBook->addOrder(ord);
            		}
        	} 
    	}
    	catch (const TraderException& e) {
        	// Handle trader-specific exceptions
        	std::cerr << "Trader Exception: " << e.what() << std::endl;
    	} catch (const std::exception& e) {
        	// Handle other exceptions (if any)
        	std::cerr << "Exception: " << e.what() << std::endl;
    	}
}

void Trader::trade(double buyThreshold, double sellThreshold, int buyQuantity, int sellQuantity)
{
	// Buy when the stock price is lower than a threshold and sell when it's higher
    
    	for (const Stock& stock : stocks) {
        	if (stock.getPrice() < buyThreshold) {
            		// Buy the stock with a fixed quantity (e.g., 100 shares)
            		buy(stock, buyQuantity);
        	} else if (stock.getPrice() > sellThreshold) {
            		// Sell the stock with a fixed quantity (e.g., 50 shares)
            		sell(stock, sellQuantity);
        	}
    	}
}

int Trader::getID() const
{
	return id;
}

const std::vector<std::shared_ptr<Order>>& Trader::getOrders() const {
    	return orders;
}

void Trader::addStock(const Stock& st)
{
    	stocks.push_back(st);
}

std::vector<Stock> Trader::getStocks() const
{
    	return stocks;
}

Trader::~Trader()
{
    	delete orderFactory;
    	delete orderBook;
}
