#include <iostream>
#include "Song.h"



int main() {
    std::cout << "See if commit works, Elias was here" << std::endl;
    std::string holder = "her comes the sun, beatles, 3, 1967";
    std::string song2 = "Billie Jean, Michael Jackson, 5, 1980";
    Song* test = new Song(holder);
    Song* test2 = new Song(song2);
    std::cout<<"artist = "<<test->getArtist()<<"\n";
    std::cout<<"length  = "<<test->getLength()<<"\n";
    std::cout<<"title = "<<test->getTitle()<<"\n";
    std::cout<<"year = "<<test->getYear()<<"\n";

    std::cout<<"artist = "<<test2->getArtist()<<"\n";
    std::cout<<"length  = "<<test2->getLength()<<"\n";
    std::cout<<"title = "<<test2->getTitle()<<"\n";
    std::cout<<"year = "<<test2->getYear()<<"\n";




    //forrest was here, testing commit
    return 0;
}