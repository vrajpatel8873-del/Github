#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

void writeSongs() {
    ofstream out("my_fav_songs.txt");
    if (!out) { cerr << "Could not open my_fav_songs.txt for writing.\n"; return; }
    const string songs[] = {"Kesariya", "Apna Bana Le", "Channa Mereya",
                            "Kun Faya Kun", "Ilahi"};
    for (const auto& song : songs) out << song << '\n';
    cout << "Saved 5 songs to my_fav_songs.txt\n";
}
void readSongs() {
    ifstream in("my_fav_songs.txt");
    if (!in) { cerr << "Could not open my_fav_songs.txt. Run option 1 first.\n"; return; }
    string line;
    while (getline(in, line)) cout << line << '\n';
}
void appendSong() {
    cout << "Enter a song name: ";
    string song;
    getline(cin, song);
    if (song.empty()) { cout << "Song name cannot be empty.\n"; return; }
    ofstream out("my_fav_songs.txt", ios::app);
    if (!out) { cerr << "Could not open file for appending.\n"; return; }
    out << song << '\n';
    cout << "Song appended.\n";
}
void wishlist() {
    ofstream out("wishlist.txt");
    if (!out) { cerr << "Could not create wishlist.txt\n"; return; }
    for (int i = 0; i < 3; ++i) {
        string name; double price;
        cout << "Product " << i + 1 << " name: ";
        getline(cin, name);
        cout << "Product " << i + 1 << " price (Rs.): ";
        if (!(cin >> price) || price < 0) {
            cout << "Invalid price.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        out << name << " | Rs. " << price << '\n';
    }
    out.close();
    cout << "\nSaved wishlist:\n";
    ifstream in("wishlist.txt");
    string line;
    while (getline(in, line)) cout << line << '\n';
}
void countFollowers() {
    ifstream in("insta_followers.txt");
    if (!in) {
        cout << "insta_followers.txt not found. Create it with one username per line.\n";
        return;
    }
    string username;
    size_t count = 0;
    while (getline(in, username)) if (!username.empty()) ++count;
    cout << "Total usernames/followers listed: " << count << '\n';
}
int main() {
    while (true) {
        cout << "\n=== File Handling Practice ===\n"
             << "1. Create/overwrite 5 favourite songs\n"
             << "2. Read songs\n"
             << "3. Append a song\n"
             << "4. Create and read a 3-product wishlist\n"
             << "5. Count usernames in insta_followers.txt\n"
             << "0. Exit\nChoice: ";
        int choice;
        if (!(cin >> choice)) return 0;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1: writeSongs(); break;
            case 2: readSongs(); break;
            case 3: appendSong(); break;
            case 4: wishlist(); break;
            case 5: countFollowers(); break;
            case 0: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
