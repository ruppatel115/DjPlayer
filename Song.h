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
    /**
     * Constructor
     * @param artist name of artist
     * @param title name of song
     * also initalizes playCount, length, and year as 0
     */
    Song(std::string artist, std::string title);

    /** Default constructor
     * Initializes artist and title as "default" and playCount, length, and year as 0
     */
    Song();

    /**
     * Constructor
     * takes in string of songs and splits each in the form of title, artist, length and year to init those values
     * @param songStr
     */
    Song(std::string songStr);

    /**
     * Gets the song's title
     * @return a string, the title of the song
     */
    virtual const std::string &getTitle() const;
    /**
     * Gets the song's artist
     * @return a string, the name of the artist
     */
    virtual const std::string &getArtist() const;
    /**
     * Gets the song's length
     * @return an int, the length which has now been converted to seconds after the songstr constructor
     */
    virtual int getLength() const;
    /**
     * Gets the song's year
     * @return an int, the year the song was made
     */
    virtual int getYear() const;
    /**
     * Increments playCount, which is used after playNext cmd
     * @post playCount is increased by one
     */
    virtual void incrementPlaycount();
    /**
     * Gets the song's playCount
     * @return an int, value of playcount
     */
    virtual int getPlaycount();

    virtual std::string toString();


};

#endif //DJPLAYER_SONG_H
