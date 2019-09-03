#ifndef PAD
#define PAD
#include <QGraphicsPixmapItem>
class Pad: public QGraphicsPixmapItem {

public:
    static int count; //use count to randomize the pads created in the same time
    Pad(int miny, int maxy, int maxx, QGraphicsPixmapItem *parent = 0);
};

class NormalPad : public Pad{
public:
    NormalPad(int miny, int maxy, int maxx, QGraphicsPixmapItem *parent = 0);
};
class BreakingPad : public Pad{
public:
    BreakingPad(int miny, int maxy, int maxx, QGraphicsPixmapItem *parent = 0);
};
class JumpingPad : public Pad{
public:
    JumpingPad(int miny, int maxy, int maxx, QGraphicsPixmapItem *parent = 0);
};
#endif // PAD

