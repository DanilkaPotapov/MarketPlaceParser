cmake_minimum_required(VERSION 3.10)
project(TelegramBot)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify target architecture if necessary
set(CMAKE_OSX_ARCHITECTURES "arm64" CACHE STRING "Target architecture")

# Find required libraries
find_package(Boost REQUIRED COMPONENTS system filesystem)
find_package(OpenSSL REQUIRED)
find_package(CURL REQUIRED)

# Include directories for headers
include_directories(/opt/homebrew/include)  # Path to Boost and other headers
include_directories(${CMAKE_SOURCE_DIR}/tgbot-cpp/include)  # Path to tgbot headers

# Link directories for libraries
link_directories(/opt/homebrew/lib)  # Path to system libraries
link_directories(${CMAKE_SOURCE_DIR}/tgbot-cpp/lib)  # Path to libTgBot.a

# Define source files
set(SOURCES
    main.cpp
    parser.cpp
)

# Create executable
add_executable(bot ${SOURCES})

# Link libraries
target_link_libraries(bot
    PRIVATE
    ${CMAKE_SOURCE_DIR}/tgbot-cpp/lib/libTgBot.a  # Explicitly link libTgBot.a
    ${Boost_LIBRARIES}
    ${OPENSSL_LIBRARIES}
    ${CURL_LIBRARIES}
    pthread
)