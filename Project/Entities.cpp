class Entities : public Elements{
    private:
        int speed;
    public:
        Entities() {}
        virtual bool move(int direction,Maze maze){return false;}
};