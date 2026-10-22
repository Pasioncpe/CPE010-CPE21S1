#include <iostream>
#include "songPlaylist.h"
#include <string>


int main() {
    playlist<std::string>* head = nullptr;
    playlist<std::string>* playing = nullptr;
    bool isPaused = false;

    // showing that the playlist empty by default
    std::cout << "--- Default State ---\n";
    songList(head);

    // gonna add the first song and have the head pointer value pointed to that
    head = newSong<std::string>("New Genesis", "Ado");
    head->next = head;
    head->prev = head;

    // now we add more songs
    addSong("Caramel Pain", "Hoshimachi Suisei", head);
    addSong("Sparkling Daydream", "ZAQ", head);
    addSong("Trapped in the Past", "Tuyu", head);
    addSong("If I Could Be A Constellation", "kessoku band", head);

    std::cout << "\n--- After adding songs ---\n";
    songList(head);

    // now we'll play a song
    playSong("Sparkling Daydream", &playing, head);

    // now we're gonna use the next and previous functions
    std::cout << "\n--- Spamming Next Button ---\n";
    nextSong(&playing); // should move to "Trapped in the Past"
    nextSong(&playing); // should be at "kessoku band"
    nextSong(&playing); // should be at "Ado"
    std::cout << "\n--- Clicking the Previous Button ---\n";
    prevSong(&playing);      // back to "kessoku band"

    // demonstrating the pause and resume and the significance of the bool variable
    std::cout << "\n--- Pause and Resuming---\n";
    pauseSong(&playing, &isPaused);
    pauseSong(&playing, &isPaused);   // should say "already paused"
    resumeSong(&playing, &isPaused);
    resumeSong(&playing, &isPaused);  // should say "already playing"

    // deleting a random song
    std::cout << "\n--- Deleting a song ---\n";
    deleteSong("Caramel Pain", &head, &playing);
    songList(head);

    // deleting the "playing" song, this automatically stops the playing music (in pretend)
    std::cout << "\n--- Deleting the currently playing song ---\n";
    deleteSong("If I Could Be A Constellation", &head, &playing); // this was "playing"
    songList(head);

    // playing is now nullptr
    nextSong(&playing);

    // now to delete the playlsit
    std::cout << "\n--- Deleting entire playlist ---\n";
    deleteplaylist(&head, &playing);
    songList(head); // should report empty

    return 0;

}