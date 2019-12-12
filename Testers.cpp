//
// Created by Forrest Wargo on 12/11/19.
//
#include "CommandHandler.h"
#include "TestLib.h"
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
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    Song* testSong = new Song(song1);
    printAssertEquals("here comes the sun",testSong->getTitle());
    printAssertEquals("beatles",testSong->getArtist());
    printAssertEquals(212,testSong->getLength());

    printAssertEquals(1967,testSong->getYear());







}
void ArtistMapTesters(){}
void artistMapNodeTesters(){}
void songArrayListTesters(){}
void playlistTesters(){}
void playListArrayListTesters(){}
int main(){
    songTesters();
    return 0;
}
