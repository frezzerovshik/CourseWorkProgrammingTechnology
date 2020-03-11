//
//  Sportsman.hpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 11.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#pragma once
#include "Country.h"
#include "Sports.h"
#include <string>

class Sportsman {
public:
    Country whereFrom;
    Sports kindOfSports;
    std::string name;
    unsigned int strenght;
    unsigned int agility;
    unsigned int luck;
    unsigned int stamina;
};
