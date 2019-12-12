/**@file Song.cpp
 * Implementation of Song.h to create Song objects
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */
#include "Song.h"
#include <iostream>
#include <sstream>

/***
 *
 * @param artist
 * @param title
 * constructor
 */
Song::Song(std::string artist, std::string title){  //default constructor int length, int year
    this->title = title;
    this->artist = artist;
    this->length = 0;
    this->year = 0;
    playcount = 0;
}

/***
 * default constructor
 */
Song::Song(){
    this->artist = "default";
    this->title = "default";
    this->length = 0;
    playcount = 0;
}


/***
 * takes in string of songs and splits each in the form of title, artist, length and year
 * @param songStr
 */
Song::Song(std::string songStr) {
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
    //TODO not giving exactly correct length values
    //std::cout<<"full string  "<<lengthStr<<std::endl;
    //std::cout<<"part 1 "<<lengthStr.substr(0,lengthStr.rfind(":"))<<std::endl;
    if(lengthStr.find(":") != lengthStr.npos){
        length = std::stoi(lengthStr.substr(0,lengthStr.rfind(":")))*60;
        //std::cout<<"part 2 "<<lengthStr.substr(lengthStr.rfind(":")+1)<<std::endl;

        length += std::stoi(lengthStr.substr(lengthStr.rfind(":")+1));
    }else{
        length = std::stoi(lengthStr);

    }

    //length = std::stoi(lengthStr);
    year = std::stoi(yearStr);
}

/***
 * @return title of the song
 */
const std::string &Song::getTitle() const {
    return title;
}

/***
 * @return artist of the song
 */
const std::string &Song::getArtist() const {
    return artist;
}

/***
 * @return length of the song
 */
int Song::getLength() const {
    return length;
}


/***
 * @return year song was released
 */
int Song::getYear() const {
    return year;
}


/***
 * increases count of song played
 */
void Song::incrementPlaycount() {
    playcount++;
}

int Song::getPlaycount() {
    return playcount;
}

