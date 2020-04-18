#pragma once

typedef int CodeOfError;

class MyException {
public:
    CodeOfError wrongSports();
    CodeOfError wrongCountry();
    CodeOfError emptyFile();
};
