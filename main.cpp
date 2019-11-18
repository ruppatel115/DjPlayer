#include <iostream>
#include "Song.h"



int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "See if commit works, Elias was here" << std::endl;
    std::string holder = "her comes the sun, beatles, 3, 1967";
    Song* test = new Song(holder);
    std::cout<<"artist = "<<test->getArtist()<<"\n";
    std::cout<<"length  = "<<test->getLength()<<"\n";
    std::cout<<"title = "<<test->getTitle()<<"\n";
    std::cout<<"year = "<<test->getYear()<<"\n";



    //forrest was here, testing commit
    return 0;
}