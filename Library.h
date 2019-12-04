//
// Created by Elias on 11/25/2019.
//

#ifndef DJPLAYER_LIBRARY_H
#define DJPLAYER_LIBRARY_H

#include <iostream>

class Library{
///Might not use this at all since we have the map
private:
    //TODO songlist?
    std::string filename;
    //Probably won't need these:
    Library(const Library& libraryToCopy);
    Library& operator=(const Library& libraryToCopy);

public:

    Library();

    ~Library();

    void save();
    void load();
    std::string getArtistSongs(std::string artist);
    std::string getSongs();
    void import(std::string fileToImport);
    void remove(std::string fileToRemove);



};

#endif //DJPLAYER_LIBRARY_H
