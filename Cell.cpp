/* 
 * File:   Cell.cpp
 * Author: jacob
 * 
 * Created on October 20, 2014, 11:42 PM
 */

#include "Cell.h"
#include "Defines.h"
#include <cstdlib>
#include <GL/glut.h>

/* This is the constructor for the cells.
 * 3 ints must be provided.
 * s: The size of the cell.
 * wx, wz: The World Coordinate of the cell.*/
Cell::Cell(int s, int wx, int wz) {
    size = s;
    wbx = wx * s;
    wbz = wz * s;
    
    first = NULL;
}

Cell::Cell(const Cell& orig) {
    
}

/* Deconstructor */
// Delete all Entities and Spells.
Cell::~Cell() {
    
}

/* Simple data access method */
int Cell::get_size(){
    return size;
}

/* Will draw the cell and all the entities inside it.
 * Even though the player inherits entity it wont be tacked by Cells.  */
void Cell::draw(float i, int x, int z){
    Entity_List* curr = first;
    // Start of by drawing the ground.
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, size);
    glVertex3f(size, 0, size);
    glVertex3f(size, 0, 0);
    glEnd();
    // Debug draw to show where cells end.
#ifdef DEBUG_MESSAGES
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, size);
    glVertex3f(size, 0, size);
    glVertex3f(size, 0, 0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glVertex3f(size/16, 0, 0);
    glVertex3f(size/16, 0, size/16);
    glEnd();
#endif
    while(curr != NULL){
        glPushMatrix();
        glTranslatef(curr->e->getX() - (size * x), 0, curr->e->getZ() - (size * z));
        curr->e->draw(i);
        glPopMatrix();
        curr = curr->next;
    }
}

void Cell::add_entity(Entity* e){
    if(first == NULL){
        first = new Entity_List;
        first->e = e;
        first->next = NULL;
    }
    else{
        Entity_List* curr = first;
        while(curr->next != NULL) curr = curr->next;
        curr->next = new Entity_List;
        curr = curr->next;
        curr->e = e;
        curr->next = NULL;
    }
}

/* Will go ahead and update all the entities in the cell.
 * Will also initialize the movement of spells. */
void Cell::update(){
    
}

/* Update all the entities movement*/
void Cell::update_movement(){
    Entity_List* curr = first;
    while(curr != NULL) {
        curr->e->update_pos();
        // We need to check if we need to move an entity to a neighbor cell.
        //if()
        curr = curr->next;
    }
}

