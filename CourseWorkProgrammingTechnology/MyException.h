#pragma once

#define WRONG_SPORTS 1
#define WRONG_COUNTRY 2
#define EMPTY_FILE 3

typedef int CodeOfError;

class MyException {
public:
    CodeOfError wrongSports();
    CodeOfError wrongCountry();
    CodeOfError emptyFile();
};
