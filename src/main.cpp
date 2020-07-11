#include "../include/password_generator.hpp"
#include "../include/defines.hpp"
#include "../include/kitty.hpp"

int main(int argc, char * argv[]) {
    print_hello(std::cout);

    if(argc == 1) return 0;

    for(std::size_t i{1}; i < static_cast<std::size_t>(argc); i++) {
        if(std::string(argv[i]) == "-h") {
            print_help(std::cout);
            return 0;
        }
    }

    return 0;
}
