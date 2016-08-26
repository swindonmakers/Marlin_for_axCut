// relay.h

#ifndef relay_h
#define relay_h

void relay_init();

void turnRelayOn(int relay);

void turnRelayOff(int relay);

void setLighting(int level);

void fadeLighting(int level, int dur);

#endif
