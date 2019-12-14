/**@file main.cpp
 * Runs the user interface and testers (testers are in this file)
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */

#include <iostream>
#include "Song.h"
#include "ArtistMap.h"
#include "CommandHandler.h"
#include "Playlist.h"
#include "PlaylistArrayList.h"
#include "List.h"
#include "TestLib.h"
#include <stdexcept>
#include <string>
using namespace std;

void runInterface(){

    std::cout << "Importing playlists...." << endl;
    CommandHandler* handler = new CommandHandler();
    std::string mystr;
    cout << "INTERFACE START:" << endl;
    while(mystr != "quit") {
        std::cout << "Enter your command or help for a list of commands (type quit to stop program):"<<endl;
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

            handler->addToPlaylist(playlistTitle, songTitle,artistName);

        }else if(mystr == "remove"){
            std::cout << "Enter playlist title:" << std::endl;
            std::string playlistTitle = "";
            getline(std::cin, playlistTitle);
            std::cout << "Enter song title:" << std::endl;
            std::string songTitle = "";
            getline(std::cin, songTitle);
            std::cout << "Enter artist name:" << std::endl;
            std::string artistName = "";
            getline(std::cin, artistName);


            handler->removeFromPlaylist(playlistTitle, songTitle,  artistName
            );

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
            std::string durationStr = "";
            getline(std::cin, durationStr);
            int duration = stoi(durationStr);
            handler->createRandomPlaylist(duration, playlistTitle);
        }else if(mystr == "quit"){
            break;
        }
        else{
            cout << "Invalid command, type help for a list of commands." <<endl;
        }

    }
    std::cout << "Saving and quitting program..." <<endl;
    handler->quit();

}


int main() {

    //To run Testers, replace main.cpp in CMakeLists.txt with Testers.cpp
    runInterface();


    return 0;
    }

