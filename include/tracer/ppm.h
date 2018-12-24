#ifndef FREY_PPM_H
#define FREY_PPM_H

#include <string>
#include <math/vector.h>
#include <memory>

namespace frey{
    class ppm{
        private:
            uint height, width;
            std::unique_ptr<frey::vector> pixels, current;
            std::unique_ptr<uint> samples;

        public:
            ppm(uint h, uint w);

            void save(std::string filename);
            void set(uint x, uint y, const frey::vector val);
            frey::vector get(uint x, uint y);
    };
}

#endif 
