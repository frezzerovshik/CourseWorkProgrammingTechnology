//
//  MyException.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 18.04.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#include "MyException.h"

CodeOfError MyException::wrongSports() {
    return WRONG_SPORTS;
}

CodeOfError MyException::wrongCountry() {
    return WRONG_COUNTRY;
}

CodeOfError MyException::emptyFile() {
    return EMPTY_FILE;
}

CodeOfError MyException::wrongAnswer() {
    return WRONG_ANSWER;
}

CodeOfError MyException::wrongValue() {
    return WRONG_VALUE;
}
