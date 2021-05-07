#pragma once
#include "GameObject.h"
#include <string>
class DetailObject :
    public GameObject
{
public:

    DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h);
    DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, int sw, int sh);
    DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, bool anim, int frames, int delayTime = 500);
    DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, int sw, int sh, bool anim, int frames, int delayTime = 500, bool looper = true);
    DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, bool offs);
    DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, int sw, int sh, bool offs);
    DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, bool offs, bool anim, int frames, int delayTime = 500);
    DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, int sw, int sh, bool offs, bool anim, int frames, int delayTime = 500, bool looper = true);
    void moveObjectTo(int x, int y);
    void moveObject(int x, int y);
    virtual void update();
    int width;
    int height;
    int frames;
    bool animated;
    bool aniInit;
    int sx;
    int sy;
    bool loop = true;
    int delayTime;
    std::string objectID;
    void setObjectID(std::string newid);
};

