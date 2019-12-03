//
// Created by Forrest Wargo on 11/18/19.
//
#include "Song.h"
#include <iostream>
#include <fstream>
#include <sstream>
Song::Song(){  //default constructor
    title = "";
    artist = "";
    length = 0;
    year = 0;
    playcount = 0;
}

Song::Song(std::string& songStr) {
    //song string should be in form: title, artist, length, year
    std::stringstream splitter (songStr);
    std::string yearStr, lengthStr, space;

    getline(splitter, title, ',');
    getline(splitter, space, ' ');
    getline(splitter, artist, ',');
    getline(splitter, space, ' ');
    getline(splitter, lengthStr, ',');
    getline(splitter, space, ' ');
    getline(splitter, yearStr, ',');
    //TODO add error handling for when all info is not there
    length = std::stoi(lengthStr);
    year = std::stoi(yearStr);
}

const std::string &Song::getTitle() const {
    return title;
}

const std::string &Song::getArtist() const {
    return artist;
}

int Song::getLength() const {
    return length;
}

int Song::getYear() const {
    return year;
}

void Song::incrementPlaycount() {
    playcount++;
}

