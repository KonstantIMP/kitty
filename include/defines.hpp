#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <cstddef>
#include <string>

const std::size_t major_ver{1};
const std::size_t minor_ver{0};
const std::size_t build_ver{1};

const std::string str_version = std::to_string(major_ver) + '.' + std::to_string(minor_ver) + '.' +
                                std::to_string(build_ver) + " (build " + std::to_string(build_ver) + ")";

#endif // DEFINES_HPP
