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
using namespace std;
#include <stdexcept>
#include <string>

void artistMapTester(){
    string song1 = "here comes the sun, beatles, 3, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5, 1980";
    string song3 = "rap god, eminem, 5, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 3, 1967";
    string song5 = "a hard days night, beatles, 3, 1964";
    string song6 = "loose yourself, eminem, 5, 2013";
    cout<<"=======ArtistMapNode Tests=======\n";
    ArtistMapNode* testNode = new ArtistMapNode(*new Song(song1));

    testNode->addSong(song4);
    testNode->addSong(song5);
    cout<<"expecting 'duplicate song a hard days night', actual: ";
    testNode->addSong(song5);
    cout<<"\n";
    cout<<"expecting {a hard days night, here comes the sun, lucy in thr sky with diamonds}, actual ="<< testNode->toString()<<'\n';

    cout<<"=======ArtistMap Tests=======\n";
    ArtistMap* testMap = new ArtistMap();
    testMap->put(song1);
    testMap->put(song2);
    testMap->put(song3);
    testMap->put(song4);
    testMap->put(song5);
    cout<<"expecting 'duplicate song a hard days night', actual: ";
    testMap->put(song5);
    if( testMap->getArtist("beatles") == nullptr){
        cout<<"fail\n";
    }
    testMap->put(song6);
    cout<<"expecting {a hard days night, here comes the sun, lucy in thr sky with diamonds}, actual ="<< testMap->getArtist("beatles")->toString()<<'\n';
    cout<< testMap->toString();

    cout<<"-----done-----\n"<< std::endl;

}

void PlayListTester(){
    string song1 = "A her comes the sun, beatles, 3, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5, 1980";
    string song3 = "rap god, eminem, 5, 2013";
    string song4 = "b lucy in thr sky with diamonds, beatles, 3, 1967";
    string song5 = "c  hey jude, beatles, 3, 1968";

    std::cout << "=======PLAYLIST TEST=======" <<endl;
    Playlist playList;
    cout<<"expecting 1 or true, actual: ";
    cout<<playList.isEmpty()<<endl;
    //cout<<"throw exception actual: " << endl;
    //cout<<playList.removeSong(0)<<endl;
    cout<<"expecting 0, actual: ";
    cout<<playList.itemCount()<<endl;
    //playList.insertAtEnd(song1);
    //playList.insertAtEnd(song2);
    cout<<"expecting 2, actual: ";
    cout<<playList.itemCount()<<endl;
    cout<<"expecting 0 or false, actual: ";
    cout<<playList.isEmpty()<<endl;
    //playList.insertAtEnd(song3);
    //playList.insertAtEnd(song4);
    cout<<"expecting 4 actual: ";
    cout<<playList.itemCount()<<endl;
    cout<<"rap god, eminem, 5, 2013, actual: ";
    cout<<playList.removeSong(3)<<endl;
    cout<<"expecting 3 actual: ";
    cout<<playList.itemCount()<<endl;
    std::cout << "-----done-----" <<endl;
}



void displayArtistTester(){
    cout<<"=======displayArtistTester======="<<endl;
    CommandHandler* testHandler = new CommandHandler();
    string song1 = "here comes the sun, beatles, 3, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5, 1980";
    string song3 = "rap god, eminem, 5, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 3, 1967";
    string song5 = "a hard days night, beatles, 3, 1964";
    testHandler->getSongLibrary()->put(song1);
    testHandler->getSongLibrary()->put(song2);
    testHandler->getSongLibrary()->put(song3);
    testHandler->getSongLibrary()->put(song4);
    testHandler->getSongLibrary()->put(song5);
    cout<<"expecting {a hard days night, here comes the sun, lucy in thr sky with diamonds}, actual: ";
    testHandler->displayArtist("beatles");
    cout<<"expecting {rap god}, actual: ";
    testHandler->displayArtist("eminem");
    cout<<"expecting {Billies jean}, actual: ";
    testHandler->displayArtist("Michael Jackson");
    cout<<"expecting artist not found, actual: ";
    testHandler->displayArtist("jon doe");
    cout<<"-----done-----"<<endl;
}




