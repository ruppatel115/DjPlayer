//
// Created by Forrest Wargo on 11/18/19.
//

#ifndef DJPLAYER_SONG_H
#define DJPLAYER_SONG_H
#include <iostream>

class Song{
private:
    std::string title;
    std::string artist;
    int length;
    int year;



public:
    Song(std::string& songStr);
    int getLengthl();

    const std::string &getTitle() const;

    const std::string &getArtist() const;

    int getLength() const;

    int getYear() const;


};

#endif //DJPLAYER_SONG_H
