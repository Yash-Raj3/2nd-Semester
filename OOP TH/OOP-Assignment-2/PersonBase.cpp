#include "PersonBase.h"

PersonBase::PersonBase() : userID(0), name("Unknown") {}

PersonBase::PersonBase(int id, const std::string &n) : userID(id), name(n) {}

PersonBase::~PersonBase() {}