void libraryTester(){
    cout<<"=======libraryTester======="<<endl;
    CommandHandler* testHandler = new CommandHandler();
    string song1 = "here comes the sun, beatles, 3, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5, 1980";
    string song3 = "rap god, eminem, 5, 2013";
    string song4 = "Lucy in thr sky with diamonds, beatles, 3, 1967";
    string song5 = "a hard days night, beatles, 3, 1964";
    testHandler->getSongLibrary()->put(song2);
    testHandler->getSongLibrary()->put(song1);
    testHandler->getSongLibrary()->put(song3);
    testHandler->getSongLibrary()->put(song4);
    testHandler->getSongLibrary()->put(song5);
    testHandler->getSongLibrary()->put(song1);

    cout<<"[\n"
          "beatles: { a hard days night, here comes the sun, lucy in thr sky with diamonds}\n"
          "eminem: { loose yourself, rap god}\n"
          "Michael Jackson: { Billie Jean}\n"
          "]\n"
          "actual: \n";
    testHandler->library();
    cout<<"-----done-----"<<endl;
}
void quitTester(){
    cout<<"======Quit tester======"<<endl;
    CommandHandler* testHandler = new CommandHandler();
    /*
    string song1 = "here comes the sun, beatles, 3:23, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:54, 1980";
    string song3 = "rap god, eminem, 5:43, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 2:21, 1967";
    string song5 = "a hard days night, beatles, 31:56, 1964";
    testHandler->getSongLibrary()->put(song1);
    testHandler->getSongLibrary()->put(song2);
    testHandler->getSongLibrary()->put(song3);
    testHandler->getSongLibrary()->put(song4);
    testHandler->getSongLibrary()->put(song5);
     */
    testHandler->newPlaylist("test1");
    testHandler->addToPlaylist("test1","a hard days night", "beatles");
    testHandler->addToPlaylist("test1","Billie Jean", "Michael Jackson");
    testHandler->playlist("test1");//TODO THIS LINE ISNT WORKING
    testHandler->quit();
    CommandHandler* testHandler2 = new CommandHandler();
    //testHandler2->import("/Users/forrest/Google Drive/College Fall 2019/Data Structures/DjPlayer/Save.txt");
    testHandler2->library();
    testHandler2->playlist("test1");
    cout<<"-----done-----"<<endl;

}

void playlistArrayListTester(){
    CommandHandler* testHandler = new CommandHandler();
    //testHandler.

}
void displaySongTester(){
    CommandHandler* testHandler = new CommandHandler();
    testHandler->import("/Users/forrest/Google Drive/College Fall 2019/Data Structures/DjPlayer/importTest.txt");
    cout<<"expecting rap god, eminem, 5:43, 2013, actual: ";
    testHandler->song("eminem", "rap god");
    cout<<"=====done=======\n";

}

void testRandomPlaylist() {
    std::cout << "---------- Testing Random Playlist ---------" << std::endl;
    CommandHandler *testHandler = new CommandHandler();
//    testHandler->newPlaylist("randomplaylisttest");
//    testHandler->addToPlaylist("randomplaylisttest", "a hard days night", "beatles");

    //testHandler->import("/Users/ruppatel/CLionProjects/DjPlayer/importTest.txt");

    std::cout<<"Create New Playlist"<<std::endl;
    testHandler->createRandomPlaylist(5, "tester");

    testHandler->listPlaylists();



    std::cout <<"Finished test"<<std::endl;
}
void addToPlaylistTester(){
    cout<<"=========AddToPlayListTest=========\n";
    CommandHandler *testHandler = new CommandHandler();
    //testHandler->library();
    testHandler->newPlaylist("test");
    cout<<"expecting, Added new song rap god, actual: ";
    testHandler->addToPlaylist("test","rap god","eminem");
    testHandler->playlist("test");

    cout<<"\n=========done=========\n";
}

void tests(){
    //displaySongTester();
    //quitTester();
    //libraryTester();
    //artistMapTester();
    //displayArtistTester();
    //playlistArrayListTester();
    //PlayListTester();
}
void discontinueTester(){
//    cout<<"=====discontinueTester=======\n";
//
//    CommandHandler* testHandler = new CommandHandler();
//    testHandler->import("/Users/forrest/Google Drive/College Fall 2019/Data Structures/DjPlayer/importTest.txt");
//    testHandler->newPlaylist("testList");
//    testHandler->library();
//    testHandler->addToPlaylist("testList","rap god", "eminem");
//    testHandler->addToPlaylist("testList","here comes the sun", "beatles");
//    testHandler->discontinue("/Users/forrest/Google Drive/College Fall 2019/Data Structures/DjPlayer/discontinueTest.txt");
//    testHandler->library();
//    cout<<"=====done=======\n";
//


}

int main() {

    addToPlaylistTester();
    //quitTester();
    //tests();
//discontinueTester();
    //testRandomPlaylist();
    /*
    //CommandHandler* test = new CommandHandler();
    //test->import("/Users/forrest/Google Drive/College Fall 2019/Data Structures/DjPlayer/importTest.txt");

    //std::cout << "See if commit works, Elias was here" << std::endl;
    //Library mainLibrary;

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

            handler->addToPlaylist(playlistTitle, songTitle,artistName,);

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

           // handler->newRandomPlaylist(playlistTitle, duration);

        }

        }

*/

    return 0;
    }

