#include <iostream>
#include <string>
using namespace std;

class SocialMediaUser {
protected:
    string username;
    int followers;
public:
    SocialMediaUser(string user, int count) : username(user), followers(count) {}
    void displayProfile() const {
        cout << "@" << username << " | Followers: " << followers << '\n';
    }
};

class YouTuber : public SocialMediaUser {
protected:
    string channelName;
public:
    YouTuber(string user, int count, string channel)
        : SocialMediaUser(user, count), channelName(channel) {}
    void uploadVideo(const string& title) const {
        cout << "Video [" << title << "] uploaded to [" << channelName << "].\n";
    }
};

class Podcaster : public SocialMediaUser {
private:
    string podcastName;
public:
    Podcaster(string user, int count, string podcast)
        : SocialMediaUser(user, count), podcastName(podcast) {}
    void publishEpisode(const string& title) const {
        cout << "Episode [" << title << "] published on [" << podcastName << "].\n";
    }
};

class GamingYouTuber : public YouTuber {
public:
    GamingYouTuber(string user, int count, string channel)
        : YouTuber(user, count, channel) {}
    void streamGame(const string& game) const {
        cout << "[" << username << "] is now streaming [" << game
             << "] on [" << channelName << "].\n";
    }
};

class InstagramInfluencer : public SocialMediaUser {
public:
    InstagramInfluencer(string user, int count) : SocialMediaUser(user, count) {}
    void postStory(const string& story) const {
        cout << "[" << username << "] posted a new story: [" << story << "].\n";
    }
};

int main() {
    YouTuber creator("tech_vraj", 25000, "Tech with Vraj");
    creator.displayProfile();
    creator.uploadVideo("C++ OOP Basics");

    Podcaster podcaster("dailybytes", 8000, "Daily Bytes");
    podcaster.displayProfile();
    podcaster.publishEpisode("Learning Programming");

    GamingYouTuber gamer("game_vraj", 15000, "Vraj Plays");
    gamer.streamGame("Minecraft");

    InstagramInfluencer influencer("vraj_daily", 12000);
    influencer.displayProfile();
    influencer.postStory("New coding setup");
}
