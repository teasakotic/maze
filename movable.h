#ifndef MOVABLE_H_INCLUDED
#define MOVABLE_H_INCLUDED

class Movable{
public:
    virtual void move()=0;
    virtual void move(int dx, int dy)=0;
};


#endif // MOVABLE_H_INCLUDED
