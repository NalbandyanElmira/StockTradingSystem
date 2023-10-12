#include "../include/orderBook.h"

#include <iostream>

using namespace StockTradingSystem;

OrderBook::OrderBook() : strategy(nullptr)
{
}

void OrderBook::addOrder(std::shared_ptr<Order> order)
{
    book.push_back(order);
}

void OrderBook::matchOrders() {
    std::vector<std::shared_ptr<Order>> buyOrders;
    std::vector<std::shared_ptr<Order>> sellOrders;

    // Create vectors of shared pointers to orders
    for (const auto& order : book) {
        if (order->getPrice() > 0) {
            buyOrders.push_back(std::static_pointer_cast<Order>(order));
        } else {
            sellOrders.push_back(std::static_pointer_cast<Order>(order));
        }
    }

    // Call the matching strategy with the separated buy and sell order vectors
    strategy->matchOrders(buyOrders, sellOrders);

    // Update the order book with remaining orders
    book.clear();
    book.insert(book.end(), buyOrders.begin(), buyOrders.end());
    book.insert(book.end(), sellOrders.begin(), sellOrders.end());
}

void OrderBook::printOrderBook() const
{
    std::cout << "Order Book content...\n";
    std::cout << "ID\tPrice\tQuantity\tOrder Type\n";
    for (const auto& order : book)
    {
        std::string orderTypeName = (order->getOrdertype() == OrderType::BUY) ? "Buy" : "Sell";
        std::cout << order->getTraider_id() << "\t" << order->getPrice() << "\t" <<
            order->getQuantity() << "\t\t" << orderTypeName << "\n";
    }
    std::cout << "\n";
}


void OrderBook::setStrategy(OrderMatchingStrategy* s)
{
    strategy = s;
}