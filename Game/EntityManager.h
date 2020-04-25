#pragma once
#include "Entity.h"
#include "NonPlayer.h"

static Entity* floorTile = new Entity("Floor", 0x002D);
static Entity* wallTile = new Entity("Wall", 0x0023);

static NonPlayer* jeff = new NonPlayer("Jeff", 0x004A);
