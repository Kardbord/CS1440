//
// Created by Stephen Clyde on 3/4/17.
//

#ifndef GEO_REGIONS_STATE_H
#define GEO_REGIONS_STATE_H

#include "Region.h"

#include <string>

// TODO: Implement States having cities and counties
class State : public Region {
public:
    State(const std::string data[]);
};

#endif //GEO_REGIONS_STATE_H
