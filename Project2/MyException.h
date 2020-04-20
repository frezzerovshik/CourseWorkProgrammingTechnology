#pragma once

#define WRONG_SPORTS 1
#define WRONG_COUNTRY 2
#define EMPTY_FILE 3
#define WRONG_ANSWER 4
#define WRONG_VALUE 5


typedef int CodeOfError;

class MyException {
public:
    CodeOfError wrongSports();
    CodeOfError wrongCountry();
    CodeOfError emptyFile();
    CodeOfError wrongAnswer();
    CodeOfError wrongValue();
};
