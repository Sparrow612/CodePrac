//
//  Twitter.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/8.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Tweet{
    int userId, tweetId;
    Tweet(int uid, int tid){
        userId = uid;
        tweetId = tid;
    }
};

struct Follow{
    int follower, followee;
    bool valid = false;
    Follow(int r, int e){
        follower = r;
        followee = e;
        valid = true;
    }
};

class Twitter {
private:
    vector<Tweet> tweets;
    vector<Follow> follows;
    
    vector<int> getUserFollows(int uid){
        vector<int> res = {uid};
        for (Follow f : follows){
            if (f.valid&&f.follower == uid){
                res.push_back(f.followee);
            }
        }
        return res;
    }
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back(Tweet(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (tweets.size()==0) return res;
        vector<Tweet>::iterator it = tweets.end()-1;
        vector<int> follows = getUserFollows(userId);
        int cur = 0;
        while (cur<10&&it>=tweets.begin()){
            vector<int>::iterator temp = find(follows.begin(), follows.end(), it->userId);
            if (temp!=follows.end()){
                res.push_back(it->tweetId);
                cur++;
            }
            it--;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId!=followeeId)
            follows.push_back(Follow(followerId, followeeId));
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        for (Follow& f : follows){
            if (f.follower == followerId && f.followee == followeeId){
                f.valid = false;
                break;
            }
        }
    }
};

//int main(){
//    Twitter * t =new Twitter;
//    t->getNewsFeed(1);
//}

// 题目不难，用心做即可
