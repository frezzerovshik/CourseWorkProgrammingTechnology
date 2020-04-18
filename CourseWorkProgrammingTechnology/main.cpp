//
//  main.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 10.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#include <iostream>
#include "Games.hpp"
#include "User.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	bool flag = true;
	while (flag) {
		Games* olympicGames = new Games;
		User user(olympicGames);
		olympicGames->competitions();
		cout << "Stop?" << endl;
		char c;
		cin >> c;
		if (c == '1')
			break;
	}
    return 0;
}
