// Copyright 2018 Your Name <your_email>

#include <header.hpp>
#include <string>
#include <thread>

static const std::string endOfHash = "0000";

void Hash::hashMake() {

    while (true)
    {
        std::string randStringHash = std::to_string(std::rand());
        std::string hashOfRandString = picosha2::hash256_hex_string(randStringHash);

        if (hashOfRandString.substr(hashOfRandString.size() - endOfHash.size()) == endOfHash){

            BOOST_LOG_TRIVIAL(info)        << "Found correct value '"  << randStringHash
                                           << "' with hash '"          << hashOfRandString
                                           << "'";
        }
        else
        {
            BOOST_LOG_TRIVIAL(trace)       << "Thread with ID: "       << std::this_thread::get_id()
                                           << " uncorrect value '"    << randStringHash
                                           << "' with hash '"          << hashOfRandString
                                           << "'";
        }
    }
}