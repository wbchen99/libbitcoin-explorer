/**
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
#ifndef SX_STEALTH_ADDR_HPP
#define SX_STEALTH_ADDR_HPP

#include <stdint.h>
#include <string>
#include <vector>
#include <boost/program_options.hpp>
#include <sx/command.hpp>
#include <sx/generated.hpp>
#include <sx/utility/compat.hpp>
#include <sx/utility/config.hpp>
#include <sx/utility/console.hpp>

/********* GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY **********/

namespace sx {
namespace extensions {

/**
 * Class to implement the sx stealth-addr command.
 */
class stealth_addr 
    : public command
{
public:

    /**
     * The symbolic (not localizable) command name, lower case.
     */
    static const char* symbol() { return "stealth-addr"; }

    /**
     * The member symbolic (not localizable) command name, lower case.
     */
    const char* name()
    {
        return stealth_addr::symbol();
    }

    /**
     * The localizable command category name, upper case.
     */
    const char* category()
    {
        return "OFFLINE KEYS AND ADDRESSES";
    }

    /**
     * The localizable command subcategory name, upper case.
     */
    const char* subcategory()
    {
        return "STEALTH";
    }

    /**
     * The localizable command description, multiple lines, punctuated.
     */
    const std::vector<const char*> description()
    {
        return
        {
        };
    }

    /**
     * The non-localizable command usage examples, multiple lines.
     */
    const std::vector<const char*> example()
    {
        return
        {
        };
    }

    /**
     * The localizable command explanation, multiple lines, punctuated.
     */
    const std::vector<const char*> explanation()
    {
        return
        {
        };
    }
    
    /**
     * Load program argument definitions.
     * A value of -1 indicates that the number of instances is unlimited.
     *
     * @param[out] definitions  The defined program argument definitions.
     */
    void load_arguments(
        boost::program_options::positional_options_description& definitions)
    {
        definitions.add("SCAN_PUBKEY", 1);
        definitions.add("SPEND_PUBKEY", -1);
    }
    
    /**
     * Load program option definitions.
     * The implicit_value call allows flags to be strongly-typed on read while
     * allowing but not requiring a value on the command line for the option.
     *
     * BUGBUG: see boost bug/fix: svn.boost.org/trac/boost/ticket/8009
     *
     * @param[out] definitions  The defined program option definitions.
     */
    void load_options(
        boost::program_options::options_description& definitions)
    {
        using namespace boost::program_options;
        definitions.add_options()
            (
                SX_VARIABLE_CONFIG ",c",
                value<boost::filesystem::path>(),                 
                "The path and file name for the configuration settings file for this application."
            )
            (
                "help,h",
                value<bool>(&option.help)->implicit_value(true),
                "Generate a stealth address from given input."
            )
            (
                "reuse-key,r",
                value<bool>(&option.reuse_key)->implicit_value(true),
                "Reuse the SCAN_PUBKEY as a SPEND_PUBKEY."
            )
            (
                "signatures,s",
                value<uint8_t>(&option.signatures),
                "Specify the number of signatures needed. Defaults to the number of SPEND_PUBKEYs provided."
            )
            (
                "SCAN_PUBKEY",
                value<std::string>(&argument.scan_pubkey)->required(),
                "The public key of the recipient."
            )
            (
                "SPEND_PUBKEY",
                value<std::vector<std::string>>(&argument.spend_pubkeys),
                "The public key that is spent to."
            );
    }   

    /**
     * Invoke the command.
     *
     * @return  The appropriate console return code { -1, 0, 1 }.
     */
    console_result invoke();
    
protected:

    /**
     * Command line argument bound variables.
     */
    struct
    {
        std::string scan_pubkey;
        std::vector<std::string> spend_pubkeys;
    } argument;
    
    /**
     * Command line option bound variables.
     */
    struct
    {
        bool help;
        bool reuse_key;
        uint8_t signatures;
    } option;
};

} // extensions
} // sx

#endif