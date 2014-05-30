/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SX_GENERATED_HPP
#define SX_GENERATED_HPP

#include <functional>
#include <memory>
#include <string>
#include <sx/command.hpp>

/* TODO: GSL Code generation */
#include <sx/command/wallet.hpp>
//#include <sx/command/wallet.hpp>
//#include <sx/command/wallet.hpp>

/********** WARNING: This file is generated, do not edit directly. **********/

namespace sx {
namespace extensions {

/**
 * Find the command identified by the specified symbolic command name.
 *
 * @param symbol the symbolic command name.
 * @return An instance of the command or nullptr if not found.
 */
std::shared_ptr<command> find(const char* symbol);

/**
 * Invoke a specified function on all commands.
 *
 * @param the function to invoke on all commands.
 * @return True if invoked successfully, otherwise false.
 */
bool broadcast(std::function<void(std::shared_ptr<command>)> func);

}
}

#endif