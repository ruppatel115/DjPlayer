/**@file Song.h
 * Interface for Song object/class
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */

#ifndef DJPLAYER_SONG_H
#define DJPLAYER_SONG_H
#include <iostream>

class Song{
private:
    std::string title;
    std::string artist;
    int length;
    int year;
    int playcount;



public:
    //TODO function comments, destructor not needed
    Song(std::string artist, std::string title);

    Song(); //default constructor

    Song(std::string songStr);


    const std::string &getTitle() const;

    const std::string &getArtist() const;

    int getLength() const;

    int getYear() const;

    void incrementPlaycount();


};

#endif //DJPLAYER_SONG_H
