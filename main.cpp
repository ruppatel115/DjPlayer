#include <iostream>
#include "Song.h"

int main() {
    Song songtest("title1","artist1","year1",180);
    std::cout << songtest.toString();
    return 0;
}