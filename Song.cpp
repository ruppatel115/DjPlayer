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
}

Song::Song(std::string& songStr) {
    std::stringstream splitter (songStr);
    std::string yearStr, lengthStr;

    getline(splitter, title, ',');
    getline(splitter, artist, ',');
    getline(splitter, lengthStr, ',');
    getline(splitter, yearStr, ',');
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

