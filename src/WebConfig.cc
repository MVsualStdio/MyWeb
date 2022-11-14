
#include "WebConfig.hpp"

using namespace web;

std::ifstream Config::in("./config.json");
const std::string Config::ObjectDir = Config::getCwd();
const std::string Config::SourceDir = Config::ObjectDir + "/static/";
const json Config::data = json::parse(in);

const int Config::port = Config::data["port"].get<int>();
const int Config::numThread = Config::data["numThread"].get<int>();
const int Config::BufferMaxLen = Config::data["BufferMaxLen"].get<int>();