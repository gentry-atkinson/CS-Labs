//Gentry Atkinson
//CS1428 Fall 2019
//Lab 13

#ifndef MATERIAL_H
#define MATERIAL_H


class Material
{
    public:
        Material();
        ~Material();

        void addMelting(float);
        void addBreaking(float);
        float getAvgMelt();
        float getAvgBreak();
        void reset();

    private:
        //Holds the results of 3 melting tests
        float melting[3];

        //Holds the results of 3 breaking tests
        float breaking[3];

        //Pointer to the melt and break array
        //Should be the index of the next position to write
        int meltPointer, breakPointer;
};


#endif // MATERIAL_H
