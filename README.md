Elastic collision of 2 objects

There 2 states of program:
State::Pause - mass of second object must be entered(int num above 0)
speed of second object is -128 by default, can be changed in constructor of engine class
Enter mass of object before pressing to start
State::Play - program demonstrates collision
1st object has mass of 1kg by default and doesn't move untill second object collides with it

Press ESC button to return to State::Pause
while puting mass of second object in State::Pause press BACKSPACE to correct number if it's necessary

BUGS:
a bugmay occure while colliding. In this case just get back to State::Pause put mass and start again
second bug is related to correcting while puting mass of second object in State::Pause. it deletes 2 numbers instead of 1
