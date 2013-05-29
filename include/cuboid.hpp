#ifndef CUBOID_HPP
#define CUBOID_HPP

#include <vector>
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_oarchive.hpp>

#include "forward_declarations.hpp"

class Cuboid {
public:
	Cuboid() {}
    Cuboid(int w, int h, int d) :
        width(w), height(h), depth(d) {}

    template<class Archive>
    void serialize(Archive &ar, const unsigned int file_verision)
    {
        ar & boost::serialization::make_nvp("width", width);
        ar & boost::serialization::make_nvp("height", height);
        ar & boost::serialization::make_nvp("depth", depth);
        ar & boost::serialization::make_nvp("x", x);
        ar & boost::serialization::make_nvp("y", y);
        ar & boost::serialization::make_nvp("z", z);
    }

    int width;
    int height;
    int depth;
    int x = 0;
    int y = 0;
    int z = 0;
    bool isPlaced = false;

    /* Variable useful in global guillotine algorithm to store a score
     * of choosing this cuboid. */
    int score = std::numeric_limits<int>::max();

    static bool compareMaxEdge(Cuboid i,Cuboid j)
    {
    	int i_max = std::max({i.width, i.height, i.depth});
    	int j_max = std::max({j.width, j.height, j.depth});
    	return i_max > j_max;
    }
    static bool compareVolume(Cuboid i,Cuboid j)
    {
    	return ((i.width * i.height * i.depth) > (j.width * j.height * j.depth));
    }

};

#endif
