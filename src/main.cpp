#include <iostream>
#include <stdexcept>
#include <memory>

#include "minecraft/mc.hpp"

int main(int argc, const char** argv) {
    try {
        std::unique_ptr<MC> mc = std::make_unique<MC>();
        mc->Run();

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::cin.get();
    }

    std::cin.get();
    return 0;
}