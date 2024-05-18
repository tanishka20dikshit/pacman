class Entities : public Elements{
    private:
        int speed;
    public:
        Entities() {}
        virtual bool move(int direction,Maze maze,float time){return false;}
        virtual float getSpeed(){return speed;}
};