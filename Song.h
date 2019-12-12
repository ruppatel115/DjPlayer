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


    virtual const std::string &getTitle() const;

    virtual const std::string &getArtist() const;

    virtual int getLength() const;

    virtual int getYear() const;

    virtual void incrementPlaycount();

    virtual int getPlaycount();


};

#endif //DJPLAYER_SONG_H
