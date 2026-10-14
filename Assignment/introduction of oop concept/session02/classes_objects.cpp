#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Playlist {
public:
    string name;
    string createdOn;
    bool isPublic;
    vector<string> songs;

    Playlist(string n, string date, bool pub)
        : name(n), createdOn(date), isPublic(pub) {}

    void togglePublic() { isPublic = !isPublic; }
    void addSong(const string& songTitle) { songs.push_back(songTitle); }

    void display() const {
        cout << "Playlist: " << name << "\nCreated: " << createdOn
             << "\nPublic: " << (isPublic ? "Yes" : "No") << "\nSongs:\n";
        for (const auto& song : songs) cout << "- " << song << '\n';
    }
};

class FoodOrder {
public:
    int orderId;
    string restaurantName;
    bool isDelivered;

    FoodOrder(const string& restaurant, int id, bool delivered)
        : orderId(id), restaurantName(restaurant), isDelivered(delivered) {}

    explicit FoodOrder(const FoodOrder& details)
        : orderId(details.orderId), restaurantName(details.restaurantName),
          isDelivered(details.isDelivered) {}

    void markDelivered() {
        isDelivered = true;
        cout << "Order " << orderId << " from " << restaurantName
             << " has been delivered.\n";
    }
};

int main() {
    Playlist playlist("My Favourites", "2026-10-14", false);
    playlist.addSong("Song One");
    playlist.addSong("Song Two");
    playlist.addSong("Song Three");
    playlist.display();

    playlist.togglePublic();
    cout << "\nAfter toggle 1: " << (playlist.isPublic ? "Public" : "Private") << '\n';
    playlist.togglePublic();
    cout << "After toggle 2: " << (playlist.isPublic ? "Public" : "Private") << '\n';

    FoodOrder order("Gujarati Thali", 501, false);
    order.markDelivered();
    FoodOrder copiedOrder(order);
    cout << "Copied order ID: " << copiedOrder.orderId
         << ", restaurant: " << copiedOrder.restaurantName << '\n';
}
