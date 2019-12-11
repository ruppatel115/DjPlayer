/**@file ArtistMap.h
 * Interface for an ArtistMap using ArtistMapNodes (artist keys and SongArrayList values)
 * This is essentially used to hold all the songs and artists in the library
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 * Mostly done by Forrest
 */

#ifndef DJPLAYER_ARTISTMAP_H
#define DJPLAYER_ARTISTMAP_H

#include <iostream>
#include <algorithm>
#include "ArtistMapNode.h"

using namespace std;


class ArtistMap{
private:
    ArtistMapNode* front;
    int songCount;
    int artistCount;
public:
    //TODO function comments

    void checkNext(Song song, ArtistMapNode* node);
    ~ArtistMap();
    ArtistMap();
    std::string toString();
    void removeAll();
    void put(Song song);
    void remove(string song, string title);
    ArtistMapNode* getArtist(std::string artist);
    ArtistMapNode* getFront();
    Song* getSong(std::string title, std::string artist);

    int getSongCount();

    int getArtistCount();

    ArtistMapNode *getArtistAt(int index);
};

#endif //DJPLAYER_ARTISTMAP_H
