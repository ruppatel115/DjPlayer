#include <fstream>
#include "Song.h"
#include "TestLib.h"
#include "CommandHandler.h"


//
// Created by Forrest Wargo on 12/11/19.
//

using namespace std;
/*
here comes the sun, beatles, 3:32, 1967
Billie Jean, Michael Jackson, 5:56, 1980
rap god, eminem, 5:09, 2013
lucy in thr sky with diamonds, beatles, 3:45, 1967
a hard days night, beatles, 3:02, 1964
loose yourself, eminem, 5:00, 2013
 */
void songTesters(){
    cout << "=======SONG TESTERS=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    Song* testSong = new Song(song1);
    printAssertEquals("here comes the sun",testSong->getTitle());
    printAssertEquals("beatles",testSong->getArtist());
    printAssertEquals(212,testSong->getLength());
    printAssertEquals(1967,testSong->getYear());
    string song2 = "here comes the sun, beatles, 212, 1967";
    Song* testSong2 = new Song(song2);
    printAssertEquals("here comes the sun",testSong2->getTitle());
    printAssertEquals("beatles",testSong2->getArtist());
    printAssertEquals(212,testSong2->getLength());
    printAssertEquals(1967,testSong2->getYear());


    delete testSong;

    cout << "=======DONE=======" << endl;

}




void songArrayListTesters(){
    cout<<"=====SONG ARRAY LIST TESTS=======\n";
    SongArrayList testList = SongArrayList();
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";



    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    cout<<"-----testing item count ------\n";
    printAssertEquals(0,testList.itemCount());
    testList.insertAtEnd(*testSong1);
    printAssertEquals(1,testList.itemCount());
    testList.insertAtEnd(*testSong2);
    printAssertEquals(2,testList.itemCount());
    testList.insertAtEnd(*testSong3);
    printAssertEquals(3,testList.itemCount());

    cout<<"-----testing get value at and insert at end------\n";
    printAssertEquals("here comes the sun",testList.getValueAt(0)->getTitle());

    printAssertEquals("Billie Jean",testList.getValueAt(1)->getTitle());
    printAssertEquals("rap god",testList.getValueAt(2)->getTitle());
    cout<<"-----testing get song------\n";
    //testList.insertAtEnd(song1);
    printAssertEquals("here comes the sun",testList.getSong("here comes the sun")->getTitle());
    cout<<"-----testing find------\n";
    printAssertEquals(0,testList.find("here comes the sun"));
    printAssertEquals(1,testList.find("Billie Jean"));
    cout<<"-----testing remove value at and is empty------\n";
    printAssertEquals("Billie Jean",testList.removeValueAt(1).getTitle());
    printAssertEquals(2,testList.itemCount());
    printAssertEquals("here comes the sun",testList.removeValueAt(0).getTitle());
    printAssertEquals("rap god",testList.removeValueAt(0).getTitle());
    printAssertEquals(0,testList.itemCount());
    printAssertEquals(true,testList.isEmpty());
    cout<<"-----testing insert at ------\n";
    testList.insertAtEnd(*testSong1);
    testList.insertAtEnd(*testSong2);
    testList.insertAt(*testSong3,1);
    printAssertEquals("rap god",testList.getValueAt(1)->getTitle());
    cout<<"-----testing clear list------\n";
    testList.clearList();
    printAssertEquals(true,testList.isEmpty());
    printAssertEquals(0,testList.itemCount());
    cout<<"-----testing tostring------\n";
    printAssertEquals("{}",testList.toString());

    testList.insertAtEnd(*testSong1);
    testList.insertAtEnd(*testSong2);
    testList.insertAtEnd(*testSong3);
    printAssertEquals("{here comes the sun, Billie Jean, rap god}",testList.toString());
    cout<<"=====DONE=======\n";
    //todo add testers for destructor and coy constructor



}
void songArrayListTesters2(){

    std::cout << "=======SONGARRAYLIST TEST=======" <<endl;
    Song* song1 = new Song("eminem", "rap god");
    Song* song2 = new Song("beatles", "hey jude");
    Song* song3 = new Song("jay z", "welcome to the jungle");
    Song* song4 = new Song("beatles", "some song");

    SongArrayList* songList = new SongArrayList();
    printAssertEquals(true,songList->isEmpty());
    songList->insertAtEnd(*song1);
    songList->insertAtEnd(*song2);
    songList->insertAtEnd(*song3);
    printAssertEquals(3, songList->itemCount());
    songList->insertAtEnd(*song4);
    printAssertEquals(4,songList->itemCount());
    printAssertEquals(song3,songList->getValueAt(2));
    printAssertEquals("{rap god, hey jude, welcome to the jungle, some song}", songList->toString());
    printAssertEquals(0, songList->find("rap god"));
    printAssertEquals(3, songList->find("some song"));
    songList->removeValueAt(2);
    printAssertEquals(3,songList->itemCount());
    songList->clearList();
    printAssertEquals(0, songList->itemCount());

    std::cout << "======DONE======" <<endl;
}
void artistMapNodeTesters(){
    std::cout << "=======Artist Map Node TESTS=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";

    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    ArtistMapNode* testNode = new ArtistMapNode(*testSong1);
    cout<<"-----testing toString and i guess get song list------\n";
    printAssertEquals("{here comes the sun}",testNode->toString());
    testNode->getSongList()->clearList();
    printAssertEquals("{}",testNode->toString());
    cout<<"-----testing add song-----\n";
    testNode->addSong(song1);
    cout<<"expecting 'duplicate song: here comes the sun' actual: ";
    testNode->addSong(song1);
    testNode->addSong(song2);
    testNode->addSong(song3);
    printAssertEquals("{Billie Jean, here comes the sun, rap god}",testNode->toString());
    cout<<"-----testing get artist-----\n";
    printAssertEquals("beatles",testNode->getArtist());
    cout<<"-----testing set and get next-----\n";
    ArtistMapNode* testNode2 = new ArtistMapNode(*testSong2);
    testNode->setNext(testNode2);
    printAssertEquals("Michael Jackson",testNode->getNext()->getArtist());

    std::cout << "======DONE======" <<endl;


}

