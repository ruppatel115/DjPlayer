//
// Created by Forrest Wargo on 11/24/19.
//

#ifndef DJPLAYER_ARTISTMAP_H
#define DJPLAYER_ARTISTMAP_H
//#include "Song.h"
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
    void addArtistNode(Song song);
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
