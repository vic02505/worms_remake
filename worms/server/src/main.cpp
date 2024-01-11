#include <iostream>
#include "../include/Server.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cout << "Error: invalid arguments. To run it properly set a port" << std::endl;
        return 1;
    }
    try {
        Server server(argv[1]);
        server.start();
        while (std::cin.get() != 'q') {}
        server.stop();
        server.join();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return 1;
    }
}
