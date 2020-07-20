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

#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <cstddef>
#include <string>

const std::size_t major_ver{1};
const std::size_t minor_ver{0};
const std::size_t build_ver{2};

const std::string str_version = std::to_string(major_ver) + '.' + std::to_string(minor_ver) + '.' +
                                std::to_string(build_ver) + " (build " + std::to_string(build_ver) + ")";

#endif // DEFINES_HPP
