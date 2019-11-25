//
// Created by Forrest Wargo on 11/24/19.
//

#ifndef DJPLAYER_ARTISTMAP_H
#define DJPLAYER_ARTISTMAP_H
#include "Song.h"
#include <iostream>
#include "ArtistMapNode.h"



class ArtistMap{
private:
    ArtistMapNode* front;
public:
    ArtistMap();

    void put(Song song);
    ArtistMapNode* getArtist(std::string artist);
    ArtistMapNode* getFront();

};

#endif //DJPLAYER_ARTISTMAP_H
