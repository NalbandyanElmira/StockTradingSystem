cmake_minimum_required(VERSION 3.12)

project(StockTradingSystem)

# Add source files
add_executable(my_app main.cpp src/order.cpp src/orderBook.cpp src/stock.cpp src/trader.cpp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Specify additional libraries or dependencies
target_link_libraries(my_app PRIVATE pthread)

# Install target (optional)
# install(TARGETS my_app DESTINATION bin)
