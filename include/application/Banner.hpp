#pragma once

#include <fstream>
#include <sstream>
#include "Version.hpp"

namespace Misc {

    class Banner {

    public:
        // methods

        static const std::string loadBannerTextFromFile(const std::string &bannerFilePath) {
            // load banner from file
            std::ifstream t(bannerFilePath);
            std::stringstream buffer;
            buffer << t.rdbuf();
            // format banner text with vars from Version.h APP_NAME and APP_VERSION
            return formatBanner(buffer.str(), APP_NAME, APP_VERSION);
        }

        static const std::string formatBanner(std::string&& bannerText, std::string appName, std::string appVersion) {
            // temp vars to replace
            const std::string appNamePlaceHoder = "${APP_NAME}";
            const std::string appVersionPlaceHolder = "${APP_VERSION}";

            // replace version place holder with version string
            const auto indexOfAppVersionStr = bannerText.find(appVersionPlaceHolder, 0);
            bannerText.replace(indexOfAppVersionStr, appVersionPlaceHolder.size(), appVersion);

            // replace appName place holder with appName string
            const auto indexOfAppNameStr = bannerText.find(appNamePlaceHoder, 0);
            bannerText.replace(indexOfAppNameStr, appNamePlaceHoder.size(), appName);

            // return formatted banner
            return bannerText;
        }

    };
}