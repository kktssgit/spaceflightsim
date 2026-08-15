#pragma once
#include <bits/stdc++.h> // change  later
#include "kmath.hpp"

namespace kgraph {
    struct Point{
        long double x=0;
        long double y=0;    
    };
    
    struct Polygon{
        std::vector<Point>vertices;
        size_t size{};

        Polygon(const std::vector<Point>&vertices) : vertices(vertices) {
            size = vertices.size();
        }

        void change(size_t it, Point pt){
            assert(it < vertices.size() && it >= 0);

            vertices[it]=pt;
        }
    };
};
