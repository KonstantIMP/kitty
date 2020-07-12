//Copyright 2020 KonstantIMP
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

#include "../include/password_generator.hpp"
#include "../include/defines.hpp"
#include "../include/kitty.hpp"

#include <fstream>
#include <list>

int main(int argc, char * argv[]) {
    print_hello(std::cout);

    bool debug = false, f_out = false;
    unsigned char opt = 0b00001111;
    std::size_t length = 16;
    std::size_t num = 1;

    std::fstream fout;

    for(std::size_t i{1}; i < static_cast<std::size_t>(argc); i++) {
        if(std::string(argv[i]) == "-h") {
            print_help(std::cout);
            return 0;
        }
        if(std::string(argv[i]) == "-v") {
            std::cout << "Version : " << str_version << "\n";
            return 0;
        }
        if(std::string(argv[i]) == "-d") {
            if(debug) {
                std::cout << "[ERROR #130] Incorrect command line argument and logical errors\n";
                std::cout << "\twhat() : twice \'-d\' flag\n";
                return 130;
            }
            debug = true;
            continue;
        }
        if(std::string(argv[i]) == "-l") {
            if((i + 1) == static_cast<std::size_t>(argc)) {
                std::cout << "[ERROR #13] Incorrect command line arguments\n";
                std::cout << "\twhat() : too few arguments\n";
                return 13;
            }

            try {
                length = static_cast<std::size_t>(std::stoi(argv[i + 1]));
            }  catch (std::invalid_argument e) {
                std::cout << "[ERROR #10] Incorrect command line arguments\n";
                std::cout << "\twhat() : " << e.what() << " [can't translate string to number]\n";
                return 10;
            }  catch (std::out_of_range e) {
                std::cout << "[ERROR #20] Incorrect command line argument\n";
                std::cout << "\twhat() : " << e.what() << " [number is too big]\n";
                return 20;
            }

            i++; continue;
        }
        if(std::string(argv[i]) == "-o") {
            if((i + 1) == static_cast<std::size_t>(argc)) {
                std::cout << "[ERROR #14] Incorrect command line arguments\n";
                std::cout << "\twhat() : too few arguments\n";
                return 14;
            }

            if(f_out) {
                std::cout << "[ERROR #131] Incorrect command line argument and logical errors\n";
                std::cout << "\twhat() : you can use only one output file\n";
                return 131;
            }

            try {
                fout.open(std::string(argv[i + 1]), std::ios_base::out | std::ios_base::app);
                if(!fout.is_open()) throw std::ios_base::failure("std::ofstream::open");
            }  catch (std::ios_base::failure e) {
                std::cout << "[ERROR #40] Runtime error\n";
                std::cout << "\twhat() : " << e.what() << " [can't open or create \'" << std::string(argv[i + 1]) << "\']\n";
                return 40;
            }

            f_out = true; i++;
            continue;
        }
        if(std::string(argv[i]) == "-c") {
            if(num != 1) {
                std::cout << "[ERROR #132] Incorrect command line argument and logical errors\n";
                std::cout << "\twhat() : twice \'-c\' option\n";
                return 132;
            }
            if((i + 1) == static_cast<std::size_t>(argc)) {
                std::cout << "[ERROR #15] Incorrect command line arguments\n";
                std::cout << "\twhat() : too few arguments\n";
                return 15;
            }

            try {
                num = static_cast<std::size_t>(std::stoi(argv[i + 1]));
            }  catch (std::invalid_argument e) {
                std::cout << "[ERROR #11] Incorrect command line argument\n";
                std::cout << "\twhat() : " << e.what() << " [can't translate string to number]\n";
                return 11;
            }  catch (std::out_of_range e) {
                std::cout << "[ERROR #21] Incorrect command line argument\n";
                std::cout << "\twhat() : " << e.what() << " [number is too big]\n";
                return 21;
            }

            i++; continue;
        }
        if(std::string(argv[i]) == "-p") {
            if(opt != 0b00001111) {
                std::cout << "[ERROR #133] Incorrect command line argument and logical errors\n";
                std::cout << "\twhat() : twice \'-p\' option\n";
                return 133;
            }
            if((i + 1) == static_cast<std::size_t>(argc)) {
                std::cout << "[ERROR #16] Incorrect command line arguments\n";
                std::cout << "\twhat() : too few arguments\n";
                return 16;
            }

            try {
                opt = static_cast<unsigned char>(std::stoi(argv[i + 1], 0, 2));
            }  catch (std::invalid_argument e) {
                std::cout << "[ERROR #12] Incorrect command line argument\n";
                std::cout << "\twhat() : " << e.what() << " [can't translate string to number]\n";
                return 12;
            }  catch (std::out_of_range e) {
                std::cout << "[ERROR #22] Incorrect command line argument\n";
                std::cout << "\twhat() : " << e.what() << " [number is too big]\n";
                return 22;
            }

            i++; continue;
        }
    }

    password_generator gen;

    try {
        gen.set_length(length);
        gen.set_options(opt);
    }  catch (std::invalid_argument e) {
        std::cout << "[ERROR #134] Incorrect command line argument and logical errors\n";
        std::cout << "\twhat() : " << e.what() << '\n';
        return 134;
    }

    std::list<std::string> passwords;

    for(std::size_t i{0}; i < num; i++) {
        gen.gen_passwd(debug);
        try {
            passwords.push_back(gen.get_passwd());
        }  catch (std::bad_alloc e) {
            std::cout << "[ERROR #41] Runtime error\n";
            std::cout << "\twhat() : " << e.what() << " [can't allocate memory foe password storage]\n";
            return 41;
        }  catch (std::runtime_error e) {
            std::cout << "[ERROR #42] Runtime error\n";
            std::cout << "\twhat() : " << e.what() << '\n';
            return 42;
        }
    }

    std::cout << "Result passwords :\n";

    for(auto iter : passwords) {
        std::cout << '\t' << iter << '\n';
        if(f_out) fout << iter << '\n';
    }

    if(f_out) fout.close();

    return 0;
}
