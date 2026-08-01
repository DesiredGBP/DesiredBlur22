#include "license_auth.h"

#include <iostream>
#include <string>

#include "auth.hpp"
#include "skStr.h"

namespace {

std::string name = skCrypt("Desired Blur").decrypt();
std::string ownerid = skCrypt("ujZfgqWv4j").decrypt();
std::string version = skCrypt("2.0").decrypt();
std::string url = skCrypt("https://keyauth.win/api/1.3/").decrypt();
std::string path = skCrypt("").decrypt();

KeyAuth::api KeyAuthApp(name, ownerid, version, url, path);

}

namespace licensing {

bool authenticate()
{
    KeyAuthApp.init();

    if (!KeyAuthApp.response.success) {
        std::cerr << "KeyAuth initialization failed: "
                  << KeyAuthApp.response.message << '\n';
        return false;
    }

    std::cout << "Enter license key: ";

    std::string key;
    std::getline(std::cin, key);

    if (key.empty()) {
        std::cerr << "No license key entered.\n";
        return false;
    }

    KeyAuthApp.license(key);

    if (!KeyAuthApp.response.success) {
        std::cerr << "License rejected: "
                  << KeyAuthApp.response.message << '\n';
        return false;
    }

    return true;
}

}
