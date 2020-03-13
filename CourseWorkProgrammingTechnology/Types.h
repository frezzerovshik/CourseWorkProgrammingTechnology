//
//  Types.h
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 12.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#pragma once
#include <string>

class Notify {
public:
    std::string country;
    std::string sport;
    std::string place;
};

class Shell {
public:
    Observer* observerObject;
    Country choosenCountry;
    Sports choosenSport;
};

