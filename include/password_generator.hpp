#ifndef PASSWORD_GENERATOR_HPP
#define PASSWORD_GENERATOR_HPP

#include <exception>
#include <stdexcept>

#include <algorithm>

#include <iostream>

#include <cstddef>
#include <string>

#include <memory>
#include <array>

#include <chrono>
#include <thread>
#include <ctime>

enum password_option {UPPERCASE = 0b00000001, LOWERCASE = 0b00000010,
                      NUMERAL = 0b00000100, SPECIAL_SYM = 0b00001000};

class password_generator {
public:
    password_generator();

    void set_length(const std::size_t &);
    std::size_t get_length() const;

    void set_options(const unsigned char &);
    unsigned char get_options() const;

    bool set_option(const password_option &, const bool &);
    bool get_option(const password_option &) const;

    bool gen_passwd(const bool & = false);

    std::string get_passwd() const;

    void reset();

private:
    std::size_t p_length;

    unsigned char p_opt;

    std::string passwd;
};

#endif // PASSWORD_GENERATOR_HPP
