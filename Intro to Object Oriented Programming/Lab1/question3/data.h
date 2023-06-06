#pragma once //makes sure header file isn't used twice in compilation
namespace m //creating namespace for our class to avoid doing m::Type::
{
    class Type
    {
    public:

        int Integer(int a, float b, char c); //in the public part of the class I set up the functions with various types of arguments
        void Void(int d, char e);
        float Float(float f, float g, int h, char i);
        char Character(char j, float k);

    };
}