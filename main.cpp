#include <iostream>
#include "Song.h"
#include "ArtistMap.h"
#include "Library.h"
#include "CommandHandler.h"
using namespace std;


void artistMapTester(){
    string song1 = "her comes the sun, beatles, 3, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5, 1980";
    string song3 = "rap god, eminem, 5, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 3, 1967";
    string song5 = "hey jude, beatles, 3, 1968";
    cout<<"=======ArtistNode Tests=======\n";
    ArtistMapNode* testNode = new ArtistMapNode(*new Song(song1));

    testNode->addSong(song4);
    testNode->addSong(song1);
    testNode->addSong(song5);
    cout<<"expecting hey jude:";
    testNode->addSong(song5);

}


int main() {
    artistMapTester();
    /*
    //CommandHandler* test = new CommandHandler();
    //test->import("/Users/forrest/Google Drive/College Fall 2019/Data Structures/DjPlayer/importTest.txt");

    std::cout << "See if commit works, Elias was here" << std::endl;
    Library mainLibrary;

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


    CommandHandler* handler = new CommandHandler(&mainLibrary);
    std::string mystr;
    while(mystr != "done") {
        std::cout << "Enter your command or help:";
        getline(std::cin, mystr);
        std::cout << mystr<<'\n';


        if(mystr == "help"){
            handler->help();
        }else if(mystr == "library"){
            handler->library();

        }else if(mystr == "artist") {
            std::cout << "Enter artist:" << std::endl;
            std::string artist = "";
            getline(std::cin, artist);
            std::cout << "Displaying all songs by " + artist << std::endl;

            handler->displayArtist(artist);

        }else if(mystr == "song"){
            std::cout << "Enter artist:" << std::endl;
            std::string artist = "";
            getline(std::cin, artist);
            std::cout << "Enter title:" << std::endl;
            std::string title = "";
            getline(std::cin, title);

            handler->song(artist, title);

        }else if(mystr == "import"){
            std::cout << "Enter filename:" << std::endl;
            std::string filename = "";
            getline(std::cin, filename);

            handler->import(filename);

        }else if(mystr == "discontinue"){
            std::cout << "Enter filename:" << std::endl;
            std::string filename = "";
            getline(std::cin, filename);

            handler->discontinue(filename);

        }else if(mystr == "list playlists"){
            handler->listPlaylists();

        }else if(mystr == "playlist"){
            std::cout << "Enter playlist title:" << std::endl;
            std::string playlistTitle = "";
            getline(std::cin, playlistTitle);
            handler->playlist(playlistTitle);

        }else if(mystr == "new"){
            std::cout << "Enter playlist title:" << std::endl;
            std::string playlistTitle = "";
            getline(std::cin, playlistTitle);

            handler->newPlaylist(playlistTitle);

        }else if(mystr == "add"){
            std::cout << "Enter playlist title:" << std::endl;
            std::string playlistTitle = "";
            getline(std::cin, playlistTitle);
            std::cout << "Enter artist name:" << std::endl;
            std::string artistName = "";
            getline(std::cin, artistName);
            std::cout << "Enter song title:" << std::endl;
            std::string songTitle = "";
            getline(std::cin, songTitle);

            handler->addToPlaylist(playlistTitle, artistName, songTitle);

        }else if(mystr == "remove"){
            std::cout << "Enter playlist title:" << std::endl;
            std::string playlistTitle = "";
            getline(std::cin, playlistTitle);
            std::cout << "Enter artist name:" << std::endl;
            std::string artistName = "";
            getline(std::cin, artistName);
            std::cout << "Enter song title:" << std::endl;
            std::string songTitle = "";
            getline(std::cin, songTitle);

            handler->removeFromPlaylist(playlistTitle, artistName, songTitle);

        }else if(mystr == "play next"){
            std::cout << "Enter playlist title:" << std::endl;
            std::string playlistTitle = "";
            getline(std::cin, playlistTitle);

            handler->playNext(playlistTitle);

        }else if(mystr == "new random"){
            std::cout << "Enter playlist title:" << std::endl;
            std::string playlistTitle = "";
            getline(std::cin, playlistTitle);
            std::cout << "Enter max duration:" << std::endl;
            std::string duration = ""; //TODO different type?
            getline(std::cin, duration);

            handler->newRandomPlaylist(playlistTitle, duration);

        }

        }

*/

    return 0;
    }

