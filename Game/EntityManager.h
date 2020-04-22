#pragma once
#include "Entity.h"
#include "NonPlayer.h"

static Entity* floorTile = new Entity("Floor", '-');
static Entity* wallTile = new Entity("Wall", '#');

static NonPlayer* jeff = new NonPlayer("Jeff", 'J');
