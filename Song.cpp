//
// Created by Elias on 11/18/2019.
//
#include "Song.h"

Song::Song(std::string titleIn, std::string artistIn, std::string yearIn, int lengthInSecIn) {
    title = titleIn;
    artist = artistIn;
    year = yearIn;
    lengthInSec = lengthInSecIn;
}

std::string Song::toString() {
    std::string result;
    result+=this->title + ",";
    result+=this->artist + ",";
    result+=this->year + ",";
    result+=std::to_string(lengthInSec);

    return result;

}
