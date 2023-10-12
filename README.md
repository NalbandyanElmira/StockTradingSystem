# StockTradingSystem

## Overview
The Stock Trading System is a C++ application that simulates a stock trading environment. It allows multiple traders to buy and sell stocks and maintains an order book for processing these orders. This README provides an overview of the project, its design, and instructions for running the application.

## Project Structure

The project is organized into several key components:

- **include**: Contains header files for classes and interfaces.
- **src**: Contains the source code for the application.
- **main.cpp**: The entry point of the program.

### Classes
The following key classes are part of the project:

- **Trader**: Represents a trader who can buy and sell stocks.
- **Stock**: Represents a stock with a price and name.
- **Order**: Represents an order placed by a trader (base class).
- **MarketOrder**: Represents a market order that buys or sells at the current market price.
- **LimitOrder**: Represents a limit order with a specified price.
- **OrderFactory**: Creates different types of orders (Market or Limit).
- **OrderMatchingStrategy**: Defines strategies for matching buy and sell orders.
- **PriceTimeOrderMatchingStrategy**: A specific matching strategy based on order prices and timestamps.
- **OrderBook**: Maintains an order book and matches buy/sell orders.
- **OrderMatchingStrategy**: The base class for order matching strategies.

## Design Patterns

The project uses the following design patterns:

- **Factory Method Pattern**: The `OrderFactory` class uses a factory method to create different types of orders (Market or Limit).
- **Strategy Pattern**: The `OrderMatchingStrategy` hierarchy allows for various order matching strategies to be implemented. The `PriceTimeOrderMatchingStrategy` is an example of such a strategy.

## Running the Application

To run the Stock Trading System application, follow these steps:

1. Clone repository.
   
   ```bash
   git clone https://github.com/NalbandyanElmira/StockTradingSystem
   ```

   ```bash
   cd StockTradingSystem/build
   ```
   
   ```bash
   make
   ```
   
2. Execute the compiled binary.
   ```bash
   ./my_app
   ```

3. The application will simulate trading with multiple traders, and the order book will be displayed at the end of the simulation.
