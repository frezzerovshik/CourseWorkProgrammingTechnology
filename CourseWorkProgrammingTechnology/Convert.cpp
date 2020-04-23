//
//  Convert.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 23.04.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#include "Convert.hpp"
#include "MyException.h"

using namespace std;

string countryToString(Country country) {
    switch (country) {
    case Country::Russia:
        return "России";
    case Country::Japan:
        return "Японии";
    case Country::France:
        return "Франции";
    case Country::Finland:
        return "Финляндии";
    case Country::Canada:
        return "Канады";
    default:
        break;
    }
    MyException exception;
    throw exception.wrongCountry();
}

string sportsToString(Sports sport) {
    switch (sport) {
    case Sports::Biatlon:
        return "биатлону";
        break;
    case Sports::Skeleton:
        return "скелетону";
        break;
    case Sports::Skies:
        return "конькобежному спорту";
        break;
    case Sports::FigureSkiing:
        return "фигурному катанию";
        break;
    default:
        break;
    }
    MyException exception;
    throw exception.wrongSports();
}
