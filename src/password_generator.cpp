#include "../include/password_generator.hpp"

std::array<char, 26> uppercase {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                                'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                                'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

std::array<char, 26> lowercase {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                                's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

std::array<char, 10> numeral {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

std::array<char, 22> special {'.', ',', '|', '\\', '/', '\'', '\"', '!', '@', ':', '^',
                              '#', '$', '%', '&', '?', '-', '+', '=', '~', ';', '*'};

password_generator::password_generator() : p_length(16), p_opt(0b00001111), passwd("") {}

void password_generator::set_length(const std::size_t & length) {
    if(length == 0) throw std::invalid_argument("Password can't exist from no one character");
    p_length = length;
}

std::size_t password_generator::get_length() const {
    return p_length;
}

void password_generator::set_options(const unsigned char & opt) {
    if(opt == 0) throw std::invalid_argument("Password can't exist from no one character");
    p_opt = opt;
}

unsigned char password_generator::get_options() const {
    return p_opt;
}

bool password_generator::set_option(const password_option & opt, const bool & value) {
    if(value) p_opt = p_opt | opt;
    else p_opt = p_opt & (~opt);

    return (get_option(opt) == value);
}

bool password_generator::get_option(const password_option & opt) const {
    return static_cast<bool>(p_opt & opt);
}

bool password_generator::gen_passwd(const bool & debug) {
    if(debug) std::clog << "[DEBUG] Generation start\n\n";

    if(debug) std::clog << "[DEBUG] Passwords length is " << p_length << "\n\n";

    if(debug && p_length < 8) std::clog << "[WARNING] We recommend 8 as the minimum password length!\n\n";

    if(debug) {
        std::clog << "[DEBUG] Passwords options analisys :\n";
        std::clog << "\tUsing uppercase characters : " << (get_option(UPPERCASE) ? "YES" : "NO") << '\n';
        std::clog << "\tUsing lowercase characters : " << (get_option(LOWERCASE) ? "YES" : "NO") << '\n';
        std::clog << "\tUsing numeral characters  :  " << (get_option(NUMERAL) ? "YES" : "NO") << '\n';
        std::clog << "\tUsing special characters  :  " << (get_option(SPECIAL_SYM) ? "YES" : "NO") << "\n\n";
    }

    std::size_t min_length = 0; passwd = "";
    if(get_option(UPPERCASE)) min_length++;
    if(get_option(LOWERCASE)) min_length++;
    if(get_option(NUMERAL)) min_length++;
    if(get_option(SPECIAL_SYM)) min_length++;

    if(min_length == 0) {
        throw std::logic_error("Password can't exist from no one character");
        return false;
    }

    if(debug) {
        std::clog << "[DEBUG] Using symbols analysis : \n";

        if(get_option(UPPERCASE)) {
            std::clog <<"\tUppercase    : \t ";

            for(std::size_t i{0}; i < uppercase.size(); i++) {
                if(i == 9 || i == 18) std::clog << "\t\t\t ";
                std::clog << '\'' << uppercase[i] << '\'';
                if(i < (uppercase.size() - 1)) std::clog << ", ";
                if(i == 8 || i == 17) std::clog << '\n';
            }

            std::clog << "\n\n";
        }

        if(get_option(LOWERCASE)) {
            std::clog <<"\tLowercase    : \t ";

            for(std::size_t i{0}; i < lowercase.size(); i++) {
                if(i == 9 || i == 18) std::clog << "\t\t\t ";
                std::clog << '\'' << lowercase[i] << '\'';
                if(i < (lowercase.size() - 1)) std::clog << ", ";
                if(i == 8 || i == 17) std::clog << '\n';
            }

            std::clog << "\n\n";
        }

        if(get_option(NUMERAL)) {
            std::clog << "\tNumeral  :  ";
            for(std::size_t i{0}; i < numeral.size(); i++) {
                std::clog << '\'' << numeral[i] << '\'';
                if(i != (numeral.size() - 1)) std::clog << ", ";
            }

            std::clog << "\n\n";
        }

        if(get_option(SPECIAL_SYM)) {
            std::clog << "\tSpecial  :  ";
            for(std::size_t i{0}; i < special.size(); i++) {
                if(i == 10 || i == 20) std::clog << "\n\t\t    ";
                std::clog << '\'' << special[i] << '\'';
                if(i != (special.size() - 1)) std::clog << ", ";
            }

            std::clog << "\n\n";
        }
    }

    if(debug) std::clog << "[DEBUG] Minimum passwords length is " << min_length << "\n\n";

    if(p_length < min_length) {
        throw std::runtime_error("Passwords length is too small for your options");
        return false;
    }

    std::size_t up_n = 0, low_n = 0, num_n = 0, spec_n = 0;

    if(debug) std::clog << "[DEBUG] Delay for randomization\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    srand(static_cast<unsigned int>(time(nullptr)));

    if(min_length == 1) {
        if(get_option(UPPERCASE)) up_n = p_length;
        else if(get_option(LOWERCASE)) low_n = p_length;
        else if(get_option(NUMERAL)) num_n = p_length;
        else spec_n = p_length;
    }
    else if(min_length == 2) {
        std::unique_ptr<std::size_t> first{nullptr}, second{nullptr};

        if(get_option(UPPERCASE)) first = std::unique_ptr<std::size_t>{&up_n};
        if(get_option(LOWERCASE)) {
            if(first == nullptr) first = std::unique_ptr<std::size_t>{&low_n};
            else second = std::unique_ptr<std::size_t>{&low_n};
        }
        if(get_option(NUMERAL)) {
            if(first == nullptr) first = std::unique_ptr<std::size_t>{&num_n};
            else second = std::unique_ptr<std::size_t>{&num_n};
        }
        if(get_option(SPECIAL_SYM)) {
            second = std::unique_ptr<std::size_t>{&spec_n};
        }

        (*first) = (static_cast<std::size_t>(rand()) % (p_length - 2)) + 1;
        (*second) = p_length - (*first);

        first.release(); second.release();
    }
    else if(min_length == 3) {
        std::unique_ptr<std::size_t> first{nullptr}, second{nullptr}, third{nullptr};

        if(get_option(UPPERCASE)) first = std::unique_ptr<std::size_t>{&up_n};
        if(get_option(LOWERCASE)) {
            if(first == nullptr) first = std::unique_ptr<std::size_t>{&low_n};
            else second = std::unique_ptr<std::size_t>{&low_n};
        }
        if(get_option(NUMERAL)) {
            if(second == nullptr) second = std::unique_ptr<std::size_t>{&num_n};
            else third = std::unique_ptr<std::size_t>{&num_n};
        }
        else third = std::unique_ptr<std::size_t>{&spec_n};

        (*first) = (static_cast<std::size_t>(rand()) % (p_length - 3)) + 1;
        (*second) = (static_cast<std::size_t>(rand()) % (p_length - 2 - *first)) + 1;
        (*third) = p_length - ((*first) + (*second));

        first.release(); second.release(); third.release();
    }
    else {
        up_n = (static_cast<std::size_t>(rand()) % (p_length - 4)) + 1;
        low_n = (static_cast<std::size_t>(rand()) % (p_length - up_n - 3)) + 1;
        num_n = (static_cast<std::size_t>(rand()) % (p_length - up_n - low_n - 2)) + 1;
        spec_n = p_length - (up_n + low_n + num_n);
    }

    if(debug) {
        std::clog << "[DEBUG] Passwords characters datagramm\n";

        float up_p = (static_cast<float>(up_n) / static_cast<float>(p_length)) * 100;
        float low_p = (static_cast<float>(low_n) / static_cast<float>(p_length)) * 100;
        float num_p = (static_cast<float>(num_n) / static_cast<float>(p_length)) * 100;
        float spec_p = (static_cast<float>(spec_n) / static_cast<float>(p_length)) * 100;

        std::string tmp = "";
        for(std::size_t i{0}; i < static_cast<std::size_t>(up_p / 4); i++) tmp += '#';
        while(tmp.length() != 25) tmp += '_';
        std::clog << "\t|" << tmp << "| - " << up_p << "% \tuppercase characters (" << up_n << ")\n";

        tmp = "";
        for(std::size_t i{0}; i < static_cast<std::size_t>(low_p / 4); i++) tmp += '#';
        while(tmp.length() != 25) tmp += '_';
        std::clog << "\t|" << tmp << "| - " << low_p << "% \tlowercase characters (" << low_n << ")\n";

        tmp = "";
        for(std::size_t i{0}; i < static_cast<std::size_t>(num_p / 4); i++) tmp += '#';
        while(tmp.length() != 25) tmp += '_';
        std::clog << "\t|" << tmp << "| - " << num_p << "% \tnumeral characters (" << num_n << ")\n";

        tmp = "";
        for(std::size_t i{0}; i < static_cast<std::size_t>(spec_p / 4); i++) tmp += '#';
        while(tmp.length() != 25) tmp += '_';
        std::clog << "\t|" << tmp << "| - " << spec_p << "% \tspecial characters (" << spec_n << ")\n";

        std::clog << '\n';
    }

    passwd = "";

    for(std::size_t i{0}; i < up_n; i++) passwd += uppercase[static_cast<std::size_t>(rand()) % uppercase.size()];
    for(std::size_t i{0}; i < low_n; i++) passwd += lowercase[static_cast<std::size_t>(rand()) % lowercase.size()];
    for(std::size_t i{0}; i < num_n; i++) passwd += numeral[static_cast<std::size_t>(rand()) % numeral.size()];
    for(std::size_t i{0}; i < spec_n; i++) passwd += special[static_cast<std::size_t>(rand()) % special.size()];

    if(debug) std::clog << "[DEBUG] First password generation : " << passwd << "\n\n";

    if(debug) std::clog << "[DEBUG] Password shuffle (10000 times)\n";
    for(std::size_t i{0}; i < 10000; i++) {
        std::random_shuffle(passwd.begin(), passwd.end());
        if(debug) std::clog << "\tDone : " << i + 1 << " times\r";
    }
    if(debug) {
        std::clog << "\n\n[DEBUG] Result password : ";
        for(std::size_t i{0}; i < p_length; i++) std::clog << '*';
        std::clog << "\n";
    }

    return true;
}

std::string password_generator::get_passwd() const {
    if(passwd == "") throw std::runtime_error("The password has not been generated yet");
    return passwd;
}

void password_generator::reset() {
    p_opt = 0b00001111;
    p_length = 16;
    passwd = "";
}
