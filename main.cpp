#include <iostream>
#include "Song.h"
#include "CommandHandler.h"


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


    CommandHandler* handler = new CommandHandler();
    std::string mystr = "empty";
    while(mystr != "done") {
        std::cout << "Enter your command or help:";
        getline(std::cin, mystr);
        std::cout << mystr<<'\n';


        if(mystr == "help"){
            handler->help();
        }else if(mystr == "library"){
            handler->library();
        }else if(mystr == "artist"){
            handler->displayArtist();

        }else if(mystr == "song"){
            handler->song();

        }else if(mystr == "import"){
            handler->import();

        }else if(mystr == "discontinue"){
            handler->discontinue();

        }else if(mystr == "list playlists"){
            handler->listPlaylists();

        }else if(mystr == "playlist"){
            handler->playlist();

        }else if(mystr == "newPlaylist"){
            handler->newPlaylist();

        }else if(mystr == "addToPlaylist"){
            handler->addToPlaylist();

        }else if(mystr == "remove"){

        }else if(mystr == "play next"){
            handler->playNext();

        }else if(mystr == "new random"){
            handler->newRandomPlaylist();

        }

        }
    }
    return 0;
}