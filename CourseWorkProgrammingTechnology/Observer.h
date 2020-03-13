//
//  Observer.h
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 11.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#pragma once
class Notify;

class Observer {
public:
    virtual void update(Notify newNotify) = 0;
};
