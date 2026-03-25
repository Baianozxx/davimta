#ifndef AIMBOT_H
#define AIMBOT_H

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Circle {
    Vector3 center;
    float radius;
};

void initializeAimbot();
void aimAtTarget(Vector3 target);

#endif // AIMBOT_H
