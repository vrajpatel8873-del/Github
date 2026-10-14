#include <iostream>
#include <string>
using namespace std;

// Compile-time polymorphism: overloaded methods.
class PaymentProcessor {
public:
    void processPayment(double amount) const {
        cout << "processPayment(amount) called. Final amount: Rs. " << amount << '\n';
    }
    void processPayment(double amount, const string& coupon) const {
        double finalAmount = amount;
        if (coupon == "SAVE10") finalAmount *= 0.90;
        else if (coupon == "SAVE20") finalAmount *= 0.80;
        cout << "processPayment(amount, coupon) called. Coupon: " << coupon
             << ", final amount: Rs. " << finalAmount << '\n';
    }
};

class SocialMediaUploader {
public:
    virtual void uploadContent() const {
        cout << "Uploading generic social media content.\n";
    }
    virtual ~SocialMediaUploader() = default;
};
class InstagramUploader : public SocialMediaUploader {
public:
    void uploadContent() const override { cout << "Uploading a photo/reel to Instagram.\n"; }
};
class YouTubeUploader : public SocialMediaUploader {
public:
    void uploadContent() const override { cout << "Uploading a video to YouTube.\n"; }
};

class MusicPlayer {
public:
    virtual void play(const string& song) const {
        cout << "Playing: " << song << '\n';
    }
    virtual ~MusicPlayer() = default;
};
class SpotifyPlayer : public MusicPlayer {
public:
    void play(const string& song) const override {
        cout << "Streaming on Spotify: " << song << '\n';
    }
};

void searchProduct(const string& productName) {
    cout << "Searching product: " << productName << '\n';
}
void searchProduct(const string& productName, const string& category) {
    cout << "Searching product: " << productName << " in category: " << category << '\n';
}

int main() {
    PaymentProcessor payment;
    payment.processPayment(1000);
    payment.processPayment(1000, "SAVE10");

    InstagramUploader instagram;
    YouTubeUploader youtube;
    SocialMediaUploader* uploader = &instagram;
    uploader->uploadContent();
    uploader = &youtube;
    uploader->uploadContent();

    searchProduct("Headphones");
    searchProduct("Headphones", "Electronics");

    MusicPlayer* player = new SpotifyPlayer();
    player->play("My Favourite Song");
    delete player;
}
