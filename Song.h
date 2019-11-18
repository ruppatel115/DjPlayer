//
// Created by Elias on 11/18/2019.
//

#ifndef DJPLAYER_SONG_H
#define DJPLAYER_SONG_H
#include <iostream>
class Song {
private:
    std::string title;
    std::string artist;
    std::string year;
    int lengthInSec;

public:
    Song(std::string titleIn, std::string artistIn, std::string yearIn, int lengthInSecIn);

    std::string toString();
};

#endif //DJPLAYER_SONG_H
