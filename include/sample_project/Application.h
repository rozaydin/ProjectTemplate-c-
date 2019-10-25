//
// Created by rozaydin on 10/25/19.
//

#ifndef SAMPLE_PROJECT_APPLICATION_H
#define SAMPLE_PROJECT_APPLICATION_H

// C++ standard libs
#include <iostream>
#include <string>

// Boost Logging
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

// Application specific
#include "Banner.h"
#include "Version.h"

// initializes boost logging

namespace app {

    void initLogging() {

        boost::log::add_common_attributes();

        std::string logFileName{APP_NAME};
        logFileName.append("_%N.log");

        namespace bl = boost::log;
        boost::log::add_file_log
                (
                        bl::keywords::file_name = logFileName,
                        bl::keywords::rotation_size = 10 * 1024 * 1024,
                        bl::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
                        bl::keywords::format = "[%TimeStamp%] : %Message%"
                );

        // logging filters
        boost::log::core::get()->set_filter
                (
                        boost::log::trivial::severity >= boost::log::trivial::info
                );
    }

}


#endif //SAMPLE_PROJECT_APPLICATION_H