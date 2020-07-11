#include "../include/defines.hpp"
#include "../include/kitty.hpp"

void print_hello(std::ostream & os) {
    os << "\t\t    __      _    __     __          \n";
    os << "\t\t   / /__   (_)  / /_   / /_   __  __\n";
    os << "\t\t  / //_/  / /  / __/  / __/  / / / /\n";
    os << "\t\t / ,<    / /  / /_   / /_   / /_/ / \n";
    os << "\t\t/_/|_|  /_/   \\__/   \\__/   \\__, /  \n";
    os << "\t\t                           /____/   \n\n";

    os << "                   ___\n";
    os << "   /\\__/\\         / _/\t\tVersion : " << str_version << '\n';
    os << "  | @  @ |       / /\n";
    os << "   \\_*__/_______/ /\t\tDeveloper : KonstantIMP (Mikhedov Konstantin)\n";
    os << "    |            |\t\tFeedback email : mihedovkos@gmail.com\n";
    os << "     \\__________/\n";
    os << "      | |    | |\t\tUse \"kitty -h\" to view help message\n";
    os << " ######################\t\tEnjoy using!\n\n";
}

void print_help(std::ostream & os) {
    os << "KITTY : Version " << str_version << "\n\n";

    os << "kitty is a simple, but powerful password generator\n\n";

    os << "HELP MANUAL :\n\n";
    os << "[USAGE]\n\tkitty [OPTIONS]\n\n";

    os << "[OPTIONS]\n";
    os << "\t-d\tView debug output\n";
    os << "\t-h\tShow this help text and exit\n";
    os << "\t-v\tShow program version and exit\n";
    os << "\t-c [N]\tGenerate N passwords\n";
    os << "\t-l [N]\tSet the generated passwords length as N\n";
    os << "\t-o [F]\tSet an output file as F\n";
    os << "\t-p [P]\tSet the generated passwords parameters as P\n\n";

    os << "[PASSWORDS PARAMETRS]\n";
    os << "\tTo create a parameter string, use the \"Logical OR\"\n\t\t operation with the necessary parameter codes\n\n";

    os << "\t[PARAMETR CODES]\n";
    os << "\t\tUPPERCAS : 0b00000001\n";
    os << "\t\tLOWERCAS : 0b00000010\n";
    os << "\t\tNUMERAL  : 0b00000100\n";
    os << "\t\tSPECIAL  : 0b00001000\n\n";

    os << "END\n";
}