void ArtistMapTesters(){
    std::cout << "=======ARTIST MAP TESTS=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 3:45, 1967";

    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    Song* testSong4 = new Song(song4);


    ArtistMap* mapTest = new ArtistMap();


    cout<<"-----testing put and tostring-----\n";
    mapTest->put(*testSong1);
    printAssertEquals("[\nbeatles: {here comes the sun}\n]\n",mapTest->toString());
    cout<<"expecting 'duplicate song: here comes the sun' actual: ";
    mapTest->put(*testSong1);
    printAssertEquals("[\nbeatles: {here comes the sun}\n]\n",mapTest->toString());
    mapTest->put(*testSong2);
    printAssertEquals("[\nbeatles: {here comes the sun}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());
    mapTest->put(*testSong4);
    printAssertEquals("[\nbeatles: {here comes the sun, lucy in thr sky with diamonds}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());


    cout<<"-----testing remove-----\n";
    mapTest->remove("here comes the sun", "beatles");
    printAssertEquals("[\nbeatles: {lucy in thr sky with diamonds}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());
    mapTest->remove("here comes the sun", "Michael Jackson");
    printAssertEquals("[\nbeatles: {lucy in thr sky with diamonds}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());
    mapTest->remove("here comes the sun", "fake");
    printAssertEquals("[\nbeatles: {lucy in thr sky with diamonds}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());




    cout<<"-----testing get artist count-----\n";
    delete mapTest;
    mapTest = new ArtistMap();
    printAssertEquals(0,mapTest->getArtistCount());
    //printAssertEquals(0,mapTest->getSongCount());
    mapTest->put(*testSong1);
    printAssertEquals(1,mapTest->getArtistCount());
    //printAssertEquals(1,mapTest->getSongCount());
    mapTest->put(*testSong2);
    printAssertEquals(2,mapTest->getArtistCount());
    //printAssertEquals(2,mapTest->getSongCount());
    mapTest->put(*testSong3);
    printAssertEquals(3,mapTest->getArtistCount());
    //printAssertEquals(3,mapTest->getSongCount());
    //testing with a duplicate song
    mapTest->put(*testSong3);
    printAssertEquals(3,mapTest->getArtistCount());
    //printAssertEquals(3,mapTest->getSongCount());
    //testing with a song from an artist already in map
    mapTest->put(*testSong4);
    printAssertEquals(3,mapTest->getArtistCount());
    //printAssertEquals(4,mapTest->getSongCount());

    cout<<"-----testing removeAll-----\n";
    mapTest->removeAll();
    printAssertEquals("[]",mapTest->toString());
    printAssertEquals(0,mapTest->getArtistCount());
    mapTest->removeAll();
    printAssertEquals("[]",mapTest->toString());
    printAssertEquals(0,mapTest->getArtistCount());

    cout<<"-----testing getArtist-----\n";
    mapTest->put(*testSong1);
    mapTest->put(*testSong2);
    mapTest->put(*testSong3);
    mapTest->put(*testSong4);
    ArtistMapNode* testNode = mapTest->getArtist("beatles");
    printAssertEquals("{here comes the sun, lucy in thr sky with diamonds}",testNode->toString());
    testNode = mapTest->getArtist("the beatles");
    //printAssertEquals(nullptr,testNode);


    cout<<"-----testing getArtistAt-----\n";
    testNode = mapTest->getArtistAt(0);
    printAssertEquals("{here comes the sun, lucy in thr sky with diamonds}",testNode->toString());
    try{
        mapTest->getArtistAt(-1);
        cout << "FAIL: removeSong did not throw exception when index was negative" <<endl;
    }
    catch(out_of_range& e){
        printAssertEquals("invalid index",e.what());
    }
    try{
        mapTest->getArtistAt(3);
        cout << "FAIL: removeSong did not throw exception when index was negative" <<endl;
    }
    catch(out_of_range& e){
        printAssertEquals("invalid index",e.what());
    }
    try{
        mapTest->getArtistAt(10000);
        cout << "FAIL: removeSong did not throw exception when index was negative" <<endl;
    }
    catch(out_of_range& e){
        printAssertEquals("invalid index",e.what());
    }
    testNode = mapTest->getArtistAt(2);
    printAssertEquals("{Billie Jean}",testNode->toString());

    cout<<"-----testing getSong-----\n";
    delete mapTest;
    mapTest = new ArtistMap();
    mapTest->put(*testSong1);
    mapTest->put(*testSong2);
    mapTest->put(*testSong3);
    mapTest->put(*testSong4);
    printAssertEquals("rap god",mapTest->getSong("rap god", "eminem")->getTitle());
    printAssertEquals("eminem",mapTest->getSong("rap god", "eminem")->getArtist());
    printAssertEquals("here comes the sun",mapTest->getSong("here comes the sun", "beatles")->getTitle());
    printAssertEquals("here comes the sun",mapTest->getSong("here comes the sun", "beatles")->getTitle());



    delete testSong1; delete testSong2; delete testSong3; delete testSong4;
    std::cout << "======DONE======" <<endl;


}


void playlistTesters(){ //TODO borked?
    cout << "=======PLAYLIST TESTERS=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    Song* testSong = new Song(song1);
    Playlist* testPlaylist = new Playlist("testPlaylist");

    //Testing with nothing in playlist
    printAssertEquals("testPlaylist",testPlaylist->getTitle());
    printAssertEquals(0,testPlaylist->getNumSongs());

    try{
        testPlaylist->getSong(0);
        cout << "FAIL: getSong did not throw exception when playlist is empty" <<endl;
    }
    catch(out_of_range& e){
        printAssertEquals("playlist is empty",e.what());
    }
    printAssertEquals("{}",testPlaylist->toString());

    printAssertEquals(0,testPlaylist->getDuration());
    printAssertEquals(true,testPlaylist->isEmpty());

    try{
        testPlaylist->removeSong(0);
        cout << "FAIL: removeSong did not throw exception when playlist is empty" <<endl;
    }
    catch(out_of_range& e){
        printAssertEquals("playlist is empty",e.what());
    }
    printAssertEquals(-1,testPlaylist->findSong(testSong->getTitle(),testSong->getArtist()));

    testPlaylist->insertAtEnd(testSong);
    //One song now in playlist

    printAssertEquals(1,testPlaylist->getNumSongs());
    try {
        printAssertEquals(testSong->getTitle(), testPlaylist->getSong(0)->getTitle());
    }
    catch(out_of_range& e){
        cout <<"FAIL: getSong threw exception"<<endl;
    }

    printAssertEquals("{0: here comes the sun (Artist: beatles; Length: 212 secs; Year: 1967)}",testPlaylist->toString());

    printAssertEquals(212,testPlaylist->getDuration());
    printAssertEquals(false,testPlaylist->isEmpty());
    printAssertEquals(0,testPlaylist->findSong(testSong->getTitle(),testSong->getArtist()));
    cout << "removesongtest" <<endl;
    printAssertEquals("here comes the sun, beatles, 212, 1967",testPlaylist->removeSong(0));





    delete testSong; delete testPlaylist;
    cout << "=======DONE=======" << endl;
}


void playListArrayListTesters(){
    cout << "======PLAYLIST ARRAYLIST TESTERS=======" << endl;

    PlaylistArrayList listOfPlaylists = PlaylistArrayList();
    Playlist* playlist1 = new Playlist("playlist1");
    Playlist* playlist2 = new Playlist("playlist2");
    Playlist* playlist3 = new Playlist("playlist3");
    Playlist* playlist4 = new Playlist("playlist4");
    Playlist* playlist5 = new Playlist("playlist5");
//    string song1 = "here comes the sun, beatles, 3:32, 1967";
//    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
//    string song3 = "rap god, eminem, 5:09, 2013";
//    string song4 = "lucy in thr sky with diamonds, beatles, 3:45, 1967";
//
//    Song* testSong1 = new Song(song1);
//    Song* testSong2 = new Song(song2);
//    Song* testSong3 = new Song(song3);
//    Song* testSong4 = new Song(song4);
//    playlist5->insertAtEnd(testSong3);
//    playlist5->insertAtEnd(testSong2);




    std::cout << "==isEmpty and playlistCount==" <<endl;

    printAssertEquals(0,listOfPlaylists.playlistCount());
    printAssertEquals(true,listOfPlaylists.isEmpty());
    listOfPlaylists.insertAtEnd(*playlist1);
    printAssertEquals(1,listOfPlaylists.playlistCount());
    printAssertEquals(false,listOfPlaylists.isEmpty());


    std::cout << "==ToString==" <<endl;
    printAssertEquals("{playlist1 (empty playlist)}", listOfPlaylists.toString());
    listOfPlaylists.insertAtEnd(*playlist2);
    listOfPlaylists.insertAtEnd(*playlist3);
    printAssertEquals("{playlist1 (empty playlist), playlist2 (empty playlist), playlist3 (empty playlist)}", listOfPlaylists.toString());

    std::cout << "==find==" <<endl;
    listOfPlaylists.insertAtEnd(*playlist4);
    listOfPlaylists.insertAtEnd(*playlist5);

    printAssertEquals(2,listOfPlaylists.find("playlist3"));
    printAssertEquals(0,listOfPlaylists.find("playlist1"));
    printAssertEquals(3,listOfPlaylists.find("playlist4"));
    printAssertEquals(5,listOfPlaylists.playlistCount());


    std::cout << "==remove==" <<endl;

    listOfPlaylists.removeAt(2);
    printAssertEquals(4,listOfPlaylists.playlistCount());
    std::cout<<listOfPlaylists.toString() <<std::endl;



    delete playlist1; delete playlist2; delete playlist3; delete playlist4; delete playlist5;
    cout << "=======DONE=======" << endl;
}


void rupPlaylistTesters(){
    std::cout << "=======PLAYLIST TEST=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:32, 1980";
    string song3 = "rap god, eminem, 5:12, 2013";
    string song4 = "b lucy in thr sky with diamonds, beatles, 3:39, 1967";
    string song5 = "c  hey jude, beatles, 3:01, 1968";
    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    Song* testSong4 = new Song(song4);
    Song* testSong5 = new Song(song5);
    Playlist playList;
    printAssertEquals(true, playList.isEmpty());
    playList.insertAtEnd(testSong1);
    printAssertEquals(false, playList.isEmpty());
    printAssertEquals(1, playList.getNumSongs());
    playList.insertAtEnd(testSong2);
    playList.insertAtEnd(testSong3);
    printAssertEquals(3, playList.getNumSongs());
    //playList.removeSong(2);
    //printAssertEquals(2, playList.itemCount());
    playList.insertAtEnd(testSong3);
    playList.insertAtEnd(testSong3);
    //printAssertEquals(4, playList.itemCount());
    std::cout<<playList.toString()<<std::endl;

    //playList.calcDuration();NOT WORKING
    std::cout << "======DONE======" <<endl;


}
void wipeFile(string fileName){
    std::ofstream outf(fileName);
    if (outf){
        outf.close();
    }else{
        cout<<"file "<<fileName<<" cant be found \n";
    }
}
void commandHandlerTesters(){

    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 3:45, 1967";

    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    Song* testSong4 = new Song(song4);
    std::cout << "======TESTING COMMAND HANDLER ======" <<endl;
    wipeFile("../Save.txt");
    wipeFile("../savedPlaylists.txt");
    CommandHandler* testHandler = new CommandHandler();//constructor calls save files
    cout<<"-----testing Library-----\n";
    testHandler->getSongLibrary()->put(*testSong1);
    testHandler->getSongLibrary()->put(*testSong2);
    testHandler->getSongLibrary()->put(*testSong3);
    testHandler->getSongLibrary()->put(*testSong4);
    testHandler->getSongLibrary()->put(*testSong1);
    printAssertEquals("[\nbeatles: {here comes the sun, lucy in thr sky with diamonds}\neminem: {rap god}\nMichael Jackson: {Billie Jean}\n]\n",testHandler->getSongLibrary()->toString());

    cout<<"-----testing import-----\n";
    std::ofstream outf("../Save.txt");
    if (outf){
        outf << testSong1->getTitle()+", "+testSong1->getArtist()+", "+std::to_string(testSong1->getLength())+", "+std::to_string(testSong1->getYear())+'\n';
        outf << testSong2->getTitle()+", "+testSong2->getArtist()+", "+std::to_string(testSong2->getLength())+", "+std::to_string(testSong2->getYear())+'\n';
        outf << testSong3->getTitle()+", "+testSong3->getArtist()+", "+std::to_string(testSong3->getLength())+", "+std::to_string(testSong3->getYear())+'\n';
        outf << testSong4->getTitle()+", "+testSong4->getArtist()+", "+std::to_string(testSong4->getLength())+", "+std::to_string(testSong4->getYear())+'\n';
        outf << testSong4->getTitle()+", "+testSong4->getArtist()+", "+std::to_string(testSong4->getLength())+", "+std::to_string(testSong4->getYear())+'\n';



        outf.close();
    }else{
        cout<<"file "<<"Save.txt"<<" cant be found \n";
    }
    testHandler->getSongLibrary()->removeAll();
    testHandler->import("../Save.txt");
    printAssertEquals("[\nbeatles: {here comes the sun, lucy in thr sky with diamonds}\neminem: {rap god}\nMichael Jackson: {Billie Jean}\n]\n",testHandler->getSongLibrary()->toString());
    cout<<"-----testing display artist-----\n";








    std::cout << "======DONE======" <<endl;

};


int main(){
    commandHandlerTesters();
    songTesters();
    playlistTesters();
    rupPlaylistTesters();
    playListArrayListTesters();

    artistMapNodeTesters();
    ArtistMapTesters();
    songTesters();
    songArrayListTesters();
    artistMapNodeTesters();
    return 0;
}
