/* 
 * File:   Entity.cpp
 * Author: jacob
 * 
 * Created on October 20, 2014, 1:57 PM
 */

#include "Entity.h"

Entity::Entity() {
}

Entity::Entity(const Entity& orig) {
}

Entity::~Entity() {
}

void Entity::move(float px, float pz){
    distX = px - x;
    distZ = pz - z;
}
void Entity:: update_pos(){ return; }
float Entity::getX(){ return x;}
float Entity::getZ(){ return z;}
void Entity::draw(float f){ return; };
void Entity::update(){ return; }

